#pragma once

#ifdef RZ_DEBUG

#include <iostream>

#define LOG(msg)
#define WARN(msg)
#define ASSERT(exp, msg)

#else

#define LOG(msg)
#define WARN(msg)
#define ASSERT(exp, msg)

#endif