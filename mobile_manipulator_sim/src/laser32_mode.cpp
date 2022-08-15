#include <ros/ros.h>
// PCL specific includes
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
//关于平面分割的头文件
#include <pcl/sample_consensus/model_types.h>   //分割模型的头文件
#include <pcl/sample_consensus/method_types.h>  //采样一致性的方法
#include <pcl/segmentation/sac_segmentation.h>  //ransac分割法
void cloudCallback(const sensor_msgs::PointCloud2ConstPtr& input)
{
   pcl::PCLPointCloud2* cloud = new pcl::PCLPointCloud2;    //原始的点云的数据格式  
   pcl_conversions::toPCL(*input, *cloud);  

   pcl::PointCloud<pcl::PointXYZ>::Ptr cloudxyz (new pcl::PointCloud<pcl::PointXYZ>); 
   pcl::fromPCLPointCloud2(*cloud, *cloudxyz);
   for(int i = 0; i < cloudxyz->size();i++)
   {
    std::cout << "data : " << i << std::endl;
    std::cout << cloudxyz->points[i].x << std::endl;
    std::cout << cloudxyz->points[i].y << std::endl;  
    std::cout << cloudxyz->points[i].z << std::endl;
   }
}
int main(int argc, char** argv)
{
  ros::init(argc, argv, "laser32_publisher");
  ros::AsyncSpinner spinner(3);
  spinner.start();
  ros::NodeHandle nh;
  ros::Subscriber pcl_sub;
  ros::Publisher pcl_pub;
  pcl_sub = nh.subscribe("velodyne_points", 100, cloudCallback);
  ros::Rate loop_rate(10);
  while(ros::ok())
  {
    loop_rate.sleep();
  }
}
