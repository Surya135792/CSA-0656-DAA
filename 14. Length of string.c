#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    printf("A. Surya 192211797\n");
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    int length = strlen(str);
    printf("The length of the string is: %d\n", length);
    return 0;
}
