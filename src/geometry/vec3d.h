#pragma once

namespace geometry {

struct vec3d {
    double x, y, z;
};

constexpr bool operator==(const vec3d& u, const vec3d& v) noexcept {
    return u.x == v.x && u.y == v.y && u.z == v.z;
}

constexpr bool operator!=(const vec3d& u, const vec3d& v) noexcept {
    return not(u == v);
}

constexpr vec3d operator*(const vec3d& v, double s) noexcept {
    return vec3d{ v.x * s, v.y * s, v.z * s };
}

constexpr vec3d operator*(double s, const vec3d& v) noexcept {
    return v * s;
}

constexpr vec3d operator/(const vec3d& v, double s) noexcept {
    return vec3d{ v.x / s, v.y / s, v.z / s };
}

constexpr double dot(const vec3d& u, const vec3d& v) noexcept {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

constexpr vec3d cross(const vec3d& u, const vec3d& v) noexcept {
    return { u.y * v.z - u.z * v.y,
        u.z * v.x - u.x * v.z,
        u.x * v.y - u.y * v.x };
}

constexpr vec3d I{ 1, 0, 0 };
constexpr vec3d J{ 0, 1, 0 };
constexpr vec3d K{ 0, 0, 1 };
}
