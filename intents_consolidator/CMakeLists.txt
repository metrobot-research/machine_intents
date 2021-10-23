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
find_package(Eigen3 REQUIRED)

ament_auto_find_build_dependencies()


ament_auto_add_library(
  datastructures
  src/datastructures/embedding.cpp
)
target_link_libraries(datastructures Eigen3::Eigen)

ament_auto_add_library(
  intents
  src/intents/consolidator/consolidator.cpp
  src/intents/entity/point_of_interest.cpp
)

# consolidator_node
ament_auto_add_library(
  consolidator_node
  SHARED
  src/consolidator_node.cpp
)
target_link_libraries(consolidator_node intents datastructures)
target_compile_definitions(consolidator_node
  PRIVATE "COMPOSITION_BUILDING_DLL")
rclcpp_components_register_nodes(consolidator_node "machine_intents::intents_consolidator::ConsolidatorNode")
set(node_plugins "${node_plugins}machine_intents::intents_consolidator::ConsolidatorNode;$<TARGET_FILE:consolidator_node>\n")
ament_auto_add_executable(
  consolidator_exe
  src/consolidator_node.cpp
)

if(BUILD_TESTING)
  set(TEST_TARGET ${PROJECT_NAME}_TEST)

  find_package(ament_lint_auto REQUIRED)

  # Intentionally defeat the copyright check for MIT license
  set(ament_cmake_copyright_FOUND true)

  ament_lint_auto_find_test_dependencies()

  # TODO(JS): Uncomment gtest once cppcheck stops complaining
  # ament_add_gtest(${TEST_TARGET} src/intents/consolidator/consolidator_test.cpp)
  # target_link_libraries(${TEST_TARGET} intents)

endif()

ament_auto_package()
