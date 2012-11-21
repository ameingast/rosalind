include ../common.mk

dna: dna.c
	$(CC) $(CFLAGS) -I../common ../common/read.o $< -o $@
	strip $@

input.txt:
	time ../common/gen input.txt > /dev/null

run: dna input.txt
	time ./dna input.txt > /dev/null

clean:
	rm -f dna input.txt
