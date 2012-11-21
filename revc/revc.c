#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "read.h"

inline static void reverse(char *mem, long size)
{
  long i, half, last;
  char reverse[256], tmp;

  half = size / 2;
  last = size - 1;
  reverse['A'] = 'T'; reverse['C'] = 'G'; reverse['G'] = 'C'; reverse['T'] = 'A';
  #pragma omp parallel for num_threads(8) private(tmp)
  for (i = 0; i < half; i++)
  {
    tmp = reverse[(int) mem[last - i]];
    mem[last - i] = reverse[(int) mem[i]];
    mem[i] = tmp;
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
  reverse(mem, size);
  (void)fprintf(stdout, "%s\n", mem);
  return EXIT_SUCCESS;
}
