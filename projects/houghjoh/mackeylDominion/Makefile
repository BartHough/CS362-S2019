CFLAGS= -Wall -fpic -coverage -lm -std=c99 -w

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)


#########
randomtestresults: randomtestcard1.c randomtestcard2.c randomtestadventurer.c dominion.c dominion.o
	
	echo "Random test results:" > randomtestresults.out
	echo "randomtestcard1.c testing the GREAT HALL function" >> randomtestresults.out
	gcc -o randotest1 randomtestcard1.c dominion.o rngs.o $(CFLAGS)
	-./randotest1 >> randomtestresults.out
	gcov -bf dominion.c >> randomtestresults.out

	echo >> randomtestresults.out
	echo "----------------------------------------------------------" >> randomtestresults.out
	echo "Randomtestcard2.c testing the VILLAGE function" >> randomtestresults.out
	gcc -o randotest2 randomtestcard2.c dominion.o rngs.o $(CFLAGS)
	-./randotest2 >> randomtestresults.out
	gcov -bf dominion.c >> randomtestresults.out

	echo >> randomtestresults.out
	echo "----------------------------------------------------------" >> randomtestresults.out
	echo "Randomtestadventurer.c" >> randomtestresults.out
	gcc -o randoadv randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	-./randoadv >> randomtestresults.out
	gcov -bf dominion.c >> randomtestresults.out



unittestresults: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.c dominion.h rngs.o
	echo "Result for running dominion.c tests:\n" > unittestresults.out
	echo "unittest1.c" >> unittestresults.out
	gcc -o unittest1 dominion.c unittest1.c rngs.o $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "unittest2.c" >> unittestresults.out
	gcc -o unittest2 dominion.c unittest2.c rngs.o $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "unittest3.c" >> unittestresults.out
	gcc -o unittest3 dominion.c unittest3.c rngs.o $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "unittest4.c" >> unittestresults.out
	gcc -o unittest4 dominion.c unittest4.c rngs.o $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out 

	echo "cardtest1.c" >> unittestresults.out
	gcc -o cardtest1 cardtest1.c dominion.c rngs.o $(CFLAGS)
	./cardtest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "cardtest2.c" >> unittestresults.out
	gcc -o cardtest2 cardtest2.c dominion.c rngs.o $(CFLAGS)
	./cardtest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "cardtest3.c" >> unittestresults.out
	gcc -o cardtest3 cardtest3.c dominion.c rngs.o $(CFLAGS)
	./cardtest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "cardtest4.c" >> unittestresults.out
	gcc -o cardtest4 cardtest4.c dominion.c rngs.o $(CFLAGS)
	./cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe 

