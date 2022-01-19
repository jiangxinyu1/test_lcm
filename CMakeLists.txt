cmake_minimum_required(VERSION 2.8.3)
project(test_lcm)

set(Thirdparty_DIR ~/cleanRobot/thirdparty)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${Thirdparty_DIR}/CMakeModules")
set( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

find_package(lcm REQUIRED) 

include_directories(
    ${INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/src/include
    ${Thirdparty_DIR}/include
    ${Thirdparty_DIR}/include/lcm_msgs
    ${Thirdparty_DIR}/include/lcm_msgs/lcm_std_msgs
    ${Thirdparty_DIR}/include/lcm_msgs/lcm_sensor_msgs
    ${Thirdparty_DIR}/include/lcm_msgs/lcm_geometry_msgs
    ${LCM_INCLUDE_DIR}
)

FILE(
  GLOB
  SO_FILES
  # ... 
)

add_executable(test_lcm ./src/test.cpp)
target_link_libraries(test_lcm ${LCM_LIBRARY})