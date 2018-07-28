#include "./include/LOT_Log.h"

#include <iostream>

using namespace LOT;
using namespace std;

int main() {
    string logPath;
    cout<<"Please input log path"<<endl; //未检测合法路径
    cin>>logPath;
    Log::LogInit(logPath);
    cin.clear();
    string data;
    while(cin>>data && data != "stop") {
        Log::LogWrite(1, data.c_str(), data.length());
    }
}

