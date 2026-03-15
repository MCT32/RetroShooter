cmake_minimum_required(VERSION 4.2.3)

project(RetroShooter)

add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)

add_executable(RetroShooter src/main.c src/render.c src/util.c)

target_link_libraries(RetroShooter PRIVATE SDL2::SDL2)
target_link_libraries(RetroShooter PRIVATE m)