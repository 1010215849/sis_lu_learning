#! /usr/bin/env python3
import math
import rospy
from std_msgs.msg import Float64

if __name__ == "__main__":
    rospy.init_node("arm_circle")
    pub = rospy.Publisher("/arm_controller/elbow_joint/command",Float64,queue_size=10)

    msg = Float64()
    msg = 0.1
    rate = rospy.Rate(10)
    count = 0

    while not rospy.is_shutdown():
        msg =  0.4 *math.cos(count*0.1)
        pub.publish(msg)
        rospy.logerr("publish succeessfully %.2f",count)
        rate.sleep()
        count += 1