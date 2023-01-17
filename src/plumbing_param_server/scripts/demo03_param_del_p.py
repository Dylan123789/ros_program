#! /usr/bin/env python

import rospy

if __name__ == "__main__":
    rospy.init_node("del_param_P")
    #删除参数
    rospy.delete_param("radius_p")
    