all: 
	make Qwirkle

run: 
	make all
	./Qwirkle

main.o: main.c
	gcc -o main.o -c main.c
  
aumentatab.o: aumentatab.c
	gcc -o aumentatab.o -c aumentatab.c
  

jogarch.o: jogarch.c
	gcc -o jogarch.o -c jogarch.c
  
contapont.o: contapont.c
	gcc -o contapont.o -c contapont.c
  
ganhador.o: ganhador.c
	gcc -o ganhador.o -c ganhador.c
  
trocar.o: trocar.c
	gcc -o trocar.o -c trocar.c
  
jogar.o: jogar.c
	gcc -o jogar.o -c jogar.c
  
tabu.o: tabu.c
	gcc -o tabu.o -c tabu.c
  
Qwirkle: main.o jogar.o tabu.o aumentatab.o contapont.o ganhador.o trocar.o jogarch.o
	gcc -o Qwirkle main.o jogar.o tabu.o aumentatab.o contapont.o ganhador.o trocar.o jogarch.o

clean:
	@rm *.o