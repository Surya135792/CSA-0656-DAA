#include <stdio.h>
#include <limits.h>

// Function to find the optimal binary search tree
void optimalBST(int keys[], int freq[], int n) {
    int cost[n][n];
    int sumFreq[n][n];

    // Initialize cost and sumFreq matrices
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
        sumFreq[i][i] = freq[i];
    }

    // Fill the cost and sumFreq matrices
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            cost[i][j] = INT_MAX;
            sumFreq[i][j] = sumFreq[i][j - 1] + freq[j];

            // Try making each key in interval keys[i..j] as root
            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) + ((r < j) ? cost[r + 1][j] : 0) + sumFreq[i][j];
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                }
            }
        }
    }
    printf("A. Surya 192211797\n");
    printf("Cost of the Optimal BST is %d\n", cost[0][n - 1]);
}

int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);

    optimalBST(keys, freq, n);

    return 0;
}
