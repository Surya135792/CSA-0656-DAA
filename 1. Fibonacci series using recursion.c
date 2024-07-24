#include <stdio.h>

void printFibonacci(int n) {
    int first = 0, second = 1, next, i;
    if (n >= 1) {
        printf("%d ", first);
    }
    if (n >= 2) {
        printf("%d ", second);
    }

    for (i = 3; i <= n; i++) {
        next = first + second;
        printf("%d ", next);
        first = second;
        second = next;
    }
    printf("\n");
}

int main() {
    int terms;
    printf("A. Surya 192211797\n");

    printf("Enter the number of terms for Fibonacci series: ");
    scanf("%d", &terms);
    if (terms <= 0) {
        printf("Number of terms must be a positive integer.\n");
    } else {
        printFibonacci(terms);
    }

    return 0;
}

