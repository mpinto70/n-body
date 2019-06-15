#include "geometry/vec3d.h"

#include <iostream>

int main() {
    const geometry::vec3d v = {1.0, 2.0, 3.0};

    std::cout << v.x << "," << v.y << "," << v.z << std::endl;
}
