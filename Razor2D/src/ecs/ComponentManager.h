#pragma once

#include "../core/Types.h"

namespace RZ
{
    class ComponentManager
    {
    public:
        void DestroyEntity(EntityId entity);

        template <typename T>
        void AddComponent(EntityId entity, T componentData);

        template <typename T>
        void ShareComponent(EntityId originalEntity, EntityId newEntity);

        template <typename T>
        void RemoveComponent(EntityId entity);

        template <typename T>
        bool HasComponent(EntityId entity);

        template <typename T>
        T& GetComponent(EntityId entity);
    };
}