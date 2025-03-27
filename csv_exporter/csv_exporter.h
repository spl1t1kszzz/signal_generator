#ifndef CSV_EXPORTER_H
#define CSV_EXPORTER_H
#include <vector>


class csv_exporter {
public:
    static void export_data(const std::string&, std::vector<double> &, std::vector<double> &);
};


#endif //CSV_EXPORTER_H
