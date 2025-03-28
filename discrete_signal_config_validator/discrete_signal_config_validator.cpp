#include "discrete_signal_config_validator.h"


void discrete_signal_config_validator::validate_config(json &config) {
    try {
        std::vector<std::string> params = {
            "frequency", "x_min", "x_max", "x_delta", "p_min", "p_max", "p_delta", "b", "k"
        };
        for (const auto &param: params) {
            contains_param(config, param);
        }
        const auto x_min = config["x_min"].get<double>();
        const auto x_max = config["x_max"].get<double>();
        const auto x_delta = config["x_delta"].get<double>();
        const auto p_min = config["p_min"].get<double>();
        const auto p_max = config["p_max"].get<double>();
        const auto p_delta = config["p_delta"].get<double>();
        const auto b = config["b"].get<double>();
        const auto k = config["k"].get<double>();
        if (std::abs(x_delta) < std::numeric_limits<double>::epsilon()) {
            throw std::invalid_argument("Шаг для x не может быть равен 0");
        }
        if (x_delta > 0 and x_min > x_max) {
            throw std::invalid_argument("Для положительного шага x начало отрезка должно быть меньше конца отрезка");
        }
        if (x_delta < 0 and x_max < x_min) {
            throw std::invalid_argument("Для отрицательного шага x конец отрезка должен быть больше начала отрезка");
        }
        if (p_delta > 0 and p_min > p_max) {
            throw std::invalid_argument("Для положительного шага p начало отрезка должно быть меньше конца отрезка");
        }
        if (p_delta < 0 and p_max < p_min) {
            throw std::invalid_argument("Для отрицательного шага p конец отрезка должен быть больше начала отрезка");
        }
    } catch (json::exception &e) {
        throw std::invalid_argument(std::string("Ошибка валидации конфигурации") + e.what());
    } catch ([[maybe_unused]] std::invalid_argument &e) {
        throw;
    }
}

void discrete_signal_config_validator::contains_param(const json &config, const std::string &param) {
    if (!config.contains(param)) {
        throw std::invalid_argument(std::string("Пропущен параметр ") + param);
    }
}
