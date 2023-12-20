#pragma once

#include "../core/Types.h"
#include "../debug/Logging.h"

namespace RZ
{
    class IComponentArray
    {
    public:
        virtual ~IComponentArray() = default;
        virtual void EntityDestroyed(EntityId entity) = 0;
    };

    template <typename T>
    class ComponentArray : public IComponentArray
    {
    public:
        ComponentArray()
        {
            for (size_t idx = 0; idx < MAX_ENTITIES; idx++)
            {
                m_entityToIndex[idx] = NULL_ENTITY;
            }
        }

        inline void EntityDestroyed(EntityId entity) override
        {
            if (this->HasComponent(entity))
            {
                this->RemoveComponent(entity);
            }
        }

        inline void AddComponent(EntityId entity, T componentData)
        {
            m_entityToIndex[entity] = m_size;
            m_components[m_size] = componentData;
            m_componentUses[m_size] = 1;
            m_size++;
        }

        inline void ShareComponent(EntityId originalEntity, EntityId newEntity)
        {
            size_t shareIdx = m_entityToIndex[originalEntity];
            m_entityToIndex[newEntity] = shareIdx;
            m_componentUses[shareIdx]++;
        }

        inline void RemoveComponent(EntityId entity)
        {
            size_t rmvIdx = m_entityToIndex[entity];
            m_entityToIndex[entity] = NULL_ENTITY;
            m_componentUses[rmvIdx]--;
            if (m_componentUses[rmvIdx] > 0) { return; }

            // TODO - Compact Component Data Array
        }

        inline bool HasComponent(EntityId entity)
        {
            return m_entityToIndex[entity] != NULL_ENTITY;
        }

        inline T& GetComponent(EntityId entity)
        {
            return m_components[m_entityToIndex[entity]];
        }

    private:
        size_t m_entityToIndex[MAX_ENTITIES];
        size_t m_componentUses[MAX_ENTITIES];
        T m_components[MAX_ENTITIES];
        size_t m_size = 0;
    };
}