#include <stdio.h>
#define ROW1 3   
#define COL1 3   
#define ROW2 3   
#define COL2 2   
void multiplyMatrices(int mat1[][COL1], int mat2[][COL2], int result[][COL2]) {
    for (int i = 0; i < ROW1; ++i) {
        for (int j = 0; j < COL2; ++j) {
            result[i][j] = 0;
        }
    }
    for (int i = 0; i < ROW1; ++i) {
        for (int j = 0; j < COL2; ++j) {
            for (int k = 0; k < COL1; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
void displayMatrix(int matrix[][COL2]) {
    for (int i = 0; i < ROW1; ++i) {
        for (int j = 0; j < COL2; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    printf("A. Surya 192211797\n");
    int matrix1[ROW1][COL1] = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};
    int matrix2[ROW2][COL2] = {{1, 2},
                               {3, 4},
                               {5, 6}};
    int result[ROW1][COL2];
    multiplyMatrices(matrix1, matrix2, result);
    printf("Resultant Matrix:\n");
    displayMatrix(result);
    return 0;
}
