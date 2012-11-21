#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read.h"

static inline void rewrite(char *in, long size)
{
  long i;
  char lookup[256];

  lookup['A'] = 'A'; lookup['C'] = 'C'; lookup['G'] = 'G'; lookup['T'] = 'U';
  #pragma omp parallel for num_threads(2)
  for (i = 0; i < size; i++)
  {
    in[i] = lookup[(int) in[i]];
  }
}

int main(int argc, char **argv)
{
  char *mem;
  long size;

  if (argc != 2)
  {
    (void)fprintf(stderr, "%s <filename>\n", *argv);
    return EXIT_FAILURE;
  }
  if (NULL == (mem = read_in(argv[1], &size)))
  {
    (void)fprintf(stderr, "IO/Memory error\n");
    return EXIT_FAILURE;
  }
  rewrite(mem, size);
  (void)fprintf(stdout, "%s\n", mem);
  return EXIT_SUCCESS;
}
