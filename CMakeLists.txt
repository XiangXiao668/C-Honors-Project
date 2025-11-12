cmake_minimum_required(VERSION 3.16)

project(QTinQT VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt 6 with Widgets + Charts
find_package(Qt6 REQUIRED COMPONENTS Widgets Charts)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
        budgetmanager.cpp
)

# One target definition ONLY
qt_add_executable(QTinQT
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
    resources.qrc
    budgetmanager.h budgetmanager.cpp
        budgetmanager.cpp
)

# Link once
target_link_libraries(QTinQT
    PRIVATE
        Qt6::Widgets
        Qt6::Charts
)

# Optional bundle / install settings
set_target_properties(QTinQT PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(Qt6_VERSION VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.QTinQT)
    set_target_properties(QTinQT PROPERTIES
        ${BUNDLE_ID_OPTION}
    )
endif()

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QTinQT)
endif()
