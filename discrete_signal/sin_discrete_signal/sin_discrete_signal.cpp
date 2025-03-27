#include "sin_discrete_signal.h"

sin_discrete_signal::sin_discrete_signal(const double amplitude_, const double frequency_): amplitude(amplitude_),
    frequency(frequency_) {
}


std::vector<double> sin_discrete_signal::generate(const double x_min, const double x_max, const double x_delta) {
    std::vector<double> result;
    if (x_delta > 0) {
        for (double x = x_min; x < x_max; x += x_delta) {
            result.emplace_back(amplitude * std::sin(frequency * x));
        }
    } else {
        for (double x = x_min; x > x_max; x += x_delta) {
            result.emplace_back(amplitude * std::sin(frequency * x));
        }
    }
    return result;
}
