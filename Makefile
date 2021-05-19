copy : uList.o
	cp uList.o ./test/

uList.o : ./src/uList.c
	gcc -c ./src/uList.c -o uList.o


clean :
	rm -f uList.o
	rm -f ./test/uList.o