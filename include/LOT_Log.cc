#include "./LOT_Log.h"
#include <fstream>
#include <iostream>

using namespace std;
using namespace LOT;


std::string LOT::Log::logPath_ = "file.txt"; //暂时不考虑跨平台

void Log::LogInit(const char* path, int length){
    logPath_ = string(path, length);
}

void Log::LogInit(string& path){
    swap(logPath_, path);
}

int Log::LogWrite(int64_t id, const char* data, int length){
    ofstream outputStream(logPath_, ofstream::out | ofstream::app);
    if(outputStream.is_open()) {
        outputStream<<"id : "<<id<<" "<<data<<endl;
        outputStream.close();
        return LOG_WRITE_ACCEPT; // No exception
    }
    else{
        cout<<"Open LogFile error"<<endl;
        return LOG_WRITE_ERROR;
    }
}
