#pragma once

#include "space/Particle.h"

#include <vector>

namespace space {

class System {
public:
    System(Particle p1, Particle p2);

    const std::vector<Particle>& particles() const { return particles_; }
    const Particle& particle1() const { return particles_[0]; }
    const Particle& particle2() const { return particles_[1]; }

    void step(double delta_t);

private:
    std::vector<Particle> particles_;
};
}
