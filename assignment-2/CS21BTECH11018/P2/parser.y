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

    /* global extern variables */
    extern FILE *yyin, *tfile, *pfile;

    /* prototypes for yylex and yyerror */
    int yylex();
    int yyerror(char *);
%}

// Union of datatypes for yylval.
// A char * is enough since we need to output
// the obtained lexeme without evaluation or 
// data flow analysis.

%union {
    char *str;
}

/* %define parse.error verbose */

// Token definitions for use in grammar productions and lexer.

%token <str> ID
%token <str> DTYPE
%token <str> CONST
%token <str> NUMBER
%token <str> UNARY_OP
%token <str> ARTH_OP
%token <str> UNARY_LOGICAL_OP
%token <str> BINARY_LOGICAL_OP
%token <str> LOGICAL_JOIN_OP
%token <str> GLOBAL LOCAL
%token <str> CLASS
%token <str> DECLARE
%token <str> EXPR
%token <str> TRUE
%token <str> FALSE
%token <str> LOOP
%token <str> WHILE
%token <str> DO
%token <str> CALL
%token <str> INCASE OTHERWISE
%token <str> RETURN
%token <str> FOR
%token <str> THIS
%token <str> L_PAREN R_PAREN L_SQUARE R_SQUARE L_BRACE R_BRACE ASGN_OP
%token <str> SEMICOLON COMMA ARROW
%token <str> VOID

%%

// Program productions

program                     : program_body
                            ;

program_body                : function_definition_global block_scope program_body
                            | class program_body
                            |
                            ;

// Function and class prototypes

function                    : function_definition_global block_scope
                            | function_definition_local block_scope
                            ;

function_definition_global  : GLOBAL function_definition
                            ;
                            
function_definition_local   : LOCAL function_definition
                            ;

function_definition         : dtype_or_void ID num_args L_PAREN args R_PAREN { fprintf(pfile, " : function definition"); }
                            | error
                            ;

dtype_or_void               : DTYPE
                            | VOID
                            ;

class                       : class_definition block_scope
                            ;

class_definition            : CLASS ID num_args { fprintf(pfile, " : class definition"); }
                            | error
                            ;

block_scope                 : L_BRACE blocks R_BRACE
                            ;

// Argument declarations

args                        : DTYPE ID args_comma
                            |
                            | error
                            ;

args_comma                  : COMMA DTYPE ID args_comma
                            |
                            | error
                            ;

num_args                    : L_SQUARE NUMBER R_SQUARE
                            |
                            | error
                            ;

// Block statements and simple statements

blocks                      : block blocks
                            | block
                            ;

block                       : stmt
                            | cond_block
                            | loop_block
                            | function
                            | class
                            ;

stmt                        : stmt_body SEMICOLON
                            ;

stmt_body                   : decl_stmt
                            | expr_stmt
                            | call_stmt
                            | return_stmt
                            ;

// Declaration statements

decl_stmt                   : DECLARE ID ID { fprintf(pfile, " : declaration statement"); }
                            | DECLARE DTYPE ID { fprintf(pfile, " : declaration statement"); }
                            ;

// Expression statements

expr_stmt                   : unary_expr_rhs_body { fprintf(pfile, " : expression statement"); }
                            | EXPR ID ASGN_OP expr_rhs_body { fprintf(pfile, " : expression statement"); }
                            ;

unary_expr_rhs_body         : UNARY_OP L_PAREN expr_term R_PAREN
                            ;

expr_rhs_body               : expr_term
                            | error
                            ;

expr_term                   : ARTH_OP L_PAREN expr_term COMMA expr_term R_PAREN
                            | ID
                            | method_call
                            | CONST
                            | NUMBER
                            | TRUE
                            | FALSE
                            | unary_expr_rhs_body
                            ;

// Function and method call statements

call_stmt                   : CALL call_stmt_body
                            ;

call_stmt_body              : method_call
                            | function_call
                            ;

method_call                 : id_or_this ARROW method_name num_args L_PAREN call_params R_PAREN { fprintf(pfile, " : call statement with object"); }
                            ;

method_name                 : id_or_this ARROW method_name
                            | ID
                            ;

id_or_this                  : ID
                            | THIS
                            | error
                            ;

function_call               : ID num_args L_PAREN call_params R_PAREN { fprintf(pfile, " : call statement"); }
                            ;

call_params                 : ID call_params_comma
                            | NUMBER call_params_comma
                            | error
                            ;

call_params_comma           : COMMA ID call_params_comma
                            | COMMA NUMBER call_params_comma
                            |
                            | error
                            ;

// Return statements

return_stmt                 : RETURN expr_term { fprintf(pfile, " : return statement"); }
                            | RETURN VOID { fprintf(pfile, " : return statement"); }
                            | error
                            ;

// Conditional blocks

cond_block                  : INCASE predicate DO { fprintf(pfile, " : conditional statment"); } block_scope OTHERWISE block_scope
                            ;

predicate                   : L_PAREN predicate_body_start R_PAREN
                            ;

predicate_body_start        : predicate_term predicate_body
                            | error
                            ;

predicate_term              : predicate
                            | unary_pred BINARY_LOGICAL_OP unary_pred
                            ;

predicate_body              : LOGICAL_JOIN_OP predicate_term predicate_body
                            |
                            | error
                            ;

unary_pred                  : UNARY_LOGICAL_OP L_PAREN unary_pred_body R_PAREN
                            | unary_pred_body
                            | error
                            ;

unary_pred_body             : expr_term
                            | predicate
                            ;

// Loop blocks

loop_block                  : loop_while_block
                            | loop_for_block
                            | error
                            ;

loop_while_block            : LOOP WHILE predicate DO { fprintf(pfile, " : loop"); } block_scope
                            ;

loop_for_block              : FOR L_PAREN expr_stmt SEMICOLON predicate SEMICOLON loop_for_update R_PAREN { fprintf(pfile, " : loop"); } block_scope
                            ;

loop_for_update             : unary_expr_rhs_body
                            |
                            | error
                            ;

%%

int main(int argc, char *argv[]) {
    // Set input filestream
    if (argv[1]) yyin = fopen(argv[1], "r");
    else yyin = stdin;
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
    // Parse the input file
    yyparse();
    return 0;
}
