#pragma once

#include "../core/Core.h"
#include "../debug/Logging.h"
#include "ComponentManager.h"
#include <bitset>

namespace RZ
{
    class RZ_API EntitySystem
    {
    public:
        EntitySystem();
        ~EntitySystem();

        const EntityId CreateEntity();
        void DestroyEntity(const EntityId entity);

        bool IsEnabled(const EntityId entity);
        void SetEnabled(const EntityId entity, const bool enabled);

        template <typename T>
        inline void AddComponent(const EntityId entity)
        {
            m_componentManager->AddComponent<T>(entity, {});
        }

        template <typename T>
        inline void AddComponent(const EntityId entity, const T componentData)
        {
            m_componentManager->AddComponent<T>(entity, componentData);
        }

        template <typename T>
        inline void RemoveComponent(const EntityId entity)
        {
            m_componentManager->RemoveComponent<T>(entity);
        }

        template <typename T>
        inline T& GetComponent(const EntityId entity)
        {
            return m_componentManager->GetComponent<T>(entity);
        }

        template <typename T>
        inline bool HasComponent(const EntityId entity)
        {
            return m_componentManager->HasComponent<T>(entity);
        }

    private:
        ComponentManager* m_componentManager;

        EntityId m_entityPool[MAX_ENTITIES];
        size_t m_topIndex = MAX_ENTITIES;
        std::bitset<MAX_ENTITIES> m_statuses;
    };
}