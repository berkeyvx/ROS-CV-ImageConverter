#include "Converter.hpp"


Converter::Converter(const ros::NodeHandle& nh,const std::string& source): _source(source), _imageTransporter(nh)
{
    _imageSubs = _imageTransporter.subscribe(_source, 1, &Converter::imageCallback, this);
}


void Converter::imageCallback(const sensor_msgs::ImageConstPtr &msg)
{
    try
    {
        _cvImagePtr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    }
    catch(const cv_bridge::Exception& e)
    {
        ROS_ERROR("cv_bridge exception: %s", e.what());
        return;
    }  
}


// References to original image returned, clone image if necessary
cv::Mat& Converter::getCvImage() const
{
    return _cvImagePtr->image;
}


// Triggers callback functions
void Converter::tick() const
{
    ros::spinOnce();
}