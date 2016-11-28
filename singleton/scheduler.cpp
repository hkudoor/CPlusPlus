#include<iostream>
#include<scheduler.hpp>
#include<stdint.h>
#include<task.hpp>

using namespace std;

// Scheduler Class definition
uint8_t Scheduler::getHighestPriorityTaskIndex() {
    uint8_t index=0;
    uint8_t highestPriorityIndex=0, highestPriority;
    highestPriority = mTaskList[highestPriorityIndex]->getPriority();
    for(index=1; index<mTaskRegistrationIndex; index++) {
        if(mTaskList[index]->getPriority() > highestPriority) {
            highestPriority = mTaskList[index]->getPriority();
            highestPriorityIndex = index;
        }
    }
    return highestPriorityIndex;
}

void Scheduler::promoteAllTasksExcept(uint8_t thisTaskIndex) {
    uint8_t index=0, tempPriority;
    cout<<"Priorities : ";
    for(index=0; index<mTaskRegistrationIndex; index++) {
        if(index == thisTaskIndex) { 
            cout<<(int)tempPriority<<" : ";
            continue;
        }
        tempPriority = mTaskList[index]->getPriority();
        tempPriority++;
        mTaskList[index]->setPriority(tempPriority);
        cout<<(int)tempPriority<<" : ";
    }
    cout<<endl;
}

uint8_t Scheduler::registerTask(Task* task) {
    uint8_t taskId = -1;
    if(mTaskRegistrationIndex != (MAX_NUM_TASKS - 1)) {
	    mTaskList[mTaskRegistrationIndex] = task;
		taskId = mTaskRegistrationIndex;
		mTaskRegistrationIndex++;
        cout<<(int)mTaskRegistrationIndex<<" number of tasks registered\n";
	}
	return taskId;
}

void Scheduler::runScheduler() {
   uint8_t index=0;
   index = getHighestPriorityTaskIndex();
   mTaskList[index]->runTask();
   promoteAllTasksExcept(index);
}
