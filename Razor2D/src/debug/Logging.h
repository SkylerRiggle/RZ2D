#pragma once

#ifdef RZ_DEBUG

#include <iostream>
#include <signal.h>

#define BLUE "\033[1;34m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define CLEAR "\033[0m"

#define LOG(msg) std::cout << '[' << BLUE << "INFO" CLEAR << "]: " << msg << '\n';
#define SUCCESS(msg) std::cout << '[' << GREEN << "SUCCESS" CLEAR << "]: " << msg << '\n';
#define WARN(msg) std::cout << '[' << YELLOW << "WARN" CLEAR << "]: " << msg << '\n';

#define ASSERT(exp, msg) if (!(exp)) { \
    std::cout << '[' << RED << "ERROR" CLEAR << "]: " << msg << '\n'; \
    raise(SIGABRT); \
}

#else

#define LOG(msg)
#define WARN(msg)
#define ASSERT(exp, msg)

#endif