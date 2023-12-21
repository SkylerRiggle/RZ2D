#pragma once

#include "ECSCoordinator.h"

namespace RZ
{
    class RZ_API System
    {
    public:
        void RegisterEntity(const ECSCoordinator& coordinator, const EntityId entity);
        void UnRegisterEntity(const ECSCoordinator& coordinator, const EntityId entity);

        void UpdateSystem();
        virtual void Update() = 0;
    };
}