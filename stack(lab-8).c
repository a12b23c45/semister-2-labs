#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
#define MAX_STACK_SIZE 100

typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;


void push(Stack* stack, int val) {
    if (stack->top == MAX_STACK_SIZE - 1) {
        printf("Error: stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->data[++stack->top] = val;
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Error: stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}


int evaluate_prefix(char* expr) {
    Stack stack = { .top = -1 };
    int i = strlen(expr) - 1;

    while (i >= 0) {
        
        if (isdigit(expr[i])) {
            push(&stack, expr[i] - '0');
        }
        
        else {
            int op1 = pop(&stack);
            int op2 = pop(&stack);
            switch (expr[i]) {
                case '+':
                    push(&stack, op1 + op2);
                    break;
                case '-':
                    push(&stack, op1 - op2);
                    break;
                case '*':
                    push(&stack, op1 * op2);
                    break;
                case '/':
                    push(&stack, op1 / op2);
                    break;
                case '%':
                    push(&stack, op1 % op2);
                    break;
                default:
                    
            }
        }
        i--;
    }
    return pop(&stack);
}

int main() {
    char expr[] = "+9*26 ";
    int result = evaluate_prefix(expr);
    printf("%s = %d\n", expr, result);
return 0;
}
/*Write c program to evaluate prefix expression.

Example:

+9*26

Ans: 21

-+8/632

Ans: 8*/