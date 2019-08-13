#pragma once

#include "geometry/vec3d.h"

#include <string>

namespace space {

class Particle {
public:
    Particle(std::string name, double mass, geometry::vec3d position, geometry::vec3d velocity);

    [[nodiscard]] const std::string& name() const noexcept { return name_; }
    [[nodiscard]] double mass() const noexcept { return mass_; }
    [[nodiscard]] const geometry::vec3d& position() const noexcept { return position_; }
    [[nodiscard]] const geometry::vec3d& velocity() const noexcept { return velocity_; }

    void move(double delta_t, const geometry::vec3d& acceleration);

private:
    std::string name_;
    double mass_;
    geometry::vec3d position_;
    geometry::vec3d velocity_;
};
}
