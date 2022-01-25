cmake_minimum_required(VERSION 3.21)
project(wordles)

set(CMAKE_CXX_STANDARD 17)
find_package(GTest CONFIG REQUIRED)
include_directories(/usr/local/include)

find_package(nlohmann_json 3.2.0 REQUIRED)

add_library(wordle_lib
        src/words_in.cpp src/words_in.hpp
        feedback/feedback.cpp
        feedback/feedback.hpp
        wordle_test/wordle_test.cpp
        word_node/word_node.cpp word_node/word_node.hpp)

target_include_directories(wordle_lib PUBLIC src feedback word_node)
target_link_libraries(wordle_lib PUBLIC nlohmann_json::nlohmann_json)


add_executable(wordles main.cpp)
target_link_libraries(wordles wordle_lib )

add_executable(wordle_test wordle_test/wordle_test.cpp)
target_link_libraries(wordle_test PUBLIC wordle_lib GTest::gtest GTest::gtest_main)
