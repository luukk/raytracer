#pragma once
#include "hittable.h"

class Hittable_list: public Hittable{
    public:
        Hittable_list(Hittable **, int);
        bool hit(const Ray& r, float tmin, float tmax, hit_record& rec) const override;
        
        Hittable **list;
        int list_size;
};

