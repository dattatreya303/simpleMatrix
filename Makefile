CPPFLAGS = -std=c++14

all : test_matrix

test_matrix : test_matrix.cpp simple_matrix.h test_suite.h
	g++ ${CPPFLAGS} -g -o test_matrix test_matrix.cpp

clean:
	rm test_matrix