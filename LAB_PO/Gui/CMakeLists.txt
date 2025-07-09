cmake_minimum_required(VERSION 3.19)
project(GUI LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt6 6.5 REQUIRED COMPONENTS Widgets PrintSupport)

qt_standard_project_setup()

include(FetchContent)

FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.12.0
)
FetchContent_MakeAvailable(nlohmann_json)

qt_add_executable(GUI
    WIN32 MACOSX_BUNDLE
    main.cpp
    widget.cpp
    widget.h
    widget.ui
# Program includes
    ../Constant.cpp
    ../RecursiveSine.cpp
    ../Sine.cpp
    ../Square.cpp
    ../Triangle.cpp
    ../WhiteNoise.cpp

    ../ModelARX.cpp
    ../ObiektStatyczny.cpp
    ../PetlaSprzerzeniaZwrotnego.cpp
    ../PetlaUAR.cpp
    ../RegulatorPID.cpp

    ../AddDecorator.cpp
    ../SaturationDecorator.cpp

    ../ModelFactory.cpp
    ../RegulatorFactory.cpp
    ../SignalFactory.cpp
    ../SISOFactory.cpp
    qcustomplot.h
    qcustomplot.cpp
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    # C:/Users/Hose/.nuget/packages/nlohmann.json/3.12.0/build/native/include
)

target_link_libraries(GUI
    PRIVATE
        Qt::Core
        Qt::Widgets
        nlohmann_json::nlohmann_json
        Qt::PrintSupport
)

include(GNUInstallDirs)

install(TARGETS GUI
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET GUI
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
