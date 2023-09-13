%{
    /*
    Name    : Gautam Singh
    ID      : CS21BTECH11018
    Date    : 2023-09-13
    File    : lex.l
    Purpose : Lex source code for C-like program language. Takes program source
              code and:
              1. Outputs a file containing a sequence of tokens along with their type.
              2. Returns token type to parser
    */
%}

%{
    /* global includes */
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    // Include parser header file
    #include "y.tab.h"

    /* global defines */
    #define PREAMBLE            "Name: Gautam Singh\nID: CS21BTECH11018\n"
    // define token types as indices into toknames
    #define ID                  0
    #define KEYWORD             1
    #define PUNC                2
    #define DTYPE               3
    #define CONST               4
    #define OP                  5
    #define SPECIAL             6
    // macro for writing to token file
    #define TOKWRITE(tok, yytok) fprintf(tfile, "%s: %s\n", toknames[tok], yytok)

    /* doubly linked list struct */
    typedef struct node { 
        // Pointers to next and previous nodes
        struct node *next, *prev;
        // Actual lexeme
        char *lexeme;
        // Type of lexeme
        int type;
    } node_t;

    /* global variables */
    // Start and end nodes of the double linked list
    node_t *start, *end;
    // Array of names of each type of token
    char *toknames[] = { 
        "ID",
        "reserved keyword",
        "punctuation",
        "datatype",
        "constant",
        "operator",
        "special symbol",
    };
    FILE *tfile;        // Filestream to output tokens.

    /* prototypes for linked list */
    node_t *newNode (char *, int);
    int findLL (node_t *, char *);
    void addNode (node_t *, node_t *);
    void deleteNode (node_t *);
    void initLL (node_t **, node_t **);
    void destroyLL (node_t **);
    void printLL (node_t *);
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
    /* keywords */  
%}

"call"                                          |
"class"                                         |
"declare"                                       |
"do"                                            |
"expr"                                          |
"for"                                           |
"global"                                        |
"in case that"                                  |
"local"                                         |
"loop"                                          |
"return"                                        |
"this"                                          |
"while"                                         { TOKWRITE(KEYWORD, yytext); yylval.str = strdup(yytext); return KEYWORD; }

%{
    /* datatypes */
%}

"int"                                           |
"char"                                          |
"string"                                        |
"bool"                                          |
"void"                                          { TOKWRITE(DTYPE, yytext); yylval.str = strdup(yytext); return DTYPE; }

%{
    /* operators */
%}

"neg"                                           |   
"gteq"                                          |
"gt"                                            |
"lteq"                                          |
"lt"                                            |
"eq"                                            |
"ne"                                            |
"and"                                           |
"or"                                            |
"add"                                           |
"sub"                                           |
"mul"                                           |
"div"                                           { TOKWRITE(OP, yytext); yylval.str = strdup(yytext); return OP; }

%{
    /* punctuators */
%}

","                                             |
";"                                             |
":"                                             { TOKWRITE(PUNC, yytext); return PUNC; }

%{
    /* special symbols */
%}

"("                                             |
")"                                             |
"{"                                             |
"}"                                             |
"["                                             |
"]"                                             { TOKWRITE(PUNC, yytext); return PUNC; }

%{
    /* constants */

    // note that we have to lex the punctuator quotes 
    // along with character and string constants, else
    // the string constants are lexed as identifiers.

    // note also that some string manipulations are
    // performed on yytext in case a character or string
    // has been lexed to omit the start and end quotes.
%}

{number}                                        { TOKWRITE(CONST, yytext); return CONST; }
[']({char})?[']                                 |
["]{char}*["]                                   { TOKWRITE(PUNC, "'"); yytext[yyleng - 1] = '\0'; ++yytext; TOKWRITE(CONST, yytext); TOKWRITE(PUNC, "'"); }

%{
    /* identifiers */
%}

{special}?({letter}|{digit})*                   { TOKWRITE(ID, yytext); return ID; }

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
node_t *newNode (char *lexeme, int type) { 
    node_t *retnode = (node_t *)malloc(sizeof(node_t));
    // Dynamically allocate memory to char * elements of struct
    if (lexeme) {
        retnode->lexeme = (char *)malloc(strlen(lexeme)+1);
        strcpy(retnode->lexeme, lexeme);
    } else retnode->lexeme = lexeme;
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

// function to find the token in the linked list
// and return the type of token it represents
int findLL (node_t *start, char *yytok) { 
    node_t curr = start;
    while (curr) {
        if (!strcmp(yytok, curr->lexeme)) return curr->type;
        curr = curr->next;
    }
    return -1;
}

// function to initialize linked list
void initLL (node_t **start, node_t **end) { 
    // Assign dummy values to sentinels
    *start = newNode(NULL, -1);
    *end = newNode(NULL, -1);
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
        free(curr->lexeme), free(curr);
        curr = next;
    }
}

// function to delete a node in a doubly linked list
void deleteNode(node_t *node) {
    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;
    // free the node and its pointers
    free(node->lexeme), free(node);
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
