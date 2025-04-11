#include <iostream>
using namespace std;

class Vector2D {
    double x, y;

public:
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    Vector2D operator+(Vector2D& v) {
        return Vector2D(x + v.x, y + v.y);
    }

    Vector2D operator-(Vector2D& v) const {
        return Vector2D(x - v.x, y - v.y);
    }

    Vector2D operator*(double scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    friend double dotProduct(Vector2D& v1, Vector2D& v2);

    friend ostream& operator<<(ostream& out, Vector2D& v);
};

double dotProduct(Vector2D& v1, Vector2D& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

ostream& operator<<(ostream& out, Vector2D& v) {
    out << "(" << v.x << ", " << v.y << ")";
    return out;
}

int main() {
    Vector2D a(3, 4);
    Vector2D b(1, 2);

    Vector2D sum = a + b;
    Vector2D diff = a - b;
    Vector2D scaled = a * 2.5;
    double dot = dotProduct(a, b);

    cout << "A: " << a << endl;
    cout << "B: " << b << endl;
    cout << "A + B: " << sum << endl;
    cout << "A - B: " << diff << endl;
    cout << "A * 2.5: " << scaled << endl;
    cout << "Dot Product: " << dot << endl;

    return 0;
}
