/*
 * integer_sum: get a text file composed by an integer for very line
 * and calculates the sum of the integers
 */

#include <stdio.h>
//#include <ctype.h>
#include <errno.h>
#include "intseq.h"

int __program_error = 0;
#define __PROGRAM_ERROR_NOERROR 0
#define __PROGRAM_ERROR_ERROR -1
#define IS_ERROR() __program_error == __PROGRAM_ERROR_ERROR
#define SET_ERROR() __program_error = __PROGRAM_ERROR_ERROR

void program_sum_integers(char * filename) {
  
  FILE * fp;
  int current;
  int index;
  int retval;
  int scancheck;
  
  /*
   * Data elements container initliazation
   */
  data_list el = init_data_list();
  data_list cursor = el;
  
  /*
   * Data file opening
   */
  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file\n");
    return;
  }
  
  /*
   * Start reading while end of file is not reached
   */
  index = 0;
  while (!feof(fp)) {
 
    /*
     * Counter has reached max elements for a node
     * a new one is created and passing cursor to next node
     */
    if (index == ELEMENT_SIZE) {
      index = 0;
      add_new(el);
      cursor = cursor->next;
    }

    /*
     * getting data, put into node elements, increasing counter
     */
    errno = 0;
    scancheck = fscanf(fp, "%d\n", &current);
    if (scancheck != 1) {
      if (scancheck == EOF) {
	SET_ERROR();
	perror("Error reading file\n");
	break;
      }
    }
    cursor->elements[index] = current;
    index++;
    cursor->len++;

  }
  
  /*
   * Closing data file
   */
  retval = fclose(fp);
  if (retval == EOF) {
    perror("Error closing file\n");
    return;
  }

  if (IS_ERROR()) {
    fprintf(stdout, "Not executing sum due to an error in the application.\n");
  } else {
  
    /*
     * Getting sum
     */
    fprintf(stdout, "sum all: %d\n", sum_all(el));
  }
}

int main(int argc, char * argv[]) {
  
  if (argc > 1) {
    program_sum_integers(argv[1]);
  } else {
    fprintf(stdout, "A filename argument is required!\n");
  }
  return EXIT_SUCCESS;
  
}
