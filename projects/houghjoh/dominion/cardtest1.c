/* -----------------------------------------------------------------------
 * Card test 1/
 * Testing the refactored "Council_Room" card, located within cardEffect 
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main(){
  
  int newCards = 0;
  int discarded = 1;
  int xtraCoins = 0;
  int shuffledCards = 0;
  int i, j, m;
  int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
  int remove1, remove2;
  int seed = 10;
  int numPlayers = 2;
  int thisPlayer = 0;
  struct gameState G, testG;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,sea_hag, tribute, smithy, council_room};
  // initialize a game state and player cards
  initializeGame(numPlayers, k, seed, &G);
  memcpy(&testG, &G, sizeof(struct gameState));
  
  
   
   
  //Testing that numBuys increases
  int numBy=testG.numBuys;
  numBy++;
  cardEffect(8, choice1, choice2, choice3, &testG, handpos, &bonus);
  printf("\ntesting that numbuys increases\n");
  printf("expected: %d ", numBy);
  printf("got: %d \n", testG.numBuys);
  if(numBy == testG.numBuys){
    printf("PASSED\n");
  }
  else{
    printf("FAILED\n");
  }
  
  //Testing that numBuys increases
  numBy=testG.numBuys;
  for(int i=0; i<100; i++){
    numBy++;
    cardEffect(8, choice1, choice2, choice3, &testG, handpos, &bonus);
  }
  printf("\ntesting that numbuys increases\n");
  printf("expected: %d ", numBy);
  printf("got: %d \n", testG.numBuys);
  if(numBy == testG.numBuys){
    printf("PASSED\n");
  }
  else{
    printf("FAILED\n");
  }
  
  //Same test but with weird choice values
  numBy=testG.numBuys;
  for(int i=0; i<100; i++){
    numBy++;
    cardEffect(8, 150, -1, 100, &testG, handpos, &bonus);
  }
  printf("\ntesting that numbuys increases\n");
  printf("expected: %d ", numBy);
  printf("got: %d \n", testG.numBuys);
  if(numBy == testG.numBuys){
    printf("PASSED\n");
  }
  else{
    printf("FAILED\n");
  }
  
  //Same test but with different handPos
  int numBy=testG.numBuys;
  for(int i=0; i<100; i++){
    numBy++;
    cardEffect(8, choice1, choice2, choice3, &testG, 7, &bonus);
  }
  printf("\ntesting that numbuys increases\n");
  printf("expected: %d ", numBy);
  printf("got: %d \n", testG.numBuys);
  if(numBy == testG.numBuys){
    printf("PASSED\n");
  }
  else{
    printf("FAILED\n");
  }
  
