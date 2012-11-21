#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

static unsigned long count = 1073741824;
static unsigned int seed = 0;

static inline void randomize(char *mem, long size)
{
  long i;
  char lookup[4] = { 'A', 'C', 'G', 'T' };

  seed = time(NULL);
  #pragma omp parallel for num_threads(8)
  for (i = 0; i < size; i++)
  {
    seed = 214013 * seed + 2531011;
    mem[i] = lookup[((seed>>16) & 0x7FFF) % 4];
  }
}

static inline char *persist(const char *filename, char *mem, long size)
{
  int fd;

  if (0 > (fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644))) return NULL;
  if (-1 == write(fd, mem, count)) return NULL;
  if (-1 == close(fd)) return NULL;
  return mem;
}

int main(int argc, char **argv)
{
  char *mem;

  if (argc != 2)
  {
    (void)fprintf(stderr, "%s <filename>\n", *argv);
    return EXIT_FAILURE;
  }
  if (NULL == (mem = calloc(count, sizeof(char))))
  {
    (void)fprintf(stderr, "Memory error\n");
    return EXIT_FAILURE;
  }
  randomize(mem, count);
  if (NULL == persist(argv[1], mem, count))
  {
    (void)fprintf(stderr, "IO error\n");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
