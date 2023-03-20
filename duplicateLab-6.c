//duplicate removing in linked list lab-6 question -2
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void addNode(Node** head, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
}

void removeDuplicates(Node* head) {
    if (head == NULL) {
        return;
    }

    Node* curr = head;
    while (curr != NULL) {
        Node* prev = curr;
        Node* temp = curr->next;

        while (temp != NULL) {
            if (temp->data == curr->data) {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int n, val;
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        addNode(&head, val);
    }


    removeDuplicates(head);

    printList(head);

    return 0;
}