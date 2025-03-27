#ifndef RESULT_DISCRETE_SIGNAL_H
#define RESULT_DISCRETE_SIGNAL_H
#include "../discrete_signal.h"
#include "../cos_discrete_signal/cos_discrete_signal.h"
#include "../sin_discrete_signal/sin_discrete_signal.h"


class result_discrete_signal final: public discrete_signal {
public:
    std::vector<double> generate(double x_min, double x_max, double x_delta) override;

    result_discrete_signal(double, double);
private:
    double amplitude;
    double frequency;
};


#endif //RESULT_DISCRETE_SIGNAL_H
