%{
    /*
    Name    : Gautam Singh
    ID      : CS21BTECH11018
    Date    : 2023-09-13
    File    : lex.l
    Purpose : Lex source code for C-like program language. Takes program source
              code and: 
              1. Outputs a file `seq_tokens.txt` containing a sequence of tokens
              along with their type. 
              2. Returns token type to parser.
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
    // macro for writing to token file and parsed file
    #define TOKWRITE(yytype, tokname, yytok) fprintf(tfile, "%s: %s\n", tokname, yytok); fprintf(pfile, "%s", yytok); return yytype

    // File to write out tokens and parsed file
    FILE *tfile, *pfile;
    int yyerrfl, yytype;

    // Array of statement types
    char *stmt_type[] = {
        "function definition",
        "class definition",
        "declaration statement",
        "expression statement",
        "call statement",
        "call statement with object",
        "loop",
        "conditional statement",
        "return statement",
    };
%}

%{
    /* regular definitions */
%}

delim                                           [ \t]
ws                                              {delim}+
letter                                          [a-zA-Z]
digit                                           [0-9]
number                                          [+\-]?{digit}+
special                                         [@#\*\+/\\:_\-]
char                                            (\\.|[^"\\])

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
"geq"                                           |
"gt"                                            |
"leq"                                           |
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
[']{char}?[']                                   { fprintf(pfile, yytext); fprintf(tfile, "punctuation: \'\n"); yytext[yyleng-1] = '\0'; ++yytext; if (yytext) fprintf(tfile, "constant: %s\n", yytext); fprintf(tfile, "punctuation: \'\n"); return CONST; }
["]{char}+["]                                   { fprintf(pfile, yytext); fprintf(tfile, "punctuation: \"\n"); yytext[yyleng-1] = '\0'; ++yytext; if (yytext) fprintf(tfile, "constant: %s\n", yytext); fprintf(tfile, "punctuation: \"\n"); return CONST; }

%{
    /* identifiers */
%}

({letter}|{special})({letter}|{digit})*         { TOKWRITE(ID, "identifier", yytext); }

%{
    /* whitespaces, newlines and bad characters */

    // yylineno is incremented here and whitespaces
    // are reflected in the .parsed file.
%}

\n                                              { ++yylineno; if (yyerrfl) { fprintf(pfile, " : invalid statement"); exit(yyerrfl); } if(yytype != -1) { fprintf(pfile, " : %s", stmt_type[yytype]); yytype = -1; } fprintf(pfile, "\n"); }
{ws}                                            { fprintf(pfile, "%s", yytext); }
.                                               { printf("%d: Lexical error: %s\n", yylineno, yytext); return 0; }
<<EOF>>                                         { if (yyerrfl) { fprintf(pfile, " : invalid statement"); exit(yyerrfl); } }

%%
