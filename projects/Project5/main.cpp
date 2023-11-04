#include <iostream>
#include <fstream>
#include "CoursePlan.h"

using namespace std;

int main(int argc, char *argv[]){
    if(argc!=2){
        cout<<"Usage:"<<argv[0]<<"name of an input file"<<endl;
        exit(1);
    }
    CoursePlan* myCoursePlan = new CoursePlan(argv[1]);
    // myCoursePlan->print();
    cout<<myCoursePlan<<endl;
    delete myCoursePlan;
    return 0;
}