#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

char stack[MAX_STACK_SIZE];
int top = -1;

void push(char c) {
    if (top >= MAX_STACK_SIZE - 1) {
        printf("Error: Stack overflow\n");
        exit(1);
    }
    stack[++top] = c;
}

char pop() {
    if (top < 0) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

void removeDuplicates(char* str) {
    int i, len;
    len = strlen(str);
    for (i = 0; i < len; i++) {
        if (top == -1 || str[i] != stack[top]) {
            push(str[i]);
        }
        else {
            pop();
        }
    }
    stack[top+1] = '\0';
    strcpy(str, stack);
}

int main() {
    char str[MAX_STACK_SIZE];
    printf("Enter a string: ");
    gets(str);
    removeDuplicates(str);
    printf("String after removing duplicate adjacent characters: %s\n", str);
 return 0;
}
/*removing duplicte from stack*/
