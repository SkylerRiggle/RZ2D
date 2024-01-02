#pragma once

#include "../core/Types.h"
#include "../debug/Logging.h"

namespace RZ
{
    class EntityManager
    {
    public:
        EntityManager();
        ~EntityManager();

        const EntityId CreateEntity();
        void DestroyEntity(const EntityId entity);

    private:
        EntityId* m_entityPool;
        int m_topIndex;
    };
}