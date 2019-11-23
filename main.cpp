   #include <iostream>
   #include <fstream>

   #include "float.h"
   #include "hittable_lists.h"
   #include "sphere.h"

    Vector3 color(const Ray& r, Hittable *world) {
        hit_record rec;
        if (world->hit(r, 0.0, MAXFLOAT, rec)) {
            return 0.5*Vector3(rec.normal.getX()+1, rec.normal.getY()+1, rec.normal.getZ()+1);
        }
        else {
            Vector3 unit_direction = unit_vector(r.direction());
            float t = 0.5*(unit_direction.getY() + 1.0);
            return (1.0-t)*Vector3(1.0, 1.0, 1.0) + t*Vector3(0.5, 0.7, 1.0);
        }
    }

    int main() {
        int nx = 200;
        int ny = 100;
        std::ofstream myfile;
        myfile.open ("example.ppm");

        myfile << "P3\n" << nx << " " << ny << "\n255\n" << std::endl;

        Vector3 lower_left_corner(-2.0, -1.0, -1.0);
        Vector3 horizontal(4.0, 0.0, 0.0);
        Vector3 vertical(0.0, 2.0, 0.0);
        Vector3 origin(0.0, 0.0, 0.0);
            
        Hittable *list[2];
        list[0] = new Sphere(Vector3(0,0,-1), 0.5);
        list[1] = new Sphere(Vector3(0,-100.5,-1), 100);
        Hittable *world = new Hittable_list(list,2);

        for (int j = ny-1; j >= 0; j--) {        

            for (int i = 0; i < nx; i++) {
                float u = float(i) / float(nx);
                float v = float(j) / float(ny);

                Vector3 test = lower_left_corner + u*horizontal + v*vertical;
                Ray r(origin, test);
                
                Vector3 p = r.point_at_parameter(2.0);
                Vector3 col = color(r, world);
                
                int ir = int(255.99*col[0]);
                int ig = int(255.99*col[1]);
                int ib = int(255.99*col[2]);

                myfile << ir << " " << ig << " " << ib << std::endl;
                std::cout << ir << " " << ig << " " << ib << "\n";
            }
        }
    }