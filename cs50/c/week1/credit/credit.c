#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

enum Cards {AMEX, MASTERCARD, VISA, INVALID};
int card_number[16];

/**
 * Luhn Algorithm for Credit Card Validation
 * 
 * Steps:
 * 1. Starting from the rightmost digit (excluding the checksum digit),
 *    double the value of every second digit.
 *    If doubling results in a number greater than 9, subtract 9.
 * 2. Sum up all the digits including the ones you didn't double.
 * 3. The card number is valid if the sum is a multiple of 10.
 * 
 * @param cardDigits Pointer to an integer array containing the card digits.
 * @param length The length of the integer array.
 * @return an enum representing the type of card detected
 */
int isValid(int* CardDigits, int length, int cardType)
{

    int total_sum = 0;

    // Loop through the card digits in reverse order
    for (int i = length - 1; i >= 0; i--) {
        int n = CardDigits[i];

        // If the index is even (considering 0-based index), double the digit
        if ((length - 1 - i) % 2 == 1) {
            n *= 2;
            if (n > 9) {
                n -= 9;
            }
        }

        total_sum += n;
    }

    if(total_sum % 10 == 0)
    {
        return cardType;
    }
    else
    {
        return INVALID;
    }

}

// Return whether card is AMEX, MASTERCARD, VISA, INVALID
int getCardTypeInitial(int* intArray, int length)
{
    // AMEX: starts with 34 or 37 and is 15 digits long
    // MASTERCARD: starts with numbers ranging from 51 to 55 and is 16 digits long
    // VISA: Starts with 4 and can be 13 or 16 digits long

    if(intArray[0] == 3 && (intArray[1] == 4 || intArray[1] == 7) && length == 15)
    {
        printf("Could be an AMEX...\n");
        return AMEX; 
    }

    if(intArray[0] == 5 && (intArray[1] == 1 || intArray[1] == 2 || intArray[1] == 3 || intArray[1] == 4) && length == 16)
    {
        printf("Could be a MASTERCARD...\n");
        return MASTERCARD; 
    }

    if(intArray[0] == 4 && (length == 13 || length == 16))
    {
        printf("Could be an VISA...\n");
        return VISA; 
    }

    printf("Card is INVALID based off initial check\n");

    return INVALID;

}


char* intToString(long long int num, int* lengthPointer) {

    char *str = malloc(256);  // Allocate memory for string; max digits for int32 + sign + null terminator

    if (str == NULL) {
        return NULL;  // Return NULL if memory allocation fails
    }

    sprintf(str, "%lld", num);  // Convert integer to string
    int length = strlen(str);
    // printf("String length: %d", length);
    *lengthPointer = length;
    return str;
}

int* stringToDigitsArray(const char *str, int length) {

    // Validate string content and length
    if (length == 0) {
        return NULL;
    }

    // Allocate memory for the array of integers
    int *arr = (int *)malloc(length * sizeof(int));
    if (arr == NULL) {
        return NULL;  // Return NULL if memory allocation fails
    }

    // Convert each character in the string to an integer using ASCII offset
    for (int i = 0; i < length; ++i) {
        if (str[i] < '0' || str[i] > '9') {
            free(arr);
            return NULL;  // Invalid character in string
        }
        arr[i] = str[i] - '0';
    }

    return arr;
}

// Get number of digits
int getNumberOfDigits(long long num)
{
    int numberOfDigits = 0;
    numberOfDigits = (int)log10(llabs(num)) + 1;
    return numberOfDigits;
}

int checkCard(long long int cardNumber)
{

    int digit = 0;
    int numberOfDigits = 0;

    // Testing
    numberOfDigits = getNumberOfDigits(cardNumber);
    printf("Number of digits: %d\n", numberOfDigits);
    
    int length = 0;
    char *str = intToString(cardNumber, &length);

    if (str != NULL) {

        int *arr = stringToDigitsArray(str, length);
        printf("Converted string: %s\n", str);
        printf("Converted string length: %d\n", length);

        printf("Numbers (ints): ");
        for(int i = 0; i < length; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");


        // We now have all initial card information
        // AMEX: starts with 34 or 37 and is 15 digits long
        // MASTERCARD: starts with numbers ranging from 51 to 55 and is 16 digits long
        // VISA: Starts with 4 and can be 13 or 16 digits long

        // Do initial card type check
        int cardType = getCardTypeInitial(arr, length);

        // Now perform the algorithm to check validity 
        int returnCode = INVALID;
        returnCode = isValid(arr, length, cardType);

        switch (returnCode) {
        case AMEX:
            printf("AMEX\n");
            break;
        case MASTERCARD:
            printf("MASTERCARD\n");
            break;
        case VISA:
            printf("VISA\n");
            break;
        case INVALID:
            printf("INVALID\n");
            break;
        default:
            printf("something broke\n");
        }


        free(str);  // Free allocated memory
    }

    return 0;
}

int main(void)
{

    // For testing
    long long int amexExample = 341234567890123LL;  // 15
    long long int masterCardExample = 5105105105105100; // 16
    long long int visaExampleLong = 4111111111111111;  // 16
    long long int visaExampleShort = 4111111111111;      // 13
    long long int invalidExample = 123456789012345;   // 15
    long long int test = 32985238;

    checkCard(test);
    checkCard(amexExample);
    checkCard(masterCardExample);
    checkCard(visaExampleLong);
    checkCard(visaExampleShort);

    return 0;
}



// Extract digits from cards
// int getDigits(long long number) {

//     long long foo = number;
 
// //   do
// //   {
// //     if (number < 0)
// //     {
// //       printf ("invalid input...enter a positive integer: ");
// //       continue;
// //     }
// //     else break;
// //   } while (1);

//   int a = -1;
//   int b = -1;
//   int c = -1;
//   int d = -1;
//   int e = -1;
//   int f = -1;
//   int g = -1;
//   int h = -1;
//   int i = -1;
//   int j = -1;
//   int k = -1;
//   int l = -1;
//   int m = -1;
//   int n = -1;
//   int o = -1;
//   int p = -1;

//   while (foo > 0)
//   {
//     if (a < 0) a = foo % 10;
//     else if (b < 0) b = foo % 10;
//     else if (c < 0) c = foo % 10;
//     else if (d < 0) d = foo % 10;
//     else if (e < 0) e = foo % 10;
//     else if (f < 0) f = foo % 10;
//     else if (g < 0) g = foo % 10;
//     else if (h < 0) h = foo % 10;
//     else if (i < 0) i = foo % 10;
//     else if (j < 0) i = foo % 10;
//     else if (k < 0) i = foo % 10;
//     else if (l < 0) i = foo % 10;
//     else if (m < 0) i = foo % 10;
//     else if (n < 0) i = foo % 10;
//     else if (o < 0) i = foo % 10;
//     else if (p < 0) i = foo % 10;

//     // number /= 10;
//     foo = foo / 10;

//   }

//   /* Printing for verification. */

//   printf("%i\n", a);
//   printf("%i\n", b);
//   printf("%i\n", c);
//   printf("%i\n", d);
//   printf("%i\n", e);
//   printf("%i\n", f);
//   printf("%i\n", g);
//   printf("%i\n", h);
//   printf("%i\n", i);
//   printf("%i\n", j);
//   printf("%i\n", k);
//   printf("%i\n", l);
//   printf("%i\n", m);
//   printf("%i\n", n);
//   printf("%i\n", o);
//   printf("%i\n", p);

//   card_number[0] = a;
//   card_number[1] = b;
//   card_number[2] = c;
//   card_number[3] = d;
//   card_number[4] = e;
//   card_number[5] = f;
//   card_number[6] = g;
//   card_number[7] = h;
//   card_number[8] = i;
//   card_number[9] = j;
//   card_number[10] = k;
//   card_number[11] = l;
//   card_number[12] = m;
//   card_number[13] = n;
//   card_number[14] = o;
//   card_number[15] = p;


//   return 0;
// }