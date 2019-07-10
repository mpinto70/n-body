#include "Particle.h"

namespace space {

// if it is trivially copyable there is no need to std::move the position
static_assert(std::is_trivially_copyable<geometry::vec3d>::value);

Particle::Particle(std::string name, double mass, geometry::vec3d position, geometry::vec3d velocity)
      : name_(std::move(name)), mass_(mass), position_(position), velocity_(velocity) {
}

void Particle::move(double delta_t, const geometry::vec3d& force) {
    const auto acceleration = force / mass_;
    const auto delta_v = acceleration * delta_t;
    position_ += velocity_ * delta_t + delta_v / (2 / delta_t); // p = p0 + v*dt + (dv/2) * dt
    velocity_ += delta_v;
}
}
