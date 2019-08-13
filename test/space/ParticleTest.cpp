#include "space/Particle.h"
#include "geometry/vec3d.h"

#include <gtest/gtest.h>

namespace space {

TEST(Particle, creation) {
    const std::string name = "some name";
    constexpr double mass = 123;
    constexpr geometry::vec3d position{ 10, 20, 30 };
    constexpr geometry::vec3d velocity{ -7, 12, -8 };

    const Particle p(name, mass, position, velocity);
    EXPECT_EQ(p.name(), name);
    EXPECT_EQ(p.mass(), mass);
    EXPECT_EQ(p.position(), position);
    EXPECT_EQ(p.velocity(), velocity);
}

TEST(Particle, move) {
    const std::string name = "name";
    constexpr double mass = 123;
    constexpr geometry::vec3d s0{ 10, 20, 30 };
    constexpr geometry::vec3d v0{ -7, 12, -8 };

    constexpr double delta_t = 0.85;
    constexpr geometry::vec3d a{ 7, 19, 20 };

    const geometry::vec3d delta_s = v0 * delta_t + a / 2 * delta_t * delta_t;
    const geometry::vec3d delta_v = a * delta_t;

    Particle p(name, mass, s0, v0);

    p.move(delta_t, a);
    EXPECT_EQ(p.name(), name);
    EXPECT_EQ(p.mass(), mass);
    EXPECT_EQ(p.position(), s0 + delta_s);
    EXPECT_EQ(p.velocity(), v0 + delta_v);
}

TEST(Particle, move_manual_calculation) {
    const std::string name = "name";
    constexpr double mass = 100;
    constexpr geometry::vec3d s0{ 10, 15, 30 };
    constexpr geometry::vec3d v0{ 2, 4, 6 };

    constexpr geometry::vec3d a{ 3, 2, 1 };
    constexpr double delta_t = 2.5;

    const geometry::vec3d delta_s = { 14.375, 16.25, 18.125 };
    const geometry::vec3d delta_v = { 7.5, 5, 2.5 };

    Particle p(name, mass, s0, v0);

    p.move(delta_t, a);
    EXPECT_EQ(p.name(), name);
    EXPECT_EQ(p.mass(), mass);
    EXPECT_EQ(p.position(), s0 + delta_s);
    EXPECT_EQ(p.velocity(), v0 + delta_v);
}
}
