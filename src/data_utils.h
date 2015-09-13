typedef struct data_struct {
  char * id;
  char * key;
  char * value;
} data;

typedef data * data_ptr;

#define FUNC_ERR -1

#define INT_MAX_STR_LEN 4096

data_ptr create_data(const char *, const char *);

void deallocate_data(data_ptr);
