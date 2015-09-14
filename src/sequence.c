/*
 * sequence: simple input program
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SCANF_LEN 4096

int main(int argc, char * argv[]) {

  char value;

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

  value = 1;

  /*
   * 0x00 00000000
   * 0x01 00000001
   * 0x02 00000010
   * 0x04 00000100
   * 0x08 00001000
   * 0xF0 00010000
   */

  value = value & 0x0;

  printf("%d %x\n", 256, 255);
  printf("%d \n", 0x0f);
  
  return EXIT_SUCCESS;
  
}
