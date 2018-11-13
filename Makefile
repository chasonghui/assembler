# Write this Makefile
myas : main.o check.o trans.o
	gcc -o myas main.o trans.o check.o
main.o:myas.h main.c
	gcc -c main.c myas.h
trans.o : myas.h trans.c check.c
	gcc -c trans.c check.c myas.h
check.o: myas.h check.c
	gcc -c check.c myas.h
clean: 
	rm -rf myas main.o trans.o check.o
