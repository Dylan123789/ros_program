#include "ros/ros.h"
#include "plumbing_pub_sub/person.h"
/*
  发布方：发布人的消息
     1.包含头文件
     #include "plumbing_pub_sub/person.h"
     2.初始化ros节点
     3.创建节点句柄
     4.创建发布者对象
     5.编写发布逻辑，发布数据

*/
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ROS_INFO("这是消息发布方");
    //2.初始化ros节点
    ros::init(argc,argv,"part5");
    //3.创建节点句柄
    ros::NodeHandle nh;
    //4.创建发布者对象
    ros::Publisher pub = nh.advertise<plumbing_pub_sub::person>("liao",10);
    //5.编写发布逻辑，发布数据
     //创建被发布的数据
     plumbing_pub_sub::person person1;
     person1.name ="小明";
     person1.age = 17;
     person1.height =1.73;
     //设置发布频率
    ros::Rate rate(1);
     //循环发布数据
     while (ros::ok())
     {
        //动态修改数据
        person1.age += 1;
        //发布数据
        pub.publish(person1);
        ROS_INFO("发布的消息：%s,%d,%.2f",person1.name.c_str(),person1.age,person1.height);
        rate.sleep();
        ros::spinOnce();
     }
     

}