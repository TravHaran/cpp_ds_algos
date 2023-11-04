#include <iostream>
using namespace std;

Course::Course(json obj){
    _title = obj["Title"];
    _instructor = obj["Instructor"];
    _courseID = obj["ID"];
    _prerequisites = obj["Prerequisites"];

}


