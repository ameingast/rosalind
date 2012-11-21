#include <stdio.h>
#include <stdlib.h>

#include "read.h"

int main(int argc, char **argv)
{
  long counter[256], size, i;
  char *mem;

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
  #pragma omp parallel for num_threads(8)
  for (i = 0; i < size; i++)
  {
    counter[(int) mem[i]]++;
  }
  (void)fprintf(stdout, "%ld %ld %ld %ld\n", counter['A'], counter['C'], counter['G'], counter['T']);
  return EXIT_SUCCESS;
}
