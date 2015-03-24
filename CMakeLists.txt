cmake_minimum_required(VERSION 3.1)
project(found_wally)

find_package(OpenCV REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cc)

configure_file(img/wally.jpg
    ${CMAKE_CURRENT_BINARY_DIR}/img/wally.jpg COPYONLY)
configure_file(img/template.png
    ${CMAKE_CURRENT_BINARY_DIR}/img/template.png COPYONLY)

add_subdirectory(src)

add_executable(found_wally ${SOURCE_FILES})

target_link_libraries(found_wally ${OpenCV_LIBS})
target_link_libraries(found_wally find_wally)