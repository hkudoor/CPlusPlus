#include<iostream>
#include<task.hpp>
#include<scheduler.hpp>

using namespace std;

// Task Class Definition
Task::Task(string name, uint8_t priority) {
    mTaskName = name;
    mPriority = priority;
    cout<<"Creating Task with name "<<mTaskName.c_str()<<endl;

    // register task with a scheduler
    registerTask();
    if(mTaskId != -1) {
        mRegisteredToScheduler = true;
    }
}

void Task::runTask() {
    cout<<"Base Task Class "<<mTaskName.c_str()<<" running..."<<endl;
}

void Task::registerTask() {
    Scheduler& scheduler = Scheduler::getScheduler();
    mTaskId = scheduler.registerTask(this);
}

// TaskOne Class Definition
TaskOne::TaskOne(string name, uint8_t priority):
         Task(name, priority) {
    cout<<"Creating object of type TaskOne\n";
}

void TaskOne::runTask() {
    cout<<"Running Task --- ONE ---\n";
}

// TaskTwo Class Definition
TaskTwo::TaskTwo(string name, uint8_t priority):
         Task(name, priority) {
    cout<<"Creating object of type TaskTwo\n";
}

void TaskTwo::runTask() {
    cout<<"Running Task --- TWO ---\n";
}

// TaskThree Class Definition
TaskThree::TaskThree(string name, uint8_t priority):
           Task(name, priority) {
    cout<<"Creating object of type TaskThree\n";
}

void TaskThree::runTask() {
    cout<<"Running Task --- THREE ---\n";
}
