#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char id[100], choice;
    int i, valid, found;

    // List of C keywords
    char keywords[][20] = {
        "auto", "break", "case", "char", "const", "continue",
        "default", "do", "double", "else", "enum", "extern",
        "float", "for", "goto", "if", "int", "long",
        "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned",
        "void", "volatile", "while"
    };

    int n = sizeof(keywords) / sizeof(keywords[0]);

    do {
        valid = 1;
        found = 0;

        printf("Enter an identifier: ");
        scanf("%99s", id);

        // Check if it is a keyword
        for (i = 0; i < n; i++) {
            if (strcmp(id, keywords[i]) == 0) {
                found = 1;
                valid = 0;
                break;
            }
        }

        // Check first character
        if (!(isalpha(id[0]) || id[0] == '_')) {
            valid = 0;
        }

        // Check remaining characters
        for (i = 1; id[i] != '\0'; i++) {
            if (!(isalnum(id[i]) || id[i] == '_')) {
                valid = 0;
                break;
            }
        }

        if (valid)
            printf("'%s' is a Valid Identifier.\n", id);
        else
            printf("'%s' is an Invalid Identifier.\n", id);

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}