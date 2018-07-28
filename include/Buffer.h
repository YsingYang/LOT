#ifndef __BUFFER_H__
#define __BUFFER_H__

namespace LOT{
    class Buffer {
    public:
        Buffer(int size);
        ~Buffer();
        char* getBuff();
    private:
        char* buffer_;
    };
}

#endif // __BUFFER_H__


