//lab -7 linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*top =NULL, *temp;

void peek()
{
    printf ("\n The top most element of the stack is %d \n", top -> data);
}

void push (int data)
{
    if(top==NULL)
    {
        top=(struct node*)malloc(sizeof(struct node));
        top->data=data;
        top->next=NULL;
    }
    else
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->next=top;
        temp->data=data;
        top=temp;
    }
    printf ("The entered number has been pushed\n");
}
int pop()
{
    temp=top;
    if(top==NULL){
        printf("Stack underflow");
        return -1;
    }
    else{
        temp=temp->next;
        int popped=top->data;
        top=temp;
        printf("%d is popped",popped);
    }
}
void display(){
    temp=top;
    if(top==NULL){
        printf("Stack underflow");
        return;
    }
    else{
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("NULL");
    }
}

int main() {
    int choice, value;
    int i=1;
    while (1) {
        printf("\n\nChoice %d\nChoose:\n1. Push\n2. Peak\n3. Pop\n4. Display\n5. Exit\n",i);
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            peek();
            break;
        case 3:
            pop();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("End.\n");
            exit(0);
            break;
       
        default:
            printf("\nChoose 1/2/3/4/5\n");
        }
        i++;
    }
}
