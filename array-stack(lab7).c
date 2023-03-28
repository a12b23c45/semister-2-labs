 //lab 7 qs 1 in array form liked list second next upload
 
 
 #include <stdio.h>
 #include <stdlib.h>
 #define MAX 100
 int stack_arr[MAX];
 int top = -1;
 int isFull();
 int isEmpty();
 void push(int X)
 {
   if (isFull())
   {
       printf ("\n Stack Overflow \n");
       return;
   }
   top = top + 1;
   stack_arr[top] = X;
 }
 int pop()
 {
     int X;
     if (isEmpty())
     {
         printf ("\n Stack Undeflow \n");
         exit(1);
     }
     top  = top -1;
 }
 int peek()
 {
     if (top == -1)
     {
         printf ("\n Stack Underflow \n");
     }
     printf ("\n %d is the peek value from the stack \n", stack_arr[top]);
 }
 void display()
 {
     if (top == -1) {
        printf("Stack is empty\n");
    }
    printf("Stack elements are: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack_arr[i]);
    }
    printf("\n");
 }
 int isEmpty()
 {
     if (top == -1)
     {
         return 1;
     }
     else
     {
     return 0;    
     }
 }
 int isFull()
 {
     if (top == MAX -1)
     {
         return 1;
     }
     else
     {
         return 0;
     }
 }
 
 int main()
 {
     int choice, X;
     while (1)
     {
         printf ("\n 1. Push \n");
         printf ("\n 2. Pop \n");
         printf ("\n 3. Display the top element \n");
         printf ("\n 4. Display the stack elements \n");
         printf ("\n 5. Quit \n");
         printf ("\nEnter your choice");
         scanf ("%d", &choice);
         
         switch(choice)
         {
             case 1:
             printf ("\n Enter the number to be pushed\n ");
             scanf ("%d", &X);
             push (X);
             break;
             case 2:
             X = pop();
             printf ("\n Popped number: %d \n ", X);
             break;
             case 3:
             printf ("\n The number at the top is %d \n", peek());
             break;
             case 4:
             display();
             break;
             case 5:
             exit(1);
             default:
             printf ("\n Wrong Choice \n");
         }
     }
     
     return 0;
 }

