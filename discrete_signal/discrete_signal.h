#ifndef DISCRETE_SIGNAL_H
#define DISCRETE_SIGNAL_H
#include <vector>


class discrete_signal {
public:
    virtual ~discrete_signal() = default;

    virtual std::vector<double> generate(double x_min, double x_max, double x_delta) = 0;
};


#endif //DISCRETE_SIGNAL_H
