include ../common.mk

revc: revc.c
	$(CC) $(CFLAGS) -I../common ../common/read.o $< -o $@
	strip $@

input.txt:
	time ../common/gen input.txt > /dev/null

run: revc input.txt
	time ./revc input.txt > output.txt

clean:
	rm -f revc input.txt output.txt
