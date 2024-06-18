.PHONY: all clean

all: randomizer NumberOfPrimes myNumberOfPrimes

randomizer: randomizer.c randomizer.h
	gcc -o randomizer randomizer.c

modularArithmetic.o: modularArithmetic.c modularArithmetic.h
	gcc -c modularArithmetic.c -o modularArithmetic.o

primality: primality.c primality.h
	gcc -c primality.c -o primality.o

NumberOfPrimes: NumberOfPrimes.c NumberOfPrimes.h
	gcc -o NumberOfPrimes NumberOfPrimes.c

myNumberOfPrimes: myNumberOfPrimes.c myNumberOfPrimes.h modularArithmetic.o primality.o
	gcc -o myNumberOfPrimes myNumberOfPrimes.c modularArithmetic.o primality.o -lpthread -lm

clean:
	-rm -f randomizer NumberOfPrimes myNumberOfPrimes modularArithmetic.o primality.o
