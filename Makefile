all:makefile run

makefile: main.o randevu.o
	gcc main.o randevu.o -o makefile

main.o: main.c
	gcc -c main.c

randevu.o: randevu.c randevu.h
	gcc -c randevu.c

clean:
	del *.o makefile.exe

run:
	makefile.exe