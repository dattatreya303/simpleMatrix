#include "simple_matrix.h"

#include <chrono>
#include <complex>

int main(int argc, char const *argv[]) {

    /*
    Un-comment this to test complex matrix.
    */
    // smps::Matrix< std::complex<int> > mat1(1000,1000);
    // for(int i=0; i<1000; i++){
    //     for(int j=0; j<1000; j++){
    //         mat1(i,j) = {i+j, i+j};
    //     }
    // }

    /*
    Un-comment this to test complex matrix.
    */
    // smps::Matrix< std::complex<int> > mat2(1000,1000);
    // for(int i=0; i<1000; i++){
    //     for(int j=0; j<1000; j++){
    //         mat2(i,j) = {i+j, i+j};
    //     }
    // }

    /*
    Un-comment this to test int matrix.
    */
    smps::Matrix<int> mat1(1000,1000);
    for(int i=0; i<1000; i++){
        for(int j=0; j<1000; j++){
            mat1(i,j) = i+j;
        }
    }

    /*
    Un-comment this to test int matrix.
    */
    smps::Matrix<int> mat2(1000,1000);
    for(int i=0; i<1000; i++){
        for(int j=0; j<1000; j++){
            mat2(i,j) = i+j;
        }
    }

    const auto start_time = std::chrono::steady_clock::now();
    // mat1 = mat1 * mat2;
    // mat1 *= mat2;
    mat1 = mat1 + mat2;
    // mat1 += mat2;
    const auto end_time = std::chrono::steady_clock::now();

    std::cout << "Execution time = " <<
    std::chrono::duration<double, std::milli>(end_time - start_time).count() / 1000 << " seconds" << std::endl;

    /*
    Un-comment this to print resultant matrix.
    */
    // for(int i=0; i<3; i++){
    //     for(int j=0; j<3; j++){
    //         std::cout<< mat1(i,j) << " ";
    //     }
    //     std::cout<< std::endl;
    // }
}