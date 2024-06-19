Advanced Programming
Assignment 2

# Prime Stream Counter

## Created By:
* [Dana Zorohov](https://github.com/danaZo)
* [Noa Nussbaum](https://github.com/Noa-Nussbaum)

</br>

## Overview

This application is developed to handle a continuous stream of data, simulating a scenario such as a security camera feed where rapid processing is essential. It employs a provided random number generator to simulate an infinite stream of data, focusing on counting prime numbers rapidly to maximize the utilization of CPU cores.

## Compilation Instructions

Compile the application using the following command:
```bash
make
```
Ensure that the `make` utility is installed on your machine.

## Execution

To run the application using a basic prime counting method:
```bash
./randomizer 7 1000 | ./NumberOfPrimes
```
This executes the program using a seed of `7` to generate `1000` random numbers, which are then piped into the prime counting application. Parameters can be adjusted according to the requirements.

## Prime Counting Implementation

The program, `enhancedPrimeCounter`, leverages parallel processing to efficiently manage the counting of prime numbers within the continuous data stream. This method significantly improves performance by utilizing multiple CPU cores through threading.

### Details of Implementation

- **Modular Arithmetic**: Incorporates functions like `modular_multiply` and `modular_exponentiation` to manage large numbers efficiently.
- **Parallel Processing**: Distributes the data stream across multiple threads, each handling a portion of the data independently to speed up processing.
- **Atomic Operations**: Uses atomic operations to synchronize the start and end indices of data chunks across threads, reducing overhead and avoiding locks.

### Primality Testing

Utilizes the Miller-Rabin primality test, a probabilistic method, to check for prime numbers. The test's accuracy improves with the number of iterations specified, enhancing the reliability of prime detection under high-throughput conditions.

## Running the Enhanced Prime Counter

Execute the enhanced prime counter with a command like:
```bash
./randomizer 10 10000000 | ./myNumberOfPrimes
```
This setup processes 10 million numbers using a seed of `10`.

## Performance Monitoring

Measure execution time using:
```bash
time ./randomGenerator 10 10000000 | ./enhancedPrimeCounter
```

## Comparative Analysis

The performance of `enhancedPrimeCounter` is compared against the naive implementation using benchmarks that demonstrate a significant reduction in execution time.

### Efficiency Metrics

- **Execution Time**: The time command outputs user, system, and real time, indicating performance improvements.
- **Memory Usage**: Monitored using tools like `valgrind` to ensure it does not exceed 2MB, vital for operations on limited-resource environments.

### Results

The `enhancedPrimeCounter` outperforms the basic version by up to 10 times, especially when the primality test function is optimized.

## Dependencies

Relies on the `make` and `valgrind` utilities for compilation and memory monitoring, respectively.

---

This README reflects the task's requirement to utilize threading and optimize performance while ensuring memory usage does not exceed 2MB. It is structured to guide the user through compiling, running, and understanding the application within the specified constraints.
