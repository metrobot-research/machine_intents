cmake_minimum_required(VERSION 3.5)
project(machine_intents_interfaces)

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

# Prepare custom interfaces
find_package(rosidl_default_generators REQUIRED)
rosidl_generate_interfaces(${PROJECT_NAME}
  msg/DetectionResult.msg
  msg/Embedding.msg
  msg/ObjectClassificationResult.msg
  msg/PoseEstimationResult.msg
  msg/VoiceDetectionResult.msg
  DEPENDENCIES geometry_msgs std_msgs
)
ament_export_dependencies(rosidl_default_runtime)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  
  # Intentionally defeat the copyright check for MIT license
  set(ament_cmake_copyright_FOUND true)

  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
