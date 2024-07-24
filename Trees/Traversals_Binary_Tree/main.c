#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

struct Node *root = NULL;

void Treecreate() {
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);
    
    printf("Enter root value: ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root -> data = x;
    root -> lchild = root -> rchild = NULL;
    enqueue(&q, root);
    
    while(!isEmpty(q)) {
        p = dequeue(&q);
        printf("Enter left child of %d: ", p -> data);
        scanf("%d", &x);
        if(x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t -> data = x;
            t -> lchild = t -> rchild = NULL;
            p -> lchild = t;
            enqueue(&q, t);
        }
        printf("Enter right child of %d: ", p -> data);
        scanf("%d", &x);
        if(x != -1) {
            t = (struct Node *)malloc(sizeof(struct Node));
            t -> data = x;
            t -> lchild = t -> rchild = NULL;
            p -> rchild = t;
            enqueue(&q, t);
        }
    } 
}

void Preorder(struct Node *p) {
    if(p) {
        printf("%d ", p -> data);
        Preorder(p -> lchild);
        Preorder(p -> rchild);
    }
}

void Inorder(struct Node *p) {
    if(p) {
        Inorder(p -> lchild);
        printf("%d ", p -> data);
        Inorder(p -> rchild);
    }
}

void Postorder(struct Node *p) {
    if(p) {
        Postorder(p -> lchild);
        Postorder(p -> rchild);
        printf("%d ", p -> data);
    }
}

void IPreorder(struct Node *p) {
    struct Stack stk;
    Stackcreate(&stk, 100);
    
    while(p || !isEmptyStack(stk)) {
        if(p) {
            printf("%d ", p -> data);
            push(&stk, p);
            p = p -> lchild;
        } else {
            p = pop(&stk);
            p = p -> rchild;
        }
    }
}

void IInorder(struct Node *p) {
    struct Stack stk;
    Stackcreate(&stk, 100);
    
    while(p || !isEmptyStack(stk)) {
        if(p) {
            push(&stk, p);
            p = p -> lchild;
        } else {
            p = pop(&stk);
            printf("%d ", p -> data);
            p = p -> rchild;
        }
    }
}

void IPostorder(struct Node *p) {
    struct Stack stk;
    Stackcreate(&stk, 100);
    long int temp;
    
    while(p || !isEmptyStack(stk)) {
        if(p) {
            push(&stk, p);
            p = p -> lchild;
        } else {
            temp = (long int)pop(&stk);
            if(temp > 0) {
                push(&stk, (struct Node *)((-1) * temp));
                p = ((struct Node *)temp) -> rchild;
            } else {
                printf("%d ", ((struct Node *)-temp) -> data);
                p = NULL;
            }
        }
    }
}

int main() {
	Treecreate();
    
    printf("\nPost Order ");
    IPostorder(root);
    
	return 0;
}