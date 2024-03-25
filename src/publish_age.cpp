#include "topic_ex/Age.h"
#include <ros/ros.h>

int main(int argc, char **argv) {

  ros::init(argc, argv, "age_publisher");
  ros::NodeHandle nh;

  ros::Publisher pub = nh.advertise<topic_ex::Age>("age", 1000);
  ros::Rate loop_rate(1);

  topic_ex::Age age;
  age.years = 1976;
  age.months = 8;
  age.days = 24;

  while (ros::ok()) {
    pub.publish(age);
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}