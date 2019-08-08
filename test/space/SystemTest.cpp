#include "space/System.h"
#include "geometry/vec3d.h"

#include <gtest/gtest.h>

namespace space {

TEST(System, creation) {
    const std::string n1 = "name1";
    constexpr double m1 = 123;
    constexpr geometry::vec3d p1{ 10, 20, 30 };
    constexpr geometry::vec3d v1{ 40, 50, 60 };
    constexpr double m2 = 487;
    const std::string n2 = "name2";
    constexpr geometry::vec3d p2{ -25, 17, 96 };
    constexpr geometry::vec3d v2{ -17, 25, 69 };
    const Particle particle1(n1, m1, p1, v1);
    const Particle particle2(n2, m2, p2, v2);

    const System s({ particle1, particle2 }, 127.5);
    EXPECT_EQ(s.particles()[0].name(), n1);
    EXPECT_EQ(s.particles()[0].mass(), m1);
    EXPECT_EQ(s.particles()[0].position(), p1);
    EXPECT_EQ(s.particles()[0].velocity(), v1);
    EXPECT_EQ(s.particles()[1].name(), n2);
    EXPECT_EQ(s.particles()[1].mass(), m2);
    EXPECT_EQ(s.particles()[1].position(), p2);
    EXPECT_EQ(s.particles()[1].velocity(), v2);
    EXPECT_EQ(s.delta_t(), 127.5);
}
}
