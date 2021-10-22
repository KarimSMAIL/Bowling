cmake_minimum_required(VERSION 3.10)

project(Bowling)

add_subdirectory(include/googletest)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/test
)

file(GLOB all_MainSRCS
    ${PROJECT_SOURCE_DIR}/include/*.h
    ${PROJECT_SOURCE_DIR}/include/*.hpp
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/bowling.cpp
)

add_executable(bowling ${all_MainSRCS})

file(GLOB all_TestSRCS
    ${PROJECT_SOURCE_DIR}/include/*.h
    ${PROJECT_SOURCE_DIR}/include/*.hpp
    ${PROJECT_SOURCE_DIR}/src/bowling.cpp
    ${PROJECT_SOURCE_DIR}/test/bowling_test.cpp  
)

add_executable(bowling_test ${all_TestSRCS})

target_link_libraries(bowling_test PRIVATE gtest)