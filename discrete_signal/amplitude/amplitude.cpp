#include "amplitude.h"

#include <ostream>

amplitude::amplitude(const double k_, const double b_): k(k_), b(b_) {
}

std::vector<double> amplitude::generate(const double p_min, const double p_max, const double p_delta) {
    std::vector<double> result;
    for (double p = p_min; p <= p_max; p += p_delta) {
        result.push_back(k * p + b);
    }
    return result;
}
