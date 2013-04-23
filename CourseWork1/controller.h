#ifndef CONTROLLER_H
#define CONTROLLER_H

#include<iostream>
#include <QDebug>
#include<fstream>

#include "cmatrix.h"
#include "cvector.h"

using namespace std;

class Controller
{
    private:

        Controller();
    public:
        static Controller* getSharedController();
        ~Controller();

        void RunTest();
};

#endif // CONTROLLER_H
