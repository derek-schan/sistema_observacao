// diane_octomap.cpp

#include <iostream>

#include <sistema_observacao/diane_octomap.h>

using namespace std;
using namespace octomap;
using octomap_msgs::Octomap;


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

    DianeOctomap::GenerateOcTreeFromFile();

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


void diane_octomap::DianeOctomap::teste()
{
    string btFilename = "/home/derekchan/catkin_workspace/src/sistema_observacao/files/MapFiles/BonsaiTree/Escada_Kinect_5.bt";


    cout << "\nReading OcTree file\n===========================\n" << endl;
    OcTree* tree = new OcTree(btFilename);


    size_t count(0);
    for(OcTree::leaf_iterator it = tree->begin(), end=tree->end(); it!= end; ++it)
    {
        if(tree->isNodeOccupied(*it))
        {
            count++;
        }
    }

    delete tree;


}


void diane_octomap::DianeOctomap::GenerateOcTreeFromFile()
{
    string otFileName = "/home/derekchan/catkin_workspace/src/sistema_observacao/files/MapFiles/Octree/Escada_Kinect_5.ot";

    AbstractOcTree* abs_tree = AbstractOcTree::read(otFileName);
    if(abs_tree) // read error returns NULL
    {
        octree = dynamic_cast<OcTree*>(abs_tree);

        if (octree) // cast succeeds if correct type
        {
            size_t occupied_count(0);

            size_t free_count(0);

            size_t total_count(0);

            double size;

            for(OcTree::leaf_iterator it = octree->begin(), end=octree->end(); it!= end; ++it)
            {
                if(octree->isNodeOccupied(*it))
                {
                    occupied_count++;
                }
                else
                {
                    free_count++;
                }

                total_count++;

                size = it.getSize();
            }

            cout << "\nWriting OcTree Information\n===========================\n\n" << endl;

            cout << "Número de nós ocupados: " << occupied_count << ".\n" << endl;
            cout << "Número de nós livres: " << free_count << ".\n" << endl;
            cout << "Número de nós totais: " << total_count << ".\n" << endl;

        }
    }

}


void diane_octomap::DianeOctomap::StairDetection(OcTree* octree)
{


}


diane_octomap::DianeOctomap::~DianeOctomap()
{
    StopInternalCycle();
}
