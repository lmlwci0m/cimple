/*
 * data: implementation of persistent storage
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

int main(int argc, char * argv[]) {

  int retval;

  uint32_t status;

  status = 1;

  errno = 0;
  retval = fprintf(stdout, "%d\n", status);
  if (errno != 0 || retval < 0) {
    perror("Error during fprintf");
    exit(EXIT_FAILURE);
  }

  

  return EXIT_SUCCESS;
}
