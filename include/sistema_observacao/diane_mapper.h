/*!
 * \file diane_mapper.h
 */



#ifndef DIANE_MAPPER_H
#define DIANE_MAPPER_H


#include <vector>
#include <ros/ros.h>

#include <std_msgs/Empty.h>
#include <std_msgs/UInt8.h>
#include <std_srvs/Empty.h>

#include <octomap/OcTree.h>

using std::vector;

namespace diane_mapper {



/*!
 * \class DianeMapper
 * \brief The DianeMapper class
 */
class DianeMapper
{
    //OcTree


protected:

public:
    DianeMapper();

    void onInit();

    virtual ~DianeMapper();
};


}

#endif
