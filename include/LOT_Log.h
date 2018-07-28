#ifndef __LOT_LOG_H__
#define __LOT_LOG_H__

#include <cstdint>
#include <string>

const uint32_t SELF_ERROR_ID = 0;

const uint32_t LOG_WRITE_ACCEPT = 1;
const uint32_t LOG_WRITE_ERROR = 2;

const uint32_t LOG_FLUSH_ACCEPT = 1;
const uint32_t LOG_FLUSH_ERROR = 2;


namespace LOT{

    class Log {
    public:
        static void LogInit(const char*, int length); //设置路径
        static void LogInit(std::string&);
        static int LogWrite(int64_t, const char*, int length);
        static int LogFlush();
    private:
        Log() {}
        Log(const Log&) = delete;
        Log& operator=(const Log& ) = delete;

    private:
        static std::string logPath_;
    };
}


#endif // __LOT_LOG_H__

