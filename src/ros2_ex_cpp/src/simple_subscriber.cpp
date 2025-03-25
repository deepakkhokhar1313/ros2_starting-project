#include<rclcpp/rclcpp.hpp>
#include<std_msgs/msg/string.hpp>

using std::placeholders:: _1;

class SimpleSubscriber: public rclcpp::Node
{
    public:
    SimpleSubscriber(): Node("simple_subscriber")
    {
        sub_ = create_subscription<std_msgs::msg::String>("chatter",10, std::bind(&SimpleSubscriber::msgcallback, this, _1));
    }
    void msgcallback(const std_msgs::msg::String &msg) const
    {
        RCLCPP_INFO_STREAM(get_logger(), "I heard : "<< msg.data.c_str());
    }
    private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;
};

int main(int argc, char * agrv[])
{
    rclcpp::init(argc, agrv);
    auto simple_subscriber = std::make_shared<SimpleSubscriber>();
    rclcpp::spin(simple_subscriber);
    rclcpp::shutdown();
    return 0;
}