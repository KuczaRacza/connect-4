cmake_minimum_required(VERSION 3.10)
 
project(open-connect-4)
add_executable(4-in-row.exe main.cpp game.cpp panel.cpp global.cpp animation.cpp) 
target_link_libraries(4-in-row.exe SDL2 SDL2_image SDL2_ttf)
