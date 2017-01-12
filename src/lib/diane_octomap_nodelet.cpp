// diane_octomap_nodelet.cpp



#include <sistema_observacao/diane_octomap_nodelet.h>


diane_octomap::DianeOctomapNodelet::DianeOctomapNodelet()
{
}


void diane_octomap::DianeOctomapNodelet::onInit()
{
    DianeOctomap::onInit();

    nodeHandle = getNodeHandle();

    StartInternalCycle();

}

diane_octomap::DianeOctomapNodelet::~DianeOctomapNodelet()
{
    StopInternalCycle();
}
