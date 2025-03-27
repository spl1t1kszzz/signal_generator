#include "csv_exporter.h"

#include <fstream>
#include <iostream>


void csv_exporter::export_data(const std::string &output_file_name, std::vector<double> &x, std::vector<double> &y) {
    std::ofstream output_file(output_file_name);
    if (!output_file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл для записи h(x)");
    }
    output_file << "x, h(x)" << std::endl;
    for (int i = 0; i < x.size(); i++) {
        output_file << x[i] << ", " << y[i] << std::endl;
    }
    output_file.close();
    std::cout << "h(x) сохранена в " << output_file_name << std::endl;
}
