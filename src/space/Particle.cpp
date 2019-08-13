#include "Particle.h"

namespace space {

// if it is trivially copyable there is no need to std::move the position and velocity
static_assert(std::is_trivially_copyable<geometry::vec3d>::value);

//cppcheck-suppress passedByValue
Particle::Particle(std::string name, double mass, geometry::vec3d position, geometry::vec3d velocity)
      : name_(std::move(name)), mass_(mass), position_(position), velocity_(velocity) {
}

void Particle::move(double delta_t, const geometry::vec3d& acceleration) {
    const auto delta_v = acceleration * delta_t;      // (11)
    position_ += (velocity_ + delta_v / 2) * delta_t; // (12)
    velocity_ += delta_v;                             // (13)
}
}
