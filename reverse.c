
#include "stack_fDoble.h"
#include <stdlib.h>
#include <string.h>
/* Include here any other headers you need */

/**
 * @brief: Reverses a string
 * @param str, String to reverse
 * @return A newly allocated string with the reversed string
 **/

char *string_invert(char *str) {
  
  str = (char*)malloc((strlen(str)+1)*sizeof(char));
  if(str == NULL)
    return NULL;
  char *res;
  res = (char*)malloc((strlen(str)+1)*sizeof(char));
  if (salida == NULL)
    return NULL;
  Stack *s;
  int i;
  s = stack_init();
  if(s == NULL)
    return NULL;
  for(i = 0; str[i]!='\0'; i++){
    if(stack_isFull(s) == FALSE)
      if(stack_push(s, &str[i])== ERROR)
        return ERROR;
  }
  for(i = 0;stack_isEmpty(s) == FALSE;i++){
    res[i] = *(char*)stack_pop(s);
  }
  stack_free(s);
  return res;
}

/**
 * @brief: Reverse the words of an input string to an output string.
 *
 * @example: "Hello World" => "olleH dlroW"
 * The words in the input string are separated by a space character.
 * The strings may not overlap, and the destination string strout
 * must be large enough to receive the inverted expression.
 *
 * @param strout, Pointer to the output buffer
 * @param strin, Pointer to the input expression
 * @return The function returns OK or ERROR
 **/

Status reverseWords(char *strout, char *strin) {
  strout = (char*)malloc(strlen(strin)*sizeof(char));
  strin = (char*)malloc(strlen(strin)*sizeof(char));
  if(strout == NULL || strin == NULL)
    return NULL;
  char *p1, *
  strtok(strin, "\0");
  
  

  return ERROR; // remove this line once you add your code
};