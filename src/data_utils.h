/*
 * Structure for managing nodes
 */

typedef struct data_struct {
  char * id;
  char * key;
  char * value;
} data;

typedef data * data_ptr;

/*
 * Structure for managing storage
 */

typedef struct storage_struct {
  char * filepath;
  FILE * fileobj;
} storage;

typedef storage * storage_ptr;

#define FUNC_ERR 0

#define INT_MAX_STR_LEN 4096

data_ptr create_data(const char *, const char *);

void deallocate_data(data_ptr);

#define INT_PERSIST_SUCCESS 1
#define INT_PERSIST_FAILURE 0

int persist_data(storage_ptr, data_ptr);
