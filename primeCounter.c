#include <stdio.h>
#include <stdbool.h>
#include "primeCounter.h"

// Checks if a number is prime by testing divisibility from 2 up to the square root of the number
bool checkPrime(int number) {
    if (number <= 1) return false; // Numbers less than or equal to 1 are not prime
    for (int divisor = 2; divisor * divisor <= number; divisor++) {
        if (number % divisor == 0) return false; // A divisible number is not prime
    }
    return true; // Number is prime
}

int main() {
    int inputNumber;
    int primeCount = 0;

    // Continuously read integers from standard input until EOF is reached
    while (scanf("%d", &inputNumber) != EOF) {
        if (checkPrime(inputNumber)) { // Check if the current number is prime
            primeCount++; // Increment count if prime
        }
    }

    // Output the total count of prime numbers encountered
    printf("%d total primes.\n", primeCount);

    return 0;
}
