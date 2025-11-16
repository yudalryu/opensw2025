#!/bin/bash

factorial() {
    num=$1
    result=1

    for ((i=1; i<=num; i++))
    do
        result=$((result * i))
    done

    echo "Factorial of $1 is $result"
}

read -p "Enter a number: " NUM
factorial $NUM
