#include "ros/ros.h"

/*
   参数查询
   实现：ros::NodeHandle

        ros：：param

*/
int main(int argc,char *argv[])
{
    //设置编码
    setlocale(LC_ALL,"");
    //初始化ros节点
    ros::init(argc,argv,"get_param_c");
    //创建节点句柄
    ros::NodeHandle nh;
    //ros::NodeHandle--------------
    //1.param
    double radius = nh.param("radius",0.5);//查询radius，如果没有，返回设置的默认值0.5，有的话，返回radius数值.
    ROS_INFO("radius = %.2f",radius);
    //2.getParam
    double radius2 = 0.0;
    double radius3 = 0.0;
    bool result = nh.getParam("radius",radius2);
    if(result)
    {
       ROS_INFO("获取数值为：%.2f",radius2);
    } else{
        ROS_INFO("对应变量不存在");
    }
    //3.getParamCached 逻辑与getparam一致，但是性能提升
    bool result1 = nh.getParamCached("radius",radius3);
    //4.getParamNames
    std::vector<std::string> names;
    nh.getParamNames(names);
    for (auto &&name : names)
    {
        ROS_INFO("遍历的元素：%s",name.c_str());
    }
    //5.hasParam
    bool flag1 = nh.hasParam("radius");
    bool flag2 = nh.hasParam("radiusxxx");
    ROS_INFO("radius存在? %d",flag1);
    ROS_INFO("radiusxxx存在? %d",flag2);
    
    //6.searchParam
    std::string key;
    nh.searchParam("radius",key);
    ROS_INFO("搜索结果：%s",key.c_str());
    // ros::param------------------------------------
    double radius_param = ros::param::param("radius",100.5);
    ROS_INFO("radius_param = %.2f",radius_param);
    return 0;

}