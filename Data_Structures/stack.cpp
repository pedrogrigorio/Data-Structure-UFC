#include <iostream>
#include <stdlib.h>

struct NODE_{
    double data;
    struct NODE_ *next;
    struct NODE_ *prev;
};

typedef struct NODE_ NODE;

NODE* createStack(NODE *head){
    head = (NODE*) malloc(sizeof(NODE));
    if(head != NULL){
        head->data = 0;
        head->next = head;
        head->prev = head;

        return head;
    }
    else 
        return NULL;
}

int push(NODE *head, int x){
    NODE *newNode = (NODE*) malloc(sizeof(NODE));
    if(newNode != NULL){
        newNode->data = x;
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;

        return 1;
    }
    else 
        return 0;
}

void pop(NODE *head){
    if(head->prev == head)
        std::cout << "Stack is empty!\n";
    else{
        NODE *p = head->prev;
        p->prev->next = head;
        head->prev = p->prev;
        free(p);
    }
}

void top(NODE *head){
    NODE *p = head->prev;
    if(p == head)
        std::cout << "Stack is empty!\n";
    else
        std::cout << "Stack top is " << p->data << "\n";
}


int main(){

    NODE *stack = createStack(stack);
    
    int n = 0;
    std::cout << "Enter elements (enter -1 to finish): ";
    std::cin >> n;
    
    while(n != -1){
        push(stack, n);
        std::cin >> n;
    }
    top(stack);

    std::cout << "Enter any number to unstack elements (enter -1 to finish): ";
    std::cin >> n;
    while(n != -1){
        pop(stack);
        top(stack);
        std::cin >> n;
    }
}