#include<iostream>
#include<task.hpp>
#include<scheduler.cpp>

// main
int main(int argc, char** argv) {
   uint8_t numIter = 5, index = 0;
   string numIterString;
   size_t sz = 0;
   Scheduler& sched = Scheduler::getScheduler();
   TaskOne task1("T-One", 5);
   TaskTwo task2("T-Two", 2);
   TaskThree task3("T-Three", 8);

   if(argc>1) {
       numIterString = argv[1];
       numIter = stoi(numIterString, &sz);
   }
   for(index=0; index<numIter; index++) {
       sched.runScheduler();
   } 
}
