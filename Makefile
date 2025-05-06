logic.o:
	g++ -std=c++11 -c logic.cpp 

display.o:
	g++ -std=c++11 -c display.cpp 	

Tetris.o:
	g++ -std=c++11 -c Tetris.cpp

TETRIS: logic.o display.o Tetris.o
	g++ -std=c++11 logic.o display.o Tetris.o main.cpp -o TETRIS;make clean

clean:
	rm *.o;
