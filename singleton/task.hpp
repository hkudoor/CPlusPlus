#ifndef _TASK_HPP_
#define _TASK_HPP_

#define MAX_PRIORITY 10

using namespace std;

// Task Class
class Task {
protected:
    string mTaskName;
    uint8_t mTaskId;
    uint8_t mPriority;
    bool mRegisteredToScheduler;
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
        mPriority = priority%(MAX_PRIORITY+1);
    }
    uint8_t getRegistrationStatus() {
        return mRegisteredToScheduler;
    }
    string& getTaskName() {
        return mTaskName;
    }
};

// TaskOne
class TaskOne:public Task {
public:
    TaskOne(string name, uint8_t priority);
    void runTask();
};


// TaskTwo
class TaskTwo:public Task {
public:
    TaskTwo(string name, uint8_t priority);
    void runTask();
};

// TaskThree
class TaskThree:public Task {
public:
    TaskThree(string name, uint8_t priority);
    void runTask();
};

#endif // _TASK_HPP_
