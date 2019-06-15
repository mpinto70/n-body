#include "space/System.h"
#include "geometry/vec3d.h"

#include <gtest/gtest.h>

namespace space {

TEST(System, creation) {
    constexpr double m1 = 123;
    constexpr geometry::vec3d p1{ 10, 20, 30 };
    constexpr geometry::vec3d v1{ 40, 50, 60 };
    constexpr double m2 = 487;
    constexpr geometry::vec3d p2{ -25, 17, 96 };
    constexpr geometry::vec3d v2{ -17, 25, 69 };
    const Particle particle1(m1, p1, v1);
    const Particle particle2(m2, p2, v2);

    const System s(particle1, particle2);
    EXPECT_EQ(s.particle1().mass(), m1);
    EXPECT_EQ(s.particle1().position(), p1);
    EXPECT_EQ(s.particle1().velocity(), v1);
    EXPECT_EQ(s.particle2().mass(), m2);
    EXPECT_EQ(s.particle2().position(), p2);
    EXPECT_EQ(s.particle2().velocity(), v2);
}
}
