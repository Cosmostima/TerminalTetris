logic.o:
	g++ -std=c++11 -c logic.cpp 

display.o:
	g++ -std=c++11 -c display.cpp 	

Tetris.o:
	g++ -std=c++11 -c Tetris.cpp

testlogic: logic.o
	g++ -std=c++11 testlogic.cpp logic.o -o testlogic;make clean;clear

testdisplay: display.o
	g++ -std=c++11 testdisplay.cpp display.o -o testdisplay;make clean;clear

testboth: display.o logic.o
	g++ -std=c++11 testboth.cpp display.o logic.o -o testboth;make clean

TETRIS: logic.o display.o Tetris.o
	g++ -std=c++11 logic.o display.o Tetris.o main.cpp -o TETRIS;make clean


clean:
	rm *.o;