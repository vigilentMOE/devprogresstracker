#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

// Check to see if user input is OK
bool isValidInput(int input) {
    bool foo = false;

    if(input > 10)
    {
        foo = false;
        printf("Please enter input less than 10\n");
    }

    else if(input < 1)
    {
        foo = false;
        printf("Please enter input greater than 1\n");
    }

    else
    {
        foo = true;
    }

    return foo;
}

void printPyramid(int height)
{

    int foo = height - 1;
    // Each individual pass through the pyramid line wise
    for(int i = (height-1); i >= 0; i--)
    {
        // Beginning the print 
        for(int j = 0; j < foo; j++)
        {
            printf(" ");
        }
        // Print the #s
        for(int j = 0; j < (height-foo); j++)
        {
            printf("#");
        }

        // Print spacer
        printf("  ");

        // Print the #s
        for(int j = 0; j < (height-foo); j++)
        {
            printf("#");
        }
        // Ending the print 
        for(int j = 0; j < foo; j++)
        {
            printf(" ");
        }

        foo--;
        printf("\n");
    }
    return;

}

int main(void)
{

    int height = 0;
    printf("Please enter height of pyramid\n");
    scanf("%d", &height);
    isValidInput(height);
    printPyramid(height);

    return 0;

}
