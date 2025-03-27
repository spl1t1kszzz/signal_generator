cmake_minimum_required(VERSION 3.30)
project(signal_generator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Charts
        REQUIRED)

add_executable(signal_generator main.cpp
        discrete_signal/discrete_signal.h
        discrete_signal/sin_discrete_signal/sin_discrete_signal.cpp
        discrete_signal/sin_discrete_signal/sin_discrete_signal.h
        discrete_signal/cos_discrete_signal/cos_discrete_signal.cpp
        discrete_signal/cos_discrete_signal/cos_discrete_signal.h
        discrete_signal_config_validator/discrete_signal_config_validator.cpp
        discrete_signal_config_validator/discrete_signal_config_validator.h
        config/config.h
        config/config.cpp
        discrete_signal/amplitude/amplitude.cpp
        discrete_signal/amplitude/amplitude.h
        discrete_signal/result_discrete_signal/result_discrete_signal.cpp
        discrete_signal/result_discrete_signal/result_discrete_signal.h
        csv_exporter/csv_exporter.cpp
        csv_exporter/csv_exporter.h
        chart_exporter/chart_exporter.cpp
        chart_exporter/chart_exporter.h
)
target_link_libraries(signal_generator
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Charts
)

