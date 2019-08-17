#pragma once

#include "space/Particle.h"

#include <vector>

namespace space {

class System {
public:
    explicit System(std::vector<Particle> particles, double delta_t);

    [[nodiscard]] const std::vector<Particle>& particles() const { return particles_; }

    [[nodiscard]] double delta_t() const { return delta_t_; }

    void step();

private:
    std::vector<Particle> particles_;
    const double delta_t_;
    const std::vector<double> Gm_;
    std::vector<std::vector<geometry::vec3d>> unity_matrix_;
};
}
