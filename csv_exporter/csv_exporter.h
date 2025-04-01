#ifndef CSV_EXPORTER_H
#define CSV_EXPORTER_H
#include <vector>
#include <fstream>
#include <iostream>
#include <filesystem>


class csv_exporter {
public:
    static void export_data(const std::string&, const std::vector<double> &, const std::vector<double> &);
};


#endif //CSV_EXPORTER_H
