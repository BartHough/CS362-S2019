/* -----------------------------------------------------------------------
 * Random test for refactored adventurer card 
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
  int temphand[MAX_HAND];
  int thisPlayer = 0;
  int drawntreasure = 0;
  struct gameState G, testG;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,sea_hag, tribute, smithy, council_room};
  // initialize a game state and player cards
  initializeGame(numPlayers, k, seed, &G);
  memcpy(&testG, &G, sizeof(struct gameState));
   


  //Testing the adventurer function increasing the number of actions by n
  memcpy(&testG, &G, sizeof(struct gameState));
  numActions = testG.numActions;
  n=0;
  for(int i=0; i<35; i++){
    numActions++;
    adventurerFxn(drawntreasure, &testG, 1, 3, temphand, 0);
    n+= drawntreasure;
  }
  printf("\nTesting that adventurer function increases number of treasure cards\n");
  printf("expected: %d ", 35*4);
  printf("got: %d \n", n);
  if(n == (35*4)){
    printf("PASSED\n");
  }
  else{
    printf("FAILED\n");
  }

}
