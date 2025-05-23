#include "chart_exporter.h"


void chart_exporter::export_chart(const std::string &output_file_name, const std::vector<double> &x,
                                  const std::vector<double> &y) {
    if (const std::filesystem::path outputPath(output_file_name); !outputPath.parent_path().empty() && !exists(
                                                                      outputPath.parent_path())) {
        if (!create_directories(outputPath.parent_path())) {
            throw std::runtime_error("Не удалось создать директорию " + outputPath.parent_path().string());
        }
    }

    auto *series = new QLineSeries();
    for (size_t i = 0; i < x.size(); i++) {
        series->append(x[i], y[i]);
    }
    auto *chart = new QChart();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("h(x)");
    chart->legend()->hide();
    auto *view = new QChartView(chart);
    const QString output_file_string = QString::fromStdString(output_file_name);
    if (const auto pixmap = view->grab(); !pixmap.save(output_file_string)) {
        throw std::runtime_error("Не удалось сохранить изображение графика h(x)");
    }
    std::cout << "Изображение графика h(x) успешно сохранено в " << output_file_name << std::endl;
}
