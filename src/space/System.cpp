#include "System.h"

#include <utility>

namespace space {

namespace {
constexpr double G = 6.67430e-11;
}

System::System(std::vector<Particle> particles)
      : particles_(std::move(particles)) {
}

void System::step(double delta_t) {
    constexpr geometry::vec3d ZERO{ 0, 0, 0 };
    std::vector<std::vector<geometry::vec3d>> forces_matrix(particles_.size());
    for (auto& forces_row : forces_matrix) {
        forces_row.resize(particles_.size(), ZERO);
    }
    for (size_t i = 0; i < particles_.size(); ++i) {
        const auto GI = G * particles_[i].mass();
        for (size_t j = i + 1; j < particles_.size(); ++j) {
            if (i == j)
                continue;
            const auto r = particles_[j].position() - particles_[i].position();
            const auto d_squared = geometry::size_square(r);
            const auto r_unity = r / std::sqrt(d_squared);
            const auto F = r_unity * (GI * particles_[j].mass() / d_squared);
            forces_matrix[i][j] = F;
            forces_matrix[j][i] = -F;
        }
    }

    for (size_t i = 0; i < particles_.size(); ++i) {
        geometry::vec3d force = ZERO;
        for (size_t j = 0; j < particles_.size(); ++j) {
            if (i == j)
                continue;
            force += forces_matrix[i][j];
        }
        particles_[i].move(delta_t, force);
    }
}
}
