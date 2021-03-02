TARGET=stall.out
OBJS=test.o src/mystring.o  src/bitmask.o src/myutils.o

TOPDIR=${PWD}
CFLAGS=-I${TOPDIR}/include
LDFLAGS=-lmystring -lmyutils -lbitmask
LIBPATH=${PWD}

all:stall.out

stall.out:test.o libmystring.a libmyutils.a libbitmask.a
	gcc -L${LIBPATH} $< -o $@ ${LDFLAGS} -static
libmystring.a:src/mystring.o 
	ar rc $@ $^
libmyutils.a:src/myutils.o 
	ar rc $@ $^
libbitmask.a:src/bitmask.o 
	ar rc $@ $^
%.o:src/%.c include/%.h

test.o: test.c include/*.h

test:
	./stall.out

clean:
	rm -rf *.a *.o src/*.o ${TARGET}
