#include "rclcpp/rclcpp.hpp"
#include "rclcpp_lifecycle/lifecycle_node.hpp"

using CallbackReturn =
    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn;

class ManagedNode : public rclcpp_lifecycle::LifecycleNode
{
public:
    explicit ManagedNode(const std::string & name)
        : LifecycleNode(name)
    {
        RCLCPP_INFO(get_logger(), "Node created");
    }

    CallbackReturn on_configure(
        const rclcpp_lifecycle::State &) override
    {
        RCLCPP_INFO(get_logger(), "Node configured");
        return CallbackReturn::SUCCESS;
    }

    CallbackReturn on_activate(
        const rclcpp_lifecycle::State &) override
    {
        RCLCPP_INFO(get_logger(), "Node activated");
        return CallbackReturn::SUCCESS;
    }

    CallbackReturn on_deactivate(
        const rclcpp_lifecycle::State &) override
    {
        RCLCPP_INFO(get_logger(), "Node deactivated");
        return CallbackReturn::SUCCESS;
    }

    CallbackReturn on_cleanup(
        const rclcpp_lifecycle::State &) override
    {
        RCLCPP_INFO(get_logger(), "Node cleaned up");
        return CallbackReturn::SUCCESS;
    }
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);

    auto node1 = std::make_shared<ManagedNode>("managed_node_1");
    auto node2 = std::make_shared<ManagedNode>("managed_node_2");

    rclcpp::executors::SingleThreadedExecutor executor;

    executor.add_node(node1->get_node_base_interface());
    executor.add_node(node2->get_node_base_interface());

    executor.spin();

    rclcpp::shutdown();
    return 0;
}
