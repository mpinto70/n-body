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

TEST(Particle, no_move) {
    const double mass = 123;
    const geometry::vec3d p0{ 10, 20, 30 };

    Particle p(mass, p0);

    constexpr geometry::vec3d ZERO{ 0, 0, 0 };
    constexpr geometry::vec3d velocity{ 7, -4, 2 };
    constexpr geometry::vec3d acceleration{ -7, 2, 5 };

    p.move(0.0, velocity, acceleration);
    EXPECT_EQ(p.mass(), mass);
    EXPECT_EQ(p.position(), p0);

    p.move(2.3, ZERO, ZERO);
    EXPECT_EQ(p.mass(), mass);
    EXPECT_EQ(p.position(), p0);
}

TEST(Particle, move) {
    const double mass = 123;
    const geometry::vec3d p0{ 10, 20, 30 };

    Particle p(mass, p0);

    constexpr geometry::vec3d velocity{ 7, -4, 2 };
    constexpr geometry::vec3d acceleration{ -7, 2, 5 };

    p.move(0.5, velocity, acceleration);
    const geometry::vec3d p1 = p0 + 0.5 * velocity + 0.25 * acceleration / 2;
    EXPECT_EQ(p.mass(), mass);
    EXPECT_EQ(p.position(), p1);
}
}
