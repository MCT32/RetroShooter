cmake_minimum_required(VERSION 4.1.2)

project(RetroShooter)

add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)

add_executable(RetroShooter src/main.cpp src/render.cpp src/util.cpp src/vec.cpp src/player.cpp)

target_link_libraries(RetroShooter PRIVATE SDL2::SDL2)
target_link_libraries(RetroShooter PRIVATE m)
