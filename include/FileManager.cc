#include "FileManager.h"
#include "LOT_Log.h"

using namespace LOT;
using namespace std;

const int EACH_TIME_READ = 1;
const int EACH_TIME_WRITE = 2;

FileManager* FileManager::instance_ = nullptr;

FileManager* FileManager::getInstance() { //假设线程安全
    if(instance_ == nullptr) {
        instance_ = new FileManager();
    }
    return instance_;
}

void FileManager::free() {
    this->~FileManager();
}

int FileManager::getFileSize(FILE* file) {
    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    return fileSize;
}

int FileManager::ReadFile(FILE* file, char* buffer, int maxLength) {
    return fread(buffer, EACH_TIME_READ, maxLength-1, file);
}

int FileManager::writeFile(FILE* file, int length, char* buffer) {
    return fwrite(buffer, EACH_TIME_WRITE, length, file);
}

int FileManager::ReadFileType(string path) {
    string type = path.substr(path.find_last_of(".")+1);
    if(type == IMG_JPEG_TYPE_1 || type == IMG_JPEG_TYPE_2) {
        return DEFINE_JPG_TAG;
    }
    else if(type == IMG_PNG_TYPE) {
        return DEFINE_PNG_TAG;
    }
    else {
        string error = "NO MATCH TYPE";
        cout<<error<<endl;
        Log::LogWrite(SELF_ERROR_ID, error.c_str(), error.size());
        return 0;
    }
}

