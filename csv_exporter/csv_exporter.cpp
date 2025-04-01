#include "csv_exporter.h"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <filesystem>


void csv_exporter::export_data(const std::string &output_file_name, const std::vector<double> &x,
                               const std::vector<double> &y) {
    if (const std::filesystem::path outputPath(output_file_name);
        !outputPath.parent_path().empty() && !exists(outputPath.parent_path())) {
        if (!create_directories(outputPath.parent_path())) {
            throw std::runtime_error("Не удалось создать директорию " + outputPath.parent_path().string());
        }
    }

    std::ofstream output_file(output_file_name);
    if (!output_file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл для записи h(x)");
    }
    output_file << "x, h(x)" << std::endl;
    for (size_t i = 0; i < x.size(); i++) {
        output_file << x[i] << ", " << y[i] << std::endl;
    }
    output_file.close();
    std::cout << "h(x) сохранена в " << output_file_name << std::endl;
}
