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
  SRC_FILES
  ${PROJECT_SOURCE_DIR}/src/lcmHandler.cpp
  ${PROJECT_SOURCE_DIR}/src/test.cpp
)

FILE(
  GLOB
  SRC_FILES_2
  ${PROJECT_SOURCE_DIR}/src/lcmHandler.cpp
  ${PROJECT_SOURCE_DIR}/src/test_lcm.cpp
)

# add_executable(test_lcm ${SRC_FILES})
# target_link_libraries(test_lcm ${LCM_LIBRARY})

add_executable(test_lcm_2 ${SRC_FILES_2})
target_link_libraries(test_lcm_2 ${LCM_LIBRARY})