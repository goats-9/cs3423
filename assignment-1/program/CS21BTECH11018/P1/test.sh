#!/bin/bash

# Number of testcases
N=8

# Name of file
LEXFILE=lex.l

# Name of C file
LEXCFILE=lex.yy.c

# Lex the source
lex $LEXFILE

# Compile the C file
gcc -Wall -g -O2 -lfl $LEXCFILE

for (( i = 1; i <= $N; i++ ))
do
    ./a.out T1/$i.txt TK/seq_tokens_$i.txt TC/C_$i.txt
done