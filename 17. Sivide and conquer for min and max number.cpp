#include <stdio.h>
#include <limits.h>

// Structure to hold the result
typedef struct {
    int min;
    int max;
} MinMax;

// Function to find the minimum and maximum values using Divide and Conquer
MinMax findMinMax(int arr[], int low, int high) {
    MinMax result, leftResult, rightResult;
    
    // If there's only one element
    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }
    
    // If there are two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    int mid = (low + high) / 2;
    leftResult = findMinMax(arr, low, mid);
    rightResult = findMinMax(arr, mid + 1, high);

    result.min = (leftResult.min < rightResult.min) ? leftResult.min : rightResult.min;
    result.max = (leftResult.max > rightResult.max) ? leftResult.max : rightResult.max;
    
    return result;
}

int main() {
    int arr[] = {100, 11, 445, 1, 330, 3000};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    MinMax result = findMinMax(arr, 0, size - 1);
    
    printf("Minimum element is %d\n", result.min);
    printf("Maximum element is %d\n", result.max);
    
    return 0;
}
