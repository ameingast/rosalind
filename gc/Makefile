include ../common.mk

gc: gc.c
	$(CC) $(CFLAGS) -I../common ../common/read.o $< -o $@
	strip $@

input.txt:
	time ../common/gen input.txt > /dev/null

run: gc input.txt
	time ./gc input.txt > output.txt

clean:
	rm -f gc input.txt output.txt