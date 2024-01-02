#pragma once

#include "../core/Core.h"
#include "../core/Types.h"
#include "../debug/Logging.h"
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

    private:
        EntityId m_entityPool[MAX_ENTITIES];
        size_t m_topIndex = MAX_ENTITIES;
        std::bitset<MAX_ENTITIES> m_statuses;
    };
}