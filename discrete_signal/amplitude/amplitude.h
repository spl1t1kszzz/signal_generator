#ifndef AMPLITUDE_H
#define AMPLITUDE_H
#include "../discrete_signal.h"


class amplitude final : public discrete_signal {
public:
    amplitude(double k_, double b_);

    std::vector<double> generate(double p_min, double p_max, double p_delta) override;
private:
    double k;
    double b;
};


#endif //AMPLITUDE_H
