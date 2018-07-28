#include <stdlib.h>
#include "Buffer.h"

using namespace LOT;

Buffer::Buffer(int size):buffer_(new char[size]){

}

Buffer::~Buffer() {
    free(buffer_);
}

