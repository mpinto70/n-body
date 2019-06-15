#include "Particle.h"

namespace space {
Particle::Particle(double mass, geometry::vec3d position)
      : mass_(mass), position_(position) {
}

void Particle::move(double delta_t,
      const geometry::vec3d& velocity,
      const geometry::vec3d& acceleration) {
    position_ += delta_t * velocity + delta_t * delta_t * acceleration / 2;
}
}
