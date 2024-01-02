#pragma once

#include "../core/Core.h"
#include "EntityManager.h"
#include "ComponentManager.h"

namespace RZ
{
    class RZ_API ECSCoordinator
    {
    public:
        ECSCoordinator();
        ~ECSCoordinator();

        // ENTITY METHODS /////////////////////////////////////////////////////

        const EntityId CreateEntity();
        void DestroyEntity(const EntityId entity);
        void SetEnabled(const EntityId entity, const bool enabled);

        // COMPONENT METHODS //////////////////////////////////////////////////

        template <typename T>
        inline void AddComponent(const EntityId entity, T componentData) 
        { 
            m_componentManager->AddComponent<T>(entity, componentData); 
        }

        template <typename T>
        inline void RemoveComponent(const EntityId entity)
        {
            m_componentManager->RemoveComponent<T>(entity);
        }

        template <typename T>
        inline bool HasComponent(const EntityId entity)
        {
            return m_componentManager->HasComponent<T>(entity);
        }

        template <typename T>
        inline T& GetComponent(const EntityId entity)
        {
            return m_componentManager->GetComponent<T>(entity);
        }

    private:
        EntityManager* m_entityManager;
        ComponentManager* m_componentManager;
    };
}