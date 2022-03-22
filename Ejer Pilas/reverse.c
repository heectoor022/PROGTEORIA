
#include "stack_fDoble.h"
#include "reverse.h"

/* Include here any other headers you need */

/**
 * @brief: Reverses a string
 * @param str, String to reverse
 * @return A newly allocated string with the reversed string
 **/

char *string_invert(char *str) {

  /* It is MANDATORY that you use a stack to implement this function */
  /* Failure to do so will result in a FAIL grade */

  /* Es OBLIGATORIO usar una pila para implementar esta función */
  /* No hacerlo implica un NO APTO */

  /*YOUR CODE HERE - TU CÓDIGO AQUÍ */
  if(str == NULL)
    return NULL;
  Stack *s;
  s = stack_init();
  int i;
  if (s == NULL)
    return NULL;
  char *resultado;
  int dimension = strlen(str);

  resultado = (char*)malloc((dimension+1)*sizeof(char));

  if(resultado == NULL){
    stack_free(s);
    return NULL;
  }
  
  for(i = 0; str[i] != '\0'; i++){  
    if(stack_push(s, &str[i]) == ERROR){
      stack_free(s);
      return NULL;
    }
    
  }

  for(i = 0; stack_isEmpty(s) == FALSE; i++){
    resultado[i] = *(char*)stack_pop(s);
    if(&resultado[i] == NULL){     
      stack_free(s); 
      return NULL;
    }
  }
  resultado[i] = '\0';
  
  stack_free(s);
  return resultado;

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
  /* It is MANDATORY that you use a stack to implement this function */
  /* Failure to do so will result in a FAIL grade */

  /* Es OBLIGATORIO usar una pila para implementar esta función */
  /* No hacerlo implica un NO APTO */

  /* YOUR CODE HERE - TU CÓDIGO AQUÍ */
  if(strout == NULL || strin == NULL)
    return ERROR;
  int i, j = 0;
  Stack *s;
  char *e;
  s = stack_init ();
  if (s == NULL)
    return ERROR;
  for (i = 0; i < strlen(strin); i++){
    if(strin[i] != ' '){
      if(stack_push(s, &strin[i]) == ERROR){
        stack_free(s);
        return ERROR;
      }
    }
    if(strin[i] == ' '){
      while (stack_isEmpty (s) == FALSE)
      {
        e = stack_pop(s);
          if(e == NULL){   
            stack_free(s);        
            return ERROR;
          }
        strout[j] = *e;
        j++;          
      }
      strout[j] = 32;
      j++;       
    }   
    
  }
  while(stack_isEmpty(s) == FALSE){
    e = stack_pop(s);
    if(e == NULL){
      stack_free(s);
      return ERROR;
    }
    strout[j] = *e;
    j++;
  }
  strout[j] = '\0';
  stack_free (s);
  return OK;

};