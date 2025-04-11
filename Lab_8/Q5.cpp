#include <iostream>
using namespace std;

class Matrix2x2 {
    int a, b, c, d;

public:
    Matrix2x2(int a = 0, int b = 0, int c = 0, int d = 0)
        : a(a), b(b), c(c), d(d) {}

    Matrix2x2 operator+(Matrix2x2 obj) {
        return Matrix2x2(a + obj.a, b + obj.b, c + obj.c, d + obj.d);
    }

    Matrix2x2 operator-(Matrix2x2 obj) {
        return Matrix2x2(a - obj.a, b - obj.b, c - obj.c, d - obj.d);
    }

    Matrix2x2 operator*(Matrix2x2 obj) {
        int r1 = a * obj.a + b * obj.c;
        int r2 = a * obj.b + b * obj.d;
        int r3 = c * obj.a + d * obj.c;
        int r4 = c * obj.b + d * obj.d;
        return Matrix2x2(r1, r2, r3, r4);
    }

    friend ostream& operator<<(ostream& out, Matrix2x2 obj) {
        out << "| " << obj.a << "  " << obj.b << " |" << endl;
        out << "| " << obj.c << "  " << obj.d << " |";
        return out;
    }

    friend int determinant(Matrix2x2& obj) {
        return obj.a * obj.d - obj.b * obj.c;
    }

    friend class MatrixHelper;
};

class MatrixHelper {
public:
    static void updateElement(Matrix2x2& matrix, int row, int col, int value) {
        if (row == 0 && col == 0) matrix.a = value;
        else if (row == 0 && col == 1) matrix.b = value;
        else if (row == 1 && col == 0) matrix.c = value;
        else if (row == 1 && col == 1) matrix.d = value;
        else cout << "Invalid indices!" << endl;
    }
};

int main() {
    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2(5, 6, 7, 8);

    Matrix2x2 sum = m1 + m2;
    Matrix2x2 diff = m1 - m2;
    Matrix2x2 prod = m1 * m2;

    cout << "Matrix 1:" << endl << m1 << endl;
    cout << "Matrix 2:" << endl << m2 << endl;

    cout << endl <<"Sum:" << endl << sum << endl;
    cout << endl << "Difference:" << endl << diff << endl;
    cout << endl << "Product:" << endl << prod << endl;

    cout << endl << "Determinant of Matrix 1: " <<endl <<  determinant(m1) << endl;

    cout << "Updating element at (0, 1) of Matrix 1 to 10..." << endl;
    MatrixHelper::updateElement(m1, 0, 1, 10);

    cout << "Updated Matrix 1:" << m1 << endl;

    return 0;
}
