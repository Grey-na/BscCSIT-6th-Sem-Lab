// Write a C program to implement DFA for accepting
// even number of 0's and even number of 1's.

#include <stdio.h>
#include <string.h>

enum states { q0, q1, q2, q3 };

enum states delta(enum states state, char ch)
{
    enum states curr_state;

    switch (state)
    {
        case q0:
            if (ch == '0')
                curr_state = q1;
            else
                curr_state = q2;
            break;

        case q1:
            if (ch == '0')
                curr_state = q0;
            else
                curr_state = q3;
            break;

        case q2:
            if (ch == '0')
                curr_state = q3;
            else
                curr_state = q0;
            break;

        case q3:
            if (ch == '0')
                curr_state = q2;
            else
                curr_state = q1;
            break;
    }

    return curr_state;
}

int main()
{
    char input[100];
    char choice;
    int i;

    do
    {
        printf("Enter the input string: ");
        scanf("%s", input);

        enum states curr_state = q0;

        i = 0;

        while (input[i] != '\0')
        {
            curr_state = delta(curr_state, input[i]);
            i++;
        }

        if (curr_state == q0)
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