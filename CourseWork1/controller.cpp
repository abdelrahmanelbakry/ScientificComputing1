#include "controller.h"

Controller* sharedController = 0;
Controller::Controller()
{
}
Controller::~Controller()
{
    delete sharedController;
    sharedController = 0;
}
Controller* Controller::getSharedController()
{
    if(sharedController == 0)
        sharedController = new Controller();
    return sharedController;
}

void Controller::RunTest()
{
    ofstream log("log.txt");
    cVector<double> newVec = cVector<double>(3,6);
    log<<newVec[0]<<" "<<newVec[1]<<" "<<newVec[2]<<endl;
    cVector<double> newVec2 = newVec;
    log<<newVec2[0]<<" "<<newVec2[1]<<" "<<newVec2[2]<<endl;
    newVec[0]=7;
    newVec.resize(4);
    log<<newVec[0]<<" "<<newVec[1]<<" "<<newVec[2]<<" "<<newVec[3]<<endl;

    cMatrix<double> newMat = cMatrix<double>(3,3,10);
    log<<newMat.toString()<<endl;
   // char* log;

}
