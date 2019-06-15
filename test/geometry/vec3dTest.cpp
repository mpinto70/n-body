#include "geometry/vec3d.h"

#include <gtest/gtest.h>

namespace geometry {

TEST(vec3d, creation) {
    const vec3d v{ 1, 2, 4 };
    EXPECT_EQ(v.x, 1);
    EXPECT_EQ(v.y, 2);
    EXPECT_EQ(v.z, 4);
}

TEST(vec3d, dot) {
    const vec3d v{ 1, 2, 4 };
    EXPECT_EQ(dot(v, I), 1);
    EXPECT_EQ(dot(v, J), 2);
    EXPECT_EQ(dot(v, K), 4);

    const vec3d u{ 7, 8, 9 };
    EXPECT_EQ(dot(u, v), 59);
    static_assert(dot(I, J) == 0);
    static_assert(dot(I, K) == 0);
    static_assert(dot(J, K) == 0);
}
}
