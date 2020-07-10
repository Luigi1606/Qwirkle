all: 
	make Qwirkle

run: 
	make all
	./Qwirkle

main.o: main.c
	gcc -o main.o -c main.c
  
aumentatab.o: aumentatab.c
	gcc -o aumentatab.o -c aumentatab.c
  
jogar.o: jogar.c
	gcc -o jogar.o -c jogar.c
  
tabu.o: tabu.c
	gcc -o tabu.o -c tabu.c
  
Qwirkle: main.o jogar.o tabu.o aumentatab.o
	gcc -o Qwirkle main.o jogar.o tabu.o aumentatab.o

clean:
	@rm *.o