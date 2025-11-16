#include <stdio.h>
#include "myops.h"

int calculate(int a, char op, int b) {
    int result;

    if (op == '+') result = myadd(a, b);
    else if (op == '-') result = mysub(a, b);
    else if (op == '*') result = mymul(a, b);
    else if (op == '/') result = mydiv(a, b);
    else if (op == '%') result = mymod(a, b);
    else if (op == '^') result = mypow(a, b);
    else {
        printf("Invalid operator.\n");
        return 0;
    }

    return result;
}

int main(void) {
    int a, b;
    char op;

    printf("~~~ Welcome to my calculator ~~~\n\n");
    printf("Enter expression (ex: 1 + 2): ");

    scanf(" %d %c %d", &a, &op, &b);

    printf("Result = %d\n", calculate(a, op, b));

    printf("~~~ Goodbye, See you again ~~~\n\n");

    return 0;
}
