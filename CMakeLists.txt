cmake_minimum_required(VERSION 2.6)
project(GEP)

include_directories(src)

add_library(rend
  src/rend/Exception.cpp
  src/rend/Context.cpp
  src/rend/Texture.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/Buffer.cpp
  src/rend/Mesh.cpp
  src/rend/Util.cpp
)
if(MSVC)
  target_link_libraries(rend glew32 opengl32)
else()
  target_link_libraries(rend GLEW GL)
endif()

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
  src/Engine/NonCopyable.cpp
  src/Engine/NonCopyable.h
  src/Engine/Camera.cpp
  src/Engine/Camera.h
  src/Engine/Mesh.cpp
  src/Engine/Mesh.h
  src/Engine/Resource.cpp
  src/Engine/Resource.h
  src/Engine/MeshRenderer.cpp
  src/Engine/MeshRenderer.h
  src/Engine/Sound.cpp
  src/Engine/Sound.h
  src/Engine/Material.cpp
  src/Engine/Material.h
  src/Engine/MaterialAttribute.cpp
  src/Engine/MaterialAttribute.h
  src/Engine/Resources.cpp
  src/Engine/Resources.h
  src/Engine/Screen.cpp
  src/Engine/Screen.h
  )
target_link_libraries(GEP SDL2 rend)

add_executable(Game
  src/Game/main.cpp
  )
target_link_libraries(Game GEP)
