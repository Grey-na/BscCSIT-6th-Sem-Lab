// Write a C program to implement DFA for accepting
// all strings ending with 00 over an alphabet {0,1}.

#include <stdio.h>
#include <string.h>

enum states { q0, q1, qf };

enum states delta(enum states state, char ch)
{
    enum states curr_state;

    switch (state)
    {
        case q0:
            if (ch == '0')
                curr_state = q1;
            else
                curr_state = q0;
            break;

        case q1:
            if (ch == '0')
                curr_state = qf;
            else
                curr_state = q0;
            break;

        case qf:
            if (ch == '0')
                curr_state = qf;
            else
                curr_state = q0;
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

        if (curr_state == qf)
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