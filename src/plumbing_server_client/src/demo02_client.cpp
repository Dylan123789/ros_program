#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"
/*
  客户端：提交两个整数，并处理响应的结果
  1. 包含头文件；
  2.初始化ros节点；
  3.创建节点句柄；
  4.创建客户端对象；
  5.提交请求并处理响应；
  实现参数动态提交:
  1.格式:rosrun xxx xxx num1 num2
  2.节点执行，需要获取命令中的参数,并组织进request
  如果要先启动客户端，挂起等待服务端启动再正常请求，使用ROS内置函数
*/
int main(int argc,char *argv[])
{
  if(argc != 3){
    ROS_INFO("提交的参数个数不对");
  
    return 1;
  }
  setlocale(LC_ALL,"");
  //2.初始化ros节点;
  ros::init(argc,argv,"node2");
  //3.创建节点句柄;
  ros::NodeHandle nh;
  //4.创建客户端对象;
  ros::ServiceClient client = nh.serviceClient<plumbing_server_client::AddInts>("addInts");
  //5.提交请求并且处理响应；
      //组织请求
      plumbing_server_client::AddInts ai;
      ai.request.num1 = atoi(argv[1]);
      ai.request.num2 = atoi(argv[2]);
      client.waitForExistence();//内置函数当服务端没启动则挂起
      //处理响应
      client.call(ai);
      bool flag = client.call(ai);
      if (flag)
      {
        ROS_INFO("响应成功！");
        ROS_INFO("响应结果 = %d",ai.response.sum);
      } else{
        ROS_INFO("处理失败");
      }

      return 0;


}