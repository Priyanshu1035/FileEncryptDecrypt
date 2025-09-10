#ifndef PROCESS_MANAGEMENT_HPP
#define PROCESS_MANAGEMENT_HPP

#include "Task.hpp"
#include<queue>
#include<memory>
#include<semaphore.h>
#include<mutex>

class ProcessManagement{
    
    sem_t* itemsSemaphore;
    sem_t* emptySlotsSemaphore;

    public:
        ProcessManagement();
        ~ProcessManagement();
        bool submitToQueue(std::unique_ptr<Task>  task);
        void executeTasks();
    private:
        struct SharedMemory{
            std::atomic<int> size;
            char tasks[1000][256];
            int front;
            int rear;

            void printSharedMemory(){
                std::cout<<size<<std::endl;
            }
        };
        SharedMemory* sharedMem;
        int shmFd;
        const char* SHM_NAME = "/my_queue";
        std::mutex queueLock;

}; 

#endif