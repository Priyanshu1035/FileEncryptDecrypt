#include "ProcessManagement.hpp"
#include<iostream>
#include<cstring>
// #include <sys/wait.h>
#include "../encryptDecrypt/Cryption.hpp"


ProcessManagement:: ProcessManagement(){}

bool ProcessManagement::submitToQueue(std::unique_ptr<Task> task){
    taskQueue.push(std::move(task));
    return true;
}

void ProcessManagement::executeTasks(){
    while(!taskQueue.empty()){
        std::unique_ptr<Task> tasktoExecute = std::move(taskQueue.front());
        taskQueue.pop();
        std::cout<<"Executing task : "<<tasktoExecute->toString()<<std::endl;
        executeCryption(tasktoExecute->toString());
    }
}



/*
                    GUIDELINE :

    #include <sys/wait.h>  ->  This will give error in Windows but 
    works perfectly fine in Linux and MacOS

    There are alternative ways to run it in Windows.


*/
