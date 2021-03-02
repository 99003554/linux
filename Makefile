Build: test.c src/mystring.c src/myutils.c src/bitmask.c
	gcc test.c src/mystring.c src/myutils.c src/bitmask.c -Iinc

run:Build
	./a.out