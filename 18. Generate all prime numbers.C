#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Function to generate all prime numbers up to a given limit
void sieveOfEratosthenes(int limit) {
    bool isPrime[limit + 1];

    // Initialize all entries to true
    for (int i = 0; i <= limit; i++) {
        isPrime[i] = true;
    }

    // Set 0 and 1 to not prime
    isPrime[0] = isPrime[1] = false;

    // Sieve of Eratosthenes algorithm
    for (int p = 2; p <= sqrt(limit); p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
    }

  
    printf("Prime numbers up to %d are:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int limit;
      printf("A. Surya 192211797\n");

    printf("Enter the limit up to which you want to generate prime numbers: ");
    scanf("%d", &limit);

    sieveOfEratosthenes(limit);

    return 0;
}
