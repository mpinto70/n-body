#include "System.h"

#include <utility>

namespace space {

namespace {
constexpr double G = 6.67430e-11;
}

// if it is trivially copyable there is no need to std::move the particles
static_assert(std::is_trivially_copyable<Particle>::value);

System::System(Particle p1, Particle p2)
      : particles_{ p1, p2 } {
}

void System::step(double delta_t) {
    const auto r = particles_[1].position() - particles_[0].position();
    const auto d_squared = geometry::size_square(r);
    const auto r_unity = r / std::sqrt(d_squared);
    const auto F = r_unity * (G * particles_[0].mass() * particles_[1].mass() / d_squared);
    particles_[0].move(delta_t, F);
    particles_[1].move(delta_t, -F);
}
}
