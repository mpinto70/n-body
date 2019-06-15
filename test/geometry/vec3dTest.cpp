#include "geometry/vec3d.h"

#include <gtest/gtest.h>

namespace geometry {

constexpr vec3d U{ 7, 8, 9 };
constexpr vec3d V{ 1, 2, 4 };

TEST(vec3d, creation) {
    static_assert(U.x == 7);
    static_assert(U.y == 8);
    static_assert(U.z == 9);

    static_assert(V.x == 1);
    static_assert(V.y == 2);
    static_assert(V.z == 4);

    static_assert(V != U);
    static_assert(U == U);
    static_assert(V == V);
}

TEST(vec3d, scalar_multiplication) {
    static_assert(dot(V, I) == 1);
    static_assert(dot(V, J) == 2);
    static_assert(dot(V, K) == 4);

    static_assert(dot(U, V) == 59);
    static_assert(dot(I, J) == 0);
    static_assert(dot(I, K) == 0);
    static_assert(dot(J, K) == 0);
}

TEST(vec3d, dot) {
    static_assert(dot(V, I) == 1);
    static_assert(dot(V, J) == 2);
    static_assert(dot(V, K) == 4);

    static_assert(dot(U, V) == 59);
    static_assert(dot(I, J) == 0);
    static_assert(dot(I, K) == 0);
    static_assert(dot(J, K) == 0);
}

TEST(vec3d, cross) {
    constexpr vec3d zero{ 0, 0, 0 };
    static_assert(cross(I, I) == zero);
    static_assert(cross(J, J) == zero);
    static_assert(cross(K, K) == zero);
}
}
