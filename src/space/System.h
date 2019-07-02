#pragma once

#include "space/Particle.h"

#include <vector>

namespace space {

class System {
public:
    System(std::vector<Particle> particles);

    const std::vector<Particle>& particles() const { return particles_; }

    void step(double delta_t);

private:
    std::vector<Particle> particles_;
};
}
