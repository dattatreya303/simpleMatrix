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
                num_rows = nrows;
                num_cols = ncols;
                matrix = ( T* ) malloc( sizeof( T ) * num_rows * num_cols );
            }

            Matrix( const Matrix<T> &M ) {
                std::pair< size_t, size_t > shape = get_shape( M );
                Matrix( shape.first, shape.second );
                for( int i = 0; i < shape.first * shape.second; i++ ) {
                    matrix[i] = M[i];
                }
            }

            ~Matrix() {
                for( int i = 0; i < num_rows * num_cols; i++ ) {
                    free( matrix[i] );
                }
                free(matrix);
            }

            Matrix& operator = ( const Matrix &other );
            Matrix& operator + ( const Matrix &other );
            Matrix& operator += ( const Matrix &other );
            Matrix& operator * ( const Matrix &other );
            Matrix& operator *= ( const Matrix &other );

            std::pair< size_t, size_t > get_shape();
            void insert_element( int i, int j, T element );
            T get_element( int i, int j );
    };

}