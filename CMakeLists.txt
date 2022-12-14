cmake_minimum_required(VERSION 3.10.0)

project("AnWaTool"
    VERSION "1.0.0"
    DESCRIPTION "A toolbox for adb"
    LANGUAGES CXX C
)

## Shared macros and functions:
set(LIRI_LOCAL_ECM TRUE)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/fluid/cmake/shared/modules")
set(CMAKE_PREFIX_PATH D:/Qt/5.15.2/mingw81_64)
## Configure Fluid:
option(FLUID_WITH_DOCUMENTATION "" OFF)
option(FLUID_WITH_DEMO "" OFF)

## Set minimum versions required:
set(QT_MIN_VERSION "5.10.0")

## Liri specific setup common for all modules:
include(LiriSetup)

## Find Qt 5:
find_package(Qt5 "${QT_MIN_VERSION}"
    CONFIG REQUIRED
    COMPONENTS
        Core
        Gui
        Svg
        Qml
        Quick
        QuickControls2
)

## Add subdirectories:
add_subdirectory(fluid)
add_subdirectory(src)
