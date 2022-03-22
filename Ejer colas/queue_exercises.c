#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "types.h"

/* Include here any other headers you need */

/**
 * @brief Returns a new queue that interleaves the elements in the first and 
 * second halves of a queue.
 *
 * Examples:
 *
 * Input:  [1, 2, 3, 4, 5, 6]
 * Output: [1, 4, 2, 5, 3, 6]
 *
 * Input:  [1, 2, 3, 4, 5]
 * Output: [1, 4, 2, 5, 3]
 *
 * @see https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/
 *
 * @param q, pointer to the queue.
 *
 * @return A new queue with the elements in the first and second halves of q
 * interleaved. See example above.
 **/
Queue *interleave(Queue *q) {
  Queue *qinter = NULL;
  Queue *aux = NULL;
  
  
  qinter = queue_new();
  if (!qinter) {
    return NULL;
  }
  aux = queue_new();
  if(!aux)
    return NULL;
  
  
  while(*(int*)queue_getFront(q) < (int)queue_size(q)/2){
    if(queue_push(aux, queue_pop(q)) == ERROR)
      return NULL;
  };

  while(*(int*)queue_getFront(qinter) < (int)queue_size(q)){
    if(queue_push(qinter, queue_pop(aux)) == ERROR)
      return NULL;
    if(queue_push(qinter, queue_pop(q)) == ERROR)
      return NULL;
  };

  queue_free(q);
  queue_free(aux);
  

  return qinter;
}

/**
 * @brief Concatenates two queues by adding all the elements in the second queue
 * to the first one. Upon successful exit the first queue will contain the 
 * elements from both queues and the second queue will be empty. In case of 
 * error the two queues will be unchanged.
 *
 * Example:
 *
 * Before concatenation: qa = [1, 2, 3, 4, 5, 6]
 *                       qb = [1, 2, 3, 4]
 *
 * After concatenation:  qa = [1, 2, 3, 4, 5, 6, 1, 2, 3, 4]
 *                       qb = []
 *
 * @param qa, pointer to the first queue.
 * @param qb, pointer to the second queue.
 *
 * @return OK on success, ERROR if there is any error. In case of error the 
 * contents of both queues must remain unchanged.
 **/
Status concatenate(Queue *qa, Queue *qb) {

  /*YOUR CODE HERE - TU CÓDIGO AQUÍ */

  return OK;
}
