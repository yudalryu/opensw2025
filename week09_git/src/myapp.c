#include <stdio.h>
#include "myops.h"

void calculate(int a, char* op, int b) {
    int result;

    if(op == '+') {
        result = myadd(a, b);
    } 
    else if(op == '-') {
        result = mysub(a, b);
    }
    else if(op == '*') {
        result = mymul(a, b);
    }
    else if(op == '/') {
        result = mydiv(a, b);
    }
    else if (op == '%') {
        result = mymod(a, b);
    }
    else if (op == '^') { result = mypow(a, b);
    }
    else {
        printf("Invalid operator.\n");
        return;
    }

    printf("Result: %d\n", result);
}

int main(void) {
    int a, b;
    char op;

    printf("Enter expression (ex: 1 + 2): ");
    scanf("%d %c %d", &a, &op, &b);

    calculate(a, op, b);

    return 0;
}
