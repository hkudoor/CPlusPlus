#include<iostream>
#include<scheduler.hpp>
#include<stdint.h>
#include<task.hpp>

using namespace std;

// Scheduler Class definition
uint8_t Scheduler::registerTask(Task* task) {
    uint8_t taskId = -1;
    if(mTaskRegistrationIndex != (MAX_NUM_TASKS - 1)) {
	    mTaskList[mTaskRegistrationIndex] = task;
		taskId = mTaskRegistrationIndex;
		mTaskRegistrationIndex++;
	}
	return taskId;
}
