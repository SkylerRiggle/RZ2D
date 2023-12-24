#pragma once

#include "ECSCoordinator.h"
#include "Archetype.h"

namespace RZ
{
    class RZ_API System
    {
    public:
        System(Archetype archetype);
        
        void RegisterEntity(const ECSCoordinator& coordinator, const EntityId entity);
        void UnRegisterEntity(const ECSCoordinator& coordinator, const EntityId entity);

        void UpdateSystem();
        virtual void Update(/** MISSING ARCHETYPE DATA HERE (Collection of Component IDs) */) = 0;
    };
}