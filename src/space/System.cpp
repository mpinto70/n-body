#include "System.h"

#include <algorithm>
#include <numeric>
#include <utility>

namespace space {

namespace {
constexpr double G = 6.67430e-11;
std::vector<double> create_Gm(const std::vector<Particle>& particles) {
    // calculate Gm from eq. 19
    std::vector<double> res(particles.size());
    std::transform(particles.begin(), particles.end(), res.begin(), [](const Particle& p) { return G * p.mass(); });
    return res;
}

constexpr geometry::vec3d ZERO{ 0, 0, 0 };
}

System::System(std::vector<Particle> particles, double delta_t)
      : particles_(std::move(particles)),
        delta_t_(delta_t),
        Gm_(create_Gm(particles_)),
        unity_matrix_(particles_.size()) {
    for (auto& forces_row : unity_matrix_) {
        forces_row.resize(particles_.size(), ZERO);
    }
}

void System::step() {
    for (auto& forces_row : unity_matrix_) {
        std::fill(forces_row.begin(), forces_row.end(), ZERO);
    }

    for (size_t i = 0; i < particles_.size(); ++i) {
        const auto& s_i = particles_[i].position();
        for (size_t j = i + 1; j < particles_.size(); ++j) {
            const auto& s_j = particles_[j].position();
            const auto r_ij = s_j - s_i;                           // (2)
            const auto r_ij_squared = geometry::size_square(r_ij); // r^2 = r_ij dot r_ij
            const auto u_ij = r_ij / std::sqrt(r_ij_squared);      // (3)
            const auto frac_ij = u_ij / r_ij_squared;              // (18)
            unity_matrix_[i][j] = frac_ij;                         // (18)
            unity_matrix_[j][i] = -frac_ij;                        // (18)
        }
    }

    for (size_t i = 0; i < particles_.size(); ++i) {
        const auto& unity_row = unity_matrix_[i];
        const auto a_i = std::inner_product(unity_row.begin(), unity_row.end(), Gm_.begin(), ZERO);
        particles_[i].move(delta_t_, a_i);
    }
}
}
