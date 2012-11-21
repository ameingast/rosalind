include ../common.mk

all: read.o fasta.o gen gen_fasta

read.o: read.c
	$(CC) $(CFLAGS) -c $< -o $@

fasta.o: fasta.c
	$(CC) $(CFLAGS) -c $< -o $@

gen: gen.c
	$(CC) $(CFLAGS) $< -o $@

gen_fasta: gen_fasta.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f read.o gen gen_fasta fasta.o 