# simpleMatrix
A small generic library supporting simple matrix operations, implemented using expression templates.

## About
- Only numerical types (`int`, `float`, `double`, `complex` etc ) are supported as of now.
- I have not yet made a custom exception class. All possible errors/exceptions are being thrown using `assert`.

## Testing
- Boost Test Framework is used to perform unit testing.
- Dimension mismatch tests are not covered as they are checked in `assert`s. I do not know how to detect that in test since compiler does not support throwing exceptions.

#### Instructions to compile and run tests:
1. `make`
2. `./test_constructor`
3. You can check for dimension mismatch by un-commenting lines 18-19, 33-35, 51-53 and 70-72. You will have to check the logs that only 4 failures are reported, and that too only for `assert` functions.

## Instructions to compile and run examples:
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