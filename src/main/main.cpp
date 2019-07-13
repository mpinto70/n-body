#include "geometry/vec3d.h"
#include "space/Particle.h"
#include "space/System.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdexcept>

namespace geometry {
std::ostream& operator<<(std::ostream& out, const vec3d& v) {
    out << v.x << "," << v.y << "," << v.z;
    return out;
}
}

namespace space {
std::ostream& operator<<(std::ostream& out, const System& s) {
    for (const auto& particle : s.particles()) {
        out << particle.position() << " , ";
        out << particle.velocity() << " , ";
    }
    return out;
}
}

namespace {
size_t day = 0;
template <bool PRINT>
void simulate(space::System& s, size_t years, size_t print_interval) {
    constexpr size_t days = 366;
    constexpr double delta_t = 300; // 5 min
    size_t print_day = print_interval;
    for (size_t year = 0; year < years; ++year) {
        for (size_t d = 0; d < days; ++d, ++day) {
            if constexpr (PRINT) {
                if (--print_day == 0) {
                    std::cout << day << "  ,  " << s << std::endl;
                    print_day = print_interval;
                }
            }
            double t = 0;
            while (t < 3600 * 24) {
                s.step(delta_t);
                t += delta_t;
            }
        }
        std::cerr << '.';
    }
    if constexpr (PRINT) {
        std::cout << day << "  ,  " << s << std::endl;
    }
    std::cerr << '\n';
}

std::string& ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](auto c) { return not std::isspace(c); }));
    return s;
}

std::string& rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](auto c) { return not std::isspace(c); }).base(), s.end());
    return s;
}

std::string& trim(std::string& s) {
    return ltrim(rtrim(s));
}

std::string trim_copy(std::string s) {
    return trim(s);
}
std::string& remove_comment(std::string& s) {
    s.erase(std::find(s.begin(), s.end(), '#'), s.end());
    return s;
}

std::vector<std::string> split(std::string line, char separator) {
    std::vector<std::string> tokens;
    while (not ltrim(line).empty()) {
        auto pos = find(line.begin(), line.end(), separator);
        tokens.emplace_back(line.begin(), pos);
        if (pos != line.end())
            ++pos;
        line.erase(line.begin(), pos);
    }
    return tokens;
}

geometry::vec3d to_vec3d(const std::string& token) {
    const std::vector<std::string> coordinates = split(token, ',');
    if (coordinates.size() != 3)
        throw std::invalid_argument("Invalid vec 3d specification: " + token);

    const auto x = std::stod(coordinates[0]);
    const auto y = std::stod(coordinates[1]);
    const auto z = std::stod(coordinates[2]);

    return { x, y, z };
}
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <configuration file>\n";
        return -1;
    }

    const std::string config_file_name = argv[1];
    std::ifstream config_file(config_file_name);
    if (!config_file) {
        std::cerr << "Configuration file not found " << config_file_name << "\n";
        return -2;
    }

    std::cerr << "Reading configuration from " << config_file_name << "\n";

    std::vector<space::Particle> particles;
    std::string line;
    int line_number = 0;
    try {
        while (std::getline(config_file, line)) {
            ++line_number;
            trim(remove_comment(line));

            if (line.empty())
                continue;

            const auto columns = split(line, '|');
            if (columns.size() != 4) {
                throw std::invalid_argument("Invalid line");
            }

            const auto body_name = trim_copy(columns[0]);
            const auto body_mass = std::stod(columns[1]);
            const auto body_position = to_vec3d(columns[2]);
            const auto body_velocity = to_vec3d(columns[3]);

            particles.emplace_back(body_name, body_mass, body_position, body_velocity);
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << " [at line " << line_number << "]: [" << line << "]\n";
        return -3;
    }

    std::cerr << "Starting the simulation\n";

    space::System s(particles);

    constexpr size_t years_transient = 100;
    constexpr size_t years_monitor = 200;
    constexpr size_t print_interval = 1;
    std::cerr << "Skipping transient period of " << years_transient << " years\n";
    simulate<false>(s, years_transient, print_interval);
    std::cerr << "Monitoring period of " << years_monitor << " years\n";
    simulate<true>(s, years_monitor, print_interval);
}
