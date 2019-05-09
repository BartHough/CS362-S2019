#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar(){
  // TODO: rewrite this function
  char ch = rand() %127;

  return ch;
}

char *inputString(){
  // TODO: rewrite this function
  char str[6];
  const char charset[] = "abcdefghijklmnopqrstuvwxyz";
  //int n;
  for (size_t n = 0; n < 5; n++) {
    int key;
    if(n==0){
      key = rand() % (int) (sizeof charset - 7) + 15;
    }
    else if(n==1){
      key = rand() % 6 + 3;
    } 
    else if(n==2){
      key = rand() % (int)(sizeof charset - 6) + 16;
    }
    else if(n==3){
      key = rand() % 6 + 3;
    } 
    else{
      key = rand() % (int) (sizeof charset - 5) + 17;
    }



    str[n] = charset[key];
  }
  str[5] = '\0';
  
  /*  int i;
  for(i=0; i<5; i++){
    str[i]=(char) rand()%122 + 97;
  }
  str[5] = '\0';*/
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
