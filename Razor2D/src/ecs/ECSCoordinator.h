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

    private:
        EntityManager* m_entityManager;
        ComponentManager* m_componentManager;
    };
}