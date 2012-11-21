include ../common.mk

rna: rna.c
	$(CC) $(CFLAGS) -I../common ../common/read.o $< -o $@
	strip $@

input.txt:
	time ../common/gen input.txt > /dev/null

run: rna input.txt
	time ./rna input.txt > output.txt

clean:
	rm -f rna input.txt output.txt