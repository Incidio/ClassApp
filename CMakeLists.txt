cmake_minimum_required(VERSION 3.16)

project(ClassApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Charts)
find_package(Qt6 REQUIRED COMPONENTS Pdf)
find_package(Qt6 REQUIRED COMPONENTS Concurrent )

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ClassApp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        service.h service.cpp
        progressdialog.h progressdialog.cpp
        createchart.h createchart.cpp createchart.ui
        redactingitem.h redactingitem.cpp redactingitem.ui
        treewidgetcolumnmanager.h treewidgetcolumnmanager.cpp treewidgetcolumnmanager.ui

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ClassApp APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ClassApp SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ClassApp
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ClassApp PRIVATE Qt6::Charts)
target_link_libraries(ClassApp PRIVATE Qt6::Pdf)
target_link_libraries(ClassApp PRIVATE Qt6::Concurrent)

add_subdirectory(3rdparty/duckx)
include_directories(
    3rdparty/duckx/include
)
target_link_libraries(ClassApp PRIVATE duckx)

# Manually find libxlsxwriter
find_path(LIBXLSXWRITER_INCLUDE_DIRS "xlsxwriter.h"
    PATHS "C:/Users/salie/vcpkg/installed/x64-windows/include")

find_library(LIBXLSXWRITER_LIBRARIES
    NAMES xlsxwriter libxlsxwriter
    PATHS "C:/Users/salie/vcpkg/installed/x64-windows/lib")

if (NOT LIBXLSXWRITER_INCLUDE_DIRS OR NOT LIBXLSXWRITER_LIBRARIES)
    message(FATAL_ERROR "libxlsxwriter not found!")
endif()

# Link to your target
target_include_directories(ClassApp PRIVATE ${LIBXLSXWRITER_INCLUDE_DIRS})
target_link_libraries(ClassApp PRIVATE ${LIBXLSXWRITER_LIBRARIES})


target_link_libraries(ClassApp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ClassApp)
endif()
set_target_properties(ClassApp PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ClassApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ClassApp)
endif()
