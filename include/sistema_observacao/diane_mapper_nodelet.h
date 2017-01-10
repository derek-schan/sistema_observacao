/*!
 * \file diane_mapper_nodelet.h
 */



#ifndef DIANE_DIANE_MAPPER_NODELET_H
#define DIANE_DIANE_MAPPER_NODELET_H

#include <sistema_observacao/diane_mapper.h>
#include <ros/ros.h>
#include <nodelet/nodelet.h>
#include <string>

#include <std_msgs/Empty.h>
#include <std_msgs/UInt8.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/Float64.h>
#include <std_srvs/Empty.h>


namespace diane_mapper {



/*!
 * \class DianeMapperNodelet
 * \brief The DianeMapperNodelet class
 */
class DianeMapperNodelet : public DianeMapper
{
     /// ROS node handle.
     ros::NodeHandle nodeHandle;

//     std::vector <ros::Subscriber> msgeposstatesub;
//     std::vector <ros::Subscriber> msgeposinfosub;
//     ros::Subscriber msgKinectPitchSub;

//     ros::Publisher msginputpub;
//     ros::Publisher msgFeedbackPub;
//     std::vector <ros::Publisher> msgEposInfoPub;

//     std::vector <ros::ServiceClient> srveposcontrolcli;

//     void EposStateCallback(const std_msgs::UInt8::ConstPtr& msg, int i);
//     void EposInfoCallback(const epos::Info::ConstPtr& msg, int i);
//     void KinectPitchCallback(const std_msgs::Float64::ConstPtr& msg);
//     void LoadVariablesInEpos(float* pos, short* controlMode, std::vector<bool>* digitalOut);
//     void Feedback();

 public:
     DianeMapperNodelet();
     void onInit();
     virtual ~DianeMapperNodelet();
};


}
#endif
