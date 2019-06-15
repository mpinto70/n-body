#include "space/Particle.h"
#include "geometry/vec3d.h"

#include <gtest/gtest.h>

namespace space {

TEST(Particle, creation) {
    const double mass = 123;
    const geometry::vec3d position{ 10, 20, 30 };

    Particle p(mass, position);
    EXPECT_EQ(p.mass(), mass);
    EXPECT_EQ(p.position(), position);
}
}
