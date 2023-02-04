#include "ros/ros.h"

int main(int argc,char *argv[])
{
   ros::init(argc,argv,"hello");
   ros::NodeHandle nh;
   /*
       使用ros::param 设置参数
   */
  //1.全局
  ros::param::set("/radiusA",100);
  //2.相对
  ros::param::set("radiusA",100);
  //3.私有
  ros::param::set("`radiusA",100);
  /*
    使用NodeHandle设置参数
  */
  //全局
  nh.setParam("/radius_nh_A",1000);
  nh.setParam("radius_nh_B",1000);
  ros::NodeHandle nh_private("~");
   return 0;
}