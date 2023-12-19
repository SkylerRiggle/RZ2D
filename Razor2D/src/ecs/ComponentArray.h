#pragma once

#include "../core/Types.h"

namespace RZ
{
    /**
     * Defines a null value within a component array as the 
     * largest out-of-bounds value possible plus 1.
    */
    constexpr EntityId POS_NULL = (MAX_COMPONENT_TYPES > MAX_ENTITIES) ? MAX_COMPONENT_TYPES + 1 : MAX_ENTITIES + 1;

    struct IComponentArray
    {
    public:
        virtual ~IComponentArray() = default;
        virtual void RemoveComponent(EntityId entity) = 0;
    };

    template <typename T>
    struct MultiUseComponent
    {
    public:
        size_t numUses;
        T componentData;
    };

    template <typename T>
    struct ComponentArray : public IComponentArray
    {
    public:
        ComponentArray()
        {
            // Initialize everything to null
            for (size_t idx = 0; idx < MAX_ENTITIES; idx++)
            {
                m_entityToIndex[idx] = POS_NULL;
                m_arr[idx] = { 0, {} };
            }
        }

        ~ComponentArray()
        {
            delete [] m_entityToIndex;
            delete [] m_arr;
        }

        void AddComponent(EntityId entity, T componentData)
        {
            m_arr[m_size] = { 1, componentData };
            m_entityToIndex[entity] = m_size;
            m_size++;
        }

        void ShareComponent(EntityId originalEntity, EntityId newEntity)
        {
            size_t idx = m_entityToIndex[originalEntity];
            m_entityToIndex[newEntity] = idx;
            MultiUseComponent<T> data = m_arr[idx];
            data.numUses++;
        }

        void RemoveComponent(EntityId entity) override
        {
            size_t rmvIdx = m_entityToIndex[entity];
            m_entityToIndex[entity] = POS_NULL;

            MultiUseComponent<T> data = m_arr[rmvIdx];
            data.numUses--;
            if (data.numUses > 0) { return; }

            m_size--;
            m_arr[rmvIdx] = m_arr[m_size];

            // TODO Remap Entitys
        }

        bool HasComponent(EntityId entity)
        {
            return m_entityToIndex[entity] != POS_NULL;
        }

        T& GetComponent(EntityId entity)
        {
            MultiUseComponent<T> data = m_arr[m_entityToIndex[entity]];
            return &(data.componentData);
        }

    private:
        size_t m_entityToIndex[MAX_ENTITIES];
        MultiUseComponent<T> m_arr[MAX_ENTITIES];
        size_t m_size = 0;
    };
}