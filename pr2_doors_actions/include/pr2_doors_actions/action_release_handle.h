/*********************************************************************
 * Software License Agreement (BSD License)
 * 
 *  Copyright (c) 2008, Willow Garage, Inc.
 *  All rights reserved.
 * 
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 * 
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 * 
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/


/* Author: Wim Meeusen */

#ifndef ACTION_RELEASE_HANDLE_H
#define ACTION_RELEASE_HANDLE_H


#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <kdl/frames.hpp>
#include <door_msgs/DoorGoal.h>
#include <door_msgs/DoorAction.h>
#include <actionlib/server/simple_action_server.h>
#include <actionlib/client/simple_action_client.h>
#include <pr2_controllers_msgs/Pr2GripperCommandAction.h>
#include <pr2_common_action_msgs/PR2ArmIKAction.h>


namespace door_handle_detector{

typedef boost::shared_ptr<geometry_msgs::PoseStamped const> PoseConstPtr;

class ReleaseHandleAction
{
public:
  ReleaseHandleAction(tf::TransformListener& tf);
  ~ReleaseHandleAction();

private:
  void execute(const door_msgs::DoorGoalConstPtr& goal);

  tf::TransformListener& tf_; 
  actionlib::SimpleActionServer<door_msgs::DoorAction> action_server_;
  door_msgs::DoorResult action_result_;

  actionlib::SimpleActionClient<pr2_controllers_msgs::Pr2GripperCommandAction> gripper_action_client_;  

  actionlib::SimpleActionClient<pr2_common_action_msgs::PR2ArmIKAction> ik_action_client_;
  pr2_common_action_msgs::PR2ArmIKGoal ik_goal_;
};

}
#endif
