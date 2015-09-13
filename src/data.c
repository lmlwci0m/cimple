/*
 * data: implementation of persistent storage
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include "data_utils.h"

int main(int argc, char * argv[]) {

  struct _status {uint32_t value; uint32_t id;} status;

  int retval;

  status = (struct _status) {1, 2};

  errno = 0;
  retval = fprintf(stdout, "%d\n", status.value);
  if (errno != 0 || retval < 0) {
    perror("Error during fprintf");
    exit(EXIT_FAILURE);
  }

  data_ptr node = create_data("11", "pippo");
  
  fprintf(stdout, "id: %s\n", node->id);
  fprintf(stdout, "key: %s\n", node->key);
  fprintf(stdout, "value: %s\n", node->value);

  deallocate_data(node);

  return EXIT_SUCCESS;
}
