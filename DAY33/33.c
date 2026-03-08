/*
Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int priority(char x) {
    if(x == '^')
        return 3;
    if(x == '*' || x == '/')
        return 2;
    if(x == '+' || x == '-')
        return 1;
    return 0;
}

int main() {
    char exp[100];
    char *e, x;

    printf("Enter infix expression: ");
    scanf("%s", exp);

    e = exp;

    while(*e != '\0') {
        if(isalnum(*e))
            printf("%c", *e);

        else if(*e == '(')
            push(*e);

        else if(*e == ')') {
            while((x = pop()) != '(')
                printf("%c", x);
        }

        else {
            while(top != -1 && priority(stack[top]) >= priority(*e))
                printf("%c", pop());
            push(*e);
        }

        e++;
    }

    while(top != -1)
        printf("%c", pop());

    return 0;
}