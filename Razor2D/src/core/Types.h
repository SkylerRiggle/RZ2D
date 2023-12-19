#pragma once

#include <stdint.h>

#ifndef MAX_ENTITIES
    #define MAX_ENTITIES 1000
#endif

#ifndef MAX_COMPONENT_TYPES
    #define MAX_COMPONENT_TYPES 48
#endif

using EntityId = uint32_t;
using ComponentId = uint8_t;