#include <stdio.h>
#include <math.h>
int isArmstrong(int num) {
    int originalNum, remainder, result = 0, n = 0;

    originalNum = num;
    while (originalNum != 0) {
        originalNum /= 10;
        ++n;
    }

    originalNum = num;
    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += pow(remainder, n);
        originalNum /= 10;
    }
    return (result == num);
}
void findArmstrongNumbers(int start, int end) {
    int i;

    printf("Armstrong numbers between %d and %d are:\n", start, end);
    for (i = start; i <= end; i++) {
        if (isArmstrong(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int num, start, end;
    printf("Enter a number to check if it's an Armstrong number: ");
    scanf("%d", &num);

    if (isArmstrong(num)) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }
    printf("Enter the range (start and end) to find Armstrong numbers:\n");
    scanf("%d %d", &start, &end);

    findArmstrongNumbers(start, end);

    return 0;
}
