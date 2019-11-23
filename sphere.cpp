#include "sphere.h"

Sphere::Sphere(Vector3 cen, float r)
    :center(cen), 
     radius(r)  
    {}

bool Sphere::hit(const Ray& r, float t_min, float t_max, hit_record& rec) const {
    Vector3 oc = r.origin() - center;
    float a = dot(r.direction(), r.direction());
    float b = dot(oc, r.direction());
    float c = dot(oc, oc) - radius*radius;
    float discriminant = b*b - a*c;
    if (discriminant > 0) {
        float temp = (-b - sqrt(discriminant))/a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            Vector3 p = r.point_at_parameter(rec.t);
            rec.p = p;
            Vector3 calulation = ((rec.p) - center) / radius;
            rec.normal = calulation;
            return true;
        }
        temp = (-b + sqrt(discriminant)) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            Vector3 ptest = r.point_at_parameter(rec.t);
            rec.p = ptest;
            Vector3 calc = ((rec.p) - center) / radius;
            rec.normal = calc;
            return true;
        }
    }
    return false;
}