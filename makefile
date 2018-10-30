all: filestat.o
	gcc -o driver filestat.o
filestat.o: filestat.c
	gcc -c filestat.c
run:
	./driver
clean:
	rm -f ./driver  *.out *~ *.o *.gch
