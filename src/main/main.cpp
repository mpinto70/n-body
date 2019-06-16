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

namespace {
size_t day = 0;
template <bool PRINT>
void simulate(space::System& s, size_t years, size_t print_interval) {
    constexpr size_t days = 366;
    constexpr double delta_t = 300; // 5 min
    size_t print_day = print_interval;
    for (size_t year = 0; year < years; ++year) {
        for (size_t d = 0; d < days; ++d, ++day) {
            if constexpr (PRINT) {
                if (--print_day == 0) {
                    std::cout << day << "  ,  " << s << std::endl;
                    print_day = print_interval;
                }
            }
            double t = 0;
            while (t < 3600 * 24) {
                s.step(delta_t);
                t += delta_t;
            }
        }
        std::cerr << '.';
    }
    if constexpr (PRINT) {
        std::cout << day << "  ,  " << s << std::endl;
    }
    std::cerr << '\n';
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

    constexpr size_t years_transient = 1500;
    constexpr size_t years_monitor = 200;
    constexpr size_t print_interval = 1;
    std::cerr << "skipping transient period of " << years_transient << " years\n";
    simulate<false>(s, years_transient, print_interval);
    std::cerr << "monitoring period of " << years_monitor << " years\n";
    simulate<true>(s, years_monitor, print_interval);
}
