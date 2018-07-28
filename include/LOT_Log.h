#ifndef __LOT_LOG_H__
#define __LOT_LOG_H__

namespace LOT{

    class Log {
    public:
        static void ServerLogInit(const char*); //设置路径

        static int LogWrite(int64_t, const char*, int length);

    private:
        Log() {}
        Log(const Log&) = delete;
        Log& operator=(const Log& ) = delete;

    private:
        static std::string logPath_;
        static const std::string serious_Log_;
    }

}

#endif // __LOT_LOG_H__

