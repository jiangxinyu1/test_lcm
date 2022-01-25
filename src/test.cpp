/*
 * @Author: jiangxinyu
 * @Date: 2021-12-15 17:03:34
 * @LastEditTime: 2022-01-24 18:46:03
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%A
 * @FilePath: /my_rkaiq_3A_server/src/test.cpp
 */

#include "lcmHandler.h"


bool isRun = true;

void exitCtrl(int sio)
{
  if(isRun)
    isRun = false;
  std::cout << "======= exit =======" << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
