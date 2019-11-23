#include "vector.h"

Vector3::Vector3(float e0, float e1, float e2) {
    // std::cout << "vector init: " << e0 << e1 << e2 << std::endl;
    e[0] = e0; //each position holds both the position as the color map position (alpha channel included)
    e[1] = e1;
    e[2] = e2;
}

float Vector3::getX() const {
    return e[0];
}

float Vector3::getY() const {
    return e[1];
}

float Vector3::getZ() const {
    return e[2];
}

float Vector3::getR() const {
    return e[0];
}

float Vector3::getG() const {
    return e[1];
}

float Vector3::getB() const {
    return e[2];
}

const Vector3& Vector3::operator+() const {
    return *this;
}

Vector3 Vector3::operator-() const {
    return Vector3(-e[0], -e[1], -e[2]);
};

float Vector3::operator[](int i) const {
    return e[i];
};

float& Vector3::operator[](int i) {
    return e[i];
};

Vector3& Vector3::operator+=(const Vector3 &v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
};
Vector3& Vector3::operator-=(const Vector3 &v) {
    e[0] -= v.e[0];
    e[1] -= v.e[1];
    e[2] -= v.e[2];
    return *this;
};
Vector3& Vector3::operator*=(const Vector3 &v) {
    e[0] *= v.e[0];
    e[1] *= v.e[1];
    e[2] *= v.e[2];
    return *this;
};

Vector3& Vector3::operator*=(const float t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

Vector3& Vector3::operator/=(const Vector3 &v) {
    e[0] /= v.e[0];
    e[1] /= v.e[1];
    e[2] /= v.e[2];
    return *this;
};
Vector3& Vector3::operator/=(const float t) {
    float k = 1.0/t;

    e[0] *= k;
    e[1] *= k;
    e[2] *= k;
    return *this;
};

void Vector3::make_unit_vector() {
    float k = 1.0 / sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
    e[0] *= k; e[1] *= k; e[2] *= k;
}

float Vector3::length() const {
    return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
}

float Vector3::squared_length() const {
    return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
}

/*---------------   VECTOR3 MEMBERS    ---------------*/

Vector3 operator+(const Vector3 &v1, const Vector3 &v2) {
    return Vector3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

Vector3 operator-(const Vector3 &v1, const Vector3 &v2) {
    return Vector3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

Vector3 operator*(const Vector3 &v1, const Vector3 &v2) {
    return Vector3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

Vector3 operator*(float t, const Vector3 &v) {
    return Vector3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

Vector3 operator*(const Vector3 &v, float t) {
    return Vector3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

Vector3 operator/(const Vector3 &v1, const Vector3 &v2) {
    return Vector3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}

Vector3 operator/(Vector3 v, float t) {
    return Vector3(v.e[0]/t, v.e[1]/t, v.e[2]/t);
}

float dot(const Vector3 &v1, const Vector3 &v2) {
    return v1.e[0]*v2.e[0]
         + v1.e[1]*v2.e[1]
         + v1.e[2]*v2.e[2];
}

Vector3 cross(const Vector3 &v1, const Vector3 &v2) {
    return Vector3(v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1],
                v1.e[2] * v2.e[0] - v1.e[0] * v2.e[2],
                v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]);
}

Vector3 unit_vector(Vector3 v) {
    return v / v.length();
}