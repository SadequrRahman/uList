copy : uList.o
	cp uList.o ./test/

uList.o : ./src/uList.c
	gcc -c ./src/uList.c -o uList.o