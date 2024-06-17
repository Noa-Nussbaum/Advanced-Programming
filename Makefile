.PHONY: all clean

all: randomizer NumberOfPrimes myNumberOfPrimes

randomizer: randomizer.c
	gcc -o randomizer randomizer.c

modularArithmetic.o: modularArithmetic.c
	gcc -c modularArithmetic.c

NumberOfPrimes: NumberOfPrimes.c
	gcc -o NumberOfPrimes NumberOfPrimes.c

myNumberOfPrimes: myNumberOfPrimes.c modularArithmetic.o primality.o
	gcc -o myNumberOfPrimes myNumberOfPrimes.c modularArithmetic.o primality.o -lpthread -lm

primality.o: primality.c
	gcc -c primality.c

clean:
	-rm -f randomizer NumberOfPrimes myNumberOfPrimes modularArithmetic.o primality.o
