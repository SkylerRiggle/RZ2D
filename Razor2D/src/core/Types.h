#pragma once

#include <stdint.h>

using EntityId = uint32_t;
using ComponentId = uint8_t;

constexpr EntityId NULL_ENTITY = EntityId(-1);

#ifndef MAX_ENTITIES
    #define MAX_ENTITIES 1000
#else 

#if (MAX_ENTITIES == 4294967295U)
    #define MAX_ENTITIES 4294967294U
#endif

#endif

namespace RZ
{
    static ComponentId s_componentCounter;
    template <typename T>
    static ComponentId GetComponentId()
    {
        static ComponentId id = s_componentCounter++;
        return id;
    }
}