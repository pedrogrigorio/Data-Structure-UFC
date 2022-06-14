#include <iostream>
#include <stdlib.h>

int** MatMul(int** matrixA, int** matrixB, int n){
    // Allocate result matrix
    int** matrixC = NULL;
    matrixC = (int**) malloc(n*sizeof(int*));

    for(int i = 0; i < n; i++)
        matrixC[i] = (int*) malloc(n*sizeof(int));

    // Calculate matrix C
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            int aux = 0;
            for(int k = 0; k < n; k++)
                aux += matrixA[i][k] * matrixB[k][j];
            matrixC[i][j] = aux;
        }

    return matrixC;
}

int main(){

    int n = 0;
    std::cout << "Square matrix size: ";
    std::cin >> n;

    // Allocate and read matrix A
    int** matrixA = NULL;
    matrixA = (int**) malloc(n*sizeof(int*));

    std::cout << "Enter matrix A elements: ";
    for(int i = 0; i < n; i++){
        matrixA[i] = (int*) malloc(n*sizeof(int));
        for(int j = 0; j < n; j++)
            std::cin >> matrixA[i][j];
    }

    // Allocate and read matrix B
    int** matrixB = NULL;
    matrixB = (int**) malloc(n*sizeof(int*));

    std::cout << "Enter matrix B elements: ";
    for(int i = 0; i < n; i++){
        matrixB[i] = (int*) malloc(n*sizeof(int));
        for(int j = 0; j < n; j++)
            std::cin >> matrixB[i][j];
    }

    // Calculate matrix C (A*B)
    int** matrixC = MatMul(matrixA, matrixB, n);

    // Print matrix C
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            std::cout << matrixC[i][j] << " ";
        std::cout << "\n";
    }
}