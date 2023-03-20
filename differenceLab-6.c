/*Question 1:Write a c program to find the difference between the largest number and the smallest number in the doubly linked list.
input: 2,6,1,5,9
output:8
input:2,4,16,10,15
output:14*/

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
struct Node* insertNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}
int findDifference(struct Node* head) {
    if (head == NULL) {
        return 0;
    }
    int largest = head->data;
    int smallest = head->data;
    struct Node* current = head;
    while (current != NULL) {
        if (current->data > largest) {
            largest = current->data;
        }
        if (current->data < smallest) {
            smallest = current->data;
        }
        current = current->next;
    }
    return largest - smallest;
}
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main() {
    struct Node* head = NULL;
    int n, data;
    printf("enter the number of nodes:");
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        printf("Enter the data for node %d: ", i+1);
        scanf("%d", &data);
        head = insertNode(head, data);
    }
    int difference = findDifference(head);
    printf("Difference is: %d\n", difference);
    return 0;
}