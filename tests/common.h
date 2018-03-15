#ifndef COMMON_H
#define COMMON_H

#include <boost/test/unit_test.hpp>

#include <type_traits>
#include <complex>

#include "../simple_matrix.h"

namespace smps { namespace test {

template <typename T>
smps::Matrix<T>& initialize_matrix(size_t num_rows, size_t num_cols) {
    Matrix<T> *matrix = new Matrix<T>(num_rows, num_cols);
    for (size_t i=0; i<num_rows; i++) {
        for (size_t j=0; j<num_cols; j++) {
            (*matrix)(i,j) = (i + j) / ((T)(2.0));
        }
    }

    return *matrix;
}

template <typename T>
smps::Matrix< std::complex<T> >& initialize_complex_matrix(size_t num_rows, size_t num_cols) {
    Matrix< std::complex<T> > *matrix = new Matrix< std::complex<T> >(num_rows, num_cols);
    for (size_t i=0; i<num_rows; i++) {
        for (size_t j=0; j<num_cols; j++) {
            (*matrix)(i,j) = {i/((T)(2.0)), j/((T)(2.0))};
        }
    }

    return *matrix;
}

template <typename T>
smps::Matrix<T>& initialize_null_matrix(size_t num_rows, size_t num_cols) {
    Matrix<T> *matrix = new Matrix<T>(num_rows, num_cols);
    for (size_t i=0; i<num_rows; i++) {
        for (size_t j=0; j<num_cols; j++) {
            (*matrix)(i,j) = (T)(-1.0);
        }
    }

    return *matrix;
}

}}

#endif