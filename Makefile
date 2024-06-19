.PHONY: all clean

all: generator primeCounter myNumberOfPrimes

generator: generator.c generator.h
	gcc -o generator generator.c

modularArithmetic.o: modularArithmetic.c modularArithmetic.h
	gcc -c modularArithmetic.c -o modularArithmetic.o

primality: primality.c primality.h
	gcc -c primality.c -o primality.o

primeCounter: primeCounter.c primeCounter.h
	gcc -o primeCounter primeCounter.c

myNumberOfPrimes: myNumberOfPrimes.c myNumberOfPrimes.h modularArithmetic.o primality.o
	gcc -o myNumberOfPrimes myNumberOfPrimes.c modularArithmetic.o primality.o -lpthread -lm

clean:
	-rm -f generator primeCounter myNumberOfPrimes modularArithmetic.o primality.o
