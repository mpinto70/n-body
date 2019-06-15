#pragma once

#include "../geometry/vec3d.h"

namespace space {

class Particle {
public:
    Particle(double mass, geometry::vec3d position);

    double mass() const noexcept { return mass_; }

    const geometry::vec3d& position() const noexcept { return position_; }

    void move(double delta_t,
          const geometry::vec3d& velocity,
          const geometry::vec3d& acceleration);

private:
    double mass_;
    geometry::vec3d position_;
};
}
