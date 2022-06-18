#include <iostream>
#include <stdlib.h>

struct NODE_{
    double data;
    struct NODE_ *next;
};

typedef struct NODE_ NODE;

NODE* createList(NODE *head){
    head = (NODE*) malloc(sizeof(NODE));
    if(head != NULL){
        head->data = 0;
        head->next = NULL;

        return head;
    }
    else 
        return 0;
}

int addList(NODE *head, double x){
    NODE *newNode = (NODE*) malloc(sizeof(NODE));

    if(newNode != NULL){
        newNode->data = x;
        newNode->next = head->next;
        head->next = newNode;

        return 1;
    }
    else return 0;
}

NODE* searchList(NODE* head, double x){
    NODE *p = head;
    while(p->next != NULL and p->next->data != x)
        p = p->next;
    if(p->next != NULL) 
        return p;
    else 
        return NULL;
}

int removeList(NODE* head, double x){
    NODE *ant = searchList(head, x);
    if(ant != NULL){
        NODE *aux = ant->next;
        ant->next = ant->next->next;
        free(aux);

        return 1;
    }
    else 
        return 0;
}

void printList(NODE* head){
    NODE *p = head->next;
    if(p == NULL){
        std::cout << "Empty";
    }
    while(p != NULL){
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << "\n";
}


int main(){

    NODE *list = createList(list);

    double n = 0;
    std::cout << "Enter elements (enter -1 to finish): ";
    std::cin >> n;

    while(n != -1){
        addList(list, n);
        std::cin >> n;
    }

    printList(list);

    double x = 0;
    std::cout << "Enter elements to remove (enter -1 to finish): ";
    std::cin >> x;

    while(x != -1){
        removeList(list, x);
        std::cin >> x;
    }

    printList(list);
}