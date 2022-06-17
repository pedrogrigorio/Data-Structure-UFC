#include <iostream>
#include <stdlib.h>

//Function alloc memory for the list
double* createList(int n){
    return (double *) malloc(n*sizeof(double));
}

void deallocateList(double* L){
    free(L);
}

//Add element in a list
int addList(double* L, int* cardinality, int size, double x){
    if(*cardinality == size)
        return 0;
    else{
        L[*cardinality] = x;
        (*cardinality)++;
        return 1;
    }
}

//
int searchList(double *L, int cardinality, double x){
    for(int i = 0; i < cardinality; i++)
        if(L[i] == x) return i;
        return -1;
}

int removeList(double *L, int *cardinality, double x){
    int i = searchList(L,*cardinality,x);
    if(i>-1){
        (*cardinality)--;
        L[i] = L[*cardinality];
    }
    return i;
}

void printList(double *L, int cardinality){
    for(int i = 0; i < cardinality; i++)
        std::cout << L[i] << " ";
    std::cout << "\n";
}

int main(){

    int size=0, cardinality=0;
    std::cout << "Enter list size: ";
    std::cin >> size;
   
    double *list = NULL;
    list = createList(size);

    double n = 0;
    std::cout << "Enter elements (fill the list or enter -1 to finish): ";
    std::cin >> n;

    int i = 0;
    while(n != -1 and i < size){
        addList(list, &cardinality, size, n);
        std::cin >> n;
        i++;
    }

    printList(list, cardinality);

    int x = 0;
    std::cout << "Search element: ";
    std::cin >> x;
    int index = searchList(list, cardinality, x);
    std::cout << "Index of " << x << ": " << index << "\n";

    std::cout << "Remove element: ";
    std::cin >> x;
    removeList(list, &cardinality, x);

    printList(list, cardinality);
    deallocateList(list);
}