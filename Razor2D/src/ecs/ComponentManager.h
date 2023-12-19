#pragma once

#include "ComponentArray.h"
#include <unordered_map>

namespace RZ
{
    static ComponentId s_componentCounter;
    template <typename T>
    static ComponentId GetComponentId()
    {
        static ComponentId id = s_componentCounter++;
        return id;
    }

    class ComponentManager
    {
    public:
        ~ComponentManager();

        void DestroyEntity(EntityId entity);

        template <typename T>
        void AddComponent(EntityId entity, T componentData)
        {

        }

        template <typename T>
        void ShareComponent(EntityId originalEntity, EntityId newEntity)
        {

        }

        template <typename T>
        void RemoveComponent(EntityId entity)
        {

        }

        template <typename T>
        bool HasComponent(EntityId entity)
        {
            return false;
        }

        template <typename T>
        T& GetComponent(EntityId entity)
        {
            return nullptr;
        }

    private:
        std::unordered_map<ComponentId, IComponentArray*> m_arrays {};
    };
}