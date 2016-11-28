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
