#include "modularArithmetic.h"

/**
 * Performs modular multiplication of two numbers.
 * This function calculates (x * y) % mod using an iterative method to avoid overflow issues
 * that can arise with direct multiplication, especially with large numbers.
 *
 * @param x The first multiplicand.
 * @param y The second multiplicand.
 * @param mod The modulus to be applied.
 * @return The result of (x * y) % mod.
 */
long long mod_mult(long long x, long long y, long long mod) {
    long long result = 0;  // Initialize result to zero.
    long long factor = x % mod;  // Reduce x modulo 'mod' to ensure it's within the mod range.
    
    while (y > 0) {
        if (y % 2 == 1)  // If y is odd, add the current factor to the result and reduce modulo 'mod'.
            result = (result + factor) % mod;
        factor = (factor * 2) % mod;  // Double the factor, and reduce modulo 'mod'.
        y /= 2;  // Divide y by 2, effectively right-shifting the binary representation of y.
    }
    return result;  // Return the computed result.
}

/**
 * Performs modular exponentiation.
 * This function calculates (base ^ exp) % mod using an iterative method to handle large exponents
 * and avoid overflow issues. It utilizes modular multiplication for intermediate calculations.
 *
 * @param base The base number of the exponentiation.
 * @param exp The exponent applied to the base.
 * @param mod The modulus to be applied.
 * @return The result of (base ^ exp) % mod.
 */
long long mod_pow(long long base, long long exp, long long mod) {
    // long long result = 1;  // Initialize result as 1. Any number to the power of 0 is 1.
    // long long tempBase = base % mod;  // Reduce 'base' modulo 'mod' to simplify multiplication.
    
    // while (exp > 0) {
    //     if (exp % 2 == 1)  // If the current power is odd, multiply the current result by the base.
    //         result = mod_mult(result, tempBase, mod);
    //     tempBase = mod_mult(tempBase, tempBase, mod);  // Square the base to move to the next power of 2.
    //     exp /= 2;  // Divide exp by 2, moving to the next higher power of 2.
    // }
    // return result;  // Return the final computed result.

    long long result = 1;
    long long y = base;
    while (exp > 0) 
    {
        if (exp % 2 == 1)
            result = (result * y) % mod;
        y = (y * y) % mod;
        exp /= 2;
    }
    return result % mod;
}
