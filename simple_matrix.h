#ifndef SIMPLE_MATRIX_H
#define SIMPLE_MATRIX_H

#include <iostream>
#include <cstdio>

namespace smps {

	template < typename T >
	class Matrix {

        private:

            size_t num_rows, num_cols;
            T *matrix;

        public:

            Matrix( size_t nrows, size_t ncols ) {
                this->num_rows = nrows;
                this->num_cols = ncols;
                this->matrix = ( T* ) malloc( sizeof( T ) * this->num_rows * this->num_cols );
            }

            Matrix( const Matrix<T> &M ) : Matrix( M.get_shape().first, M.get_shape().second ) {
                std::pair< size_t, size_t > shape = M.get_shape();
                for( int i = 0; i < shape.first * shape.second; i++ ) {
                    this->matrix[i] = M.get_element( i / shape.second, i % shape.second );
                }
            }

            ~Matrix() {
                free(this->matrix);
            }

            bool operator == (const Matrix &other ) {
                std::pair< size_t, size_t > shape = other.get_shape();
                for( int i=0; i < shape.first * shape.second; i++ ) {
                    if ( this->matrix[i] != other.matrix[i] )
                        return false;
                }
                return true;
            }

            Matrix& operator = ( const Matrix<T> &other ) {
                std::pair< size_t, size_t > shape = other.get_shape();
                for( int i=0; i < shape.first * shape.second; i++ ) {
                    this->matrix[i] = other.matrix[i];
                }
                return *this;
            }

            Matrix& operator + ( const Matrix<T> &other ) {
                smps::Matrix<T> *temp_matrix_ptr = new smps::Matrix<T>(other);
                std::pair< size_t, size_t > shape = temp_matrix_ptr->get_shape();
                for( int i = 0; i < shape.first * shape.second; i++ ) {
                    temp_matrix_ptr->matrix[i] += this->matrix[i];
                }

                return *temp_matrix_ptr;
            }

            Matrix& operator += ( const Matrix<T> &other ) {
                *this = *this + other;
                return *this;
            }

            Matrix& operator * ( const Matrix<T> &other ) {
                std::pair< size_t, size_t > shape1 = this->get_shape();
                std::pair< size_t, size_t > shape2 = other.get_shape();
                std::pair< size_t, size_t > shape3(shape1.first, shape2.second);
                smps::Matrix<T> *temp_matrix_ptr = new smps::Matrix<T>(shape3.first, shape3.second);
                for( int i = 0; i < shape3.first; i++ ) {
                    for( int j = 0; j < shape3.second; j++ ) {
                        T val = 0;
                        for( int k = 0; k < shape1.second; k++ ) {
                            val += this->get_element(i, k) * other.get_element(k, j);
                        }

                        int index = i * shape3.second + j;
                        temp_matrix_ptr->matrix[index] = val;
                    }
                }

                return *temp_matrix_ptr;
            }

            Matrix& operator *= ( const Matrix<T> &other ) {
                *this = *this * other;
                return *this;
            }

            std::pair< size_t, size_t > get_shape() const {
                return std::make_pair( this->num_rows, this->num_cols );
            }

            T get_element( int i, int j ) const {
                std::pair< int,int > shape = this->get_shape();
                int index = i * shape.second + j;
                return this->matrix[index];
            }
            
            void insert_element( int i, int j, T element ) {
                std::pair< int,int > shape = this->get_shape();
                int index = i * shape.second + j;
                this->matrix[index] = element;
            }
    };

}

#endif