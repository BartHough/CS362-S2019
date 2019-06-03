/* -----------------------------------------------------------------------
 * random card test 1
 * Testing the refactored "Great Hall" card function, called "GreathallFxn" 
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
  int thisPlayer = 0;
  struct gameState G, testG;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,sea_hag, tribute, smithy, council_room};
  // initialize a game state and player cards
  initializeGame(numPlayers, k, seed, &G);
     

  //Randomly testing the greathall function increasing the number of actions
  int failedFlag=0;
  for(int j=0; j< 10000; j++){ 
    memcpy(&testG, &G, sizeof(struct gameState));
    int numActions = testG.numActions;
    testG.coins = rand() % 25+1;
    testG.numPlayers = rand() % 10+1;
    int curPlayer = rand() % testG.numPlayers +1;
    for(int i=0; i<35; i++){
      numActions++;
      greatHallFxn(curPlayer, &testG, 1);
    }
    //printf("\nTesting that greatHall function increases number of actions\n");
    //printf("expected: %d ", numActions);
    //printf("got: %d \n", testG.numActions);
    if(numActions == testG.numActions){
      continue;
    }
    else{
      failedFlag=1;
    }
  }
  if(failedFlag ==1){
    printf("TESTFAILED\n");
  }
  else{
    printf("TESTSPASSED\n");
  }

}
