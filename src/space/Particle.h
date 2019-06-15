#pragma once

#include "geometry/vec3d.h"

namespace space {

class Particle {
public:
    Particle(double mass, geometry::vec3d position, geometry::vec3d velocity);

    double mass() const noexcept { return mass_; }
    const geometry::vec3d& position() const noexcept { return position_; }
    const geometry::vec3d& velocity() const noexcept { return velocity_; }

    void move(double delta_t, const geometry::vec3d& force);

private:
    double mass_;
    geometry::vec3d position_;
    geometry::vec3d velocity_;
};
}
