/*
 * sequence: simple input program
 */
 
#include <stdio.h>
#include <stdlib.h>

#define MAX_SCANF_LEN 4096

int main(int argc, char * argv[]) {

  char * scanf_input;
  int nchars;
  long seq_len;
  
  /*
   * Allocation for buffer for receiving input from stdin
   */
  scanf_input = (char *) malloc(MAX_SCANF_LEN * sizeof(char));
  if (scanf_input == NULL) {
    fprintf(stdout, "Error during input allocation\n");
    exit(EXIT_FAILURE);
  }
  scanf_input = (char *) memset(scanf_input, 0, MAX_SCANF_LEN * sizeof(char));
  
  /*
   * Acquisition and conversion of console input (stdin)
   */
  nchars = fscanf(stdin, "%s", scanf_input);
  seq_len = atol(scanf_input);
  fprintf(stdout, "Sequence length: %li\n", seq_len);
  
  for (; seq_len > 0; seq_len--) {
    printf("%li\n", seq_len);
  }
  
  /*
   * Deallocation of resources
   */
  free(scanf_input);
  
  return EXIT_SUCCESS;
  
}