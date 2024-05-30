/*Carrie Bailey
CS221 Spring 2024
Dynamic Arrays - Passing Array as Pointer
Week 7, Exercise #2
Description: Pass an integer array as a pointer along with its size and determine how many even and how many odd #s it has.
*/

#include <iostream>

using namespace std;

//FUNCTION PROTOTYPES
int countEven(int *array, int size);//even numbers function
int countOdd(int *array, int size);//odd numbers function
int random_number(int min, int max); //generate random number
//CONSTANTS
const int SIZE = random_number(10, 89);

//PROGRAM
int main() {
    srand(time(NULL)); // random seed
    int myArray[SIZE];

    for (int i = 0; i < SIZE; i++) {
        myArray[i] = random_number(1, 131);
    }
        cout << "size: " << SIZE << endl;
        cout << "Array Elements: ";
        for (int i = 0; i < SIZE; i++)
            cout << myArray[i] << " ";
        cout << endl;

    int even_numbers = countEven(myArray, SIZE);//variable for function to return # even integers
    int odd_numbers = countOdd(myArray, SIZE);//variable for function to return # of odd integers
    cout << "Count of even numbers: " << even_numbers << endl;//display even numbers
    cout << "Count of odd numbers: " << odd_numbers << endl;//display odd number
    return 0;
}

//FUNCTION DEFINITIONS
int countEven(int *array, int size) {//function to count even numbers, pass array in as a pointer
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {//numbers evenly divisible by 2 are even
            count++;
        }
    }
    return count;
}

int countOdd(int *array, int size) {//function to count odd numbers
    int count_even = countEven(array, size);//call count even function and put # evens in a variable
    return size - count_even;//odd #s are the result of subtracting even numbers from size of array
}

int random_number(int min, int max) {
       return rand() % (max - min) + min;
}