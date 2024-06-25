# Prime Number Counter with Multithreading

## Created By:
* [Dana Zorohov](https://github.com/danaZo)
* [Noa Nussbaum](https://github.com/Noa-Nussbaum)

</br>

## Overview

This project implements a multithreaded prime number counter. </br>
It consists of a random number generator to simulate an endless data stream and a prime number counter that processes this stream using multiple threads. </br>
The goal is to efficiently count the number of prime numbers in the generated stream.
</br></br>

## Files
- ```generator.c```: Generates random numbers within a specified range.
- ```primeCounter.c```: A basic implementation to count prime numbers from standard input.
- ```myNumberOfPrimes.c```: An optimized, multithreaded implementation to count prime numbers from standard input.
- ```modularArithmetic.c```, ```modularArithmetic.h```: Contains functions for modular arithmetic operations.
- ```primality.c```, ```primality.h```: Contains the implementation of the Miller-Rabin primality test.
- ```myNumberOfPrimes.h```: Header file for the multithreaded prime counting implementation.
- ```Makefile```: Build configuration file to compile the project.
</br></br>

## Building the Project
To build the project, ensure you have ```gcc``` installed and run the following command:</br>
```
make all
```
This will compile the following executables:
- ```randomGenerator```
- ```primeCounter```
- ```myNumberOfPrimes```
</br></br>

## Running the Project
### Random Number Generator
Generate random numbers using the ```randomGenerator``` executable. It requires two arguments: a seed and the number of values to generate.
```
./randomGenerator <seed> <number_of_values>
```
Example:
```
./randomGenerator 10 100
```
### Basic Prime Counter
Count the number of prime numbers from a stream using the basic ```primeCounter``` implementation:
```
./randomGenerator 10 100 | ./primeCounter
```
### Multithreaded Prime Counter
Count the number of prime numbers from a stream using the optimized multithreaded implementation:
```
./randomGenerator 10 100 | ./myNumberOfPrimes
```
### Benchmarking
To benchmark the performance, you can use the ```time``` command to measure the execution time:
```
time ./randomGenerator 10 10000000 | ./primeCounter
time ./randomGenerator 10 10000000 | ./myNumberOfPrimes
```
## Explanation of the Code
```generator.c```</br>
This file contains a simple random number generator. It generates numbers within a specified range using the ```rand()``` function.

```primeCounter.c```</br>
This is the basic implementation of the prime number counter. It reads numbers from standard input and checks if they are prime using a straightforward primality test.

```myNumberOfPrimes.c```</br>
This is the optimized, multithreaded implementation. It divides the workload among multiple threads, each processing a chunk of the input stream. It uses the Miller-Rabin primality test for efficient primality checking.

```modularArithmetic.c``` and ```primality.c```</br>
These files contain functions for modular arithmetic operations and the Miller-Rabin primality test, respectively. These functions are used in the ```myNumberOfPrimes.c``` file to check if numbers are prime.
</br></br>

## Memory Usage
proof of less than 2MB RAM using valgring command:
```
valgrind --tool=massif --stacks=yes ./randomGenerator 10 100 | ./myNumberOfPrimes
```
Then we receive output file named ```massif.out.7464```, print it with the command:
```
ms_print massif.out.7464
```
Result:
![mem usage](https://github.com/Noa-Nussbaum/Advanced-Programming/assets/93203695/7d946a47-2cff-4044-ae43-1c2f3024460d)
After running with ```--stacks=yes```:
![image](https://github.com/Noa-Nussbaum/Advanced-Programming/assets/76524924/94eadffa-49eb-498a-bf6e-a5e24eaa2f5c)



### Valgrind Output Summary
- Peak Total Memory Usage: 4,104 bytes (approximately 4 KB)
- Useful Heap: 4,096 bytes
- Extra Heap: 8 bytes
- Stacks: 0 bytes
This confirms that the memory usage of the program is below the 2MB requirement.
