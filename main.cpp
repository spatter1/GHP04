/*
* CS240, GHP04
* 10/25/2019
*
* Nyhoff Page 387 #4 as follows:
*
* For a given integer n>1, the smallest integer d>1 that divides n is a prime factor.  We can find the prime
* factorization of n if we find d then replace n by the quotient of n divided by d, repeating this until n becomes
* 1.  Write a program that determines the prime factorization of n in this manner, but displays the prime factors in
* descending order.  For example, for n=3960, your program should produce:
*
*                11 * 5 * 3 * 3 * 2 * 2 *2
*
* Written by Sean Patterson
* with adaptations from Nyhoff
* using Code::Blocks 17.12 IDE
*
*/

#include <iostream>

using namespace std;

#include "stack.h"

int main(void)
{
    int userInt = 0,    // user provided int
        i = 0,          // counter
        q = 0,          // quotient
        stackCount = 0; // number of values in stack

    int primeArray [] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}; //array of prime numbers for calculations

    // 1. Explain the purpose of the program
    cout << "This program will calculate the prime factor of an integer provided by the user of the program." << endl;

    // 2. Ask user for an int
    cout << "Please enter an integer that is greater than 1: ";

    // 3. Store int to memory
    cin >> userInt;

    // 4. Validate the user's entry as being greater than 1, terminate program if less than 2.
    if(userInt <2)
    {
        cout << "\n\nThis program will not work with integers of less than 1." << endl;
    }

    // 5. If the user's int is greater than 1, run routine to calculate prime factorization.
    else if (userInt > 1)
    {

    // 6. Create stack primeStack
        Stack primeStack;

    // 7. divide user provides int by prime numbers, looking for a mod of 0.  Upon calculation, push divisor to stack
        for(i=0; userInt>1; i++)
        {
            if(userInt % primeArray[i]==0)
            {
                q = userInt / primeArray[i];

                primeStack.push(primeArray[i]);     // push prime factor to the stack
                stackCount++;                       // counting values added to the stack
                i = -1;                             // resetting counter to -1

    // 8. replace userInt with q to allow calculation to run again
                userInt = q;

            }
        }

    // 9. Displaying stack
        cout << "\nYour prime factors are:" << endl;

        for(i=stackCount; i>0; i-- )
        {
            cout << primeStack.top();
            primeStack.pop();
            if(i>1)
            {
                cout << " * ";
            }
        }
    }
    cout << "\n\nProgram terminating." << endl;
return 0;
}
