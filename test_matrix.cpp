#include "simple_matrix.h"
#include "test_suite.h"

#include <chrono>

int main(int argc, char const *argv[]) {

    // test::TestIntAssign();
    // test::TestIntCompare();
    // test::TestIntAdd();
    // test::TestIntAddAssign();
    // test::TestIntMultiply();
    // test::TestIntMultiplyDifferent();
    // test::TestIntMultiplyAssign();

    // test::TestComplexAssign();
    // test::TestComplexCompare();
    // test::TestComplexAdd();
    // test::TestComplexAddAssign();
    // test::TestComplexMultiply();
    // test::TestComplexMultiplyDifferent();
    // test::TestComplexMultiplyAssign();

    smps::Matrix<int> A(1000, 1000);
    for( int i = 0; i < 1000; i++ ) {
        for( int j = 0; j < 1000; j++ ) {
            A.insert_element( i, j, rand() % 10 );
        }
    }
    smps::Matrix<int> B(A);

    const auto start_time = std::chrono::steady_clock::now();
    A *= B;
    const auto end_time = std::chrono::steady_clock::now();
    
    std::cout << "Matrix<int>(1000,1000): Multiplication: Execution time = " <<
    std::chrono::duration<double, std::milli>(end_time - start_time).count() / 1000 << " seconds" << std::endl;

    smps::Matrix< std::complex<int> > C(1000, 1000);
    for( int i = 0; i < 1000; i++ ) {
        for( int j = 0; j < 1000; j++ ) {
            C.insert_element( i, j, std::complex<int>( rand()%10, rand()%10 ) );
        }
    }
    smps::Matrix< std::complex<int> > D(C);

    // start_time = std::chrono::steady_clock::now();
    C *= D;
    // end_time = std::chrono::steady_clock::now();
    
    // std::cout << "Matrix< complex<int> >(1000,1000): Multiplication: Execution time = " <<
    // std::chrono::duration<double, std::milli>(end_time - start_time).count() / 1000 << " seconds" << std::endl;

    return 0;
}