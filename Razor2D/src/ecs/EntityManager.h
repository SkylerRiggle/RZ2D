#pragma once

#include "../core/Types.h"
#include "../core/Core.h"
#include "../debug/Logging.h"

namespace RZ
{
    class RZ_API EntityManager
    {
    public:
        EntityManager();
        ~EntityManager();

        EntityId CreateEntity();
        void DestroyEntity(EntityId entity);

    private:
        EntityId* m_entityPool;
        int m_topIndex;
    };
}