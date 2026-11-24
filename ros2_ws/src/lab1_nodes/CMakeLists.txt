cmake_minimum_required(VERSION 3.8)
project(lab1_nodes)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)

add_library(component_node SHARED
    src/component_node.cpp
)

ament_target_dependencies(component_node
    rclcpp
    rclcpp_components
)

rclcpp_components_register_nodes(component_node
    "lab1::ComponentNode"
)

add_executable(lifecycle_nodes
    src/lifecycle_nodes.cpp
)

ament_target_dependencies(lifecycle_nodes
    rclcpp
    rclcpp_lifecycle
)

install(TARGETS component_node
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(TARGETS lifecycle_nodes
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()
