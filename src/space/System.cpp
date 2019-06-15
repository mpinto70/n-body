#include "System.h"

#include <utility>

namespace space {

// if it is trivially copyable there is no need to std::move the particles
static_assert(std::is_trivially_copyable<Particle>::value);

System::System(Particle p1, Particle p2)
      : particle1_(p1), particle2_(p2) {
}
}
