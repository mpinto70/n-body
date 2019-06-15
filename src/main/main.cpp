#include "geometry/vec3d.h"
#include "space/Particle.h"
#include "space/System.h"

#include <iostream>

namespace geometry {
std::ostream& operator<<(std::ostream& out, const vec3d& v) {
    out << v.x << "," << v.y << "," << v.z;
    return out;
}
}

namespace space {
std::ostream& operator<<(std::ostream& out, const System& s) {
    out << geometry::size(s.particle2().position() - s.particle1().position()) << " , ";
    out << s.particle1().position() << " , ";
    out << s.particle2().position() << " , ";
    out << s.particle1().position() - s.particle2().position() << " , ";
    out << s.particle1().velocity() << " , ";
    out << s.particle2().velocity();
    return out;
}
}

int main() {
    constexpr double earth_mass = 5.97237e24;     // mass in kg
    constexpr double distance_to_sun = 147.095e9; // perihelion
    constexpr double orbital_speed = 30.3e3;      // in m/s
    constexpr double sun_mass = 1.9885e30;

    // earth positioned at the x axis with speed in the y direction
    constexpr double m1 = earth_mass;
    constexpr geometry::vec3d p1{ distance_to_sun, 0, 0 };
    constexpr geometry::vec3d v1{ 0, orbital_speed, 0 };

    // sun at the center of the reference plan
    constexpr double m2 = sun_mass;
    constexpr geometry::vec3d p2{ 0, 0, 0 };
    constexpr geometry::vec3d v2{ 0, 0, 0 };
    const space::Particle particle1(m1, p1, v1);
    const space::Particle particle2(m2, p2, v2);

    space::System s(particle1, particle2);

    constexpr size_t days = 150000;
    constexpr double delta_t = 300; // 5 min
    for (size_t day = 0; day < days; ++day) {
        std::cout << day << "  ,  " << s << std::endl;
        double t = 0;
        while (t < 3600 * 24) {
            s.step(delta_t);
            t += delta_t;
        }
    }
    std::cout << days << "  ,  " << s << std::endl;
}
