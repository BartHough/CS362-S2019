#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar(){
  // TODO: rewrite this function
  //Gets a random char with ascii value bewteen 0 and 127
  char ch = rand() %127;

  return ch;
}

char *inputString(){
  // TODO: rewrite this function
  //Setting size of string to fixed length of 6
  char str[6];
  
  //Set of all lowercase letters 
  const char charset[] = "abcdefghijklmnopqrstuvwxyz";
  
  //Loops through all but the last letter in str
  //randomly gets one of the letters in about a 3 letter range from the desired letters (reset)
  for (size_t n = 0; n < 5; n++) {
    int key;
    
    //first letter in str
    if(n==0){
      //random from p to t
      key = rand() % (int) (sizeof charset - 7) + 15;
    }
    //second letter in str
    else if(n==1){
      //random from d to g
      key = rand() % 6 + 3;
    } 
    //third letter
    else if(n==2){
      //random from q to u
      key = rand() % (int)(sizeof charset - 6) + 16;
    }
    //fourth letter
    else if(n==3){
      //random from d to g 
      key = rand() % 6 + 3;
    } 
    //fifth letter
    else{
      //random from r to v
      key = rand() % (int) (sizeof charset - 5) + 17;
    }
    str[n] = charset[key];
  }
  
  //Last letter is always null terminator
  str[5] = '\0';
  
  return str;
}

void testme(){
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1){
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);
    
    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'&& s[2] == 's' && s[3] == 'e'&& s[4] == 't' && s[5] == '\0'&& state == 9){
      printf("error ");
      exit(200);
    }
  }
}

int main(int argc, char *argv[]){
  srand(time(NULL));
  testme();
  
  return 0;
}
