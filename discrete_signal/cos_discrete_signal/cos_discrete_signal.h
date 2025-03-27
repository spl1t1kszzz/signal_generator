#ifndef COS_DISCRETE_SIGNAL_H
#define COS_DISCRETE_SIGNAL_H
#include "../discrete_signal.h"


class cos_discrete_signal final: public discrete_signal {
public:
    std::vector<double> generate(double x_min, double x_max, double x_delta) override;

    cos_discrete_signal(double amplitude_, double frequency_);

private:
    double amplitude;
    double frequency;
};


#endif //COS_DISCRETE_SIGNAL_H
