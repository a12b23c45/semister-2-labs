// prime number in circular list lab6-qs3
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
int isPrime(int num) {
    int i;
    if (num <= 1) {
        return 0;
    }
    for (i = 2; i <= num/2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, i, data;
    scanf("%d", &n);
    struct Node* head = NULL;
    struct Node* tail = NULL;
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    struct Node* currentNode = head;
    while (currentNode != NULL) {
        if (isPrime(currentNode->data)) {
            printf("%d", currentNode->data);
        }
        currentNode = currentNode->next;
    }
    printf("\n");
    return 0;
}