# This is my Makefile.

EXECS=args bitoperations endian funcs preproc sha512

sha512: sha512.c
	cc -o sha512 sha512.c

test: tests.sh
	./tests.sh

clean:
	rm -f $(EXECS)