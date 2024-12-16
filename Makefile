default: build

dsp.o: dsp.cpp dsp.h
	g++ -c dsp.cpp

coefficients.o: coefficients.h coefficients.cpp
	g++ -c coefficients.cpp

main.o: main.cpp coefficients.h dsp.h
	g++ -c main.cpp

build: dsp.o dsp.h coefficients.h main.o coefficients.o
	g++ -o dsp dsp.o main.o coefficients.o
