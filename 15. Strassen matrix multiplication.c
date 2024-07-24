#include <stdio.h>
#include <stdlib.h>

void add(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int n, int A[n][n], int B[n][n], int C[n][n]) {
    if (n == 2) {
        int M1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
        int M2 = (A[1][0] + A[1][1]) * B[0][0];
        int M3 = A[0][0] * (B[0][1] - B[1][1]);
        int M4 = A[1][1] * (B[1][0] - B[0][0]);
        int M5 = (A[0][0] + A[0][1]) * B[1][1];
        int M6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
        int M7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

        C[0][0] = M1 + M4 - M5 + M7;
        C[0][1] = M3 + M5;
        C[1][0] = M2 + M4;
        C[1][1] = M1 - M2 + M3 + M6;
    } else {

        int newSize = n / 2;
        int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
        int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
        int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
        int M1[newSize][newSize], M2[newSize][newSize], M3[newSize][newSize], M4[newSize][newSize];
        int M5[newSize][newSize], M6[newSize][newSize], M7[newSize][newSize];
        int AResult[newSize][newSize], BResult[newSize][newSize];

        for (int i = 0; i < newSize; i++) {
            for (int j = 0; j < newSize; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + newSize];
                A21[i][j] = A[i + newSize][j];
                A22[i][j] = A[i + newSize][j + newSize];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + newSize];
                B21[i][j] = B[i + newSize][j];
                B22[i][j] = B[i + newSize][j + newSize];
            }
        }

        add(newSize, A11, A22, AResult); // A11 + A22
        add(newSize, B11, B22, BResult); // B11 + B22
        strassen(newSize, AResult, BResult, M1); // M1 = (A11 + A22) * (B11 + B22)

        add(newSize, A21, A22, AResult); // A21 + A22
        strassen(newSize, AResult, B11, M2); // M2 = (A21 + A22) * B11

        subtract(newSize, B12, B22, BResult); // B12 - B22
        strassen(newSize, A11, BResult, M3); // M3 = A11 * (B12 - B22)

        subtract(newSize, B21, B11, BResult); // B21 - B11
        strassen(newSize, A22, BResult, M4); // M4 = A22 * (B21 - B11)

        add(newSize, A11, A12, AResult); // A11 + A12
        strassen(newSize, AResult, B22, M5); // M5 = (A11 + A12) * B22

        subtract(newSize, A21, A11, AResult); // A21 - A11
        add(newSize, B11, B12, BResult); // B11 + B12
        strassen(newSize, AResult, BResult, M6); // M6 = (A21 - A11) * (B11 + B12)

        subtract(newSize, A12, A22, AResult); // A12 - A22
        add(newSize, B21, B22, BResult); // B21 + B22
        strassen(newSize, AResult, BResult, M7); // M7 = (A12 - A22) * (B21 + B22)

        add(newSize, M1, M4, AResult); // M1 + M4
        subtract(newSize, AResult, M5, BResult); // M1 + M4 - M5
        add(newSize, BResult, M7, C11); // C11 = M1 + M4 - M5 + M7

        add(newSize, M3, M5, C12); // C12 = M3 + M5

        add(newSize, M2, M4, C21); // C21 = M2 + M4

        add(newSize, M1, M3, AResult); // M1 + M3
        subtract(newSize, AResult, M2, BResult); // M1 + M3 - M2
        add(newSize, BResult, M6, C22); // C22 = M1 + M3 - M2 + M6

        for (int i = 0; i < newSize; i++) {
            for (int j = 0; j < newSize; j++) {
                C[i][j] = C11[i][j];
                C[i][j + newSize] = C12[i][j];
                C[i + newSize][j] = C21[i][j];
                C[i + newSize][j + newSize] = C22[i][j];
            }
        }
    }
}

int main() {
    int n;
    printf("A. Surya 192211797\n");
    printf("Enter the size of the matrix (must be a power of 2): ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];

    // Input matrices A and B
    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);
    strassen(n, A, B, C);

    printf("Result matrix C:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
