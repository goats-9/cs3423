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

    /* global defines */
    #define PREAMBLE            "Name: Gautam Singh\nID: CS21BTECH11018\n"
    #define INT                 "integer"
    #define CHAR                "character"
    #define STRING              "string"
    #define FLOAT               "float"
    #define BOOL                "boolean"
    #define ID                  "id"
    #define KEYWORD             "keyword"
    #define LOGI_OP             "logical operator"
    #define ARTH_OP             "arithmetic operator"
    #define ASGN_OP             "assignment operator"
    #define PUNC                "punctuator"
    #define TYPE                "type"
%}

%{
    /* global variables */
    FILE *cfile;        // Filestream to output C file.
    FILE *tfile;        // Filestream to output tokens.
    bool yyopfl;        // Flag to distinguish operators and
                        // special characters in an identifier.
%}


%{
    /* regular definitions */

    /* 
    newlines are treated differently compared to whitespace
    since we have to generate an equivalent C program.
    */
%}

delim                           [ \t]
ws                              {delim}+
letter                          [a-zA-Z]
digit                           [0-9]
number                          [+\-]?{digit}+
posint                          [1-9]{digit}*
special                         [@#\*\-\+/\\:_]
float                           [+\-]?{digit}*("."{digit}*)?([eE][+\-]?{digit}*)?

%%

%{
    /* translation rules */
%}

%{
    /* keywords */  
%}

"pp"{posint}*":"                { ECHO; fprintf(tfile, "%s: %s\n", KEYWORD, yytext); fprintf(cfile, "%s", yytext); }
"in case that"                  { ECHO; fprintf(tfile, "%s: %s\n", KEYWORD, yytext); fprintf(cfile, "if"); }
"otherwise"                     { ECHO; fprintf(tfile, "%s: %s\n", KEYWORD, yytext); fprintf(cfile, "else"); }
"jump to"                       { ECHO; fprintf(tfile, "%s: %s\n", KEYWORD, yytext); fprintf(cfile, "goto"); }
"do"                            { ECHO; fprintf(tfile, "%s: %s\n", KEYWORD, yytext); }
"gteq"                          { ECHO; fprintf(tfile, "%s: %s\n", KEYWORD, yytext); fprintf(cfile, ">="); }
"gt"                            { ECHO; fprintf(tfile, "%s: %s\n", KEYWORD, yytext); fprintf(cfile, ">"); }
"lteq"                          { ECHO; fprintf(tfile, "%s: %s\n", KEYWORD, yytext); fprintf(cfile, "<="); }
"lt"                            { ECHO; fprintf(tfile, "%s: %s\n", KEYWORD, yytext); fprintf(cfile, "<"); }
"and"                           { ECHO; fprintf(tfile, "%s: %s\n", KEYWORD, yytext); fprintf(cfile, "&&"); }
"or"                            { ECHO; fprintf(tfile, "%s: %s\n", KEYWORD, yytext); fprintf(cfile, "||"); }
"true"                          { ECHO; fprintf(tfile, "%s: %s\n", KEYWORD, yytext); fprintf(cfile, "%s", yytext); }
"false"                         { ECHO; fprintf(tfile, "%s: %s\n", KEYWORD, yytext); fprintf(cfile, "%s", yytext); }

%{
    /* data types */
%}

"null"                          { ECHO; fprintf(tfile, "%s: %s\n", TYPE, yytext); fprintf(cfile, "null"); }
"bool"                          { ECHO; fprintf(tfile, "%s: %s\n", TYPE, yytext); fprintf(cfile, "null"); }
"integer"(_{posint})?           { ECHO; fprintf(tfile, "%s: %s\n", TYPE, yytext); fprintf(cfile, "int"); }
"character"(_{posint})?         { ECHO; fprintf(tfile, "%s: %s\n", TYPE, yytext); fprintf(cfile, "char"); }
"float"(_{posint})?             { ECHO; fprintf(tfile, "%s: %s\n", TYPE, yytext); fprintf(cfile, "float"); }
"string"                        { ECHO; fprintf(tfile, "%s: %s\n", TYPE, yytext); fprintf(cfile, "char *"); }

%{
    /* arithmetic, logical and assignment operators */
%}

"=="                            |
">="                            |
"<="                            |
">"                             |
"!="                            |
"!"                             { ECHO; fprintf(tfile, "%s: %s\n", LOGI_OP, yytext); fprintf(cfile, "%s", yytext); }
"="                             { ECHO; fprintf(tfile, "%s: %s\n", ASGN_OP, yytext); fprintf(cfile, "%s", yytext); }
"+"                             |
"-"                             |
"*"                             |
"/"                             |
"_"                             { ECHO; fprintf(tfile, "%s: %s\n", ARTH_OP, yytext); if (yyopfl) { fprintf(cfile, "%s", yytext); yyopfl = false; } else yymore(); }

%{
    /* punctuation */
%}

","                             |
";"                             |
"("                             |
")"                             |
"["                             |
"]"                             { ECHO; fprintf(tfile, "%s: %s\n", PUNC, yytext); fprintf(cfile, "%s", yytext); yyopfl = false; }

%{
    /* identifiers */
%}

{special}({digit}|{number})*     { ECHO; fprintf(tfile, "%s: %s\n", ID, yytext); fprintf(cfile, "%s", yytext); yyopfl = true; }

%{
    /* constants */
%}

{number}                        { ECHO; fprintf(tfile, "%s: %s\n", INT, yytext); fprintf(cfile, "%s", yytext); yyopfl = true; }
{float}                         { ECHO; fprintf(tfile, "%s: %s\n", FLOAT, yytext); fprintf(cfile, "%s", yytext); yyopfl = true; }
\'.*\'                          { ECHO; fprintf(tfile, "%s: %s\n", CHAR, yytext); fprintf(cfile, "%s", yytext); }
\".*\"                          { ECHO; fprintf(tfile, "%s: %s\n", STRING, yytext); fprintf(cfile, "%s", yytext); }

%{
    /* whitespaces and misc */
%}

{ws}                            { ECHO; fprintf(cfile, "%s", yytext); }
.                               { }

%%

/* auxiliary functions */

int main(int argc, char *argv[]) {
    // argv[1] : path to source file
    // argv[2] : path to token file
    // argv[3] : path to C file
    FILE *infile = fopen(argv[1], "r");
    if (!infile) { 
        printf("[ERROR] Cannot open the input file.\n");
        return -1;
    }
    tfile = fopen(argv[2], "w");
    cfile = fopen(argv[3], "w");
    fprintf(tfile, PREAMBLE);
    // yyin is input filestream
    yyin = infile;
    // lex through the input filestream
    while(yylex());
    // close the files
    fclose(cfile), fclose(tfile), fclose(infile);
    return 0;
}
