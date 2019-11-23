#include "ray.h"

Ray::Ray(Vector3 &a, Vector3 &b)
{
    A = &a;
    B = &b;
    // std::cout << B->getB() << std::endl;
    // Vector3 test = a;
    // this->A = a;
    // this->B = b;
    // this.A = a; 
    // B = b;
}

Vector3 Ray::origin() const {
    return *A; 
}

Vector3 Ray::direction() const { 
    return *B; 
}

Vector3 Ray::point_at_parameter(float t) const { 
    return *A + t * *B;
}
