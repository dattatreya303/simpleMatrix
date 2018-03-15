CPP_FLAGS = -std=c++1y
RUNTIME_FLAGS = -lboost_unit_test_framework

all : test_constructor

test_constructor : test_constructor.cpp common.h
	g++ ${CPP_FLAGS} -g -o test_constructor test_constructor.cpp $(RUNTIME_FLAGS)

clean:
	-rm test_constructor