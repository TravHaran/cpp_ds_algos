#include <iostream>
using namespace std;

CoursePlan::CoursePlan(char *filename){
    // read in the file as json
    ifstream fileIn(filename);
    json data = json::parse(fileIn);
    for(int i = 0; i < data["Courses"].size(); i++){
        Course* courseObj = new Course(data["Courses"][i]);
        _preMappings[courseObj->courseID()] = courseObj;  
        vector<Course*> courseVect;
        _adjList[courseObj->courseID()] = courseVect;
    }
    createGraph();
    topoSort();
}

CoursePlan::~CoursePlan(){
    for(auto &elem : _preMappings)
        delete elem.second;
}

deque<Course*> CoursePlan::plan(){
    return _plan;
}

ostream &operator<<(ostream &outs, CoursePlan *cp){
    int order = 1;
    for(auto &c: cp->plan()){
        outs<<order<<". "<<c->courseID()<<": \""<<c->title()<<"\""<<endl;
        outs<<"Taught by: "<<c->instructor()<<"\n"<<endl;
        order++;
    }
    return outs;
}

void CoursePlan::print(){
    cout<<"COURSE PLAN"<<endl;
    int courseCount = 1;
    while(_plan.empty()==false){
        Course* course = _plan.back();
        cout<<"Course "<<courseCount<<": ";
        cout<<"Course ID: "<<course->courseID()<<", ";
        cout<<"Title: "<<course->title()<<", ";
        cout<<"Instructor: "<<course->instructor()<<endl;
        cout<<endl;
        courseCount++;
        _plan.pop_back();
    }
}

void CoursePlan::createGraph(){
    for(auto &el: _preMappings){
        vector<Course*> prereqs;
        for(auto &elem : el.second->prerequisites()){
            _adjList[elem].push_back(el.second);
        }
    }
}

void CoursePlan::topoSort(){
    for(auto &el: _adjList){
        if(_visited[el.first]!=1){
            dfs(el.first);
        }
    } 
}

void CoursePlan::dfs(string v){
    if(!_visited[v]){
        _visited[v] = 1;
        for(Course* neighbor: _adjList[v]){
            if(_visited[neighbor->courseID()]!=1){
                dfs(neighbor->courseID());
            }
        }
        //Here we add the courses to the front of the queue
        //during the recursive (popping off the stack) phase
        _plan.push_front(_preMappings[v]);
    }
    
}

