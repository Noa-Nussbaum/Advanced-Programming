#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdatomic.h>
#include "modularArithmetic.h"
#include "primality.h"

#define THREAD_COUNT 5
#define SEGMENT_SIZE 2000000

typedef struct {
    atomic_int startIndex;  // Starting index for each thread
    atomic_int endIndex;    // Ending index for each thread
    int* primeCount;        // Local count of prime numbers found
} ThreadData;




void* thread_function(void* args) {  // Thread function to process number ranges
    ThreadData* data = (ThreadData*)args;
    int number;
    while (1) {
        int start = atomic_load(&data->startIndex);
        int end = atomic_load(&data->endIndex);
        for (int i = start; i <= end; i++) {
            if (scanf("%d", &number) != EOF) {
                if (is_prime(number, 4))
                    (*data->primeCount)++;
            } else {
                pthread_exit(NULL);
            }
        }
        atomic_store(&data->startIndex, start + THREAD_COUNT * SEGMENT_SIZE);
        atomic_store(&data->endIndex, end + THREAD_COUNT * SEGMENT_SIZE);
    }
}

int main() {
    
    int answer = 0;
    pthread_t threadIDs[THREAD_COUNT];
    ThreadData threadData[THREAD_COUNT];

    for (int i = 0; i < THREAD_COUNT; i++) {
        atomic_init(&threadData[i].startIndex, i * SEGMENT_SIZE + 1);
        atomic_init(&threadData[i].endIndex, (i + 1) * SEGMENT_SIZE);
        threadData[i].primeCount = malloc(sizeof(int));
        *threadData[i].primeCount = 0;
        pthread_create(&threadIDs[i], NULL, thread_function, &threadData[i]);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threadIDs[i], NULL);
        answer += *threadData[i].primeCount;
        free(threadData[i].primeCount);
    }   

    printf("%d total primes found.\n", answer);
    return 0;
}
