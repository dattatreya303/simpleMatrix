CPPFLAGS = -std=c++1y

all : test_matrix

test_matrix : test_matrix.cpp simple_matrix.h
	g++ ${CPPFLAGS} -g -o test_matrix test_matrix.cpp

clean:
	rm test_matrix