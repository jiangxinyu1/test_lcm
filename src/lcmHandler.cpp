/*
 * @Author: your name
 * @Date: 2022-01-24 18:28:58
 * @LastEditTime: 2022-01-25 10:34:59
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /test_lcm/src/lcmHandler.cpp
 */

#include "lcmHandler.h"


lcmHandler::lcmHandler()
{

  node_ = new lcm::LCM(getUdpmAddr(true), true);

  if(!node_->good())
  {
    std::cout << "[ERROR] : LCM node is not good ! \n";
  }
  // 在构造函数中注册回调函数，如果需要触发式的发布，则在callback中进行发布
  node_->subscribe("slam_cmd", &lcmHandler::cmdCallback, this);
  
}

lcmHandler::~lcmHandler()
{
  delete node_;
}

void lcmHandler::run()
{
  while (true)
  {
    auto res = node_->handleTimeout(50);
    if (res < 0 )
    {
      printf("[handleTimeout return] = %i \n",res);
      break;
    }
    // TODO : 如果需要持续的发布，则在此进行 
    printf("[handleTimeout return] = %i \n",res);
    sleep(0.5);
  }//while
}


void lcmHandler::cmdCallback(const lcm::ReceiveBuffer* rbuf, const std::string& chan, const lcm_std_msgs::Float32MultiArray* cmd_in)
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
