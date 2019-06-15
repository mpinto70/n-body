#pragma once

#include "space/Particle.h"

namespace space {

class System {
public:
    System(Particle p1, Particle p2);

    const Particle& particle1() const { return particle1_; }
    const Particle& particle2() const { return particle2_; }

    void step(double delta_t);

private:
    Particle particle1_;
    Particle particle2_;
};
}
