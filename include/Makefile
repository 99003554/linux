TARGET=a.out
OBJS=test.o src/mystring.o src/bitmask.o src/myutils.o
TOPDIR=${PWD}

CFLAGS=-I${TOPDIR}/include

a:$(TARGET)

$(TARGET):$(OBJS)
	gcc $^ -o $@

%.o:src/%.c 

test.o:test.c

clean:
	rm -rf ${OBJS} ${TARGET}