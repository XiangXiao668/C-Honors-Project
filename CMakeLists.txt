cmake_minimum_required(VERSION 3.16)

project(HonoraryBudgetApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Charts)

set(PROJECT_SOURCES
        src/main.cpp
        src/mainwindow.cpp
        src/budgetmanager.cpp
        include/mainwindow.h
        include/budgetmanager.h
        include/category.h
        include/file.h
        ui/mainwindow.ui
        resources/resources.qrc
        src/mosesbudgetmanager.cpp
)

qt_add_executable(HonoraryBudgetApp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        src/budgetmanager.cpp
        include/file.h
)

set_target_properties(HonoraryBudgetApp PROPERTIES
        AUTOUIC_SEARCH_PATHS "${CMAKE_SOURCE_DIR}/ui"
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
)

target_link_libraries(HonoraryBudgetApp
        PRIVATE
        Qt6::Widgets
        Qt6::Charts
)

if(Qt6_VERSION VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.HonoraryBudgetApp)  # optional but nice
    set_target_properties(HonoraryBudgetApp PROPERTIES
            ${BUNDLE_ID_OPTION}
    )
endif()

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(HonoraryBudgetApp)
endif()