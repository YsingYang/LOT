#ifndef __FILEMANAGER_H__
#define __FILEMANAGER_H__

#include <boost/core/noncopyable.hpp>
#include <memory>
#include <iostream>
#include "Serialize.h"

using namespace std;

namespace LOT{

    const string IMG_PNG_TYPE = "png";
    const string IMG_JPEG_TYPE_1 = "jpg";
    const string IMG_JPEG_TYPE_2 = "jpeg";
    const int DEFINE_PNG_TAG = 1;
    const int DEFINE_JPG_TAG = 2;

    class FileManager : boost::noncopyable {
        public:
            static FileManager* getInstance();
            void free();
            int ReadFile(FILE* , char* , int );
            int writeFile(FILE*, int, char*);
            int getFileSize(FILE*);
            int ReadFileType(string path);

        private:
            FileManager(){}
            ~FileManager(){
                delete instance_;
            }


        private:
            static FileManager* instance_;
            //FILE* fptr_; // 是否需要维护该指针
    };

}
#endif // __FILEMANAGER_H__


