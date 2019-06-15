#include "geometry/vec3d.h"

#include <gtest/gtest.h>

namespace geometry {

TEST(vec3d, creation) {
    const vec3d v{1, 2, 4};
    EXPECT_EQ(v.x, 1);
    EXPECT_EQ(v.y, 2);
    EXPECT_EQ(v.z, 4);
}
}
