# Makefile
objs = test.o bitops.o

test: Makefile $(objs)
	cc -Wall -o test $(objs)

test.o: test.c
	cc -Wall -c test.c

bitops.o: bitops.c bitops.h
	cc -Wall -c bitops.c

clean:
	rm -f shalend *.o *~
