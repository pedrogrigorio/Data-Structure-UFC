#include <iostream>
#include <stdlib.h>
#include <limits.h>

//Function print out the max and min values in the array
void vectorMinMax(int* vector, int n){
    int smaller = INT_MAX;
    int larger = INT_MIN;

    for(int i = 0; i < n; i++){
        if(vector[i] < smaller)
            smaller = vector[i];
        
        if(vector[i] > larger)
            larger = vector[i];
    }
    std::cout << "min: " << smaller << " max: " << larger;
}

int main(){
    
    int n = 0;
    std::cout << "Array size: ";
    std::cin >> n;
    
    int* vector = NULL;
    vector = (int*) malloc(sizeof(int)*n);
    
    std::cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        std::cin >> vector[i];

    vectorMinMax(vector, n);
}