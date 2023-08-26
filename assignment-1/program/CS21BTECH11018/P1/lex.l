%{
    /*
    Name    : Gautam Singh
    ID      : CS21BTECH11018
    Date    : 2023-08-16
    File    : lex.l
    Purpose : Lex source code for C-like program language. Takes program source
              code and outputs:
              1. Equivalent C source code.
              2. Sequence of tokens along with their type.
    */
%}

%{
    /* global includes */
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>

    /* global defines */
    #define PREAMBLE            "Name: Gautam Singh\nID: CS21BTECH11018\n"
    // define token types as indices into toknames
    #define LABEL               0
    #define ID                  1
    #define KEYWORD             2
    #define PUNC                3
    #define DTYPE               4
    #define CONST               5
    #define OP                  6
    #define SPECIAL             7
    // macro for actions
    #define ACTION(tok, yytok, clex) fprintf(tfile, "%s: %s\n", toknames[tok], yytok); addNode(end, newNode(yytok, clex, tok))

    /* doubly linked list struct */
    typedef struct node { 
        // Pointers to next and previous nodes
        struct node *next, *prev;
        // Actual lexeme
        char *lexeme;
        // Equivalent C lexeme
        char *c_lexeme;
        // Type of lexeme
        int type;
    } node_t;

    /* global variables */
    // Start and end nodes of the double linked list
    node_t *start, *end;
    // Array of names of each type of token
    char *toknames[] = { 
        "label",
        "ID",
        "reserved keyword",
        "punctuation",
        "datatype",
        "constant",
        "operator",
        "special symbol",
    };
    int *labelarr;      // Array to determine whether labels should be included for a line
    int labelsz;        // Size of labelarr
    FILE *cfile;        // Filestream to output C file.
    FILE *tfile;        // Filestream to output tokens.
    bool yycondfl;      // Flag to indicate predicate bracketing

    /* prototypes for linked list */
    node_t *newNode (char *, char *, int);
    void addNode (node_t *, node_t *);
    void initLL (node_t **, node_t **);
    void destroyLL(node_t **);
    void printLL(node_t *);
%}

%option noinput nounput

%{
    /* regular definitions */
%}

delim                                           [ \t\n]
ws                                              {delim}+
letter                                          [a-zA-Z]
digit                                           [0-9]
number                                          [+\-]?{digit}+
posint                                          [1-9]{digit}*
special                                         [@#\*\-\+/\\:_]
char                                            (\\.|[^\\])

%%

%{
    /* translation rules */
%}

%{
    /* labels */
%}

"pp"{posint}                                    { 
                                                    // check if this is a goto label
                                                    if (end->prev->type == KEYWORD && !strncmp(end->prev->c_lexeme, "goto", 4)) {
                                                        /* this label must be added in the C code */
                                                        int ln = atoi(yytext + 2);
                                                        if (ln + 1 > labelsz) {
                                                            labelarr = realloc(labelarr, (ln + 1)*sizeof(int));
                                                            labelsz = ln + 1;
                                                        }
                                                        labelarr[ln] = 1; 
                                                    }
                                                    ACTION(LABEL, yytext, yytext);
                                                }

%{
    /* keywords */  
%}

"in case that"                                  { ACTION(KEYWORD, yytext, "if"); yycondfl = true; }
"otherwise"                                     { ACTION(KEYWORD, yytext, "else"); }
"jump to"                                       { ACTION(KEYWORD, yytext, "goto"); }
"do"                                            { ACTION(KEYWORD, yytext, ""); yycondfl = false; }
"gteq"                                          { ACTION(KEYWORD, yytext, ">="); }
"gt"                                            { ACTION(KEYWORD, yytext, ">"); }
"lteq"                                          { ACTION(KEYWORD, yytext, "<="); }
"lt"                                            { ACTION(KEYWORD, yytext, "<"); }
"eq"                                            { ACTION(KEYWORD, yytext, "=="); }
"neq"                                           { ACTION(KEYWORD, yytext, "!="); }
"and"                                           { ACTION(KEYWORD, yytext, "&&"); }
"or"                                            { ACTION(KEYWORD, yytext, "||"); }
"return"                                        { ACTION(KEYWORD, yytext, yytext); }

%{
    /* datatypes */
%}

"null"                                          { ACTION(DTYPE, yytext, "void"); } 
"integer_2"                                     { ACTION(DTYPE, yytext, "int"); } 
"character_1"                                   { ACTION(DTYPE, yytext, "char"); } 
"string"                                        { ACTION(DTYPE, yytext, "char *"); } 

%{
    /* operators */
%}

"!"                                             |
"="                                             |
"+"                                             |
"-"                                             |
"*"                                             |
"/"                                             |
"_"                                             { ACTION(OP, yytext, yytext); }

%{
    /* punctuators */
%}

","                                             |
";"                                             |
":"                                             { ACTION(PUNC, yytext, yytext); }

%{
    /* special symbols */
%}

"("                                             |
")"                                             { ACTION(SPECIAL, yytext, yytext); }
"["                                             { if (yycondfl) { ACTION(SPECIAL, yytext, "("); } else { ACTION(SPECIAL, yytext, "{"); } }
"]"                                             { if (yycondfl) { ACTION(SPECIAL, yytext, ")"); } else { ACTION(SPECIAL, yytext, "}"); } }

%{
    /* constants */

    // note that we have to lex the punctuator quotes 
    // along with character and string constants, else
    // the string constants are lexed as identifiers.

    // note also that some string manipulations are
    // performed on yytext in case a character or string
    // has been lexed to omit the start and end quotes.
%}

{number}                                        { ACTION(CONST, yytext, yytext); }
[']({char})?[']                                 { ACTION(PUNC, "'", "'"); yytext[yyleng - 1] = '\0'; ++yytext; ACTION(CONST, yytext, yytext); ACTION(PUNC, "'", "'"); }
["]{char}*["]                                   { ACTION(PUNC, "\"", "\""); yytext[yyleng - 1] = '\0'; ++yytext; ACTION(CONST, yytext, yytext); ACTION(PUNC, "\"", "\""); }

%{
    /* identifiers */
%}

{special}?({letter}|{digit})*                   { 
                                                    // Error if equal to "pp"
                                                    if (!strcmp(yytext, "pp")) {
                                                        fprintf(tfile, "Error at line pp%d\n", yylineno);
                                                        return 0;
                                                    } 
                                                    ACTION(ID, yytext, yytext); 
                                                }

%{
    /* whitespaces, newlines and bad characters */

    // yylineno is incremented here and whitespaces
    // are reflected in the generated C code.
%}

\n                                              { 
                                                    ++yylineno; 
                                                    addNode(end, newNode(yytext, yytext, PUNC)); 
                                                    if (yylineno + 1 > labelsz) { 
                                                        labelarr = realloc(labelarr, (yylineno+1)*sizeof(int)); 
                                                        labelsz = yylineno + 1; 
                                                    }
                                                }
{ws}                                            { }
.                                               { fprintf(tfile, "Error at line pp%d\n", yylineno); return 0; }

%%

/* auxiliary functions */

// function to create a new node in the linked list
node_t *newNode (char *lexeme, char *c_lexeme, int type) { 
    node_t *retnode = (node_t *)malloc(sizeof(node_t));
    // Dynamically allocate memory to char * elements of struct
    if (lexeme) {
        retnode->lexeme = (char *)malloc(strlen(lexeme)+1);
        strcpy(retnode->lexeme, lexeme);
    } else retnode->lexeme = lexeme;
    if (c_lexeme) {
        retnode->c_lexeme = (char *)malloc(strlen(c_lexeme)+1);
        strcpy(retnode->c_lexeme, c_lexeme);
    } else retnode->c_lexeme = c_lexeme;
    retnode->type = type;
    return retnode;
}

// function to add a new node to end in the linked list
void addNode (node_t *end, node_t *nextNode) {
    nextNode->prev = end->prev;
    end->prev = nextNode;
    nextNode->next = end;
    nextNode->prev->next = nextNode;
}

// function to initialize linked list
void initLL (node_t **start, node_t **end) { 
    // Assign dummy values to sentinels
    *start = newNode(NULL, NULL, -1);
    *end = newNode(NULL, NULL, -1);
    // Link sentinels to each other
    (*start)->next = *end;
    (*end)->prev = *start;
}

// function to destroy the linked list
void destroyLL(node_t **start) {
    node_t *next;
    node_t *curr = *start;
    while (curr) {
        next = curr->next;
        // Free all pointers inside node
        free(curr->lexeme), free(curr->c_lexeme), free(curr);
        curr = next;
    }
}

// function to generate equivalent C code
void gen_C(node_t *start) { 
    node_t *curr = start;
    // Current line number to decide 
    // whether label must be inserted or not
    int cline = 1;
    while (curr) {
        switch (curr->type) {
            case LABEL:
                // Check if this is a goto label or not
                if (curr->prev->type == KEYWORD && !strncmp(curr->prev->c_lexeme, "goto", 4)) fprintf(cfile, "%s", curr->c_lexeme);
                else if (labelarr[cline]) fprintf(cfile, "%s ", curr->c_lexeme);
                break;
            case ID:
                node_t *nxt = curr->next;
                if (nxt->type == OP && !strncmp(nxt->lexeme, "_", 1)) {
                    node_t *nxt2 = nxt->next;
                    char *op1 = curr->c_lexeme;
                    if (nxt2) {
                        char *op2 = nxt2->c_lexeme;
                        fprintf(cfile, "pow(%s,1.0/%s) ", op1, op2);
                    }
                    curr = nxt2;
                } else fprintf(cfile, "%s ", curr->c_lexeme);
                break;
            // Fallthroughs!
            case KEYWORD:
            case DTYPE:
            case OP:
            case SPECIAL:
                fprintf(cfile, "%s ", curr->c_lexeme);
                break;
            case PUNC:
                if (!strncmp(curr->c_lexeme, ":", 1)) { 
                    if (curr->prev->type == LABEL && labelarr[cline]) fprintf(cfile, "%s", curr->c_lexeme);
                } else fprintf(cfile, "%s", curr->c_lexeme);
                if (!strncmp(curr->c_lexeme, "\n", 1)) ++cline;
                break;
            case CONST:
                fprintf(cfile, "%s", curr->c_lexeme);
            default:
                break;
        }
        curr = curr->next;
    }
}

// function to print the doubly linked list
void printLL(node_t *start) { 
    node_t *curr = start;
    while (curr) { 
        fprintf(stdout, "%d: %s\n", curr->type, curr->lexeme);
        curr = curr->next;
    }
}

// main function
int main(int argc, char *argv[]) {
    // argv[1] : path to source file
    // argv[2] : path to token file
    // argv[3] : path to C file
    // yyin is input filestream
    yyin = fopen(argv[1], "r");
    if (!yyin) { 
        printf("Cannot open the input file.\n");
        return -1;
    }
    tfile = fopen(argv[2], "w");
    fprintf(tfile, PREAMBLE);
    // initialize the doubly linked list
    initLL(&start, &end);
    // lex through the input filestream
    while(yylex());
    // generate C code
    cfile = fopen(argv[3], "w");
    gen_C(start);
    // print the doubly linked list
    // destroy the doubly linked list
    destroyLL(&start);
    // close the files
    fclose(cfile), fclose(tfile);
    return 0;
}
