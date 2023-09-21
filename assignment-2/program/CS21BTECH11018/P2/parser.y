%{
    /*
    Name    : Gautam Singh
    ID      : CS21BTECH11018
    Date    : 2023-09-14
    File    : parser.y
    Purpose : File to implement a parser for a C-like language.
              Takes program source `source.clike` and does the following:
              1. Outputs the parsed file in the equivalent `source.parsed` file.
              2. Reports syntax errors in the source file.
    */
%}

%{
    /* global includes */
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    /* global defines */
    #define PREAMBLE            "Name: Gautam Singh\nID: CS21BTECH11018\n"

    /* global and extern variables */
    extern FILE *yyin, *tfile, *pfile;
    extern int yylineno;
    extern int yyerrfl;     // For flagging an error
    extern int yytype;      // For determining type of statement parsed 
                            // based on ending character, which is either 
                            // ';' (0), ')' (1), ']' (2)
    int yyretcnt;           // For counting number of return statements
    char *yytypename;

    /* prototypes for yylex and yyerror */
    int yylex();
    int yyerror(char *) { yyerrfl = 1; }
%}

// Token definitions for use in grammar productions and lexer.

%token ID
%token DTYPE
%token CONST
%token NUMBER
%token UNARY_OP
%token ARTH_OP
%token UNARY_LOGICAL_OP
%token BINARY_LOGICAL_OP
%token LOGICAL_JOIN_OP
%token GLOBAL LOCAL
%token CLASS
%token DECLARE
%token EXPR
%token TRUE
%token FALSE
%token LOOP
%token WHILE
%token DO
%token CALL
%token INCASE OTHERWISE
%token RETURN
%token FOR
%token THIS
%token L_PAREN R_PAREN L_SQUARE R_SQUARE L_BRACE R_BRACE ASGN_OP
%token SEMICOLON COMMA ARROW
%token VOID
%token TOK_EOF

%%

// Program productions

program                     : program_body
                            | TOK_EOF
                            | error
                            ;

program_body                : program_body GLOBAL function_definition block_scope { if (!yyretcnt) { fprintf(pfile, "\ninvalid statement"); return 1; } yyretcnt = 0; }
                            | program_body class
                            | GLOBAL function_definition block_scope { if (!yyretcnt) { fprintf(pfile, "\ninvalid statement"); return 1; } yyretcnt = 0; }
                            | class
                            ;

// Function and class definitions

function                    : GLOBAL function_definition block_scope { if (!yyretcnt) { fprintf(pfile, "\ninvalid statement"); return 1; } yyretcnt = 0; }
                            | LOCAL function_definition block_scope { if (!yyretcnt) { fprintf(pfile, "\ninvalid statement"); return 1; } yyretcnt = 0; } 
                            ;

function_definition         : { yytype = 1; } dtype_or_void ID num_args L_PAREN args R_PAREN { fprintf(pfile, " : function definition"); }
                            ;

dtype_or_void               : DTYPE
                            | VOID
                            ;

class                       : class_definition block_scope { if (yyerrfl) { fprintf(pfile, "\ninvalid statement"); return 1; } }
                            ;

class_definition            : { yytype = 2; } CLASS ID num_args { fprintf(pfile, " : class definition"); }
                            ;

block_scope                 : L_BRACE blocks { yytype = 3; } R_BRACE
                            | L_BRACE R_BRACE
                            ;

// Argument declarations

args                        : args_comma
                            |
                            ;

args_comma                  : args_comma COMMA DTYPE ID
                            | DTYPE ID
                            ;

num_args                    : L_SQUARE NUMBER R_SQUARE
                            |
                            ;

// Block statements and simple statements

blocks                      : block blocks
                            | block_scope blocks
                            | block
                            | block_scope
                            ;

block                       : stmt
                            | cond_block
                            | loop_block
                            | function
                            | class
                            ;

stmt                        : { yytype = 0; } stmt_body SEMICOLON { fprintf(pfile, " : %s", yytypename); }
                            ;

stmt_body                   : decl_stmt { yytypename = "declaration statement"; }
                            | expr_stmt
                            | call_stmt
                            | return_stmt { yytypename = "return statement"; ++yyretcnt; }
                            ;

// Declaration statements

decl_stmt                   : DECLARE ID id_comma
                            | DECLARE DTYPE id_comma
                            ;

id_comma                    : id_comma COMMA ID
                            | ID
                            ;

// Expression statements

expr_stmt                   : unary_expr_rhs_body { yytypename = "call statement"; }
                            | EXPR ID ASGN_OP expr_term { yytypename = "expression statement"; }
                            ;

unary_expr_rhs_body         : UNARY_OP L_PAREN unary_expr_term R_PAREN
                            ;

expr_term                   : ARTH_OP L_PAREN expr_term COMMA expr_term R_PAREN
                            | CONST
                            | TRUE
                            | FALSE
                            | unary_expr_term
                            ;

unary_expr_term             : ID
                            | NUMBER
                            | unary_expr_rhs_body
                            ;

// Function and method call statements

call_stmt                   : CALL method_call
                            | CALL function_call
                            ;

method_call                 : method_name num_args L_PAREN call_params R_PAREN { yytypename = "call statement with object"; }
                            ;

method_name                 : method_name_opt ARROW ID
                            ;

method_name_opt             : method_name_opt ARROW ID
                            | ID
                            | THIS
                            ;

function_call               : ID num_args L_PAREN call_params R_PAREN { yytypename = "call statement"; }
                            ;

call_params                 : call_params COMMA call_types
                            | call_types
                            ;

call_types                  : ID
                            | NUMBER
                            | CONST
                            | TRUE
                            | FALSE
                            ;

// Return statements

return_stmt                 : RETURN returnable

returnable                  : expr_term
                            | VOID
                            | call_stmt
                            ;

// Conditional blocks

cond_block                  : { yytype = 1; } INCASE L_PAREN predicate R_PAREN { fprintf(pfile, " : conditional statement"); } DO block_scope otherwise_block
                            ;

otherwise_block             : OTHERWISE block_scope
                            |
                            ;

// Predicates

predicate                   : predicate LOGICAL_JOIN_OP single_predicate
                            | single_predicate
                            ;

single_predicate            : UNARY_LOGICAL_OP L_PAREN predicate R_PAREN
                            | L_PAREN predicate R_PAREN
                            | predicate_term
                            ;

predicate_term              : unary_pred_body
                            | unary_pred_body BINARY_LOGICAL_OP unary_pred_body                            
                            ;

unary_pred_body             : call_stmt
                            | expr_term
                            ;

// Loop blocks

loop_block                  : loop_while_block
                            | loop_for_block
                            ;

loop_while_block            : { yytype = 1; } LOOP WHILE L_PAREN predicate R_PAREN { fprintf(pfile, " : loop"); } DO block_scope
                            ;

loop_for_block              : { yytype = 1; } FOR L_PAREN expr_stmt SEMICOLON predicate SEMICOLON loop_for_update R_PAREN { fprintf(pfile, " : loop"); } block_scope
                            ;

loop_for_update             : unary_expr_rhs_body
                            |
                            ;

%%

int main(int argc, char *argv[]) {
    yytype = -1;
    yyretcnt = 0;
    // Set input filestream
    if (argv[1]) yyin = fopen(argv[1], "r");
    else {
        printf("[ERROR] Cannot open source file\n");
        return 1;
    }
    // Set output token filestream
    if (argv[2]) tfile = fopen(argv[2], "w");
    else {
        printf("[ERROR] Cannot open output token filestream.");
        return 1;
    }
    // Set output parsed filestream
    if (argv[3]) pfile = fopen(argv[3], "w");
    else {
        printf("[ERROR] Cannot open parsed filestream.");
        return 1;
    }
    fprintf(tfile, PREAMBLE);
    // Parse the input file
    yyparse();
    return 0;
}
