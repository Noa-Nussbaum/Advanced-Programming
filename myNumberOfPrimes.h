#ifndef MY_NUMBER_OF_PRIMES_H
#define MY_NUMBER_OF_PRIMES_H

#include <stdatomic.h>  // Include for atomic types

// Constants used by multiple files or that configure the module's behavior
#define THREAD_COUNT 4
#define SEGMENT_SIZE 2500000

// ThreadData structure to hold thread-specific data
typedef struct {
    atomic_int startIndex;  // Starting index for each thread
    atomic_int endIndex;    // Ending index for each thread
    int* primeCount;        // Local count of prime numbers found
} ThreadData;

struct ThreadArgs {
    atomic_int start; // starting index for the thread
    atomic_int end;  // ending index for the thread
    int* local_counter; // local counter for prime numbers found by the thread
};

// Function declaration for thread_function
void* thread_function(void* args);

#endif // MY_NUMBER_OF_PRIMES_H
