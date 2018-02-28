#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include "simple_matrix.h"

#include <cassert>
#include <complex>

namespace test {

    void TestIntAssign() {
        std::cout << "TestIntAssign ... ";
        int arr[][3] = { {1,2,3}, {2,3,4}, {3,4,5} };
        smps::Matrix<int> A(3,3);
        for( int i = 0; i < 3; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                A.insert_element( i, j, arr[i][j] );
            }
        }
        smps::Matrix<int> B(3,3);
        B = A;
        for( int i = 0; i < 3; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                assert(( B.get_element( i, j ) == arr[i][j] ));
            }
        }
        std::cout << "passed." << std::endl;
    }

    void TestIntCompare() {
        std::cout << "TestIntCompare ... ";
        int arr[][3] = { {1,2,3}, {2,3,4}, {3,4,5} };
        smps::Matrix<int> A(3,3);
        for( int i = 0; i < 3; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                A.insert_element( i, j, arr[i][j] );
            }
        }
        smps::Matrix<int> B(3,3);
        for( int i = 0; i < 3; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                B.insert_element( i, j, arr[i][j] );
            }
        }
        assert(( A == B ));
        B.insert_element( 0, 0, 10 );
        assert(( !(A == B) ));
        std::cout << "passed." << std::endl;
    }


    void TestIntAdd() {
        std::cout << "TestIntAdd ... ";
        int arr[][3] = { {1,2,3}, {2,3,4}, {3,4,5} };
        smps::Matrix<int> A(3,3);
        for( int i = 0; i < 3; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                A.insert_element( i, j, arr[i][j] );
            }
        }
        smps::Matrix<int> B(3,3);
        for( int i = 0; i < 3; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                B.insert_element( i, j, arr[i][j] );
            }
        }
        smps::Matrix<int> C = A + B;
        for( int i = 0; i < 3; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                assert(( C.get_element( i, j ) == 2 * arr[i][j] ));
            }
        }
        std::cout << "passed." << std::endl;
    }

    void TestIntAddAssign() {
        std::cout << "TestIntAddAssign ... ";
        int arr[][3] = { {1,2,3}, {2,3,4}, {3,4,5} };
        smps::Matrix<int> A(3,3);
        for( int i = 0; i < 3; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                A.insert_element( i, j, arr[i][j] );
            }
        }
        smps::Matrix<int> B(3,3);
        for( int i = 0; i < 3; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                B.insert_element( i, j, arr[i][j] );
            }
        }
        A += B;
        for( int i = 0; i < 3; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                assert(( A.get_element( i, j ) == 2 * arr[i][j] ));
            }
        }
        std::cout << "passed." << std::endl;
    }

    void TestIntMultiply() {
        std::cout << "TestIntMultiply ... ";
        int arr[][3] = { {1,2,3}, {2,3,4}, {3,4,5} };
        smps::Matrix<int> A(3,3);
        for( int i = 0; i < 3; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                A.insert_element( i, j, arr[i][j] );
            }
        }
        smps::Matrix<int> B(3,3);
        for( int i = 0; i < 3; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                B.insert_element( i, j, arr[i][j] );
            }
        }
        smps::Matrix<int> C = A * B;
        for( int i = 0; i < 3; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                int val = 0;
                for( int k = 0; k < 3; k++ ) {
                    val += arr[i][k] * arr[k][j];
                }
                assert(( C.get_element( i, j ) == val ));
            }
        }
        std::cout << "passed." << std::endl;
    }

    void TestIntMultiplyDifferent() {
        std::cout << "TestIntMultiplyDifferent ... ";
        int arr1[][3] = { {1,2,3}, {2,3,4}, {3,4,5} };
        int arr2[][4] = { {1,2,3,4}, {2,3,4,5}, {3,4,5,6} };
        smps::Matrix<int> A(3,3);
        for( int i = 0; i < 3; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                A.insert_element( i, j, arr1[i][j] );
            }
        }
        smps::Matrix<int> B(3,4);
        for( int i = 0; i < 3; i++ ) {
            for( int j = 0; j < 4; j++ ) {
                B.insert_element( i, j, arr2[i][j] );
            }
        }
        smps::Matrix<int> C = A * B;
        for( int i = 0; i < 3; i++ ) {
            for( int j = 0; j < 4; j++ ) {
                int val = 0;
                for( int k = 0; k < 3; k++ ) {
                    val += arr1[i][k] * arr2[k][j];
                }
                assert(( C.get_element( i, j ) == val ));
            }
        }
        std::cout << "passed." << std::endl;
    }

    void TestIntMultiplyAssign() {
        std::cout << "TestIntMultiply ... ";
        int arr[][3] = { {1,2,3}, {2,3,4}, {3,4,5} };
        smps::Matrix<int> A(3,3);
        for( int i = 0; i < 3; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                A.insert_element( i, j, arr[i][j] );
            }
        }
        smps::Matrix<int> B(3,3);
        for( int i = 0; i < 3; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                B.insert_element( i, j, arr[i][j] );
            }
        }
        A *= B;
        for( int i = 0; i < 3; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                int val = 0;
                for( int k = 0; k < 3; k++ ) {
                    val += arr[i][k] * arr[k][j];
                }
                assert(( A.get_element( i, j ) == val ));
            }
        }
        std::cout << "passed." << std::endl;
    }

    void TestComplexAssign() {
        std::cout << "TestComplexAssign ... ";
        std::complex<int> arr[][3] = { { {1,2},{1,3},{1,4} }, { {2,3}, {2,4}, {2,5} } };
        smps::Matrix< std::complex<int> > A(2,3);
        for( int i = 0; i < 2; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                A.insert_element( i, j, arr[i][j] );
            }
        }
        smps::Matrix< std::complex<int> > B(2,3);
        B = A;
        for( int i = 0; i < 2; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                assert(( B.get_element( i, j ) == arr[i][j] ));
            }
        }
        std::cout << "passed." << std::endl;
    }

    void TestComplexCompare() {
        std::cout << "TestComplexCompare ... ";
        std::complex<int> arr[][3] = { { {1,2},{1,3},{1,4} }, { {2,3}, {2,4}, {2,5} } };
        smps::Matrix< std::complex<int> > A(2,3);
        for( int i = 0; i < 2; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                A.insert_element( i, j, arr[i][j] );
            }
        }
        smps::Matrix< std::complex<int> > B(2,3);
        for( int i = 0; i < 2; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                B.insert_element( i, j, arr[i][j] );
            }
        }
        assert(( A == B ));
        B.insert_element( 0, 0, 10 );
        assert(( !(A == B) ));
        std::cout << "passed." << std::endl;
    }


    void TestComplexAdd() {
        std::cout << "TestComplexAdd ... ";
        std::complex<int> arr[][3] = { { {1,2},{1,3},{1,4} }, { {2,3}, {2,4}, {2,5} } };
        smps::Matrix< std::complex<int> > A(2,3);
        for( int i = 0; i < 2; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                A.insert_element( i, j, arr[i][j] );
            }
        }
        smps::Matrix< std::complex<int> > B(2,3);
        for( int i = 0; i < 2; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                B.insert_element( i, j, arr[i][j] );
            }
        }
        smps::Matrix< std::complex<int> > C = A + B;
        for( int i = 0; i < 2; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                assert(( C.get_element( i, j ) == arr[i][j] + arr[i][j] ));
            }
        }
        C = B + A;
        for( int i = 0; i < 2; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                assert(( C.get_element( i, j ) == arr[i][j] + arr[i][j] ));
            }
        }
        std::cout << "passed." << std::endl;
    }

    void TestComplexAddAssign() {
        std::cout << "TestComplexAddAssign ... ";
        std::complex<int> arr[][3] = { { {1,2},{1,3},{1,4} }, { {2,3}, {2,4}, {2,5} } };
        smps::Matrix< std::complex<int> > A(2,3);
        for( int i = 0; i < 2; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                A.insert_element( i, j, arr[i][j] );
            }
        }
        smps::Matrix< std::complex<int> > B(2,3);
        for( int i = 0; i < 2; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                B.insert_element( i, j, arr[i][j] );
            }
        }
        A += B;
        for( int i = 0; i < 2; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                assert(( A.get_element( i, j ) == 2 * arr[i][j] ));
            }
        }
        std::cout << "passed." << std::endl;
    }

    void TestComplexMultiply() {
        std::cout << "TestComplexMultiply ... ";
        std::complex<int> arr[][2] = { { {1,2},{1,3} }, { {2,3}, {2,4} } };
        smps::Matrix< std::complex<int> > A(2,2);
        for( int i = 0; i < 2; i++ ) {
            for( int j = 0; j < 2; j++ ) {
                A.insert_element( i, j, arr[i][j] );
            }
        }
        smps::Matrix< std::complex<int> > B(2,2);
        for( int i = 0; i < 2; i++ ) {
            for( int j = 0; j < 2; j++ ) {
                B.insert_element( i, j, arr[i][j] );
            }
        }
        smps::Matrix< std::complex<int> > C = A * B;
        for( int i = 0; i < 2; i++ ) {
            for( int j = 0; j < 2; j++ ) {
                std::complex<int> val = 0;
                for( int k = 0; k < 2; k++ ) {
                    val += arr[i][k] * arr[k][j];
                }
                assert(( C.get_element( i, j ) == val ));
            }
        }
        C = B * A;
        for( int i = 0; i < 2; i++ ) {
            for( int j = 0; j < 2; j++ ) {
                std::complex<int> val = 0;
                for( int k = 0; k < 2; k++ ) {
                    val += arr[i][k] * arr[k][j];
                }
                assert(( C.get_element( i, j ) == val ));
            }
        }
        std::cout << "passed." << std::endl;
    }

    void TestComplexMultiplyDifferent() {
        std::cout << "TestComplexMultiplyDifferent ... ";
        std::complex<int> arr1[][2] = { { {1,2},{1,3} }, { {2,3}, {2,4} } };
        std::complex<int> arr2[][3] = { { {1,2},{1,3},{1,4} }, { {2,3}, {2,4},{2,5} } };
        smps::Matrix< std::complex<int> > A(2,2);
        for( int i = 0; i < 2; i++ ) {
            for( int j = 0; j < 2; j++ ) {
                A.insert_element( i, j, arr1[i][j] );
            }
        }
        smps::Matrix< std::complex<int> > B(2,3);
        for( int i = 0; i < 2; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                B.insert_element( i, j, arr2[i][j] );
            }
        }
        smps::Matrix< std::complex<int> > C = A * B;
        for( int i = 0; i < 2; i++ ) {
            for( int j = 0; j < 3; j++ ) {
                std::complex<int> val = 0;
                for( int k = 0; k < 2; k++ ) {
                    val += arr1[i][k] * arr2[k][j];
                }
                assert(( C.get_element( i, j ) == val ));
            }
        }
        std::cout << "passed." << std::endl;
    }

    void TestComplexMultiplyAssign() {
        std::cout << "TestComplexMultiply ... ";
        std::complex<int> arr[][2] = { { {1,2},{1,3} }, { {2,3}, {2,4} } };
        smps::Matrix< std::complex<int> > A(2,2);
        for( int i = 0; i < 2; i++ ) {
            for( int j = 0; j < 2; j++ ) {
                A.insert_element( i, j, arr[i][j] );
            }
        }
        smps::Matrix< std::complex<int> > B(2,2);
        for( int i = 0; i < 2; i++ ) {
            for( int j = 0; j < 2; j++ ) {
                B.insert_element( i, j, arr[i][j] );
            }
        }
        A *= B;
        for( int i = 0; i < 2; i++ ) {
            for( int j = 0; j < 2; j++ ) {
                std::complex<int> val = 0;
                for( int k = 0; k < 2; k++ ) {
                    val += arr[i][k] * arr[k][j];
                }
                assert(( A.get_element( i, j ) == val ));
            }
        }
        std::cout << "passed." << std::endl;
    }

}

#endif