#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdatomic.h>
#include "modularArithmetic.h"
#include "primality.h"
#include "myNumberOfPrimes.h"


/**
 * Thread function to process a range of numbers and count how many are prime.
 * Each thread processes its own range and updates a shared prime count.
 * 
 * @param args Pointer to ThreadData structure containing start, end indices and a pointer to the prime count.
 * @return Nothing is returned because the function is designed to handle processing in an infinite loop or until EOF.
 */
void* thread_function(void* args) {
    ThreadData* data = (ThreadData*)args;  // Cast the void pointer back to ThreadData structure pointer.
    int number;

    // Infinite loop to continuously process numbers.
    while (1) {
        int start = atomic_load(&data->startIndex);  // Load the start index atomically to prevent data races.
        int end = atomic_load(&data->endIndex);  // Load the end index atomically.

        // Iterate over the range from start to end indices.
        for (int i = start; i <= end; i++) {
            // Read integers from stdin until EOF.
            if (scanf("%d", &number) != EOF) {
                // Check if the number is prime and increment the count if it is.
                if (is_prime(number, 4))  // The second parameter '4' stands for the number of checks in Miller-Rabin test.
                    (*data->primeCount)++;
            } else {
                pthread_exit(NULL);  // Exit the thread if EOF is reached or input fails.
            }
        }

        // Update start and end indices for the next segment of numbers.
        atomic_store(&data->startIndex, start + THREAD_COUNT * SEGMENT_SIZE);
        atomic_store(&data->endIndex, end + THREAD_COUNT * SEGMENT_SIZE);
    }
}

int main() {
    int answer = 0;  // This variable will hold the total number of prime numbers found.
    pthread_t threadIDs[THREAD_COUNT];  // Array to hold thread identifiers.
    ThreadData threadData[THREAD_COUNT];  // Array of ThreadData structures for each thread.

    // Initialize each thread's data and create the threads.
    for (int i = 0; i < THREAD_COUNT; i++) {
        atomic_init(&threadData[i].startIndex, i * SEGMENT_SIZE + 1);  // Initialize the start index atomically.
        atomic_init(&threadData[i].endIndex, (i + 1) * SEGMENT_SIZE);  // Initialize the end index atomically.
        threadData[i].primeCount = malloc(sizeof(int));  // Allocate memory for the prime count.
        *threadData[i].primeCount = 0;  // Initialize the prime count to zero.

        // Create each thread passing in the address of the corresponding ThreadData structure.
        pthread_create(&threadIDs[i], NULL, thread_function, &threadData[i]);
    }

    // Wait for all threads to complete and aggregate the results.
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threadIDs[i], NULL);  // Wait for thread termination.
        answer += *threadData[i].primeCount;  // Add up the prime counts from each thread.
        free(threadData[i].primeCount);  // Free the allocated memory for prime counts.
    }

    printf("%d total primes.\n", answer);  // Print the total number of primes found.
    return 0;
    
}