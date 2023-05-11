cmake_minimum_required(VERSION 3.16)
project(Aircontrol)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(TARGET_SOURCE_DIR ${CMAKE_SOURCE_DIR})


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "$ENV{QGISPATH}/cmake")
message(STATUS "CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")
find_package(QGIS REQUIRED)
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Xml
        Sql
        REQUIRED)


find_library(GDAL_LIBRARY NAMES gdal PATHS /usr/lib)
message(STATUS "GDALL_LIBRARY: ${GDAL_LIBRARY}")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(Aircontrol
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    GISMapWidget.h
    GISMapWidget.cpp
    MenuController.h
    MenuController.cpp
    ./server/fields_count.hpp
    ./server/getter.hpp
    ./server/magic_in.hpp
    ./server/magic_out.hpp
    ./server/socket.cpp
    ./server/socket.h
    ./server/socket.hpp
    ./server/database.h
    )

target_include_directories(Aircontrol PRIVATE
    ${QGIS_INCLUDE_DIR}
    /usr/include/gdal)

target_link_libraries(Aircontrol
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Xml
        Qt5::Sql
        ${GDAL_LIBRARY}
        ${QGIS_LIBRARY}
        )
