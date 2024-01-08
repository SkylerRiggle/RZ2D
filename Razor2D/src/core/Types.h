#pragma once

#include <stdint.h>

using Entity = uint32_t;
using ComponentId = uint16_t;
using ArchetypeId = uint16_t;

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