#include <stdio.h>
#include <string.h>

int main() {
    char str[20];
    char choice;

    // List of C keywords
    char keywords[][20] = {
        "auto", "break", "case", "char", "const", "continue",
        "default", "do", "double", "else", "enum", "extern",
        "float", "for", "goto", "if", "int", "long",
        "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned",
        "void", "volatile", "while"
    };

    int i, found, n = sizeof(keywords) / sizeof(keywords[0]);

    do {
        found = 0;   // Reset for each iteration

        printf("Enter a word: ");
        scanf("%s", str);

        for (i = 0; i < n; i++) {
            if (strcmp(str, keywords[i]) == 0) {
                found = 1;
                break;
            }
        }

        if (found)
            printf("'%s' is a C Keyword.\n", str);
        else
            printf("'%s' is NOT a C Keyword.\n", str);

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}