#ifndef _ROSALIND_FASTA_H_
#define _ROSALIND_FASTA_H_

typedef struct fasta_t_ {
  char code[128];
  char mem[1024];
} fasta_t;

fasta_t *read_fasta(const char *filename, long *size);

#endif