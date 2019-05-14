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
  srand(time(NULL));
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

  //Testing the adventurer function increasing the number of actions by n
  int failedFlag=0;

  for(int j=0; j<10000; j++){
    memcpy(&testG, &G, sizeof(struct gameState));
    int numActions = testG.numActions;
    testG.phase = rand() % 10 +1;
    testG.numPlayers = rand() % 10+1;
    drawntreasure = rand() % 5;
    int curPlayer = rand() % testG.numPlayers + 1;
    int cardDrawn = rand() % 7 +1;
    int n=0;
    for(int i=0; i<35; i++){
      numActions++;
      adventurerFxn(drawntreasure, &testG, curPlayer, cardDrawn, temphand, 0);
      n+= drawntreasure;
    }
    //printf("\nTesting that adventurer function increases number of treasure cards\n");
    //printf("expected: %d ", 35*4);
    //printf("got: %d \n", n);
    if(n == (35*4)){
      continue;
    }
    else{
      failedFlag=1;
    }
  }
  if(failedFlag == 1){
    printf("TESTS FAILED\n");
  }
  else{
    printf("TESTS PASSED\n");
  }

}
