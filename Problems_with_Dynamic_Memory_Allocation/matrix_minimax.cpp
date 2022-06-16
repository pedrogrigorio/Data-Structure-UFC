#include <iostream>
#include <stdlib.h>
#include <limits.h>

// The functon return the minimax element in the matrix.
// Minimax element is the smallest number in the row that in which the largest number of the matrix is.

int Minimax(int** matrix, int n, int m){
    int larger = INT_MIN;
    int row = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(matrix[i][j] > larger){
                larger = matrix[i][j];
                row = i;
            }

    int smaller = INT_MAX;
    int column = 0;

    for(int j = 0; j < m; j++)
        if(matrix[row][j] < smaller){
            smaller = matrix[row][j];
            column = j;
        }

    return matrix[row][column];
}

int main(){

    int n = 0;
    int m = 0;

    std::cout << "Matrix dimensions: ";
    std::cin >> n >> m;

    int** matrix = NULL;
    matrix = (int**) malloc(n*sizeof(int*));

    std::cout << "Enter elements in the matrix: ";
    for(int i = 0; i < n; i++){
        matrix[i] = (int*) malloc(m*sizeof(int));
        for(int j = 0; j < m; j++)
            std::cin >> matrix[i][j];
    }

    int minimax = Minimax(matrix, n, m);
    std::cout << "The minimax element is: " << minimax;
}