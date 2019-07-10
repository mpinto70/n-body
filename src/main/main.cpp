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
    for (const auto& particle : s.particles()) {
        out << particle.position() << " , ";
        out << particle.velocity() << " , ";
    }
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
    constexpr double sun_mass = 1.9885e30;

    // sun at the center of the reference plan
    constexpr geometry::vec3d sun_position{ 0, 0, 0 };
    constexpr geometry::vec3d sun_velocity{ 0, 12.4, 0 };
    const space::Particle sun_particle("Sun", sun_mass, sun_position, sun_velocity);

    // earth positioned at the x(+) axis with speed in the y(+) direction
    constexpr double earth_mass = 5.97237e24;           // mass in kg
    constexpr double distance_earth_to_sun = 147.095e9; // perihelion
    constexpr double earth_orbital_speed = 30.3e3;      // in m/s
    constexpr geometry::vec3d earth_position{ distance_earth_to_sun, 0, 0 };
    constexpr geometry::vec3d earth_velocity{ 0, earth_orbital_speed, 0 };
    const space::Particle earth_particle("Earth", earth_mass, earth_position, earth_velocity);

    // jupiter positioned at the x(-) axis with speed in the y(-) direction
    constexpr double jupiter_mass = 1.8982E27;           // mass in kg
    constexpr double distance_jupiter_to_sun = 778.57e9; // mean
    constexpr double jupiter_orbital_speed = 13.07e3;    // in m/s
    constexpr geometry::vec3d jupiter_position{ -distance_jupiter_to_sun, 0, 0 };
    constexpr geometry::vec3d jupiter_velocity{ 0, -jupiter_orbital_speed, 0 };
    const space::Particle jupiter_particle("Jupiter", jupiter_mass, jupiter_position, jupiter_velocity);

    space::System s({ sun_particle, earth_particle, jupiter_particle });

    constexpr size_t years_transient = 100;
    constexpr size_t years_monitor = 200;
    constexpr size_t print_interval = 1;
    std::cerr << "skipping transient period of " << years_transient << " years\n";
    simulate<false>(s, years_transient, print_interval);
    std::cerr << "monitoring period of " << years_monitor << " years\n";
    simulate<true>(s, years_monitor, print_interval);
}
