#!/bin/bash
flex lex.l
bison parser.y -d -by -Wcounterexamples -Wother
gcc lex.yy.c y.tab.c -lfl -ly

for (( i = 1; i <= 3; i++ ))
do
    ./a.out TPP/public_test_$i.clike TP2/pt_seq_tokens_$i.txt TP2/pt_parser_$i.parsed
done