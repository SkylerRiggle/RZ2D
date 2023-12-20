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

    constexpr EntityId POS_NUL = MAX_ENTITIES + 1;

    template <typename T>
    class ComponentArray : public IComponentArray
    {
    public:
        ComponentArray()
        {
            for (size_t idx = 0; idx < MAX_ENTITIES; idx++)
            {
                m_entityToIndex[idx] = POS_NUL;
            }
        }

        void EntityDestroyed(EntityId entity) override
        {
            if (this->HasComponent(entity))
            {
                this->RemoveComponent(entity);
            }
        }

        void AddComponent(EntityId entity, T componentData)
        {
            m_entityToIndex[entity] = m_size;
            m_components[m_size] = componentData;
            m_size++;
        }

        void ShareComponent(EntityId originalEntity, EntityId newEntity)
        {

        }

        void RemoveComponent(EntityId entity)
        {

        }

        bool HasComponent(EntityId entity)
        {
            return m_entityToIndex[entity] != POS_NUL;
        }

        T& GetComponent(EntityId entity)
        {
            return m_components[m_entityToIndex[entity]];
        }

    private:
        size_t m_entityToIndex[MAX_ENTITIES];
        T m_components[MAX_ENTITIES];
        size_t m_size = 0;
    };
}