/* -----------------------------------------------------------------------
 * Card test 2
 * Testing the refactored "adventurer" card
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
  int temphand[MAX_HAND];
  int drawntreasure=0;
  struct gameState G, testG;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,sea_hag, tribute, smithy, council_room};
  // initialize a game state and player cards
  initializeGame(numPlayers, k, seed, &G);
  memcpy(&testG, &G, sizeof(struct gameState));
  
  
   
   
  //Testing that the player gets rid of cards on large scale
  printf("\ntesting decrementing hand count of adventurer function\n");
  int playerHandCount;
  for(int i=0; i<5; i++){ 
    int playerHandCount= testG.handCount[1];
    adventurerFxn(drawntreasure, &testG, 1, 3, temphand, 0);
  
    printf("expected: less than %d ", playerHandCount);
    printf("got: %d \n", testG.handCount[1]);
    if(playerHandCount > testG.handCount[1]){
      printf("PASSED\n");
    }
    else{
      printf("FAILED\n");
    }
  }
  
  //Testing to make sure that if a deck is empty, the discard cards are shuffeled back in
  memcpy(&testG, &G, sizeof(struct gameState));
  testG.deckCount[1] = 0;
  adventurerFxn(drawntreasure, &testG, 1, 3, temphand, 0);
  printf("\ntesting suffle discards called in adventurer function\n");

  printf("expected: less than %d ", playerHandCount);
  printf("got: %d \n", testG.handCount[1]);
  if(playerHandCount > testG.handCount[1]){
    printf("PASSED\n");
  }
  else{
    printf("FAILED\n");
  }

}
