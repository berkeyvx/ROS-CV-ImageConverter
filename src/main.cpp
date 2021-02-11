#include "Converter.hpp"
#include <ros/ros.h>

int main(int argc, char const *argv[])
{
    // Example of how to use
    // Make shared_ptr if Converter is going to be a Embedded Obj. of another class auto c = std::make_shared<Converter>(nh, "/source_topic_name")
    ros::NodeHandle nh;
    Converter c(nh, "/source_topic_name");
    auto frame = c.getCvImage();

    return 0;
}
