#pragma once

#include "../core/Core.h"
#include "../debug/Logging.h"
#include "ArchetypeStore.h"
#include "ComponentStore.h"
#include <bitset>

namespace RZ
{
    class RZ_API EntitySystem
    {
    public:
        EntitySystem();
        ~EntitySystem();

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
        ArchetypeStore* m_archetypeStore;
        ComponentStore* m_componentStore;

        EntityId m_entityPool[MAX_ENTITIES];
        size_t m_topIndex = MAX_ENTITIES;
        std::bitset<MAX_ENTITIES> m_statuses;
    };
}