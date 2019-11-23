#pragma once
#include "hittable.h"

class Sphere: public Hittable  {
    public:
        Sphere(Vector3, float);
        bool hit(const Ray&, float, float, hit_record&) const override;
        
        Vector3 center;
        float radius;
};