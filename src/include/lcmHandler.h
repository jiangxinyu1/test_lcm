/*
 * @Author: your name
 * @Date: 2022-01-24 18:29:14
 * @LastEditTime: 2022-01-25 10:32:37
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /test_lcm/src/lcmHandler.h
 */

#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "lcm/lcm-cpp.hpp"
#include "lcm_ros/lcm_utils.h"
#include "lcm_std_msgs/Int8.hpp"
#include "lcm_std_msgs/Int16.hpp"
#include "lcm_std_msgs/Float32MultiArray.hpp"


class lcmHandler
{
public:

  lcmHandler();
  
  ~lcmHandler();

  void cmdCallback(const lcm::ReceiveBuffer* rbuf, const std::string& chan, const lcm_std_msgs::Float32MultiArray* cmd_in);

  void run();

private:
    lcm::LCM *node_;
};