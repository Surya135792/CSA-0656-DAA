#include <stdio.h>
#include <string.h>
#include <ctype.h>
int isPalindrome(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;
    while (left < right) {
        while (!isalnum(str[left]) && left < right)
            left++;
        while (!isalnum(str[right]) && left < right)
            right--;
        if (tolower(str[left]) != tolower(str[right]))
            return 0; 
        left++;
        right--;
    }
    return 1; 
}
int main() {
    char name[] = "A. Surya";
    char regno[] = "192211797";
    printf("Name : %s\n", name);
    printf("Regno : %s\n\n", regno);
    char str[100];
    printf("Enter a string to check if it is a palindrome: ");
    fgets(str, sizeof(str), stdin);
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
    if (isPalindrome(str)) {
        printf("\n'%s' is a palindrome.\n", str);
    } else {
        printf("\n'%s' is not a palindrome.\n", str);
    }
    return 0;
}
