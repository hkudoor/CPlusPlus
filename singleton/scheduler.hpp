#ifndef _SCHEDULER_HPP_
#define _SCHEDULER_HPP_
#include<task.hpp>

using namespace std;

#define MAX_NUM_TASKS 20

class Scheduler{
	Task* mTaskList[MAX_NUM_TASKS] = {NULL};
	uint8_t mTaskRegistrationIndex;
    Scheduler() {
	    mTaskRegistrationIndex = 0;
	    cout<<"Creating the Scheduler"<<endl;
	}
    uint8_t getHighestPriorityTaskIndex();
    void promoteAllTasksExcept(uint8_t thisTaskIndex);
public:
    ~Scheduler() {
	    cout<<"Destroying the Scheduler"<<endl;
	}
    static Scheduler& getScheduler() {
	    static Scheduler theOnlyScheduler;
		return theOnlyScheduler;
	}
	Scheduler(Scheduler const&) = delete;
	void operator=(Scheduler const&) = delete;
	uint8_t registerTask(Task* task);
    void runScheduler();
};

#endif // _SCHEDULER_HPP_
