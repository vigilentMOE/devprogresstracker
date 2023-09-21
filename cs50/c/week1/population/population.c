#include <cs50.h>
#include <stdio.h>

// Function prototype for get_int
int get_int(char message[]);

int main()
{
    // Initialize variables
    int start_population, end_population, years = 0;

    // Prompt user for start size
    // Do while loop
    do
    {
        start_population = get_int("Enter the start size: ");
    } while (start_population < 9);

    // Prompt user for end size
    do
    {
        end_population = get_int("Enter the end size: ");
    } while (end_population <= start_population);

    // Calculate the number of years
    while (start_population < end_population)
    {
        int born = start_population / 3;
        int dead = start_population / 4;

        start_population = start_population + born - dead;
        years++;
    }

    // Print the number of years
    printf("Years: %d\n", years);

    return 0;
}

// Print message and read input, then return
int get_int(char message[])
{
    int input = 0;
    printf("%s", message);
    scanf("%d", &input);

    if(input < 9)
    {
        printf("Please input a population greater than 9");
    }

    return input;
}

// ### Required Functionality

// 1. **User Input Handling**
//     - Prompt the user for the initial population size (`start`)
//     - Prompt the user for the desired population size (`end`)

// 2. **Input Validation**
//     - Ensure `start` is greater than or equal to 9
//     - Ensure `end` is greater than `start`

// 3. **Population Calculation**
//     - Calculate the number of llamas born each year (`born = start / 3`)
//     - Calculate the number of llamas that die each year (`dead = start / 4`)
  
// 4. **Population Update**
//     - Update the population size each year (`start = start + born - dead`)
  
// 5. **Year Tracking**
//     - Keep track of the number of years required for the population to reach the `end` size

// 6. **Output Display**
//     - Display the calculated number of years once the `end` size is reached or exceeded
  
// 7. **Program Termination**
//     - Gracefully exit the program once the calculation is complete

// 8. **Error Handling**
//     - Account for invalid input types (assuming `get_int()` doesn’t handle this)
//     - Handle any division-by-zero errors, although theoretically this should not happen based on the input constraints





