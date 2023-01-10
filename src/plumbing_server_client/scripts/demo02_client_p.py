#! /usr/bin/env python

import rospy
from plumbing_server_client.srv import *
"""
    客户端实现：组织提交请求，处理响应.
    1.导包;
    2.初始化ros节点;
    3.创建客户端对象；
    4.组织请求数据，并发送请求；
    5.处理响应；
对于客户端先于服务端启动，则需要让客户端先挂起，等服务端启动，再请求。
实现:ROS内置函数
    
"""


if __name__ == "__main__":
    #判断参数长度（系统自带一个默认参数，文件名）
    if len(sys.argv) != 3:
        rospy.logerr("传入参数个数不对")
        sys.exit(1)

    #2.初始化ros节点
    rospy.init_node("node4")
    #3.创建客户端对象
    client = rospy.ServiceProxy("addInts",AddInts)
    # 4.组织请求数据，并发送请求；
    num1 = int(sys.argv[1])
    num2 = int(sys.argv[2])
    client.wait_for_service()#挂起
    response =client.call(num1,num2)
    # 5.处理 响应
    rospy.loginfo("响应的数据是：%d",response.sum)

