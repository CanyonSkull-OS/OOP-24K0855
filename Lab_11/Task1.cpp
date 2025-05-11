#include <iostream>
#include <stdexcept>
#include <sstream>

using namespace std;

class DimensionMismatchException : public exception {
    string message;
public:
    DimensionMismatchException(int r1, int c1, int r2, int c2) {
        stringstream ss;
        ss << "Matrices must have same dimensions (" << r1 << "x" << 
        c1 << " vs " << r2 << "x" << c2 << ") !";
        message = ss.str();
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

template<typename T>
class Matrix {
    T** data;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i)
            data[i] = new T[cols]();
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }

    void set(int r, int c, T value) {
        data[r][c] = value;
    }

    T get(int r, int c) {
        return data[r][c];
    }

    int getRows() { return rows; }
    int getCols() { return cols; }

    Matrix<T> operator+(Matrix<T>& other) {
        if (rows != other.rows || cols != other.cols) {
            throw DimensionMismatchException(rows, cols, other.rows, other.cols);
        }

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.set(i, j, data[i][j] + other.data[i][j]);
        return result;
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    try {
        Matrix<int> A(2, 2);
        Matrix<int> B(2, 2);

        A.set(0, 0, 1);
        A.set(0, 1, 2);
        A.set(1, 0, 3); 
        A.set(1, 1, 4);

        B.set(0, 0, 5); 
        B.set(0, 1, 6); 
        B.set(1, 0, 7);
        B.set(1, 1, 8); 
 

        Matrix<int> C = A + B;

        C.print();
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
