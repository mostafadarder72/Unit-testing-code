#include "stdio.h"
#include <string.h>
#include <stdlib.h>

#define TRUE 1 
#define FALSE 0
#define UNDEF -1
/*
    {1,2} 2! 2x1 2 {1,2} {2,1}
    {1,2,3} 3! 3x2x1 {1,2,3} {1,3,2} {2,1,3} {2,3,1} {3,1,2} {3,2,1}
    {1,2,3,4} 4! 4x3x2 24
    
    {1,2,3} {3,2,1}
    {2,3,1} {2,1,3}
    {1,2,3} {1,2,3}
*/

char* sort(char* target){
  
  int length = strlen(target);
  int swapped = 0;
  int temporaryValue = 0;
  do{
    swapped = 0;
    
    //1,2,5,3,6,7
    //1,2,3,5,6,7
    for(int i=0;i<(length-1);i++){
      if(target[i] > target[i+1]){
        temporaryValue = target[i];
        target[i] = target[i+1];
        target[i+1] = temporaryValue;
        swapped = 1;
      }
    }
  }
  while(swapped != 0);
  
  return target;
}

int isPermutationOf(const char* s1, const char* s2){
  char* ps1 ; // = malloc(sizeof(s1[0]) * strlen(s1));
  char* ps2 ; //= malloc(sizeof(s2[0]) * strlen(s2));
  
  if(strlen(s1) == 0 || strlen(s2) == 0){
    return FALSE;
  }
  
  if(strlen(s1) != strlen(s2)){
    return FALSE;
  }
  
  ps1 = (char*)malloc(sizeof(s1[0]) * (strlen(s1)+1));
  
  if(ps1 == NULL){
    return UNDEF;
  }
  
  ps2 = (char*)malloc(sizeof(s2[0]) * (strlen(s2)+1));
  
  if(ps2 == NULL){
    free(ps1);  //obviously ps1 allocated memory since it made it this far
                //but since ps2 did not we still have to free ps1 before returning
    return UNDEF;
  }
  
  strcpy(ps1, s1);
  strcpy(ps2, s2);
  
  sort(ps1);
  sort(ps2);
  
  if(strcmp(ps1, ps2) == 0){
    free(ps1);
    free(ps2);
    return TRUE;
  }
  
  free(ps1);
  free(ps2);
  return FALSE;
}

void test(int expected, int actual, const char* testName){
  if(expected == actual){
    printf("\nPASSED %s", testName);
  }
  else{
    printf("\nFAILED %s ", testName);
    printf("\n   expected: %d actual: %d", expected, actual);
  }
}

int main(void) {
  
  test(TRUE, isPermutationOf("a", "a"), "a");
  test(TRUE, isPermutationOf("abc", "abc"), "abc");
  test(TRUE, isPermutationOf("cab", "bac"), "cab=>bac");
  test(FALSE, isPermutationOf("c", "b"), "c=>b");
  test(TRUE, isPermutationOf("abcdefg", "gfedcba"), "abcdefg");
  test(FALSE, isPermutationOf("", "abc"), "1 is empty");
  test(FALSE, isPermutationOf("abc", ""), "2 is empty");
  test(FALSE, isPermutationOf("", ""), "1 and 2 are empty");
  test(FALSE, isPermutationOf("abc", "ab"), "abc=>ab");
  test(TRUE, isPermutationOf("123456789", "987654321"), "123456789");
  
  
  
  
  
  return 0;
}
