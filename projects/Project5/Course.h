#ifndef COURSEPLANNER_COURSE_H
#define COURSEPLANNER_COURSE_H

#include <vector>
#include "nlohmann/json.hpp"

using json = nlohmann::json;
using namespace std;

class Course{
    public:
        Course(json obj);
        string& title() {return _title;}
        string& instructor() {return _instructor;}
        string& courseID() {return _courseID;}
        vector<string>& prerequisites() {return _prerequisites;}
    private:
        string _title;
        string _instructor;
        string _courseID;
        vector<string> _prerequisites;
};
#include "Course.cpp"
#endif