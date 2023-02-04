#include "ros/ros.h"
/*
   需求:1.演示时间相关操作(获取当前时刻+设置特定时刻)
      2.程序执行中停顿一段时间
      3.已知程序开始运行的时刻和程序运行的时间，求运行结束的时刻
      4.每隔1秒钟，在控制台输出一段文本.
   实现:
       1.准备(头文件，节点初始化，NodeHandle创建...)
       2.获取当前时刻
       3.设置指定时刻
       4.创建持续时间对象然后休眠即可实现停顿
       5.获取开始时刻
       6.ros::Rate()或用定时器实现间隔发布
*/
//回调函数
void cb(const ros::TimerEvent& event){
     ROS_INFO("-------");

}
int main(int argc,char *argv[])
{
   setlocale(LC_ALL,"");
   ros::init(argc,argv,"time");
   ros::NodeHandle nh;//必须，否则会导致时间API调用失败(再NodeHanle会初始化时间操作)
   //2.获取当前时刻
   //now 函数会将当前时刻封装并返回
   //当前时刻:now 被调用执行的那一刻
   ros::Time right_now = ros::Time::now();
   ROS_INFO("当前时刻:%.2f",right_now.toSec());//toSec()把时间转化成秒，且为浮点数
   ROS_INFO("当前时刻:%d",right_now.sec);//同样转换为秒但是为整形
   //3.设置指定时刻
   ros::Time t1(20,31234589);//设置时间为距离时间参考系过去20s加31234589纳秒
   ROS_INFO("当前时刻:%d",right_now.sec);
  // -------------------------------------------------
   ROS_INFO("开始休眠");

  ros::Duration du(4.5);//封装了4.5s持续时间
  du.sleep();//实现休眠4.5s
  ROS_INFO("休眠结束");
  //--------------------------------------------------
  ros::Time begin = ros::Time::now();
  ros::Duration du1(5);
  ros::Time stop = begin + du1;
  ROS_INFO("开始时刻=%.2f",begin.toSec());
  ROS_INFO("结束时间:%.2f",stop.toSec());
  //时刻与持续时间可以加减，持续时间之间也可，但是时刻之间只可相减，不可相加.
  //---------------------------------------------------
  ros::Timer timer = nh.createTimer(ros::Duration(1),cb,false,false);//回调函数后面加true则只实现一次,第二个false则是取消自动启动
  timer.start();//手动启动
  ros::spin();//需要回旋
}