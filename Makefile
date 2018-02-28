CPPFLAGS = -std=c++14

simpleMatrix.o : simpleMatrix.h simpleMatrix.cpp
	g++ ${CPPFLAGS} -c -g simpleMatrix.cpp

clean:
	-rm -rf *.o