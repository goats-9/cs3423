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
    #define YYSTYPE char *   /* string type for Yacc stack */
%}

// Token definitions for use in grammar productions

%token ID
%token KEYWORD
%token DTYPE
%token CONST
%token NUMBER
%token UNARY_OP
%token ARTH_OP
%token UNARY_LOGICAL_OP
%token BINARY_LOGICAL_OP
%token LOGICAL_JOIN_OP

%%

// Program productions

program                     : program_body
                            | error
                            ;
program_body                : 'global' function
                            | 'global' class
                            | program_body
                            | error
                            ;

// Function and class prototypes

function                    : function_definition block_scope
                            | error
                            ;

function_definition         : 'function' DTYPE ID num_args '(' args ')'
                            | error
                            ;

class                       : class_definition block_scope
                            | error
                            ;

class_definition            : 'class' ID num_args
                            | error
                            ;

block_scope                 : '{' blocks '}'
                            | error
                            ;

// Argument declarations

args                        : DTYPE ID args_comma
                            | error
                            ;

args_comma                  : ',' DTYPE ID args_comma
                            |
                            | error
                            ;

num_args                    : '[' NUMBER ']'
                            | error
                            ;

// Block statements and simple statements

blocks                      : block blocks
                            |
                            | error
                            ;

block                       : stmt
                            | cond_block
                            | loop_block
                            | error
                            ;

stmt                        : stmt_body ';'
                            | error
                            ;

stmt_body                   : decl_stmt
                            | expr_stmt
                            | call_stmt
                            | return_stmt
                            | error
                            ;

// Declaration statements

decl_stmt                   : 'declare' DTYPE ID
                            | error
                            ;

// Expression statements

expr_stmt                   : unary_expr_rhs_body
                            | expr_body
                            | error
                            ;

unary_expr_rhs_body         : UNARY_OP '(' expr_term ')'
                            | error
                            ;

expr_body                   : 'expr' ID '=' expr_rhs_body
                            | error
                            ;

expr_rhs_body               : unary_expr_rhs_body
                            | expr_term
                            | error
                            ;

expr_term                   : ARTH_OP '(' expr_term ',' expr_term ')'
                            | ID
                            | method_call
                            | CONST
                            | 'true'
                            | 'false'
                            | unary_expr_rhs_body
                            | error
                            ;

// Function and method call statements
call_stmt                   : 'call' method_call
                            | error
                            ;

method_call                 : method_name num_args '(' method_params ')'
                            | error
                            ;

method_name                 : ID '->' method_name
                            | ID
                            | error
                            ;

method_params               : DTYPE ID method_params_comma
                            |
                            | error
                            ;

method_params_comma         : ',' DTYPE ID method_params_comma
                            |
                            | error
                            ;

// Return statements

return_stmt                 : 'return' expr_term
                            | error
                            ;

// Conditional blocks

cond_block                  : 'in case that' predicate 'do' block_scope
                            ;

predicate                   : '(' predicate_body_start ')'
                            | error
                            ;

predicate_body_start        : predicate_term predicate_body
                            | error
                            ;

predicate_term              : predicate
                            | unary_pred BINARY_LOGICAL_OP unary_pred
                            | error
                            ;

predicate_body              : LOGICAL_JOIN_OP predicate_term predicate_body
                            | error
                            ;

unary_pred                  : UNARY_LOGICAL_OP unary_pred_body
                            | error
                            ;

unary_pred_body             : expr_term
                            | predicate
                            | error
                            ;

// Loop blocks

loop_block                  : loop_while_block
                            | loop_for_block
                            | error
                            ;

loop_while_block            : 'loop' 'while' predicate 'do' block_scope
                            ;

%%