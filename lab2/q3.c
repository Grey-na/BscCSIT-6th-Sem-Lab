// Write a C program to recognize strings under
// a*, a*b+, and abb.

#include <stdio.h>
#include <string.h>

enum states { q0, q1, q2, dead };

enum states delta(enum states state, char ch)
{
    enum states curr_state = dead;

    switch (state)
    {
        case q0:
            if (ch == 'a')
                curr_state = q1;
            else if (ch == 'b')
                curr_state = q2;
            else
                curr_state = dead;
            break;

        case q1:
            if (ch == 'a')
                curr_state = q1;
            else if (ch == 'b')
                curr_state = q2;
            else
                curr_state = dead;
            break;

        case q2:
            if (ch == 'b')
                curr_state = q2;
            else
                curr_state = dead;
            break;

        case dead:
            curr_state = dead;
            break;
    }

    return curr_state;
}

int main()
{
    char input[100];
    char choice;

    do
    {
        printf("Enter the input string: ");
        scanf("%s", input);

        enum states curr_state = q0;

        for (int i = 0; i < strlen(input); i++)
        {
            curr_state = delta(curr_state, input[i]);
        }

        if (curr_state == q0 || curr_state == q1 || curr_state == q2)
        {
            printf("The string \"%s\" is accepted.\n", input);
        }
        else
        {
            printf("The string \"%s\" is rejected.\n", input);
        }

        printf("Do you want to continue? (Y,N): ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    return 0;
}