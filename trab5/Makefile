all: 
	make Qwirkle

run: 
	make all
	./Qwirkle

main.o: main.c
	gcc -o main.o -c main.c
  
aumentatab.o: aumentatab.c
	gcc -o aumentatab.o -c aumentatab.c
  
contapont.o: contapont.c
	gcc -o contapont.o -c contapont.c
  
ganhador.o: ganhador.c
	gcc -o ganhador.o -c ganhador.c
  
jogar.o: jogar.c
	gcc -o jogar.o -c jogar.c
  
tabu.o: tabu.c
	gcc -o tabu.o -c tabu.c
  
Qwirkle: main.o jogar.o tabu.o aumentatab.o contapont.o ganhador.o
	gcc -o Qwirkle main.o jogar.o tabu.o aumentatab.o contapont.o ganhador.o

clean:
	@rm *.o