// diane_octomap.cpp


#include <sistema_observacao/diane_octomap.h>
#include <iostream>

using namespace std;
using namespace octomap;


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

    stop = false;

    DianeOctomap::teste();

    internalThread = new boost::thread(DianeOctomap::InternalThreadFunction, this);

    mutStartStop.unlock();

}


void diane_octomap::DianeOctomap::StopInternalCycle()
{
    mutStartStop.lock();

    stop = true;
    internalThread->join();
    delete internalThread;
    internalThread = NULL;

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

void diane_octomap::DianeOctomap::teste(){
      string vrmlFilename = "";
      string btFilename = "";

      btFilename = "/home/rob/catkin_ws/src/sistema_observacao/files/MapFiles/BonsaiTree/Escada_Kinect.bt";



      cout << "\nReading OcTree file\n===========================\n";
      OcTree* tree = new OcTree(btFilename);



      size_t count(0);
      for(OcTree::leaf_iterator it = tree->begin(), end=tree->end(); it!= end; ++it) {
        if(tree->isNodeOccupied(*it)){
          count++;
          double size = it.getSize();
          outfile << "Transform { translation "
              << it.getX() << " " << it.getY() << " " << it.getZ()
              << " \n  children ["
              << " Shape { geometry Box { size "
              << size << " " << size << " " << size << "} } ]\n"
              << "}\n";
        }
      }

      delete tree;

      outfile.close();



}

diane_octomap::DianeOctomap::~DianeOctomap()
{
    StopInternalCycle();
}
