#include <stdio.h>

int reverseNumber(int num) {
    int reversed = 0;
    
    while (num != 0) {
        int digit = num % 10;    
        reversed = reversed * 10 + digit; 
        num = num / 10; 
    }
    
    return reversed;
}

int main() {
    int number;
     printf("A. Surya 192211797\n");
    printf("Enter a number: ");
   
    scanf("%d", &number);

    int reversedNumber = reverseNumber(number);

    printf("The reverse of %d is %d\n", number, reversedNumber);
    
    return 0;
}
