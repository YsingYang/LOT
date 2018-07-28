#include <assert.h>
#include <string.h>
#include "Serialize.h"
#include "LOT_Log.h"

using namespace LOT;
using namespace std;

void Serializer(char* buffer, uint64_t maxLength, FileData* data) { //Filetype To buffer
    assert(sizeof(FileData) < maxLength); //FileData生成时， 保证其 < maxLength
    bzero(buffer, maxLength);
    memcpy(buffer, (char*)data, sizeof(FileData)); //注意是否会出错
    SetEndTag(buffer, maxLength, sizeof(FileData));
}

void Deserializer(char* buffer, uint64_t bufferLength, FileData* data) { //Buffer to Filetype
    bzero((char*)(data), sizeof(FileData));
    memcpy(data, buffer, bufferLength);
}

void LOT::SetEndTag(char* buffer, uint64_t maxLength, uint64_t index) {  //为什么这里不加作用域会报错.
    if(index >= maxLength) {
        string error = "[Error] : In SetEndTag Function : index >= maxLength";
        Log::LogWrite(SELF_ERROR_ID, error.c_str(), error.size());
    }
    buffer[index] = '\0';
}


