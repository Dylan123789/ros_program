#! /usr/bin/env python
import rospy
from turtlesim.srv import Spawn,SpawnRequest,SpawnResponse
"""
    需求:向服务器发送请求，生成乌龟
        话题:/spawn
        消息:turtlesim/Spawn
    1.导包
    2.初始化ros节点
    3.创建客户端
    4.组织并且发布请求
    5.处理响应结果

"""
if __name__ == "__main__":
    #2.初始化ros节点
    rospy.init_node("service_call_p")
    #3.创建客户端对象
    client = rospy.ServiceProxy("/spawn",Spawn)
    #4.组织数据发送请求
    request = SpawnRequest()
    request.x = 4.5
    request.y = 2.0 
    request.theta = 0
    request.name = "turtle3"
    client.wait_for_service()
    try:
        response = client.call(request)
        #5.处理响应结果
        rospy.loginfo("生成乌龟的名字叫:%s",response.name)
    except Exception as e:
        rospy.logerr("请求处理异常")
