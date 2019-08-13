#include "System.h"

#include <numeric>
#include <utility>

namespace space {

namespace {
constexpr double G = 6.67430e-11;
}

System::System(std::vector<Particle> particles, double delta_t)
      : particles_(std::move(particles)), delta_t_(delta_t) {
}

void System::step() {
    constexpr geometry::vec3d ZERO{ 0, 0, 0 };
    std::vector<std::vector<geometry::vec3d>> unity_matrix(particles_.size());
    for (auto& forces_row : unity_matrix) {
        forces_row.resize(particles_.size(), ZERO);
    }

    for (size_t i = 0; i < particles_.size(); ++i) {
        for (size_t j = i + 1; j < particles_.size(); ++j) {
            const auto r = particles_[j].position() - particles_[i].position(); // (2)
            const auto r_squared = geometry::size_square(r);                    // r^2 = r dot r
            const auto u = r / std::sqrt(r_squared);                            // (3)
            const auto frac = u / r_squared;                                    // (15)
            unity_matrix[i][j] = frac;
            unity_matrix[j][i] = -frac;
        }
    }

    std::vector<double> Gm;
    Gm.reserve(particles_.size());
    for (const auto& particle : particles_) {
        Gm.push_back(G * particle.mass());
    }

    for (size_t i = 0; i < particles_.size(); ++i) {
        const auto& unity_row = unity_matrix[i];
        const auto a = std::inner_product(unity_row.begin(), unity_row.end(), Gm.begin(), ZERO);
        particles_[i].move(delta_t_, a);
    }
}
}
