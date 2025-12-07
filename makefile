a.out: main.o addition.o subtraction.o multiplication.o division.o validate.o file.o
	gcc -o a.out main.o addition.o subtraction.o multiplication.o division.o validate.o file.o

main.o: main.c
	gcc -c main.c

addition.o: addition.c
	gcc -c addition.c

subtraction.o: subtraction.c
	gcc -c subtraction.c

multiplication.o: multiplication.c
	gcc -c multiplication.c

division.o: division.c
	gcc -c division.c

validate.o: validate.c
	gcc -c validate.c

file.o: file.c
	gcc -c file.c

clean:
	rm *.o a.out
