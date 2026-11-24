FROM ros:jazzy-ros-base

RUN apt-get update && apt-get install -y \
    python3-colcon-common-extensions \
    ros-jazzy-rclcpp-components \
    ros-jazzy-rclcpp-lifecycle \
    build-essential \
    git \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /ros2_ws

COPY entrypoint.sh /entrypoint.sh

RUN sed -i 's/\r$//' /entrypoint.sh && chmod +x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]

CMD ["bash"]