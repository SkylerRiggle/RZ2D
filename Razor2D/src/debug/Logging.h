#pragma once

#ifdef RZ_DEBUG

#include <iostream>
#include <ctime>
#include <signal.h>

#define BLUE "\033[1;34m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define CLEAR "\033[0m"

const char* GetTimeStamp()
{
    time_t now = time(0);
    return ctime(&now);
}

namespace RZ
{
    enum LogType {
        LOG = 0,
        SUCCESS = 1,
        WARN = 2,
        ERROR = 3
    };

    void LogStatement(LogType logType, const char* msg)
    {
        time_t epcoh = time(0);
        tm* curTime = localtime(&epcoh);
        std::cout << (1 + curTime->tm_mon) << '/' 
            << curTime->tm_mday << '/' 
            << (1900 + curTime->tm_year)
        << ' ';
        std::cout << (5 + curTime->tm_hour) << ':' 
            << (30 + curTime->tm_min) << ':' 
            << curTime->tm_sec << ':'
        << " - [";

        switch (logType)
        {
        case (LogType::LOG):
            std::cout << BLUE << "INFO";
            break;
        case (LogType::SUCCESS):
            std::cout << GREEN << "SUCCESS";
            break;
        case (LogType::WARN):
            std::cout << YELLOW << "WARN";
            break;
        case (LogType::ERROR):
            std::cout << RED << "ERROR";
            break;
        }

        std::cout << CLEAR << "]: " << msg << '\n';
    }
}

#define LOG(msg) LogStatement(RZ::LogType::LOG, msg);
#define SUCCESS(msg) LogStatement(RZ::LogType::SUCCESS, msg);
#define WARN(msg) LogStatement(RZ::LogType::WARN, msg);

#define ASSERT(exp, msg) if (!(exp)) { \
    LogStatement(RZ::LogType::ERROR, msg); \
    raise(SIGABRT); \
}

#else

#define LOG(msg)
#define WARN(msg)
#define ASSERT(exp, msg)

#endif