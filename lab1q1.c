//Write a C/C++ program to identify whether input line is comment or not.
#include <stdio.h>
#include <string.h>

int main() {
    char line[200];
    char choice;

    do {
        printf("Enter a line: ");
        fgets(line, sizeof(line), stdin);

        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        int len = strlen(line);

        if (len >= 2) {
            if (line[0] == '/' && line[1] == '/') {
                printf("It is a single-line comment.\n");
            }
            else if (line[0] == '/' && line[1] == '*' &&
                     line[len - 2] == '*' && line[len - 1] == '/') {
                printf("It is a multi-line comment.\n");
            }
            else {
                printf("It is not a comment.\n");
            }
        }
        else {
            printf("It is not a comment.\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &choice);
        getchar();   // Clear the newline left by scanf()

    } while (choice == 'y' || choice == 'Y');

    return 0;
}





























       