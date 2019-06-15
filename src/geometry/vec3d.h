#pragma once

namespace geometry {

struct vec3d {
    double x, y, z;
};

constexpr double dot(const vec3d& u, const vec3d& v) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

constexpr vec3d I{ 1, 0, 0 };
constexpr vec3d J{ 0, 1, 0 };
constexpr vec3d K{ 0, 0, 1 };
}
