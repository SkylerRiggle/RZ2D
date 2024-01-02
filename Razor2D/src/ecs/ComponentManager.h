#pragma once

#include "../core/Types.h"

namespace RZ
{
    class ComponentManager
    {
    public:
        template <typename T>
        inline void AddComponent(const EntityId entity, const T componentData)
        {
            // TODO
        }

        template <typename T>
        inline void RemoveComponent(const EntityId entity)
        {
            // TODO
        }

        template <typename T>
        inline T& GetComponent(const EntityId entity)
        {
            // TODO
        }

        template <typename T>
        inline bool HasComponent(const EntityId entity)
        {
            // TODO
        }
    };
}