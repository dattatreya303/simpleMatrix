/**
@file
@brief COTTON runtime implementation.
**/

#ifndef SIMPLE_MATRIX_H
#define SIMPLE_MATRIX_H

#include <iostream>
#include <cstdio>
#include <stdexcept>

namespace smps {

	template < typename T >
	class Matrix {

        private:

            size_t num_rows, num_cols;
            T *matrix;

        public:

            /**
            Construct an empty matrix of shape (nrows, ncols).
            **/
            Matrix( size_t nrows, size_t ncols ) {
                this->num_rows = nrows;
                this->num_cols = ncols;
                this->matrix = ( T* ) malloc( sizeof( T ) * this->num_rows * this->num_cols );
            }

            /**
            Construct a matrix from another matrix of the same type using the copy constructor.
            **/
            Matrix( const Matrix<T> &M ) : Matrix( M.get_shape().first, M.get_shape().second ) {
                std::pair< size_t, size_t > shape = M.get_shape();
                for( int i = 0; i < shape.first * shape.second; i++ ) {
                    this->matrix[i] = M.get_element( i / shape.second, i % shape.second );
                }
            }

            ~Matrix() {
                free(this->matrix);
            }

            /**
            Equality comparison operator.
            @return true, if the two matrices have the same shape and corresponding elements. Else, false.
            **/
            bool operator == (const Matrix<T> &other ) {
                std::pair< size_t, size_t > shape = other.get_shape();
                if( this->get_shape() != shape )
                    return false;
                for( int i=0; i < shape.first * shape.second; i++ ) {
                    if ( this->matrix[i] != other.matrix[i] )
                        return false;
                }
                return true;
            }

            /**
            Copy assignment operator.
            **/
            Matrix<T>& operator = ( const Matrix<T> &other ) {
                std::pair< size_t, size_t > shape = other.get_shape();
                if( this->get_shape() != shape )
                    throw std::runtime_error( "Shapes don't match." );
                for( int i=0; i < shape.first * shape.second; i++ ) {
                    this->matrix[i] = other.matrix[i];
                }
                return *this;
            }

            /**
            Addition operator.
            **/
            Matrix<T>& operator + ( const Matrix<T> &other ) {
                if( this->get_shape() != other.get_shape() )
                    throw std::runtime_error( "Shapes don't match." );
                smps::Matrix<T> *temp_matrix_ptr = new smps::Matrix<T>(other);
                std::pair< size_t, size_t > shape = temp_matrix_ptr->get_shape();
                for( int i = 0; i < shape.first * shape.second; i++ ) {
                    temp_matrix_ptr->matrix[i] += this->matrix[i];
                }

                return *temp_matrix_ptr;
            }

            /**
            Add-and-Assign operator.
            **/
            Matrix<T>& operator += ( const Matrix<T> &other ) {
                *this = *this + other;
                return *this;
            }

            /**
            Multiplication operator.
            **/
            Matrix<T>& operator * ( const Matrix<T> &other ) {
                std::pair< size_t, size_t > shape1 = this->get_shape();
                std::pair< size_t, size_t > shape2 = other.get_shape();
                if( shape1.second != shape2.first )
                    throw std::runtime_error( "Incompatible shapes for multiplication." );
                std::pair< size_t, size_t > shape3(shape1.first, shape2.second);
                smps::Matrix<T> *temp_matrix_ptr = new smps::Matrix<T>(shape3.first, shape3.second);
                for( int i = 0; i < shape3.first; i++ ) {
                    for( int j = 0; j < shape3.second; j++ ) {
                        T val = 0;
                        for( int k = 0; k < shape1.second; k++ ) {
                            val += this->get_element(i, k) * other.get_element(k, j);
                        }

                        temp_matrix_ptr->insert_element( i, j, val );
                    }
                }

                return *temp_matrix_ptr;
            }

            /**
            Multiply-and-Assign operator.
            **/
            Matrix<T>& operator *= ( const Matrix<T> &other ) {
                *this = *this * other;
                return *this;
            }

            /**
            Gets the shape of the matrix.
            @return pair< size_t, size_t> Shape.
            **/
            std::pair< size_t, size_t > get_shape() const {
                return std::make_pair( this->num_rows, this->num_cols );
            }

            /**
            Gets the element at the co-ordinates from the matrix;
            @param i Row number
            @param j Column number
            @return Element at index (i,j) in the matrix.
            **/
            T get_element( int i, int j ) const {
                std::pair< int,int > shape = this->get_shape();
                if( i < 0 || i > shape.first || j < 0 || j > shape.second )
                    throw std::runtime_error( "Indices out of range." );
                int index = i * shape.second + j;
                return this->matrix[index];
            }
            
            /**
            Sets the element at the co-ordinates in the matrix;
            @param i Row number
            @param j Column number
            @param element Object to be the set the location
            @return Void
            **/
            void insert_element( int i, int j, T element ) {
                std::pair< int,int > shape = this->get_shape();
                if( i < 0 || i > shape.first || j < 0 || j > shape.second )
                    throw std::runtime_error( "Indices out of range." );
                int index = i * shape.second + j;
                this->matrix[index] = element;
            }
    };

}

#endif