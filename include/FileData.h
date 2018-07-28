#ifndef __FILE_DATA_H__
#define __FILE_DATA_H__

#include <string>
using namespace std;

namespace LOT {

    const uint32_t BUFFER_SIZE = 1024 * 1024 * 7;

    class FileData{
    public:
        FileData();
        ~FileData();
        char* dataPtr();
    private:
        string type_;
        char* data_;
    };

}
#endif

