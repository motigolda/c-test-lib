CC=gcc
CFLAGS=-Wall -g -Iinclude
BUILDDIR=build
BINDIR=${BUILDDIR}/bin
OBJDIR=${BUILDDIR}/obj
TESTDIR=test

testlib.o:
	${CC} ${CFLAGS} -c src/testlib.c -o ${OBJDIR}/testlib.o

test_testlib.o:
	${CC} ${CFLAGS} -c ${TESTDIR}/test_testlib.c -o ${OBJDIR}/test_testlib.o

test_testlib: testlib.o test_testlib.o
	${CC} ${CFLAGS} ${OBJDIR}/*.o -o ${BINDIR}/test_testlib

.PHONY: clean

clean:
	rm -r ${OBJDIR}/*.o
