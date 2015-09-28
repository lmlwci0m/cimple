#include "data_utils.h"
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/*
 * Gets a timespec and returns a single value converting to microseconds.
 */
int64_t convert_to_microseconds(struct timespec * tms) {
  int64_t micros = tms->tv_sec * 1000000; /* convert seconds to microseconds*/

  micros += tms->tv_nsec / 1000; /* convert nanoseconds to microseconds */

  if (tms->tv_nsec % 1000 >= 500) {
    /* rounding up */
    ++micros;
  }

  return micros;

}

/*
 * Returns timestamp in POSIX 1.2008 format
 */
int64_t get_timestamp_posix() {
  struct timespec tms;
  int retval;

  retval = clock_gettime(CLOCK_REALTIME, &tms);
  if (retval == 0) {
    return FUNC_ERR;
  }

  return convert_to_microseconds(&tms);

}

/*
 * Converts a long value to string. The string is initialized
 * and returned as pointer to char.
 */
char * long2string(long value) {
  char * retval;
  int nchars;
  const int n = snprintf(NULL, 0, "%li", value); /* Obtain long lenght as string */

  /*
   * Allocates memory for string
   */
  retval = (char *) malloc((n + 1) * sizeof(char));
  if (retval == NULL) {
    fprintf(stderr, "Error during allocation in long2string!\n");
    return NULL;
  }

  /*
   * Real conversion
   */
  nchars = snprintf(retval, n + 1, "%li", value);
  if (nchars != n) {
    free(retval);
    fprintf(stderr, "Error during string format in long2string!\n");
    return NULL;
  }
  
  return retval;

}

data_ptr create_data(const char * key, const char * value) {
  
  time_t ts;
  long seconds;

  size_t key_len;
  size_t value_len;

  data_ptr retval;

  retval = (data_ptr) malloc(sizeof(data));
  if (retval == NULL) {
    fprintf(stderr, "Error during allocaton of data_ptr in create_data\n");
    return NULL;
  }

  ts = time(NULL);
  seconds = (long) ts;  
  retval->id = long2string(seconds);
  if (retval->id == NULL) {
    free(retval);
    fprintf(stderr, "Error during allocation of data_ptr->id in create_data\n");
  }

  key_len = strnlen(key, INT_MAX_STR_LEN);
  retval->key = (char *) malloc(key_len * sizeof(char));
  if (retval->key == NULL) {
    free(retval->id);
    free(retval);
    fprintf(stderr, "Error during key copy in create_data");
    return NULL;
  }
  retval->key = strncpy(retval->key, key, key_len);

  value_len = strnlen(value, INT_MAX_STR_LEN);
  retval->value = (char *) malloc(value_len * sizeof(char));
  if (retval->value == NULL) {
    free(retval->key);
    free(retval->id);
    free(retval);
    fprintf(stderr, "Error during value copy in create_data");
    return NULL;
  }
  retval->value = strncpy(retval->value, value, value_len);
  
  return retval;

}

void deallocate_data(data_ptr node) {
  
  if (node != NULL) {
    if (node->id != NULL) {
      free(node->id);
    }
    if (node->key != NULL) {
      free(node->key);
    }
    if (node->value != NULL) {
      free(node->value);
    }
    free(node);
  }

}

int persist_data(storage_ptr repo, data_ptr node) {
  
}
