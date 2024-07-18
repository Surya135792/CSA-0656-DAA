#include <stdio.h>
int findLargest(int arr[], int size) {
    int max = arr[0]; // Assume the first element is the largest

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int largest = findLargest(arr, n);

    // Output the largest element
    printf("The largest element in the array is: %d\n", largest);

    return 0;
}
