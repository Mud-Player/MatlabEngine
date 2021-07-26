cmake_minimum_required(VERSION 3.5)
project(MatlabEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(${PROJECT_NAME}
    main.cpp
    widget.h
    widget.cpp
)

# 设置Matlab头文件及依赖库
set(MATLAB_ROOT "D:/Program Files/MATLAB/R2018b")
target_include_directories(${PROJECT_NAME} PUBLIC ${MATLAB_ROOT}/extern/include)
target_link_libraries(${PROJECT_NAME} PUBLIC ${MATLAB_ROOT}/extern/lib/win64/microsoft/libMatlabEngine.lib)
target_link_libraries(${PROJECT_NAME} PUBLIC ${MATLAB_ROOT}/extern/lib/win64/microsoft/libMatlabDataArray.lib)
target_link_libraries(${PROJECT_NAME} PUBLIC Qt5::Widgets)
