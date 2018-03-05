/**
@file
**/

#ifndef SIMPLE_MATRIX_H
#define SIMPLE_MATRIX_H

#include <iostream>
#include <cstdio>
#include <stdexcept>
#include <vector>
#include <cassert>

namespace smps {

	template <typename T>
    class MatrixExpression {
    public:
        std::pair<size_t, size_t> size() const {
            return static_cast<T const&>(*this).size();
        }

        auto operator () (size_t i, size_t j) const {
            return static_cast<T const&>(*this)(i,j);
        }

        operator T& () {
            return static_cast<T&>(*this);
        }

        operator const T& () const {
            return static_cast<const T&>(*this);
        }
    };

    template <typename T1, typename T2>
    class MatrixSum : public MatrixExpression< MatrixSum<T1, T2> > {
    public:
        T1 const& _a;
        T1 const& _b;

        MatrixSum(T1 const& a, T1 const& b) : _a(a), _b(b) {
            assert(( a.size() == b.size() ));
        }

        auto operator () (size_t i, size_t j) const {
            return _a(i,j) + _b(i,j);
        }

        std::pair<size_t, size_t> size() const {
            return _a.size();
        }
    };

    template <typename T1, typename T2>
    class MatrixProduct : public MatrixExpression< MatrixProduct<T1, T2> > {
    public:
        T1 const& _a;
        T1 const& _b;

        MatrixProduct(T1 const& a, T1 const& b) : _a(a), _b(b) {
            assert(( a.size().second == b.size().first ));
        }

        auto operator () (size_t i, size_t j) const {
            auto val = _a(i,0) * _b(0,j);
            size_t com = _a.size().second;
            for (int k = 1; k < com; k++) {
                val += _a(i,k) * _b(k,j);
            }
            return val;
        }

        std::pair<size_t, size_t> size() const {
            return std::make_pair(_a.size().first, _b.size().second);
        }
    };

    template <typename T>
    class Matrix : MatrixExpression< Matrix<T> > {
    private:
        std::vector< std::vector<T> > array;

    public:
        Matrix(size_t nrows, size_t ncols) : array(nrows) {
            for(int i = 0; i < nrows; i++) {
                array[i] = std::vector<T>(ncols);
            }
        }

        template <typename E>
        Matrix(MatrixExpression<E> const& expr) : Matrix(expr.size().first, expr.size().second) {
            size_t nrows = expr.size().first;
            size_t ncols = expr.size().second;

            for(int i = 0; i < nrows; i++) {
                for(int j = 0; j < ncols; j++) {
                    array[i][j] = expr(i,j);
                }
            }
        }

        T operator () (size_t i, size_t j) const {
            return array[i][j];
        }

        T& operator () (size_t i, size_t j) {
            return array[i][j];
        }

        std::pair<size_t, size_t> size() const {
            return std::make_pair(array.size(), array[0].size());
        }
        
    };

    template<typename T1, typename T2>
    MatrixSum<T1, T2> operator + (T1 const& u, T2 const& v) {
        return MatrixSum<T1, T2>(u, v);
    }

    template<typename T1, typename T2>
    void operator += (T1& u, T2 const& v) {
        u = MatrixSum<T1, T2>(u, v);
    }

    template<typename T1, typename T2>
    MatrixProduct<T1, T2> operator * (T1 const& u, T2 const& v) {
        return MatrixProduct<T1, T2>(u, v);
    }

    template<typename T1, typename T2>
    void operator *= (T1& u, T2 const& v) {
        u = MatrixProduct<T1, T2>(u, v);
    }

}

#endif