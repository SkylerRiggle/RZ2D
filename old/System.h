#pragma once

#include "ECSCoordinator.h"

namespace RZ
{
    class RZ_API System
    {
    public:
        System(Archetype archetype);
        
        void RegisterEntity(const ECSCoordinator& coordinator, const EntityId entity);
        void UnRegisterEntity(const ECSCoordinator& coordinator, const EntityId entity);

        void UpdateSystem();
        virtual void Update(EntityId entity) = 0;

    private:
        EntityId m_entities[MAX_ENTITIES];
        size_t m_numEntities;
    };
}