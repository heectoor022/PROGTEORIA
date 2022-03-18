
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
  Stack *s;
  s = stack_init();
  int i;
  if (s == NULL)
    return NULL;
  char *resultado;
  int dimension = strlen(str);

  resultado = (char*)malloc((dimension+1)*sizeof(char*));

  if(resultado == NULL)
    return NULL;
  
  for(i = 0; i < dimension; i++){  
    if(stack_push(s, &str[i]) == ERROR)
      return NULL;
    
  }

  for(i = 0; i < dimension; i++){
    if(stack_isEmpty(s) == FALSE){
      resultado[i] = *(char*)stack_pop(s);
      if(&resultado[i] == NULL)
        return NULL;
    }
  }
  
  if(stack_isEmpty(s) == TRUE){
    stack_free(s);
    return resultado;
  }

  return NULL;

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
  int i, j;
  Stack *s;
  char *e;
  s = stack_init ();
  if (s == NULL)
    return ERROR;
  for (i = 0; i < strlen(strin); i++){
    if(strin[i] != ' '){
      if(stack_push(s, &strin[i]) == ERROR) 
        return ERROR;
      else{
        while (stack_isEmpty (s) == FALSE)
        {
          e = stack_pop(s);
          if(e == NULL)
            return ERROR;
          strout[j] = *e;
          j++;          
        }
        strout[j] = 32;
        j++;
       
      }   
    }
  }
  while(stack_isEmpty(s) == FALSE){
    e = stack_pop(s);
    if(e == NULL)
      return ERROR;
    strout[j] = *e;
    j++;
  }
  stack_free (s);
  return OK;

};