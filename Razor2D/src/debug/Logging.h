#ifndef RZ_LOGGING
#define RZ_LOGGING

#ifdef RZ_DEBUG

#include <iostream>
#include <iomanip>
#include <ctime>
#include <signal.h>

namespace RZ {
    class Logger {
    public:
        static void Log(const char* msg) {
            InternalLog(INFO_TAG, msg);
        }

        static void Success(const char* msg) {
            InternalLog(SUCCESS_TAG, msg);
        }

        static void Warning(const char* msg) {
            InternalLog(WARN_TAG, msg);
        }

        static void Error(const char* msg) {
            InternalLog(ERROR_TAG, msg);
        }

        static void AssertWarning(const bool exp, const char* msg) {
            if (exp) { return; }
            InternalLog(WARN_TAG, msg);
        }

        static void AssertError(const bool exp, const char* msg) {
            if (exp) { return; }
            InternalLog(ERROR_TAG, msg);
            raise(SIGABRT);
        }

    private:
        static const char* INFO_TAG;
        static const char* SUCCESS_TAG;
        static const char* WARN_TAG;
        static const char* ERROR_TAG;

        static inline void InternalLog(const char* tag, const char* msg) {
            time_t epoch = time(0);
            tm *curTime = localtime(&epoch);

            std::cout
                // Log Date
                << std::setw(2)
                << std:: setfill('0')
                << (1 + curTime->tm_mon) << '/'
                << std::setw(2)
                << std:: setfill('0')
                << curTime->tm_mday << '/'
                << (1900 + curTime->tm_year) << ' '

                // Log Time
                << std::setw(2)
                << std:: setfill('0')
                << curTime->tm_hour << ':'
                << std::setw(2)
                << std:: setfill('0')
                << curTime->tm_min << ':'
                << std::setw(2)
                << std:: setfill('0')
                << curTime->tm_sec << " - ["

                // Log Message
                << tag << "\033[0m]:"
                << msg
            << '\n';
        }
    };

    const char* Logger::INFO_TAG = "\033[1;34mINFO";
    const char *Logger::SUCCESS_TAG = "\033[1;32mSUCCESS";
    const char* Logger::WARN_TAG = "\033[1;33mWARN";
    const char* Logger::ERROR_TAG = "\033[1;31mERROR";
}

#define LOG(msg) RZ::Logger::Log(msg);
#define SUCCESS(msg) RZ::Logger::Success(msg);
#define WARN(msg) RZ::Logger::Warning(msg);
#define ERROR(msg) RZ::Logger::Error(msg);

#define ASSERT_WARN(exp, msg) RZ::Logger::AssertWarning(exp, msg);
#define ASSERT_ERROR(exp, msg) RZ::Logger::AssertError(exp, msg);

#else

#define LOG(msg)
#define SUCCESS(msg)
#define WARN(msg)
#define ERROR(msg)

#define ASSERT_WARN(exp, msg)
#define ASSERT_ERROR(exp, msg)

#endif

#endif