#pragma once

#include "../core/Types.h"
#include "../debug/Logging.h"

namespace RZ
{
    class IComponentArray
    {
    public:
        virtual ~IComponentArray() = default;
        virtual void RemoveComponent(EntityId entity) = 0;
        virtual bool HasComponent(EntityId entity) = 0;
    };

    template <typename T>
    class ComponentArray : public IComponentArray
    {
    };
}