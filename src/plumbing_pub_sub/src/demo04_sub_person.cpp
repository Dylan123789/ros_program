#include "ros/ros.h"
#include "plumbing_pub_sub/person.h"
/*
   订阅方:订阅消息
       1.包含头文件
           #include "plumbing_pub_sub/person.h"
       2.初始化ros节点
       3.创建节点句柄
       4.创建订阅者对象
       5.处理订阅的数据
       6.调用spin()函数
*/
//设置回调函数
void doPerson(const plumbing_pub_sub::person::ConstPtr&person1)
{
    ROS_INFO("订阅人的信息:%s,%d,%.2f",person1->name.c_str(),person1->age,person1->height);
}
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ROS_INFO("订阅方实现");
    //2.初始化ros节点
    ros::init(argc,argv,"part6");
    //3.创建节点句柄;
    ros::NodeHandle nh;
    //4.创建订阅者对象
    ros::Subscriber  sub = nh.subscribe("liao",10,doPerson);
    //5.处理订阅的数据;

    //6.调用spin()函数,确保主函数执行到这里可以使用回调函数doPerson
    ros::spin();
    return 0;
    

}