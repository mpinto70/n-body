#include "space/System.h"
#include "geometry/vec3d.h"

#include <gtest/gtest.h>

namespace space {

TEST(System, creation) {
    const double m1 = 123;
    const geometry::vec3d p1{ 10, 20, 30 };
    const double m2 = 487;
    const geometry::vec3d p2{ -25, 17, 96 };
    const Particle particle1(m1, p1);
    const Particle particle2(m2, p2);

    const System s(particle1, particle2);
    EXPECT_EQ(s.particle1().mass(), m1);
    EXPECT_EQ(s.particle1().position(), p1);
    EXPECT_EQ(s.particle2().mass(), m2);
    EXPECT_EQ(s.particle2().position(), p2);
}
}
