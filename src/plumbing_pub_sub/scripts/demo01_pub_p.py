#! /usr/bin/env python

import rospy
from std_msgs.msg import String #发布的消息类型
"""
   使用python实现消息发布:
   1.导包;
   2.初始化ros节点;
   3.创建发布者对象;
   4.编写发布逻辑并且发布数据.





"""

if __name__ == "__main__":
  #2.初始化ros节点;
  rospy.init_node("part3") #传入节点名称
  #3.创建发布者对象
  pub = rospy.Publisher("che",String,queue_size=10)
  #4.编写发布逻辑并发布数据.
  #创建数据
  msg = String()
  
  #指定发布频率
  rate = rospy.Rate(1)
  #设置计数器
  count = 0
  #使用循环发布数据
  while not rospy.is_shutdown():
    count +=1
    msg.data = "hello" + str(count)
    #发布数据
    pub.publish(msg)
    rospy.loginfo("发布的数据:%s",msg.data)
    rate.sleep()

   

