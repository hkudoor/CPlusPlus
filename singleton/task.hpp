#ifndef _TASK_HPP_
#define _TASK_HPP_

using namespace std;

// Task Class
class Task {
protected:
    uint8_t mTaskId;
    uint8_t mPriority;
    bool mRegisteredToScheduler;
    string mTaskName;
    Task(string name, uint8_t priority); 
    ~Task() {
        cout<<"Deleting Task with ID "<<(int)mTaskId<<endl;
    }
public:
    virtual void runTask();
    void registerTask();
    uint8_t getPriority() {
        return mPriority;
    }
    void setPriority(uint8_t priority) {
        mPriority = priority;
    }
    uint8_t getRegistrationStatus() {
        return mRegisteredToScheduler;
    }
    string& getTaskName() {
        return mTaskName;
    }
};


#endif // _TASK_HPP_
