#include "./include/LOT_Log.h"
#include "./include/FileManager.h"
#include <iostream>
#include <memory>
#include <string.h>
#include <vector>

using namespace LOT;
using namespace std;

int main() {
    FILE* file = fopen("/home/ysing/Project/C++/LOT/006i7geoly1fdvojsemw5j308c08cdfy.jpg", "r");
    if(file == nullptr) {
        printf("Error Open");
    }
    int fileSize = FileManager::getInstance()->getFileSize(file);
    shared_ptr<vector<char>> ptr(new vector<char>(1024*1024));
    char* buff = ptr->data();
    int type  = FileManager::getInstance()->ReadFileType("/home/ysing/Project/C++/LOT/006i7geoly1fdvojsemw5j308c08cdfy.jpg");
    memcpy(buff, (char*)(&type), sizeof(int));
    while(!feof(file)) {
        int readSize = FileManager::getInstance()->ReadFile(file, ptr->data()+sizeof(int), 1024*1024-sizeof(int));
        cout<<" readSize : " <<readSize<<endl;
        int trans;
        memcpy((char*)(&trans), ptr->data(), sizeof(int));
        cout<<trans<<endl;
        FILE* image = fopen("bak2.jpeg", "w");

        int write_size = FileManager::getInstance()->writeFile(image, readSize, ptr->data()+sizeof(int));
        //cout<<write_size<<endl;
    }
    return 0;
}
