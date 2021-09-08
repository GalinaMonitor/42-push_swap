#!/bin/bash

STR_3=`ruby -e "puts (1..3).to_a.shuffle.join(' ')"`
STR_5=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`
STR_100=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
STR_500=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`
STR_1000=`ruby -e "puts (1..1000).to_a.shuffle.join(' ')"`

WRONG_INPUT1="2147483648"
WRONG_INPUT2="-2147483649"
WRONG_INPUT3="kek"

echo "Test using checker"

./push_swap $STR_3 | ./checker_MAC $STR_3
./push_swap $STR_5 | ./checker_MAC $STR_5
./push_swap $STR_100 | ./checker_MAC $STR_100
./push_swap $STR_500 | ./checker_MAC $STR_500
./push_swap $STR_1000 | ./checker_MAC $STR_1000

echo "Test amount of operations"

echo "str_3"
./push_swap $STR_3 | wc -l

echo "str_5"
./push_swap $STR_5 | wc -l

echo "str_100"
./push_swap $STR_100 | wc -l

echo "str_500"
./push_swap $STR_500 | wc -l

echo "str_1000"
./push_swap $STR_1000 | wc -l

echo -e "\nTest wrong input"

echo -e "\nArg = $WRONG_INPUT1"
./push_swap $WRONG_INPUT1

echo -e "\nArg = $WRONG_INPUT2"
./push_swap $WRONG_INPUT2

echo -e "\nArg = $WRONG_INPUT3"
./push_swap $WRONG_INPUT3

echo -e "\n\nZero args"
./push_swap
