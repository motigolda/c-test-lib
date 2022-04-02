CC=gcc
CFLAGS=-Wall -g

test: test_testlib clean

testlib.o:
	${CC} ${CFLAGS} -c testlib.c -o testlib.o

test_testlib.o: testlib.o
	${CC} ${CFLAGS} -c test_testlib.c -o test_testlib.o

test_testlib: testlib.o test_testlib.o
	${CC} ${CFLAGS} testlib.o test_testlib.o -o test_testlib.exe

testlib.dll: testlib.o
	${CC} ${CFLAGS} -fPIC -shared -o $@ testlib.c

attach: testlib.dll
	${CC} ${CFLAGS} test_testlib_dll.c -L./ 

test_dll: dll attach

clean:
	rm -r *.o
