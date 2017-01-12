// diane_octomap.cpp

#include <iostream>

#include <sistema_observacao/diane_octomap.h>

using namespace std;
using namespace octomap;
using namespace octomap_msgs;


diane_octomap::DianeOctomap::DianeOctomap()
{
    stop = false;
}


void diane_octomap::DianeOctomap::onInit()
{
    StartInternalCycle();
}


void diane_octomap::DianeOctomap::StartInternalCycle()
{
    mutStartStop.lock();

    cout << "StartInternalCycle Called.\n\n";

    stop = false;

    DianeOctomap::teste();

    internalThread = new boost::thread(DianeOctomap::InternalThreadFunction, this);

    cout << "StartInternalCycle Ended.\n\n";

    mutStartStop.unlock();

}


void diane_octomap::DianeOctomap::StopInternalCycle()
{
    mutStartStop.lock();

    cout << "StopInternalCycle Called.\n\n";

    stop = true;
    internalThread->join();
    delete internalThread;
    internalThread = NULL;

    cout << "StopInternalCycle Ended.\n\n";

    mutStartStop.unlock();

}


void diane_octomap::DianeOctomap::InternalThreadFunction(DianeOctomap* diane_mapper)
{
    diane_mapper->InternalCycleProcedure();
}


void diane_octomap::DianeOctomap::InternalCycleProcedure()
{
    while (!stop)
    {

    }
}

void diane_octomap::DianeOctomap::teste()
{
    string btFilename = "/home/derekchan/catkin_workspace/src/sistema_observacao/files/MapFiles/BonsaiTree/Escada_Kinect.bt";
    string otFileName = "/home/derekchan/catkin_workspace/src/sistema_observacao/files/MapFiles/OcTree/Escada_Kinect.ot";



    cout << "\nReading OcTree file\n===========================\n" << endl;
    OcTree* tree = new OcTree(btFilename);


    size_t count(0);
    for(OcTree::leaf_iterator it = tree->begin(), end=tree->end(); it!= end; ++it)
    {
        if(tree->isNodeOccupied(*it))
        {
            count++;
            double size = it.getSize();
        }
    }

    delete tree;


}

diane_octomap::DianeOctomap::~DianeOctomap()
{
    StopInternalCycle();
}
