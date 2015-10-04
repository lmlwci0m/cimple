
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
 * Classical linked list with each node containing:
 * an array of integers
 * the number of elements considered from the start
 * (ELEMENTS_LEN - data_list_element.len is wasted - 
 * the strategy is to have maximum 4096 elements wasted for ease of
 * algorithms implementations)
 */
typedef struct _data_list_element {
  int * elements;
  int len;
  struct _data_list_element * next;
} data_list_element;

typedef data_list_element * data_list; /* pointer to linked list */

#define ELEMENT_SIZE 4096 /* buffer size */

data_list malloc_data_list();

int * malloc_elements();

int * memset_elements(int *);

data_list init_data_list();

void add_new(data_list);

int sum_all(data_list);

