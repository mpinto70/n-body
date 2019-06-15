#include "Particle.h"

namespace space {

// if it is trivially copyable there is no need to std::move the position
static_assert(std::is_trivially_copyable<geometry::vec3d>::value);

Particle::Particle(double mass, geometry::vec3d position)
      : mass_(mass), position_(position) {
}
}
