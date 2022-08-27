all: build run


build:
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/Kuyruk.o -c ./src/Kuyruk.cpp
	g++ -I ./include/ -o ./lib/Radix.o -c ./src/Radix.cpp
	g++ -I ./include/ -o ./lib/Sirala.o -c ./src/Sirala.cpp
	g++ -I ./include/ -o ./lib/AgacDugumu.o -c ./src/AgacDugumu.cpp
	g++ -I ./include/ -o ./lib/Avl.o -c ./src/Avl.cpp
	g++ -I ./include/ -o ./lib/kelimeleriAyir.o -c ./src/kelimeleriAyir.cpp


	g++ -I ./include/ -o ./bin/main ./lib/Dugum.o ./lib/Kuyruk.o ./lib/Radix.o ./lib/Sirala.o ./lib/AgacDugumu.o ./lib/Avl.o   ./src/main.cpp

run:
	./bin/main