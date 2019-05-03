/* -----------------------------------------------------------------------
 * Card test 2
 * Testing the refactored "Sea_hag" card, located within cardEffect 
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
  
  
   
   
  //Testing that discard increases by the number of players (2) minus current player
  int discard=testG.discardCount[1];
  discard+=1;
  cardEffect(25, choice1, choice2, choice3, &testG, handpos, &bonus);
  printf("\ntesting that discard increases\n");
  printf("expected: %d ", discard);
  printf("got: %d \n", testG.discardCount[1]);
  if(discard == testG.discardCount[1]){
    printf("PASSED\n");
  }
  else{
    printf("FAILED\n");
  }
  
  //Testing that discard increases by various numbers of players
  printf("\ntesting that discard increases\n");
  for(int i=3; i <10; i++){
    initializeGame(i, k, seed, &G);
    discard=G.discardCount[1];
    discard+=(i-2);
    cardEffect(25, choice1, choice2, choice3, &G, handpos, &bonus);
    printf("expected: %d ", discard);
    printf("got: %d \n", G.discardCount[1]);
    if(discard == G.discardCount[1]){
      printf("PASSED\n");
    }
    else{
      printf("FAILED\n");
    }
  }

}
