#include "simpleMatrix.h"

template < typename T >
smps::Matrix<T>& smps::Matrix<T>::operator = ( const smps::Matrix<T> &other ) {
    std::pair< size_t, size_t > shape = other.get_shape();
    for( int i=0; i < shape.first * shape.second; i++ ) {
        this->matrix[i] = other.matrix[i];
    }
    return *this;
}

template < typename T >
smps::Matrix<T>& smps::Matrix<T>::operator + ( const smps::Matrix<T> &other ) {
    smps::Matrix<T> *temp_matrix_ptr = new smps::Matrix<T>(other);
    std::pair< size_t, size_t > shape = temp_matrix_ptr.get_shape();
    for( int i = 0; i < shape.first * shape.second; i++ ) {
        temp_matrix_ptr->matrix[i] += this->matrix[i];
    }

    return *temp_matrix_ptr;
}

template < typename T >
smps::Matrix<T>& smps::Matrix<T>::operator += ( const smps::Matrix<T> &other ) {
    std::pair< size_t, size_t > shape = other.get_shape();
    for( int i = 0; i < shape.first * shape.second; i++ ) {
        this->matrix[i] += other.matrix[i];
    }

    return *this;
}

template < typename T >
smps::Matrix<T>& smps::Matrix<T>::operator * ( const smps::Matrix<T> &other ) {
    smps::Matrix<T> *temp_matrix_ptr = new smps::Matrix<T>(other);
    std::pair< size_t, size_t > shape = temp_matrix_ptr.get_shape();
    for( int i = 0; i < shape.first * shape.second; i++ ) {
        temp_matrix_ptr->matrix[i] *= this->matrix[i];
    }

    return *temp_matrix_ptr;
}

template < typename T >
smps::Matrix<T>& smps::Matrix<T>::operator *= ( const smps::Matrix<T> &other ) {
	std::pair< size_t, size_t > shape = other.get_shape();
    for( int i = 0; i < shape.first * shape.second; i++ ) {
        this->matrix[i] *= other.matrix[i];
    }

    return *this;
}

template < typename T >
std::pair< size_t, size_t > smps::Matrix<T>::get_shape() {
    return std::make_pair( num_rows, num_cols );
}

template < typename T >
void smps::Matrix<T>::insert_element( int i, int j, T element ) {
    matrix[i][j] = element;
}

template < typename T >
T smps::Matrix<T>::get_element( int i, int j ) {
    return matrix[i][j];
}