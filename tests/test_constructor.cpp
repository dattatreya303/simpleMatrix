#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include "common.h"
#include <boost/mpl/list.hpp>

typedef boost::mpl::list<int, float, double> test_constructor_types;

// typedef std::tuple<int, float, double> test_constructor_types;
// typedef std::tuple<int, float, double, std::complex<int>, std::complex<float>, std::complex<double> > test_constructor_types;

BOOST_AUTO_TEST_CASE_TEMPLATE( test_valid_object, T, test_constructor_types ) {
    int num_rows = 3, num_cols = 4;
    smps::Matrix<T> test_matrix = smps::test::initialize_matrix<T>(num_rows, num_cols);
    
    BOOST_REQUIRE_MESSAGE( sizeof(test_matrix) > 0, "// Object should not be null." );

    // std::pair<size_t, size_t> shape = test_matrix.size();
    // BOOST_REQUIRE_MESSAGE( shape.first == num_rows && shape.second == num_cols, "// Dimensions of the object should correct." );

    for (size_t i=0; i<num_rows; i++) {
        for (size_t j=0; j<num_cols; j++) {
            BOOST_REQUIRE_MESSAGE( abs(test_matrix(i,j) - (i+j)/(T)(2.0)) <= 1e-9, 
                "// All values should be same as intended with a tolerance of 1e-9 for floats and doubles." );
        }
    }
}

BOOST_AUTO_TEST_CASE_TEMPLATE( test_addition, T, test_constructor_types ) {
    int num_rows = 3, num_cols = 4;
    smps::Matrix<T> a = smps::test::initialize_matrix<T>(num_rows, num_cols);    
    smps::Matrix<T> b = smps::test::initialize_matrix<T>(num_rows, num_cols);

    // smps::Matrix<T> d = smps::test::initialize_matrix<T>(num_rows+1, num_cols);
    // // Addition of matrices with mismatched dimensions should give assertion error.
    // smps::Matrix<T> e = a + d;

    smps::Matrix<T> c = a + b;
    for (size_t i=0; i<num_rows; i++) {
        for (size_t j=0; j<num_cols; j++) {
            T val = ((i+j)/(T)(2.0)) + ((i+j)/(T)(2.0));
            BOOST_REQUIRE_MESSAGE( abs(c(i,j) - val) <= 1e-9 && abs(c(i,j) - val) <= 1e-9, 
                "// Every element should be correctly calculated with a tolerance of 1e-9 for floats and doubles." );
        }
    }
}

BOOST_AUTO_TEST_CASE_TEMPLATE( test_addition_complex, T, test_constructor_types ) {
    int num_rows = 3, num_cols = 4;
    smps::Matrix< std::complex<T> > a = smps::test::initialize_complex_matrix<T>(num_rows, num_cols);    
    smps::Matrix< std::complex<T> > b = smps::test::initialize_complex_matrix<T>(num_rows, num_cols);

    // smps::Matrix< std::complex<T> > d = smps::test::initialize_complex_matrix<T>(num_rows+1, num_cols);
    // // Addition of matrices with mismatched dimensions should give assertion error.
    // smps::Matrix< std::complex<T> > e = a + d;

    smps::Matrix< std::complex<T> > c = a + b;
    for (size_t i=0; i<num_rows; i++) {
        for (size_t j=0; j<num_cols; j++) {
            std::complex<T> val = std::complex<T>(i/((T)(2.0)), j/((T)(2.0))) + std::complex<T>(i/((T)(2.0)), j/((T)(2.0)));
            BOOST_REQUIRE_MESSAGE( abs(c(i,j).real() - val.real()) <= 1e-9 && abs(c(i,j).imag() - val.imag()) <= 1e-9, 
                "// Every element should be correctly calculated with a tolerance of 1e-9 for floats and doubles." );
        }
    }
}

BOOST_AUTO_TEST_CASE_TEMPLATE( test_multiplication, T, test_constructor_types ) {
    int num_rows1 = 3, num_cols1 = 4;
    int num_rows2 = 4, num_cols2 = 8;
    smps::Matrix<T> a = smps::test::initialize_matrix<T>(num_rows1, num_cols1);    
    smps::Matrix<T> b = smps::test::initialize_matrix<T>(num_rows2, num_cols2);

    // smps::Matrix<T> d = smps::test::initialize_matrix<T>(num_rows1+1, num_cols1);
    // // Multiplication of matrices with mismatched dimensions should give assertion error.
    // smps::Matrix<T> e = a * d;

    smps::Matrix<T> c = a * b;
    for (size_t i=0; i<num_rows1; i++) {
        for (size_t j=0; j<num_cols2; j++) {
            T val = 0.0;
            for (size_t k=0; k<num_cols1; k++){
                val += ((i+k)/(T)2.0) * ((k+j)/(T)2.0);
            }
            BOOST_REQUIRE_MESSAGE( abs(c(i,j) - val) <= 1e-9, 
                "// Every element should be correctly calculated with a tolerance of 1e-9 for floats and doubles." );
        }
    }
}

BOOST_AUTO_TEST_CASE_TEMPLATE( test_multiplication_complex, T, test_constructor_types ) {
    int num_rows1 = 3, num_cols1 = 4;
    int num_rows2 = 4, num_cols2 = 8;
    smps::Matrix< std::complex<T> > a = smps::test::initialize_complex_matrix<T>(num_rows1, num_cols1);    
    smps::Matrix< std::complex<T> > b = smps::test::initialize_complex_matrix<T>(num_rows2, num_cols2);

    // smps::Matrix< std::complex<T> > d = smps::test::initialize_complex_matrix<T>(num_rows1+1, num_cols1);
    // // Multiplication of matrices with mismatched dimensions should give assertion error.
    // smps::Matrix< std::complex<T> > e = a * d;

    smps::Matrix< std::complex<T> > c = a * b;
    for (size_t i=0; i<num_rows1; i++) {
        for (size_t j=0; j<num_cols2; j++) {
            std::complex<T> val = {(T)(0.0), (T)(0.0)};
            for (size_t k=0; k<num_cols1; k++){
                val += std::complex<T>(i/((T)(2.0)), k/((T)(2.0))) * std::complex<T>(k/((T)(2.0)), j/((T)(2.0)));
            }
            BOOST_REQUIRE_MESSAGE( abs(c(i,j).real() - val.real()) <= 1e-9 && abs(c(i,j).imag() - val.imag()) <= 1e-9, 
                "// Every element should be correctly calculated with a tolerance of 1e-9 for floats and doubles." );
        }
    }
}