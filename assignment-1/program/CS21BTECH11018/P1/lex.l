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
    void deleteNode (node_t *);
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
        // Free pointers inside node
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
    // First pass is for generating all C lexemes
    // Especially for _ operator where we need to
    // handle transformations such as (e1) _ (e2) 
    // to pow((e1),1.0/(e2))
    while (curr) {
        switch (curr->type) {
            case OP:
                // Handle _
                if (!strcmp(curr->lexeme, "_")) {
                    node_t *lt = curr->prev, *rt = curr->next;
                    if (lt->type == -1 || rt->type == -1) {
                        /* parse error */
                        printf("Error in C code generation, no code generated.\n");
                        return;
                    }
                    char *lexp = malloc(strlen(lt->c_lexeme)), *rexp = malloc(strlen(rt->c_lexeme));
                    strcpy(lexp, lt->c_lexeme);
                    strcpy(rexp, rt->c_lexeme);
                    // Count the bracket imbalance on left side
                    int brak = 0;
                    if (lt->type == SPECIAL && !strcmp(lt->lexeme, ")")) brak = 1;
                    node_t *prev = lt->prev;
                    deleteNode(lt);
                    lt = prev;
                    // Consider the entire expression on left side
                    while (brak && lt->type != -1) {
                        if (lt->type == SPECIAL) {
                            if (!strcmp(lt->lexeme, ")")) ++brak;
                            else if (!strcmp(lt->lexeme, "(")) --brak;
                        }
                        // Reallocate memory for both pre and lexp
                        lt->c_lexeme = realloc(lt->c_lexeme, strlen(lt->c_lexeme) + strlen(lexp) + sizeof(char));
                        strcat(lt->c_lexeme, lexp);
                        lexp = realloc(lexp, strlen(lt->c_lexeme));
                        strcpy(lexp, lt->c_lexeme);
                        lexp[strlen(lexp)] = '\0';
                        prev = lt->prev;
                        deleteNode(lt);
                        lt = prev;
                    }
                    if (brak) {
                        /* parsing error */
                        printf("Error in C code generation, no code generated.\n");
                        return;
                    }
                    // Count the bracket imbalance on right side
                    brak = 0;
                    if (rt->type == SPECIAL && !strcmp(rt->lexeme, "(")) brak = 1;
                    node_t *next = rt->next;
                    deleteNode(rt);
                    rt = next;
                    // Consider the entire expression on right side
                    while (brak && rt->type != -1) {
                        if (rt->type == SPECIAL) {
                            if (!strcmp(rt->lexeme, ")")) --brak;
                            else if (!strcmp(rt->lexeme, "(")) ++brak;
                        }
                        // Reallocate memory
                        rexp = realloc(rexp, strlen(rexp) + strlen(rt->c_lexeme) + sizeof(char));
                        strcat(rexp, rt->c_lexeme);
                        next = rt->next;
                        deleteNode(rt);
                        rt = next;
                    }
                    if (brak) {
                        /* parsing error */
                        printf("Error in C code generation, no code generated.\n");
                        return;
                    }
                    // Put left and right together
                    // 11 = 4 ("pow(") + 5 (",1.0/") + 2 (")\0")
                    curr->c_lexeme = realloc(curr->c_lexeme, strlen(lexp) + strlen(rexp) + 11*sizeof(char));
                    // Correctly format the C lexeme
                    sprintf(curr->c_lexeme, "pow(%s,1.0/%s)", lexp, rexp);
                }
                break;
            // Fallthroughs!
            case PUNC:
                if (!strcmp(curr->c_lexeme, ":")) { 
                    if (curr->prev->type == LABEL && labelarr[cline]);
                    else {
                        node_t *prev = curr->prev->prev;
                        deleteNode(curr->prev);
                        deleteNode(curr);
                        curr = prev;
                    }
                } else if (!strcmp(curr->c_lexeme, "\n")) ++cline;
            case LABEL:
            case ID:
            case KEYWORD:
            case DTYPE:
            case SPECIAL:
            case CONST:
            default:
                break;
        }
        // Move to next token
        curr = curr->next;
    }

    // Second pass - simply print out the lexemes
    curr = start->next;
    while (curr->type != -1) {
        fprintf(cfile, "%s", curr->c_lexeme);
        if (curr->type != PUNC && curr->type != CONST) fprintf(cfile, " ");
        curr = curr->next;
    }
}

// function to delete a node in a doubly linked list
void deleteNode(node_t *node) {
    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;
    // free the node and its pointers
    free(node->lexeme), free(node->c_lexeme), free(node);
}

// function to print the doubly linked list
void printLL(node_t *start) { 
    node_t *curr = start;
    while (curr) { 
        fprintf(stdout, "%d: %s\n", curr->type, curr->c_lexeme);
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
    // initialize labelarr
    labelarr = malloc(sizeof(int));
    labelsz = 1;
    // initialize the doubly linked list
    initLL(&start, &end);
    // lex through the input filestream
    while(yylex());
    // generate C code
    cfile = fopen(argv[3], "w");
    gen_C(start);
    // destroy the doubly linked list
    destroyLL(&start);
    // close the files
    fclose(cfile), fclose(tfile);
    return 0;
}
