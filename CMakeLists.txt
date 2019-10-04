cmake_minimum_required(VERSION 2.6)
project(GEP)

add_library(GEP
  src/Engine/dummp.cpp
  )
target_link_libraries(GEP SDL2 opengl32 glew32)

add_executable(Game
  src/Game/main.cpp
  )
target_link_libraries(Game GEP)
