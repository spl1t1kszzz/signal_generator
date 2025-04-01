#include <fstream>
#include <iostream>

#include "chart_exporter/chart_exporter.h"
#include "config/config.h"
#include "discrete_signal_config_validator/discrete_signal_config_validator.h"
#include "csv_exporter/csv_exporter.h"
#include "discrete_signal/amplitude/amplitude.h"
#include "discrete_signal/result_discrete_signal/result_discrete_signal.h"
#include "json/json.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    std::ifstream config_file_stream("../config.json");
    if (!config_file_stream.is_open()) {
        std::cerr << "Не удалось открыть файл с конфигурацией" << std::endl;
        return EXIT_FAILURE;
    }
    json json_config;
    try {
        json_config = nlohmann::json::parse(config_file_stream);
        discrete_signal_config_validator::validate_config(json_config);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    const config cfg(json_config);

    amplitude amplitude(cfg.get_k(), cfg.get_b());
    const auto a_vec = amplitude.generate(cfg.get_p_min(), cfg.get_p_max(), cfg.get_p_delta());
    for (const auto &a: a_vec) {
        if (a >= 0 && a <= 1) {
            std::vector<double> x_vec;
            const auto x_delta = cfg.get_x_delta();
            const auto x_min = cfg.get_x_min();
            const auto x_max = cfg.get_x_max();
            double x;
            if (x_delta > 0) {
                for (x = x_min; x <= x_max; x += x_delta)
                    x_vec.push_back(x);
            } else {
                for (x = x_min; x > x_max; x += x_delta)
                    x_vec.push_back(x);
            }
            if (std::abs(x - x_max) > std::numeric_limits<double>::epsilon()) {
                x_vec.push_back(x);
            }
            try {
                auto h = result_discrete_signal(a, cfg.get_frequency()).generate(
                    x_min, x_max, x_delta);
                csv_exporter::export_data(std::format("./data/h (a = {}).csv", a), x_vec, h);
                chart_exporter::export_chart(std::format("./images/h (a = {}).png", a), x_vec, h);
            } catch (const std::exception &e) {
                std::cerr << e.what() << std::endl;
                return EXIT_FAILURE;
            }
        }
    }
    return EXIT_SUCCESS;
}
