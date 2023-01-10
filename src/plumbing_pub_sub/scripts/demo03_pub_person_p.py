#! /usr/bin/env python

import rospy
from plumbing_pub_sub.msg import person
"""
  发布方：发布人的消息
     1.导包;
     2.初始化ros节点;
     3.创建发布者对象;
     4.组织发布逻辑并发布数据;


"""
if __name__ == "__main__":
    #2.初始化ros节点;
    rospy.init_node("part6")
    #3.创建发布者对象;
    pub = rospy.Publisher("tian",person,queue_size=10)
    #4.组织发布逻辑并且发布数据
    #创建person数据
    person2 = person()
    person2.name = "小华"
    person2.age = 18
    person2.height= 1.85
    #创建Rate对象
    rate = rospy.Rate(1)
    #循环发布数据
    while not rospy.is_shutdown():
    
        pub.publish(person2)
        rospy.loginfo("发布的消息:%s,%d,%.2f",person2.name,person2.age,person2.height)
        rate.sleep()

