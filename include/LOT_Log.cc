#include "LOT_Log.h"
#include <fstream>

Log::logPath_ = "logFile"; //暂时不考虑跨平台

static void LOT_Log::SetPath(const char* path) {
    logPath_ = path;
}

static int LogWrite(int64_t id, const char* data, int length){
    if(outputStream.is_open()) {
        ofstream outputStream(path);
        outputStream<<"id : "<<id<<" "<<data<<std::endl;
        outputStream.close();
    }
    else{
        std::cout<<"Open LogFile error"<<std::endl;
        ofstream outputStream(serious_Log_);
        if(outputStream.is_open()) {
            ofstream outputStream(path);
            outputStream<<"id : "<<id<<" "<<data<<std::endl;
            outputStream.close();
        }
        else {
            std::cout<<"Serious LogFile error"<<std::endl;
        }
    }
}
