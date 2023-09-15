%{
    /*
    Name    : Gautam Singh
    ID      : CS21BTECH11018
    Date    : 2023-09-13
    File    : lex.l
    Purpose : Lex source code for C-like program language. Takes program source
              code and: 
              1. Outputs a file containing a sequence of tokens along with their
              type. 
              2. Returns token type to parser.
    */
%}

%{
    /* global includes */
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    // Include parser header file
    #include "parser.tab.h"

    /* global defines */
    #define PREAMBLE            "Name: Gautam Singh\nID: CS21BTECH11018\n"
    // macro for writing to token file
    #define TOKWRITE(yytype, tokname, yytok) fprintf(tfile, "%s: %s\n", tokname, yytok); fprintf(pfile, "%s", yytok); yylval.str = strdup(yytok); return yytype

    // File to write out tokens and parsed file
    FILE *tfile, *pfile;
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
special                                         [@#\*\+/\\:_]
char                                            (\\.|[^\\])

%%

%{
    /* translation rules */
%}

%{
    /* keywords */  
%}

"call"                                          { TOKWRITE(CALL, "reserved keyword", yytext); }
"class"                                         { TOKWRITE(CLASS, "reserved keyword", yytext); }
"declare"                                       { TOKWRITE(DECLARE, "reserved keyword", yytext); }
"do"                                            { TOKWRITE(DO, "reserved keyword", yytext); }
"expr"                                          { TOKWRITE(EXPR, "reserved keyword", yytext); }
"false"                                         { TOKWRITE(FALSE, "reserved keyword", yytext); }
"for"                                           { TOKWRITE(FOR, "reserved keyword", yytext); }
"global"                                        { TOKWRITE(GLOBAL, "reserved keyword", yytext); }
"in case that"                                  { TOKWRITE(INCASE, "reserved keyword", yytext); }
"local"                                         { TOKWRITE(LOCAL, "reserved keyword", yytext); }
"loop"                                          { TOKWRITE(LOOP, "reserved keyword", yytext); }
"otherwise"                                     { TOKWRITE(OTHERWISE, "reserved keyword", yytext); }
"return"                                        { TOKWRITE(RETURN, "reserved keyword", yytext); }
"this"                                          { TOKWRITE(THIS, "reserved keyword", yytext); }
"true"                                          { TOKWRITE(TRUE, "reserved keyword", yytext); }
"while"                                         { TOKWRITE(WHILE, "reserved keyword", yytext); }

%{
    /* datatypes */
%}

"int"                                           |
"char"                                          |
"string"                                        |
"bool"                                          { TOKWRITE(DTYPE, "datatype", yytext); }
"void"                                          { TOKWRITE(VOID, "datatype", yytext); }

%{
    /* operators */
%}

"neg"                                           { TOKWRITE(UNARY_LOGICAL_OP, "operator", yytext); }   
"gteq"                                          |
"gt"                                            |
"lteq"                                          |
"lt"                                            |
"eq"                                            |
"ne"                                            { TOKWRITE(BINARY_LOGICAL_OP, "operator", yytext); }
"and"                                           |
"or"                                            { TOKWRITE(LOGICAL_JOIN_OP, "operator", yytext); }
"add"                                           |
"sub"                                           |
"mul"                                           |
"div"                                           { TOKWRITE(ARTH_OP, "operator", yytext); }
"postincr"                                      |
"postdecr"                                      { TOKWRITE(UNARY_OP, "operator", yytext); }
"="                                             { TOKWRITE(ASGN_OP, "operator", yytext); }

%{
    /* punctuators */
%}

","                                             { TOKWRITE(COMMA, "punctuation", yytext); }
";"                                             { TOKWRITE(SEMICOLON, "punctuation", yytext); }
"->"                                            { TOKWRITE(ARROW, "punctuator", yytext); }

%{
    /* special symbols */
%}

"("                                             { TOKWRITE(L_PAREN, "special symbol", yytext); }
")"                                             { TOKWRITE(R_PAREN, "special symbol", yytext); }
"{"                                             { TOKWRITE(L_BRACE, "special symbol", yytext); }
"}"                                             { TOKWRITE(R_BRACE, "special symbol", yytext); }
"["                                             { TOKWRITE(L_SQUARE, "special symbol", yytext); }
"]"                                             { TOKWRITE(R_SQUARE, "special symbol", yytext); }

%{
    /* constants */

    // note that we have to lex the punctuator quotes 
    // along with character and string constants, else
    // the string constants are lexed as identifiers.

    // note also that some string manipulations are
    // performed on yytext in case a character or string
    // has been lexed to omit the start and end quotes.
%}

{number}                                        { TOKWRITE(NUMBER, "constant", yytext); }
[']({char})?[']                                 { yylval.str = strdup(yytext); fprintf(tfile, "punctuation: \'\n"); yytext[yyleng-1] = '\0'; ++yytext; fprintf(tfile, "constant: %s\n", yytext); fprintf(tfile, "punctuation: \'\n"); return CONST; }
["]{char}*["]                                   { yylval.str = strdup(yytext); fprintf(tfile, "punctuation: \"\n"); yytext[yyleng-1] = '\0'; ++yytext; fprintf(tfile, "constant: %s\n", yytext); fprintf(tfile, "punctuation: \"\n"); return CONST; }

%{
    /* identifiers */
%}

({letter}|{digit}|{special})*                   { TOKWRITE(ID, "identifier", yytext); }

%{
    /* whitespaces, newlines and bad characters */

    // yylineno is incremented here and whitespaces
    // are reflected in the generated C code.
%}

\n                                              { ++yylineno; fprintf(pfile, "%s", yytext); }
{ws}                                            { fprintf(pfile, "%s", yytext); }
.                                               { printf("Lexical error\n"); }

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
    node_t *curr = start;
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
