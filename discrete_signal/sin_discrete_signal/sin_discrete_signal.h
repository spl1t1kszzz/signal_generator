#ifndef SIN_DISCRETE_SIGNAL_H
#define SIN_DISCRETE_SIGNAL_H

#include "../discrete_signal.h"

class sin_discrete_signal final : public discrete_signal {
public:
    std::vector<double> generate(double x_min, double x_max, double x_delta) override;

    sin_discrete_signal(double amplitude_, double frequency_);

private:
    double amplitude;
    double frequency;
};


#endif //SIN_DISCRETE_SIGNAL_H
