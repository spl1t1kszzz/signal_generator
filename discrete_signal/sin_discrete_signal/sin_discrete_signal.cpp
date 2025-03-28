#include "sin_discrete_signal.h"

sin_discrete_signal::sin_discrete_signal(const double amplitude_, const double frequency_): amplitude(amplitude_),
    frequency(frequency_) {
}


std::vector<double> sin_discrete_signal::generate(const double x_min, const double x_max, const double x_delta) {
    std::vector<double> result;
    double x;
    if (x_delta > 0) {
        for (x = x_min; x <= x_max; x += x_delta) {
            result.emplace_back(amplitude * std::sin(frequency * x));
        }
    } else {
        for (x = x_min; x >= x_max; x += x_delta) {
            result.emplace_back(amplitude * std::sin(frequency * x));
        }
    }
    if (std::abs(x - x_max) > std::numeric_limits<double>::epsilon()) {
        result.emplace_back(amplitude * std::sin(frequency * x_max));
    }
    return result;
}
