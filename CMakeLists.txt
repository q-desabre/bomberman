

cmake_minimum_required(VERSION 3.10)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/module")

set(default_build_type Debug)
set(CMAKE_POLICY_DEFAULT_CMP0072 NEW)
find_package(raylib REQUIRED)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3 --std=c++17")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 --std=c++17")
# set the project name
project(indieStudio)



# add the executable
add_executable(indieStudio src/main.cpp
  src/engine/AActor.cpp
  src/engine/ABind.cpp
  src/engine/ACamera.cpp
  src/engine/ACollider.cpp
  src/engine/ARenderer.cpp
  src/engine/AWidget.cpp
  src/engine/RayAnimatedCube.cpp
  src/engine/RayAnimation.cpp
  src/engine/RayBind.cpp
  src/engine/RayCamera.cpp
  src/engine/RayCollisionBox.cpp
  src/engine/RayCube.cpp
  src/engine/RayModel.cpp
  src/engine/RayRenderer.cpp
  src/engine/RayText.cpp
  src/engine/RayImage.cpp
  src/engine/Utils.cpp
  src/game/ALevel.cpp
  src/game/Bomb.cpp
  src/game/Core.cpp
  src/game/Cube.cpp
  src/game/Flame.cpp
  src/game/GameLevel.cpp
  src/game/Map.cpp
  src/game/MenuLevel.cpp
  src/game/Player.cpp
  src/game/PowerUpFlame.cpp
  src/game/Utils.cpp
  )


target_include_directories(indieStudio PRIVATE "${CMAKE_CURRENT_LIST_DIR}/include/game")

target_include_directories(indieStudio PRIVATE "${CMAKE_CURRENT_LIST_DIR}/include/engine")


target_link_libraries(indieStudio PUBLIC raylib)
