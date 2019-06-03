/* -----------------------------------------------------------------------
 * Unit test 3/
 * Testing the refactored "village" card function, called "villageFxn" 
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
   
  //Testing that the player draws a card
  int playerHandCount= testG.handCount[1];
  playerHandCount++;
  villageFxn(1, &testG, 1);
  printf("\ntesting that player draws card in village card function\n");
  printf("expected: %d ", playerHandCount);
  printf("got: %d \n", testG.handCount[1]);
  if(playerHandCount == testG.handCount[1]){
    printf("PASSED\n");
  }
  else{
    printf("FAILED\n");
  }

  //Testing the village function increasing the number of actions by two
  memcpy(&testG, &G, sizeof(struct gameState));
  int numActions = testG.numActions;
  numActions++;
  numActions++;
  villageFxn(1, &testG, 1);
  printf("\nTesting that village function increases number of actions by two\n");
  printf("expected: %d ", numActions);
  printf("got: %d \n", testG.numActions);
  if(numActions == testG.numActions){
    printf("PASSED\n");
  }
  else{
    printf("FAILED\n");
  }

   
  //Testing that the player draws two cards
  playerHandCount= testG.handCount[1];
  playerHandCount++;
  playerHandCount++;
  villageFxn(1, &testG, 1);
  villageFxn(1, &testG, 1);
  printf("\ntesting player handcount in village function\n");
  printf("expected: %d ", playerHandCount);
  printf("got: %d \n", testG.handCount[1]);
  if(playerHandCount == testG.handCount[1]){
    printf("PASSED\n");
  }
  else{
    printf("FAILED\n");
  }

  //Testing the village function increasing the number of actions by 2n
  memcpy(&testG, &G, sizeof(struct gameState));
  numActions = testG.numActions;
  for(int i=0; i<35; i++){
    numActions++;
    numActions++;
    villageFxn(1, &testG, 1);
  }
  printf("\nTesting that village function increases number of actions\n");
  printf("expected: %d ", numActions);
  printf("got: %d \n", testG.numActions);
  if(numActions == testG.numActions){
    printf("PASSED\n");
  }
  else{
    printf("FAILED\n");
  }

}
