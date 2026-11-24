#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"

namespace lab1
{
class ComponentNode : public rclcpp::Node
{
public:
    explicit ComponentNode(const rclcpp::NodeOptions & options)
        : Node("component_node", options)
    {
        RCLCPP_INFO(this->get_logger(),
                    "Component node started successfully!");
    }
};
}

RCLCPP_COMPONENTS_REGISTER_NODE(lab1::ComponentNode)
