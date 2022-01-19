/*
 * @Author: jiangxinyu
 * @Date: 2021-12-15 17:03:34
 * @LastEditTime: 2022-01-19 10:42:28
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%A
 * @FilePath: /my_rkaiq_3A_server/src/test.cpp
 */
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


bool isRun = true;

void exitCtrl(int sio)
{
  if(isRun)
    isRun = false;
  std::cout << "======= exit =======" << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Handler
{
public:
  Handler() = default;

  Handler(lcm::LCM &node)
  {
      node_ = node;
      node_.subscribe("slam_cmd", &Handler::cmdCallback, this);
  }

  bool handleTimeout()
  {
      return node_.handleTimeout(0);
  }
  
  void cmdCallback(const lcm::ReceiveBuffer* rbuf, const std::string& chan, const lcm_std_msgs::Float32MultiArray* cmd_in)
  {
    printf("[cmdCallback] : in ... \n");
    if( int(cmd_in->data[1]) == 1666 )
    {
      printf("[test]:  Get SLAM_CMD 1666. \n");
    }
    if( int(cmd_in->data[1]) == 1667 )
    {
      printf("[test]:  Get SLAM_CMD 1667. \n");
    }
    sleep(1);
    printf("[cmdCallback] : out ... \n");
    }

private:
    lcm::LCM node_;
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
  std::string url = "udpm://239.255.76.67:7666";
  lcm::LCM lcm_node( url , true);
  getUdpmAddr(true);
  if ( !lcm_node.good()){return 0;}

  Handler HandleObj;
  lcm_node.subscribe("slam_cmd", &Handler::cmdCallback, &HandleObj);
    
  signal(SIGINT, exitCtrl);

  while(true)
  {
    auto val =   lcm_node.handleTimeout(500);
    // auto val =   lcm_node.handle();
    printf("[handleTimeout return] = %i \n",val);
    if (val < 0 )
    {
      break;
    }
    if(!isRun)
    {
      std::cout << "Get exit signal\n";
      break;
    }
  }
  return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
