#pragma once

#include "../core/Core.h"
#include "../core/Types.h"
#include "../debug/Logging.h"
#include <bitset>
#include <initializer_list>

namespace RZ
{
    class RZ_API EntitySystem
    {
    public:
        EntitySystem();

        // Entity Methods /////////////////////////////////////////////////////

        const EntityId CreateEntity();
        void DestroyEntity(const EntityId entity);

        bool IsEnabled(const EntityId entity);
        void SetEnabled(const EntityId entity, const bool enabled);

        // Archetype Methods //////////////////////////////////////////////////

        const Archetype CreateArchetype(
            std::initializer_list<ComponentId> components, 
            const size_t capacity = MAX_ENTITIES
        );

        void AttachArchetype(const EntityId entity, const Archetype archetype);
        void DetachArchetype(const EntityId entity, const Archetype archetype);

    private:
        EntityId m_entityPool[MAX_ENTITIES];
        size_t m_topIndex = MAX_ENTITIES;
        std::bitset<MAX_ENTITIES> m_statuses;
    };
}