    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include "generator.h"

    int generateRandomNumber(int lower, int upper) {
        return rand() % (upper - lower + 1) + lower;
    }

    int main(int argc, char *argv[]) {
        // Check if the number of arguments is correct
        if (argc != 3) {
            fprintf(stderr, "Usage: %s <initial seed> <number of values>\n", argv[0]);
            return EXIT_FAILURE;
        }

        // Initialize seed and number of random numbers to generate
        int initialSeed = atoi(argv[1]);
        int numberOfValues = atoi(argv[2]);

        // Setup random number generation
        srand(initialSeed);

        // Define limits for random number generation
        int minRange = 1000000;
        int maxRange = 2100000000;

        // Output random numbers within specified range
        for (int i = 0; i < numberOfValues; ++i) {
            int random = generateRandomNumber(minRange, maxRange);
            printf("%d\n", random);
        }

        return EXIT_SUCCESS;
    }
