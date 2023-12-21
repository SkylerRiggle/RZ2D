#pragma once

#include "../core/Types.h"
#include "../debug/Logging.h"

namespace RZ
{
    class IComponentArray
    {
    public:
        virtual ~IComponentArray() = default;
        virtual void EntityDestroyed(const EntityId entity) = 0;
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
                m_indexToEntity[idx] = NULL_ENTITY;
            }
        }

        inline void EntityDestroyed(const EntityId entity) override
        {
            if (this->HasComponent(entity))
            {
                this->RemoveComponent(entity);
            }
        }

        inline void AddComponent(const EntityId entity, T componentData)
        {
            m_entityToIndex[entity] = m_size;
            m_indexToEntity[m_size] = entity;
            m_components[m_size] = componentData;
            m_size++;
        }

        inline void RemoveComponent(const EntityId entity)
        {
            m_size--;
            size_t rmvIdx = m_entityToIndex[entity];
            m_components[rmvIdx] = m_components[m_size];

            EntityId lastEntity = m_indexToEntity[m_size];
            m_indexToEntity[rmvIdx] = lastEntity;
            m_indexToEntity[m_size] = NULL_ENTITY;

            m_entityToIndex[lastEntity] = rmvIdx;
            m_entityToIndex[entity] = NULL_ENTITY;
        }

        inline bool HasComponent(const EntityId entity)
        {
            return m_entityToIndex[entity] != NULL_ENTITY;
        }

        inline T& GetComponent(const EntityId entity)
        {
            return m_components[m_entityToIndex[entity]];
        }

    private:
        size_t m_entityToIndex[MAX_ENTITIES];
        EntityId m_indexToEntity[MAX_ENTITIES];
        T m_components[MAX_ENTITIES];
        size_t m_size = 0;
    };
}