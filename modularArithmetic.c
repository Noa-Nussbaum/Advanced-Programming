#include "modularArithmetic.h"

long long mod_mult(long long x, long long y, long long mod) {  // Function for modular multiplication
    long long result = 0, factor = x % mod;
    while (y > 0) {
        if (y % 2 == 1)
            result = (result + factor) % mod;
        factor = (factor * 2) % mod;
        y /= 2;
    }
    return result;
}

long long mod_pow(long long base, long long exp, long long mod) {  // Function for modular exponentiation
    long long result = 1, tempBase = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = mod_mult(result, tempBase, mod);
        tempBase = mod_mult(tempBase, tempBase, mod);
        exp /= 2;
    }
    return result;
}