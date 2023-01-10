#! /usr/bin/env python

import rospy
from plumbing_pub_sub.msg import person
"""
   订阅方:订阅人的消息
      1.导包;
      2.初始化ros节点;
      3.创建订阅者对象；
      4.处理订阅的数据；
      5.spin()
"""
def doPerson(person2):
     rospy.loginfo("订阅到的数据:%s,%d,%.2f",person2.name,person2.age,person2.height)

if __name__ == "__main__":  
   # 2.初始化ros节点
   rospy.init_node("part7")
   # 3.创建订阅者对象
   sub = rospy.Subscriber("tian",person,doPerson)
   # 4.处理订阅数据;
   # 5.spin()
   rospy.spin()
   

