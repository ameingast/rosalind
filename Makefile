include common.mk

all:
	make -C common
	make -C dna
	make -C revc
	make -C rna

clean:
	make -C common clean
	make -C dna clean
	make -C revc clean
	make -C rna clean