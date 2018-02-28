CPPFLAGS = -std=c++14

all: simpleMatrix.h simpleMatrix.cpp
	g++ ${CPPFLAGS} -c -g simpleMatrix.cpp

clean:
	-rm -rf *.o