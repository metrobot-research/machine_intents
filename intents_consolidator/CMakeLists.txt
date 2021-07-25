cmake_minimum_required(VERSION 3.5)
project(intents_consolidator)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()


FILE(GLOB_RECURSE SOURCES *.cpp)
ament_auto_add_library(
  consolidator 
  ${SOURCES}
)

# ament_auto_add_library(
#   entity 
#   src/intents/entity/*.cc
#   src/intents/entity/*.h
# )

# intents_consolidator executable
ament_auto_add_executable(
  ${PROJECT_NAME}
  src/consolidator_main.cpp
)
target_link_libraries(${PROJECT_NAME} consolidator )

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_auto_package()
