#pragma once

#include <ros/ros.h>

#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>

/* 
    _source -> topic name for ros image
    _imageTransporter -> needs ros::NodeHandle
*/
class Converter
{
private:
    cv_bridge::CvImagePtr _cvImagePtr;
    image_transport::ImageTransport _imageTransporter;
    image_transport::Subscriber _imageSubs;
    std::string _source;

    void imageCallback(const sensor_msgs::ImageConstPtr &msg);

public:
    Converter(const ros::NodeHandle& nh,const std::string& source);
    cv::Mat& getCvImage() const;
    void tick() const; // Utility function to trigger callback (calls ros::spinOnce)
};