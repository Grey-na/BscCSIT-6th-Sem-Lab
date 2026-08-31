// Write a C program to implement design of lexical analyser
// to recognize tokens: identifier, keyword, operator,
// constant and special symbol.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    printf("Enter source code line by line.\n");
    printf("Press Enter on a blank line to finish.\n");

    FILE *outFile = fopen("input.txt", "w");

    if (outFile == NULL)
    {
        printf("Unable to create input.txt\n");
        return 0;
    }

    char line[500];

    while (1)
    {
        fgets(line, sizeof(line), stdin);

        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        if (strlen(line) == 0)
            break;

        fprintf(outFile, "%s\n", line);
    }

    fclose(outFile);

    FILE *file = fopen("input.txt", "r");

    if (file == NULL)
    {
        printf("Unable to open input.txt for reading.\n");
        return 0;
    }

    // Arrays to store tokens
    char keywords[100][50];
    char identifiers[100][50];
    char constants[100][50];
    char operators[100][10];
    char specialSymbols[100][10];

    int k = 0, id = 0, c = 0, op = 0, sp = 0;

    // List of keywords
    char key[10][20] = {
        "int", "float", "char", "double",
        "if", "else", "for", "while",
        "return", "void"
    };

    char sourceCode[5000] = "";
    char ch;
    int length = 0;

    // Read complete source code
    while ((ch = fgetc(file)) != EOF)
    {
        sourceCode[length++] = ch;
    }

    sourceCode[length] = '\0';

    fclose(file);

    int i = 0;

    while (i < length)
    {
        ch = sourceCode[i];

        // Identifier or keyword
        if (isalpha(ch))
        {
            char word[100];
            int w = 0;

            while (i < length && isalnum(sourceCode[i]))
            {
                word[w++] = sourceCode[i];
                i++;
            }

            word[w] = '\0';

            int found = 0;

            // Check whether word is a keyword
            for (int j = 0; j < 10; j++)
            {
                if (strcmp(word, key[j]) == 0)
                {
                    found = 1;
                    break;
                }
            }

            if (found)
            {
                int alreadyExists = 0;

                for (int j = 0; j < k; j++)
                {
                    if (strcmp(keywords[j], word) == 0)
                    {
                        alreadyExists = 1;
                        break;
                    }
                }

                if (!alreadyExists)
                {
                    strcpy(keywords[k], word);
                    k++;
                }
            }
            else
            {
                int alreadyExists = 0;

                for (int j = 0; j < id; j++)
                {
                    if (strcmp(identifiers[j], word) == 0)
                    {
                        alreadyExists = 1;
                        break;
                    }
                }

                if (!alreadyExists)
                {
                    strcpy(identifiers[id], word);
                    id++;
                }
            }
        }

        // Constant
        else if (isdigit(ch))
        {
            char word[100];
            int w = 0;

            while (i < length && isdigit(sourceCode[i]))
            {
                word[w++] = sourceCode[i];
                i++;
            }

            word[w] = '\0';

            int alreadyExists = 0;

            for (int j = 0; j < c; j++)
            {
                if (strcmp(constants[j], word) == 0)
                {
                    alreadyExists = 1;
                    break;
                }
            }

            if (!alreadyExists)
            {
                strcpy(constants[c], word);
                c++;
            }
        }

        // Operators
        else if (ch == '+' || ch == '-' ||
                 ch == '*' || ch == '/' ||
                 ch == '=' || ch == '<' ||
                 ch == '>')
        {
            char opSymbol[2];

            opSymbol[0] = ch;
            opSymbol[1] = '\0';

            int alreadyExists = 0;

            for (int j = 0; j < op; j++)
            {
                if (strcmp(operators[j], opSymbol) == 0)
                {
                    alreadyExists = 1;
                    break;
                }
            }

            if (!alreadyExists)
            {
                strcpy(operators[op], opSymbol);
                op++;
            }

            i++;
        }

        // Special symbols
        else if (ch == '(' || ch == ')' ||
                 ch == '{' || ch == '}' ||
                 ch == ';' || ch == ',' ||
                 ch == '[' || ch == ']')
        {
            char sym[2];

            sym[0] = ch;
            sym[1] = '\0';

            int alreadyExists = 0;

            for (int j = 0; j < sp; j++)
            {
                if (strcmp(specialSymbols[j], sym) == 0)
                {
                    alreadyExists = 1;
                    break;
                }
            }

            if (!alreadyExists)
            {
                strcpy(specialSymbols[sp], sym);
                sp++;
            }

            i++;
        }

        // Ignore spaces, newline and other characters
        else
        {
            i++;
        }
    }

    // Display results

    printf("\nKeywords:\n");

    for (i = 0; i < k; i++)
        printf("%s ", keywords[i]);

    printf("\n\nIdentifiers:\n");

    for (i = 0; i < id; i++)
        printf("%s ", identifiers[i]);

    printf("\n\nConstants:\n");

    for (i = 0; i < c; i++)
        printf("%s ", constants[i]);

    printf("\n\nOperators:\n");

    for (i = 0; i < op; i++)
        printf("%s ", operators[i]);

    printf("\n\nSpecial Symbols:\n");

    for (i = 0; i < sp; i++)
        printf("%s ", specialSymbols[i]);

    printf("\n");

    return 0;
}