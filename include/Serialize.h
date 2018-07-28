#ifndef SERIALIZE_H
#define SERIALIZE_H

#include <cstdint>
#include "FileData.h"


namespace LOT{

    void Serializer(char* buffer, uint64_t maxLength, FileData* );

    void Deserializer(char* buffer, uint64_t bufferLength, FileData* );

    void SetEndTag(char* buffer, uint64_t maxLength, uint64_t index);

}
#endif // SERIALIZE_H


