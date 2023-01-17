#include "ros/ros.h"

/*
  需要实现参数的新增和修改;
  需求:首先设置机器人的共享参数
      再修改参数
  实现：
     ros::NodeHandle
          set param()
     ros::param
          set()
*/

int main(int argc, char *argv[])
{
   //初始化ros节点
     ros::init(argc,argv,"set_param_c");
   //创建ros节点句柄
     ros::NodeHandle nh;
   //参数增-----------------------------------
   //nh实现("数据名称"，数据)
   nh.setParam("type","robot1");
   nh.setParam("radius",0.15);
   //方案2:ros::param("数据名称"，数据)
   ros::param::set("type_param","robot2");

   ros::param::set("radius_param",0.15);
   //参数改-----------------------------------
   //nh实现
   nh.setParam("radius",0.2);
   //ros::param实现
   ros::param::set("radius_param",0.3);

return 0;

}