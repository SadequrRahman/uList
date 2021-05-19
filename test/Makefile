test : test.o
	gcc test.o uList.o -o test

test.o : test_basic.c
	gcc -c test_basic.c -o test.o

clean :
	rm -f test.o test.exe