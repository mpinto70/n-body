#include "geometry/vec3d.h"

#include <iostream>

namespace geometry {
std::ostream& operator<<(std::ostream& out, const vec3d& v) {
    out << v.x << "," << v.y << "," << v.z;
    return out;
}
}

int main() {
    const geometry::vec3d v = { 1.0, 2.0, 3.0 };

    std::cout << v << std::endl;
}
