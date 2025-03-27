#include "result_discrete_signal.h"

std::vector<double> result_discrete_signal::generate(double x_min, double x_max, double x_delta) {
    auto sds = sin_discrete_signal(amplitude, frequency);
    auto cds = cos_discrete_signal(amplitude, frequency);
    auto f = sds.generate(x_min, x_max, x_delta);
    auto g = cds.generate(x_min, x_max, x_delta);
    if (f.size() != g.size()) {
        throw std::runtime_error("Размеры f и g не совпадают");
    }
    std::vector<double> h(f.size());
    std::transform(f.begin(), f.end(), g.begin(), h.begin(), std::plus());
    return h;
}

result_discrete_signal::result_discrete_signal(const double amplitude_, const double frequency_): amplitude(amplitude_),
    frequency(frequency_) {
}
