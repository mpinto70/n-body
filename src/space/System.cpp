#include "System.h"

#include <utility>

namespace space {

namespace {
constexpr double G = 6.67430e-11;
}

// if it is trivially copyable there is no need to std::move the particles
static_assert(std::is_trivially_copyable<Particle>::value);

System::System(Particle p1, Particle p2)
      : particle1_(p1), particle2_(p2) {
}

void System::step(double delta_t) {
    const auto r = particle2_.position() - particle1_.position();
    const auto d_squared = geometry::size_square(r);
    const auto r_unity = r / std::sqrt(d_squared);
    const auto F = r_unity * (G * particle1_.mass() * particle2_.mass() / d_squared);
    particle1_.move(delta_t, F);
    particle2_.move(delta_t, -F);
}
}
