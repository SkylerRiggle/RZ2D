#pragma once

#include "EntityManager.h"
#include "ComponentManager.h"

namespace RZ
{
    class ECSCoordinator
    {
    public:
        ECSCoordinator();
        ~ECSCoordinator();

        // ENTITY METHODS /////////////////////////////////////////////////////

        EntityId CreateEntity();
        void DestroyEntity(EntityId entity);
        void EnableEntity(EntityId entity);
        void DisableEntity(EntityId entity);

        // COMPONENT METHODS //////////////////////////////////////////////////

        template <typename T>
        void AddComponent(EntityId entity, T componentData)
        {
            m_componentManager->AddComponent<T>(entity, componentData);
        }

        template <typename T>
        void ShareComponent(EntityId originalEntity, EntityId newEntity)
        {
            m_componentManager->ShareComponent<T>(originalEntity, newEntity);
        }

        template <typename T>
        void RemoveComponent(EntityId entity)
        {
            m_componentManager->RemoveComponent<T>(entity);
        }

        template <typename T>
        bool HasComponent(EntityId entity)
        {
            return m_componentManager->HasComponent<T>(entity);
        }

        template <typename T>
        T& GetComponent(EntityId entity)
        {
            return m_componentManager->GetComponent<T>(entity);
        }

    private:
        EntityManager* m_entityManager;
        ComponentManager* m_componentManager;
    };
}