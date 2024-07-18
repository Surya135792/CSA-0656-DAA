#include <stdio.h>
int fibonacci(int n) {
    if (n <= 0) return 0; 
    if (n == 1) return 1;   
    return fibonacci(n - 1) + fibonacci(n - 2);
}
void print_fibonacci_series(int n) {
    printf("Fibonacci Series:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}
int main() {
    printf("Name: A. Surya\n");
    printf("Regno: 192211797\n");
    int num_terms = 10; 
    print_fibonacci_series(num_terms);
    return 0;
}
