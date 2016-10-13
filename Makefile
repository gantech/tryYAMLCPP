all:: a.out

a.out:: try1.c try1.h try.c
	g++ -g -c -std=c++11 -I/home/gvijayak/fastv8DriverProgram/fastv8/include/ try1.c
	g++ -g -std=c++11 -I/home/gvijayak/fastv8DriverProgram/fastv8/include/ try.c try1.o -L/home/gvijayak/fastv8DriverProgram/fastv8/lib/ -lyaml-cpp
