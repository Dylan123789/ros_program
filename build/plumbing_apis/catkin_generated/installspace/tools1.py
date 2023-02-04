#!/usr/bin/env python3
import rospy
import tools
import os
#设置临时环境变量
sys.path.insert(0,"/home/dylan/桌面/demo03_ws/src/plumbing_apis/scripts")
"""实现在该程序中调用tool文件"""
#rosrun执行时,参考路径是工作空间的路径，在工作空间下无法查找依赖模块
#解决:可以声明python的环境变量，当依赖某个模块时，先去指定的环境变量中查找依赖
if __name__ == "__main__":
    rospy.init_node("tool")
    rospy.loginfo("num = %d",tools.num)
    path = os.path.abspath(".")
    rospy.loginfo("执行时候参考的路径:%s",path)