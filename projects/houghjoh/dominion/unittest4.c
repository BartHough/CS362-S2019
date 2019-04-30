/* -----------------------------------------------------------------------
 * Unit test 4/
 * Testing the refactored "smithy" card function, called "smithyFxn" 
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
  playerHandCount++;
  playerHandCount++;
  smithyFxn(1, &testG, 1);
  printf("\ntesting that player draws three cards in smithy card function\n");
  printf("expected: %d ", playerHandCount);
  printf("got: %d \n", testG.handCount[1]);
  if(playerHandCount == testG.handCount[1]){
    printf("PASSED\n");
  }
  else{
    printf("FAILED\n");
  }

  //Testing the smithy function discards card
  memcpy(&testG, &G, sizeof(struct gameState));
  int count = testG.handCount[1];
  count--;
  smithyFxn(1, &testG, 1);
  printf("\nTesting that smithy function discards a card\n");
  printf("expected: %d ", count);
  printf("got: %d \n", testG.handCount[1]);
  if(count == testG.handCount[1]){
    printf("PASSED\n");
  }
  else{
    printf("FAILED\n");
  }

   
  //Testing that the player draws six cards
  playerHandCount= testG.handCount[1];
  for(int i=0; i<6; i++){
    playerHandCount++;
  }
  smithyFxn(1, &testG, 1);
  smithyFxn(1, &testG, 1);
  printf("\ntesting player handcount in smithy function\n");
  printf("expected: %d ", playerHandCount);
  printf("got: %d \n", testG.handCount[1]);
  if(playerHandCount == testG.handCount[1]){
    printf("PASSED\n");
  }
  else{
    printf("FAILED\n");
  }

  //Testing the smithy function discards the n cards
  memcpy(&testG, &G, sizeof(struct gameState));
  count = testG.handCount[1];
  for(int i=0; i<35; i++){
    count--;
    smithyFxn(1, &testG, 1);
  }
  printf("\nTesting that smithy function discards cards\n");
  printf("expected: %d ", count);
  printf("got: %d \n", testG.handCount[1]);
  if(count == testG.handCount[1]){
    printf("PASSED\n");
  }
  else{
    printf("FAILED\n");
  }

}
