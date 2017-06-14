start: main.o read_write.o actions.o
	gcc -o start main.o read_write.o actions.o

main.o: main.c passenger.h read_write.h actions.h
	gcc -c main.c

read_write.o: read_write.c read_write.h passenger.h
	gcc -c read_write.c

actions.o: actions.c actions.h passenger.h read_write.h
	gcc -c actions.c



clean:
	rm -rf *.o start
