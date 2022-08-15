#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <math.h>
#define PI 3.1415927

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");

    ros::init(argc,argv,"base_demo");
    ros::NodeHandle nh;

    ros::Publisher pub= nh.advertise<std_msgs::Float64>("x_dir_controller/command",10);
    std_msgs::Float64 msg;
    msg.data = 0.1;
    int count = 0;
    ros::Rate r(1);

    while (ros::ok())
    {
        pub.publish(msg);
        ROS_INFO("I am drawing a circle by the base!");
        count++;
        r.sleep();
        ros::spinOnce();
    }
    
    return 0;
}