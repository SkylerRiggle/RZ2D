#pragma once

#include "../core/Types.h"

namespace RZ
{
    struct ComponentArray
    {
        // TODO
    };

    class ComponentStore
    {
    public:
        void RegisterComponent(const ComponentId componentId);

        template <typename T>
        inline void AddComponent(const EntityId entity, T componentData = {})
        {
            // TODO
        }

        template <typename T>
        inline void RemoveComponent(const EntityId entity)
        {
            // TODO
        }

        template <typename T>
        inline bool HasComponent(const EntityId entity)
        {
            // TODO
            return false;
        }

        template <typename T>
        inline T& GetComponent(const EntityId entity)
        {
            // TODO
            return &{};
        }
    };
}