#pragma once

#ifdef RZ_DEBUG

#include <iostream>
#include <ctime>
#include <signal.h>

#ifndef RZ_DEBUG_ERROR_CALLBACK
    #define RZ_DEBUG_ERROR_CALLBACK()
#endif

namespace RZ
{
    static void LogStatement(const char* tag, const char* msg)
    {
        time_t epcoh = time(0);
        tm* curTime = localtime(&epcoh);

        std::cout << (1 + curTime->tm_mon) << '/'
            << curTime->tm_mday << '/'
            << (1900 + curTime->tm_year)
            << ' '
            << curTime->tm_hour << ':'
            << curTime->tm_min << ':'
            << curTime->tm_sec
            << " - ["
        << tag << "]: " << msg << '\n';
    }
}

#define LOG(msg) RZ::LogStatement("\033[1;34mINFO\033[0m", msg);
#define SUCCESS(msg) RZ::LogStatement("\033[1;32mSUCCESS\033[0m", msg);
#define WARN(msg) RZ::LogStatement("\033[1;33mWARN\033[0m", msg);

#define ASSERT(exp, msg) if (!(exp)) { \
    RZ::LogStatement("\033[1;31mERROR\033[0m", msg); \
    RZ_DEBUG_ERROR_CALLBACK(); \
    raise(SIGABRT); \
}

#else

#define LOG(msg)
#define SUCCESS(msg)
#define WARN(msg)
#define ASSERT(exp, msg)

#endif