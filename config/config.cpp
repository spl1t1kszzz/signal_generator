#include "config.h"


config::config(const json &cfg) {
    frequency = cfg["frequency"].get<double>();
    x_min = cfg["x_min"].get<double>();
    x_max = cfg["x_max"].get<double>();
    x_delta = cfg["x_delta"].get<double>();
    p_min = cfg["p_min"].get<double>();
    p_max = cfg["p_max"].get<double>();
    p_delta = cfg["p_delta"].get<double>();
    k = cfg["k"].get<double>();
    b = cfg["b"].get<double>();
}


double config::get_frequency() const {
    return frequency;
}

double config::get_x_min() const {
    return x_min;
}

double config::get_x_max() const {
    return x_max;
}

double config::get_x_delta() const {
    return x_delta;
}

double config::get_p_min() const {
    return p_min;
}

double config::get_p_max() const {
    return p_max;
}

double config::get_p_delta() const {
    return p_delta;
}

double config::get_k() const {
    return k;
}

double config::get_b() const {
    return b;
}
