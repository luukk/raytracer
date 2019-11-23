#pragma once
#include "vector.h"

class Ray
{
    public:
        // Ray();
        Ray(Vector3&, Vector3&);
        Vector3 origin() const;
        Vector3 direction() const;
        Vector3 point_at_parameter(float) const;

        Vector3 *A;
        Vector3 *B;
};