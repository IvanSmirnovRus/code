#include <iostream>

template<typename T>
class TMatrix {
private:
    T* matrix;
    unsigned int rows;
    unsigned int cols;
public:
    TMatrix<T>(unsigned int r, unsigned int c) : rows(r), cols(c) {
        matrix = new T[rows * cols];
        for(unsigned int i = 0; i < rows * cols; ++i) {
            matrix[i] = T();
        }
    }

    TMatrix<T>(const TMatrix& right) {
        rows = right.RowSize();
        cols = right.ColSize();
        matrix = new T[rows*cols];
        for(unsigned int i = 0; i < rows*cols; ++i) {
            matrix[i] = right[i];
        }
    }

    ~TMatrix() {
        std::cout << "!" << (long long)(matrix) << std::endl;
        delete[] matrix;
    }

    unsigned int RowSize() const{
        return rows;
    }

    unsigned int ColSize() const{
        return cols;
    }

    const T& operator[] (unsigned int i) const{
        return matrix[i];
    }

    T& operator[] (unsigned int i) {
        return matrix[i];
    }

    const TMatrix& operator=(const TMatrix& right) {
        if () {
            // самоприсваивание
        }
        for (unsigned int r = 0; r < rows; r++) {
            for (unsigned int c = 0; c < cols; c++) {
                matrix[r*c] = right[r*c];
            }
        }
        return *this;
    }
    const TMatrix operator+ (const TMatrix& right) {
        TMatrix<T> result = TMatrix<T>(rows, cols);
        for(unsigned int r = 0; r < rows; r++) {
            for (unsigned int c = 0; c < cols; c++) {
                result[r*c] = matrix[r*c] + right[r*c];
            }
        }
        return result;
    }

    template <typename N>
    const TMatrix operator+ (const N& right) {
        TMatrix<T> result = TMatrix<T>(rows, cols);
        for(unsigned int r = 0; r < rows; r++) {
            for (unsigned int c = 0; c < cols; c++) {
                result[r*c] = matrix[r*c] + right;
            }
        }
        return result;
    }

    const TMatrix operator- (const TMatrix& right) {
        TMatrix<T> result = TMatrix<T>(rows, cols);
        for(unsigned int r = 0; r < rows; r++) {
            for (unsigned int c = 0; c < cols; c++) {
                result[r*c] = matrix[r*c] - right[r*c];
            }
        }
        return result;
    }

    template <typename N>
    const TMatrix operator- (const N& right) {
        TMatrix<T> result = TMatrix<T>(rows, cols);
        for(unsigned int r = 0; r < rows; r++) {
            for (unsigned int c = 0; c < cols; c++) {
                result[r*c] = matrix[r*c] - right;
            }
        }
        return result;
    }

    const TMatrix operator* (const TMatrix& right) {
        TMatrix<T> result = TMatrix<T>(rows, cols);
        for(unsigned int r = 0; r < rows; r++) {
            for (unsigned int c = 0; c < cols; c++) {
                result[r*c] = matrix[r*c] * right[r*c];
            }
        }
        return result;
    }

    template <typename N>
    const TMatrix operator* (const N& right) {
        TMatrix<T> result = TMatrix<T>(rows, cols);
        for(unsigned int r = 0; r < rows; r++) {
            for (unsigned int c = 0; c < cols; c++) {
                result[r*c] = matrix[r*c] * right;
            }
        }
        return result;
    }

    const TMatrix operator/ (const TMatrix& right) {
        TMatrix<T> result = TMatrix<T>(rows, cols);
        for(unsigned int r = 0; r < rows; r++) {
            for (unsigned int c = 0; c < cols; c++) {
                result[r*c] = matrix[r*c] / right[r*c];
            }
        }
        return result;
    }

    template <typename N>
    const TMatrix operator/ (const N& right) {
        TMatrix<T> result = TMatrix<T>(rows, cols);
        for(unsigned int r = 0; r < rows; r++) {
            for (unsigned int c = 0; c < cols; c++) {
                result[r*c] = matrix[r*c] / right;
            }
        }
        return result;
    }

    template <typename N>
    const TMatrix& operator+= (const N& right) {
        *this = *this + right;
        return *this;
    }

    template <typename N>
    const TMatrix operator-= (const N& right) {
        *this =  *this - right;
        return *this;
    }

    void Print() {
        std::cout << "Row="<< rows << '\t'<<"Col=" << cols << std::endl;
        for(unsigned int r = 0; r < rows; ++r) {
            for(unsigned int c = 0; c < cols; ++c) {
                std::cout << matrix[c*r] << "\t";
            }
                std::cout << std::endl;
        }
    }
};
