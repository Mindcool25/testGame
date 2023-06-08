cmake_minimum_required(VERSION 3.0)

project(testgame)

add_compile_options(-Wall)

add_executable(
  testgame
  src/ascii/asciisheet.cpp
  src/board/board.cpp
  src/display/display.cpp
  src/main.cpp
)

find_package(SOL2 REQUIRED)

target_link_libraries(testgame PRIVATE sfml-graphics sfml-system sfml-window lua)


