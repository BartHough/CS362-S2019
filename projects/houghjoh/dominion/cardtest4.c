/* -----------------------------------------------------------------------
 * Card test 4/
 * Testing the refactored "smithy" card 
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
   
   
  //Testing that the current players hand is decremented
  int playerHand= testG.hand[1][handpos];
  playerHand--;
  smithyFxn(1, &testG, 1);
  printf("\ntesting that players hand is decremented in smithy card function\n");
  printf("expected: %d ", playerHand);
  printf("got: %d \n", testG.hand[1][handpos]);
  if(playerHand == testG.hand[1][handpos]){
    printf("PASSED\n");
  }
  else{
    printf("FAILED\n");
  }

  //Testing that the current players hand is decremented multiple times
  memcpy(&testG, &G, sizeof(struct gameState));
  printf("\ntesting that players hand is decremented in smithy card function\n");
  for(int i=0; i<5; i++){
    playerHand= testG.hand[1][handpos];
    playerHand--;
    smithyFxn(1, &testG, 1);
    printf("expected: %d ", playerHand);
    printf("got: %d \n", testG.hand[1][handpos]);
    if(playerHand == testG.hand[1][handpos]){
      printf("PASSED\n");
    }
    else{
      printf("FAILED\n");
    }
  }

}
