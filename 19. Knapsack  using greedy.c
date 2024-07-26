#include <stdio.h>

// Structure to represent an item with weight and value
typedef struct {
    int weight;
    int value;
} Item;

// Function to swap two items
void swap(Item* a, Item* b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort items based on value-to-weight ratio in descending order
void sortItems(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            double r1 = (double)items[j].value / items[j].weight;
            double r2 = (double)items[j + 1].value / items[j + 1].weight;
            if (r1 < r2) {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}

// Function to calculate the maximum value in the knapsack
double fractionalKnapsack(Item items[], int n, int capacity) {
    sortItems(items, n);
    
    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    int n, capacity;
    
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    Item items[n];
    
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d (weight value): ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    
    double maxValue = fractionalKnapsack(items, n, capacity);
    
    printf("Maximum value in the knapsack = %.2f\n", maxValue);
    
    return 0;
}
