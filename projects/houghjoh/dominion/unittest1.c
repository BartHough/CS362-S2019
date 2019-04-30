/* -----------------------------------------------------------------------
 * Unit test 1/
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
  greatHallFxn(1, &testG, 1);
  printf("\ntesting hand count of greatHall function\n");
  printf("expected: %d ", playerHandCount);
  printf("got: %d \n", testG.handCount[1]);
  if(playerHandCount == testG.handCount[1]){
    printf("PASSED\n");
  }
  else{
    printf("FAILED\n");
  }

  //Testing the greathall function increasing the number of actions by one
  memcpy(&testG, &G, sizeof(struct gameState));
  int numActions = testG.numActions;
  numActions++;
  greatHallFxn(1, &testG, 1);
  printf("\nTesting that greatHall function increases number of actions\n");
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
  greatHallFxn(1, &testG, 1);
  greatHallFxn(1, &testG, 1);
  printf("\ntesting hand count of greatHall function\n");
  printf("expected: %d ", playerHandCount);
  printf("got: %d \n", testG.handCount[1]);
  if(playerHandCount == testG.handCount[1]){
    printf("PASSED\n");
  }
  else{
    printf("FAILED\n");
  }

  //Testing the greathall function increasing the number of actions by n
  memcpy(&testG, &G, sizeof(struct gameState));
  numActions = testG.numActions;
  for(int i=0; i<35; i++){
    numActions++;
    greatHallFxn(1, &testG, 1);
  }
  printf("\nTesting that greatHall function increases number of actions\n");
  printf("expected: %d ", numActions);
  printf("got: %d \n", testG.numActions);
  if(numActions == testG.numActions){
    printf("PASSED\n");
  }
  else{
    printf("FAILED\n");
  }

}
