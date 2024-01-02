#pragma once

#include "../core/Types.h"
#include <initializer_list>

namespace RZ
{
    class ArchetypeStore
    {
    public:
        const Archetype CreateArchetype(
            std::initializer_list<ComponentId> components, 
            const size_t capacity
        );
    };
}