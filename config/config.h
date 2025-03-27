#ifndef CONFIG_H
#define CONFIG_H

#include "../json/json.hpp"

using json = nlohmann::json;

class config {
public:
    explicit config(const json &);

    [[nodiscard]] double get_frequency() const;

    [[nodiscard]] double get_x_min() const;

    [[nodiscard]] double get_x_max() const;

    [[nodiscard]] double get_x_delta() const;

    [[nodiscard]] double get_p_min() const;

    [[nodiscard]] double get_p_max() const;

    [[nodiscard]] double get_p_delta() const;

    [[nodiscard]] double get_k() const;

    [[nodiscard]] double get_b() const;

private:
    double frequency;
    double x_min;
    double x_max;
    double x_delta;
    double p_min;
    double p_max;
    double p_delta;
    double k;
    double b;
};

#endif //CONFIG_H
