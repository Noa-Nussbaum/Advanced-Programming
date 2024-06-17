#include "primality.h"
#include "modularArithmetic.h"
#include <stdlib.h>



// Miller-Rabin Primality Test to check if a number is prime
int is_prime(long long n, int iterations) {
    if (n < 2 || (n != 2 && n % 2 == 0)) return 0;
    long long s = n - 1;
    while (s % 2 == 0) s /= 2;
    for (int i = 0; i < iterations; i++) {
        long long a = rand() % (n - 1) + 1, temp = s;
        long long mod = mod_pow(a, temp, n);
        while (temp != n - 1 && mod != 1 && mod != n - 1) {
            mod = mod_mult(mod, mod, n);
            temp *= 2;
        }
        if (mod != n - 1 && temp % 2 == 0) return 0;
    }
    return 1;
}
