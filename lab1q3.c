#include <stdio.h>
#include <string.h>

int main()
{
    char op[5];
    char choice;

    do
    {
        printf("Enter an operator: ");
        scanf("%4s", op);

        // Arithmetic Operators
        if(strcmp(op,"+")==0 || strcmp(op,"-")==0 ||
           strcmp(op,"*")==0 || strcmp(op,"/")==0 ||
           strcmp(op,"%")==0 ||
           strcmp(op,"++")==0 || strcmp(op,"--")==0)
        {
            printf("Arithmetic Operator\n");
        }

        // Relational Operators
        else if(strcmp(op,"<")==0 || strcmp(op,">")==0 ||
                strcmp(op,"<=")==0 || strcmp(op,">=")==0 ||
                strcmp(op,"==")==0 || strcmp(op,"!=")==0)
        {
            printf("Relational Operator\n");
        }

        // Logical Operators
        else if(strcmp(op,"&&")==0 || strcmp(op,"||")==0 ||
                strcmp(op,"!")==0)
        {
            printf("Logical Operator\n");
        }

        // Assignment Operators
        else if(strcmp(op,"=")==0 ||
                strcmp(op,"+=")==0 ||
                strcmp(op,"-=")==0 ||
                strcmp(op,"*=")==0 ||
                strcmp(op,"/=")==0 ||
                strcmp(op,"%=")==0)
        {
            printf("Assignment Operator\n");
        }

        else
        {
            printf("Invalid Operator\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c",&choice);

    } while(choice=='y' || choice=='Y');

    return 0;
}