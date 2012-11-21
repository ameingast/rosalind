#ifndef _ROSALIND_READ_H_
#define _ROSALIND_READ_H_

#include <stdio.h>

long length(FILE *f);
char *read_in(const char *filename, long *size);

#endif 