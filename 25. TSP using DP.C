#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

int tsp(int dp[][10], int dist[][10], int mask, int pos, int n) {

    if (mask == (1 << n) - 1) {
        return dist[pos][0]; 
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int res = INF;

    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newCost = dist[pos][city] + tsp(dp, dist, mask | (1 << city), city, n);
            res = (res < newCost) ? res : newCost;
        }
    }

    return dp[mask][pos] = res;
}

int main() {
    int n;
    printf("A. Surya 192211797\n");
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    
    int dist[10][10];
    int dp[1 << 10][10]; 
    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    int minCost = tsp(dp, dist, 1, 0, n);

    printf("The minimum cost of the travelling salesman tour is %d\n", minCost);
    
    return 0;
}
