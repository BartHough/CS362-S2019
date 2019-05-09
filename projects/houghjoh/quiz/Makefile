CFLAGS= -Wall -fpic -coverage -lm -std=c99

test: testme.c
	echo "Running testme.c"
	gcc -o testme testme.c $(CFLAGS)
	-./testme
	gcov -b -c testme.c 
