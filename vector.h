#pragma once 
#include <math.h>
#include <iostream>

class Vector3 {
    public:
        Vector3() {};
        Vector3(float, float, float);
        float getX() const;
        float getY() const;
        float getZ() const;
        float getR() const;
        float getG() const;
        float getB() const;

        const Vector3& operator+() const;
        Vector3 operator-() const;
        float operator[](int) const;
        float& operator[](int);

        Vector3& operator+=(const Vector3&);
        Vector3& operator-=(const Vector3&);
        Vector3& operator*=(const Vector3&);
        Vector3& operator/=(const Vector3&);
        Vector3& operator*=(const float);
        Vector3& operator/=(const float);

        float length() const;
        float squared_length() const;
        void make_unit_vector();
    // private:
        float e[3];
};

    Vector3 operator+(const Vector3&, const Vector3&);
    Vector3 operator-(const Vector3&, const Vector3&);
    Vector3 operator*(const Vector3&, const Vector3&);
    Vector3 operator*(float, const Vector3&);
    Vector3 operator*(const Vector3&, float);
    Vector3 operator/(const Vector3&, const Vector3&);
    Vector3 operator/(const Vector3, float);

    Vector3 unit_vector(Vector3);
    float dot(const Vector3&, const Vector3&);
    Vector3 cross(const Vector3&, const Vector3&);