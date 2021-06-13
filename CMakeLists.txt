

cmake_minimum_required(VERSION 3.10)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/module")

set(default_build_type "Release")
set(CMAKE_POLICY_DEFAULT_CMP0072 NEW)
find_package(raylib REQUIRED)


# set the project name
project(indieStudio)



# add the executable
add_executable(indieStudio src/main.cpp include/GameLevel.cpp src/Utils.cpp
  )


target_include_directories(indieStudio PRIVATE "${CMAKE_CURRENT_LIST_DIR}/include")


target_link_libraries(indieStudio PUBLIC raylib)
