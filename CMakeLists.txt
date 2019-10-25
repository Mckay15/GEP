cmake_minimum_required(VERSION 2.6)
project(GEP)

include_directories(src)

add_library(GEP
  src/Engine/Core.cpp
  src/Engine/Core.h
  src/Engine/dummp.cpp
  src/Engine/Entity.cpp
  src/Engine/Entity.h
  src/Engine/Environment.cpp
  src/Engine/Environment.h
  src/Engine/Keyboard.cpp
  src/Engine/Keyboard.h
  src/Engine/Component.cpp
  src/Engine/Component.h
  src/Engine/TriRend.cpp
  src/Engine/TriRend.h
  )
target_link_libraries(GEP SDL2 opengl32 glew32)

add_executable(Game
  src/Game/main.cpp
  )
target_link_libraries(Game GEP)
