#ifndef MY_NUMBER_OF_PRIMES_H
#define MY_NUMBER_OF_PRIMES_H

#include <stdatomic.h>  // Include for atomic types

// Constants used by multiple files or that configure the module's behavior
#define THREAD_COUNT 5
#define SEGMENT_SIZE 2000000

// ThreadData structure to hold thread-specific data
typedef struct {
    atomic_int startIndex;  // Starting index for each thread
    atomic_int endIndex;    // Ending index for each thread
    int* primeCount;        // Local count of prime numbers found
} ThreadData;

// Function declaration for thread_function
void* thread_function(void* args);

#endif // MY_NUMBER_OF_PRIMES_H
