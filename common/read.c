#include <stdlib.h>

#include "read.h"

inline long length(FILE *f)
{
  long size;

  if (fseek(f, 0, SEEK_END)) return -1;
  if (-1 == (size = ftell(f))) return -1;
  if (fseek(f, 0, SEEK_SET)) return -1;
  return size;
}

inline char *read_in(const char *filename, long *size)
{
  FILE *f;
  char *mem;

  if (NULL == (f = fopen(filename, "r"))) return NULL;
  if (-1 == (*size = length(f))) return NULL;
  if (NULL == (mem = calloc(*size, sizeof(char)))) return NULL;
  if (!fread(mem, sizeof(char), *size, f)) return NULL;
  if (fclose(f)) return NULL;
  return mem;
}