#ifndef COURSEPLANNER_COURSEPLAN_H
#define COURSEPLANNER_COURSEPLAN_H

#include "Course.h"
#include "nlohmann/json.hpp"
#include <vector>
#include <deque>
#include <unordered_map>
#include <map>
#include <fstream>

using json = nlohmann::json;
using namespace std;

class CoursePlan{
    public:
        CoursePlan(char *filename);
        ~CoursePlan();
        friend ostream &operator<<(ostream &outs, CoursePlan *cp);
        void print();
        deque<Course*> plan();
    private:
        void dfs(string v);
        void topoSort();
        void createGraph();
        ifstream _instream;
        deque<Course*> _plan;
        unordered_map<string, int> _visited;
        map<string, Course*> _preMappings;
        unordered_map<string, vector<Course*>> _adjList;
};
#include "CoursePlan.cpp"
#endif
