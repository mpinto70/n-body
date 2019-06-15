#include "space/Particle.h"
#include "geometry/vec3d.h"

#include <gtest/gtest.h>

namespace space {

TEST(Particle, creation) {
    const double mass = 123;
    const geometry::vec3d position{ 10, 20, 30 };

    const Particle p(mass, position);
    EXPECT_EQ(p.mass(), mass);
    EXPECT_EQ(p.position(), position);
}

TEST(Particle, move) {
    constexpr double mass = 123;
    constexpr geometry::vec3d p0{ 10, 20, 30 };
    constexpr geometry::vec3d delta{ 2, -7, 4 };

    Particle p(mass, p0);

    p.move(delta);
    EXPECT_EQ(p.mass(), mass);
    EXPECT_EQ(p.position(), p0 + delta);
}
}
