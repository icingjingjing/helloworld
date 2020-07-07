hello:hello.o algorithms.o
	g++ -o hello hello.o algorithms.o
algorithms.o:algorithms.cpp algorithms.h
	g++ -c algorithms.cpp -g
hello.o:hello.cpp hello.h
	g++ -c hello.cpp -g
.PHONY:clean
	rm hello hello.o algorithms.o
