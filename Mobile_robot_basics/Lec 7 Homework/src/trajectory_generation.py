from math import pi, sqrt, atan2, cos, sin
import numpy as np
import rospy
import tf
from std_msgs.msg import Empty
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Twist, Pose2D
class Turtlebot():
    def __init__(self):
        rospy.init_node("turtlebot_move")
        rospy.loginfo("Press Ctrl + C to terminate")
        self.previous_velocity = [0, 0]  # Adjust as necessary
        self.previous_waypoint=[0,0]
        self.turning_speed = 0.1  # Or whatever default value you want to use
        self.vel = Twist()  # Initializing the Twist object
        self.vel_pub = rospy.Publisher("cmd_vel_mux/input/navi", Twist, queue_size=10)
        self.rate = rospy.Rate(10)

        # reset odometry to zero
        self.reset_pub = rospy.Publisher("mobile_base/commands/reset_odometry", Empty, queue_size=10)
        for i in range(10):
            self.reset_pub.publish(Empty())
            self.rate.sleep()

        # subscribe to odometry
        self.pose = Pose2D()
        self.logging_counter = 0
        self.trajectory = list()
        self.odom_sub = rospy.Subscriber("odom", Odometry, self.odom_callback)

        try:
            self.run()
        except rospy.ROSInterruptException:
            rospy.loginfo("Action terminated.")
        finally:
            # save trajectory into csv file
            np.savetxt('trajectory.csv', np.array(self.trajectory), fmt='%f', delimiter=',')
    def run(self):
        waypoints = [[0.5, 0], [0.5, -0.5], [1, -0.5], [1, 0], [1, 0.5],\
                      [1.5, 0.5], [1.5, 0], [1.5, -0.5], [1, -0.5], [1, 0],\
                      [1, 0.5], [0.5, 0.5], [0.5, 0], [0, 0], [0, 0]]
        for i in range(len(waypoints)-1):
            self.move_to_point(waypoints[i], waypoints[i+1])


    def move_to_point(self, current_waypoint, next_waypoint):
        # generate polynomial trajectory and move to current_waypoint
        # next_waypoint is to help determine the velocity to pass current_waypoint
        px_start=self.previous_waypoint[0]
        py_start=self.previous_waypoint[1]
        px_end=next_waypoint[0]
        py_end=next_waypoint[1]
        vx_start=self.previous_velocity[0]
        vy_start=self.previous_velocity[1]

        diff_x=next_waypoint[0]-next_waypoint[0]
        diff_y=next_waypoint[1]-next_waypoint[1]
        angle=atan2(diff_y,diff_x)

        vx_end=self.turning_speed*cos(angle)
        vy_end=self.turning_speed*sin(angle)


        if current_waypoint==[0,0]:
            vx_end=0
            vy_end=0
        T=2
        coef_x=self.polynomial_time_scaling_3rd_order(px_start,vx_start,px_end,vx_end,T)
        coef_y=self.polynomial_time_scaling_3rd_order(px_start,vx_start,px_end,vx_end,T)
        for i in range(10*T):
            t=0.1*i
            v_vec=np.array([3*t**2,2*t,1,0])
            vx=v_vec@coef_x
            vy=v_vec@coef_y
            v=sqrt(vx**2+vy**2)
            theta=atan2(vy,vx)
            w=theta-self.pose.theta
            w=w-2*pi if w >pi else w+2*pi if w<-pi else w
            w=5*w
            self.vel.linear.x=v
            self.vel.angular.z=w
            self.vel_pub.publish(self.vel)
            self.rate.sleep()
        self.previous_waypoint=current_waypoint
        self.previous_velocity=[vx_end,vy_end]
        pass


    def polynomial_time_scaling_3rd_order(self, p_start, v_start, p_end, v_end, T):
        # input: p,v: position and velocity of start/end point
        #        T: the desired time to complete this segment of trajectory (in second)
        # output: the coefficients of this polynomial
        Matrix_cof=np.array([[1, 0, 0, 0],
                            [0, 1, 0, 0],
                            [1, T, T**2, T**3],
                            [0, 1, 2*T, 3*T**2]])
        Matrix_pos=(np.array([p_start, v_start, p_end, v_end])).T
        coef=np.linalg.inv(Matrix_cof)@Matrix_pos
        return coef


    def odom_callback(self, msg):
        # get pose = (x, y, theta) from odometry topic
        quarternion = [msg.pose.pose.orientation.x, msg.pose.pose.orientation.y,\
                    msg.pose.pose.orientation.z, msg.pose.pose.orientation.w]
        (roll, pitch, yaw) = tf.transformations.euler_from_quaternion(quarternion)
        self.pose.theta = yaw
        self.pose.x = msg.pose.pose.position.x
        self.pose.y = msg.pose.pose.position.y

        # logging once every 100 times (Gazebo runs at 1000Hz; we save it at 10Hz)
        self.logging_counter += 1
        if self.logging_counter == 100:
            self.logging_counter = 0
            self.trajectory.append([self.pose.x, self.pose.y])  # save trajectory
            rospy.loginfo("odom: x=" + str(self.pose.x) +\
                ";  y=" + str(self.pose.y) + ";  theta=" + str(yaw))


if __name__ == '__main__':
    whatever = Turtlebot()
