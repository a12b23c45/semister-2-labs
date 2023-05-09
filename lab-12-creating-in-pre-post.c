// inorder post order preorder
#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data)
{
    struct Node* Node = (struct Node*)malloc(sizeof(struct Node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
};

struct Node* insert (struct Node* t,int data){
    if(t==NULL){
        return newNode(data);
        } else if (data<=t->data)
        {
            t->left=insert(t->left,data);
        }else
        { t->right=insert(t->right,data);
} return t;
}

void Inorder(struct Node* t){
    if(t!=NULL)
    {
        Inorder(t->left);
        printf(" %d",t->data);
        Inorder(t->right);
    }
}

void preorder(struct Node* t){
    if(t!=NULL){
        printf(" %d",t->data);
        preorder(t->left);
        preorder(t->right);
    }
}

void postorder(struct Node * t ){
    if(t!=NULL){
        postorder(t->left);
        postorder(t->right);
        printf(" %d",t->data);
    }
}

int main(){
    struct Node *t=NULL;
    int n;
    printf("n=");
    scanf("%d",&n);
    printf("enter %d elements:\n",n);
    for(int i=0;i<n;i++){
        int data;
        scanf("%d",&data);
        t=insert(t,data);
    }
    printf("Inorder: ");
    Inorder(t);
    printf("\n");

    printf("Preorder: ");
    preorder(t);
    printf("\n");

    printf("Postorder: ");
    postorder(t);
    printf("\n");

    return 0;
}
