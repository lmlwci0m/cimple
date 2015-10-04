#include "intseq.h"

/*
 * wrapper for data_list malloc
 */
data_list malloc_data_list() {
  return (data_list) malloc(sizeof(data_list_element));
}

/*
 * wrapper for int * malloc
 */
int * malloc_elements() {
  return (int *) malloc(ELEMENT_SIZE * sizeof(int));
}

/*
 * wrapper for int * memset
 */
int * memset_elements(int * elements) {
  elements = memset(elements, 0, ELEMENT_SIZE * sizeof(int));
  return elements;
}

/*
 * Initalizes a data_list pointer with a single node
 */
data_list init_data_list() {
  data_list retval;
  
  retval = malloc_data_list();
  if (retval == NULL) {
    perror("Error allocating data list\n");
    return NULL;
  }
  
  retval->elements = malloc_elements();
  if (retval->elements == NULL) {
    perror("Error allocating elements\n");
    free(retval);
    return NULL;
  }
  
  retval->elements = memset_elements(retval->elements);
  retval->len = 0; /* start with no elements - maximum wasted space */
  retval->next = NULL;
  
  return retval;
  
}

/*
 * Add a new node to the end of the list.
 */
void add_new(data_list dl) {
  data_list cursor;
  
  cursor = dl;
  while (cursor->next != NULL) {
    cursor = cursor->next;
  }
  cursor->next = init_data_list();
  if (cursor->next == NULL) {
    perror("Error allocating new data list\n");
  }
  
}

/*
 * Make a sum of all *considered* elements inside all nodes of the data list
 */
int sum_all(data_list dl) {
  int retval, i;

  retval = 0;
  do {

    /*
     * *non considered* elements of a node(the last one) are ignored
     */
    for (i = 0; i < dl->len; i++) {
      retval += dl->elements[i];
    }
    dl = dl->next; /* go to the next node */

  } while (dl != NULL);
  
  return retval;
}
