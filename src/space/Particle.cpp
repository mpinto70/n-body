#include "Particle.h"

namespace space {

// if it is trivially copyable there is no need to std::move the position and velocity
static_assert(std::is_trivially_copyable<geometry::vec3d>::value);

//cppcheck-suppress passedByValue
Particle::Particle(std::string name, double mass, geometry::vec3d position, geometry::vec3d velocity)
      : name_(std::move(name)), mass_(mass), position_(position), velocity_(velocity) {
}

void Particle::move(double delta_t, const geometry::vec3d& force) {
    // F = m*a                            => a = F/m                   (1)
    //                                       dv = a*dt                 (2)
    // p = p0 + v*dt + (a*dt^2)/2   - (2) => p = p0 + v*dt + dv*dt/2   (3)
    // v = v0 + a*dt                - (2) => v = v0 + dv               (4)
    const auto acceleration = force / mass_;                  // (1)
    const auto delta_v = acceleration * delta_t;              // (2)
    position_ += velocity_ * delta_t + delta_v * delta_t / 2; // (3)
    velocity_ += delta_v;                                     // (4)
}
}
