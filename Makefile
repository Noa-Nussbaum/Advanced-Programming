.PHONY: all
all: randomizer primeCounter myPrimeCounter 

randomizer:  randomizer.c
	gcc -o generator randomizer.c

primeCounter:	primeCounter.c
	gcc -o primeCounter primeCounter.c

myPrimeCounter: myPrimeCounter.c
	gcc -o myPrimeCounter myPrimeCounter.c -lpthread -lm


.PHONY: clean
clean:
	-rm generator primeCounter myPrimeCounter 2>/dev/null
