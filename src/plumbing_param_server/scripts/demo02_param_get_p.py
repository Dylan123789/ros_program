#! /usr/bin/env python

import rospy

"""
    参数查询
    get_param:当键（参数名）存在，返回对应参数数据，否则返回默认值
    get_param_names:获取所有的参数的键的集合
    has_param:判断是否包含某个键
    search_param:查找某个参数的键，并且返回完整的键名.
"""
if __name__ == "__main__":
    rospy.init_node("get_param_p")
    # 1.get_param get_param_cached语法与get_param一致，效率更高一些
    radius = rospy.get_param("radius_p",0.5)
    rospy.loginfo("radius =%.2f",radius)
    # 2.get_param_names
    names = rospy.get_param_names()
    for name in names:
        rospy.loginfo("name = %s",name)
    # 3.has_param
    flag1 = rospy.has_param("radius_p")
    if flag1:
        rospy.loginfo("radius_p存在")
    else:
        rospy.loginfo("radius_p不存在")     
    #4.search_param
    key = rospy.search_param("radius_p")
    rospy.loginfo("key = %s",key)