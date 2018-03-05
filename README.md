# simpleMatrix
A small generic library supporting simple matrix operations, implemented using expression templates.

## About
- Only numerical types (`int`, `float`, `double`, `complex` etc ) are supported as of now.
- I have not yet made a custom exception class. All possible errors/exceptions are being thrown using `std::runtime_error`.
- There is a rudimentary test_suite (`test_suite.h`)  provided, which tests some very basic test cases. It is not very robust and has very low coverage. Example code has been provided in `test_matrix.cpp` to use it.

## Instructions to compile and run:
1. Make changes in test_matrix.cpp file as needed to test functionalities. Some example code has been provided.
2. `make`
3. `./test_matrix`

## Runtime statistics

#### Addition

| Type       | Shape       | Average Execution time (in seconds)  |
| :--------: | :---------: | :----------------------------------: |
| `int`      | (1000,1000) | 0.037                                |
| `complex`  | (1000,1000) | 0.061                                |

#### Multiplication

| Type       | Shape       | Average Execution time (in seconds)  |
| :--------: | :---------: | :----------------------------------: |
| `int`      | (1000,1000) | 26                                   |
| `complex`  | (1000,1000) | 59                                   |

#### System specs

- Processor: Intel i5 5200U
- CPU speed: 2.20 GHz