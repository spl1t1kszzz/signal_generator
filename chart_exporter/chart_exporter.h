#ifndef CHART_EXPORTER_H
#define CHART_EXPORTER_H
#include <vector>
#include <iostream>
// ReSharper disable once CppUnusedIncludeDirective
#include <QtCharts>

class chart_exporter {
public:
    static void export_chart(const std::string &, const std::vector<double> &, const std::vector<double> &);
};


#endif //CHART_EXPORTER_H
