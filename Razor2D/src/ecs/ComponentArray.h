#pragma once

#include "../core/Types.h"
#include "../debug/Logging.h"

namespace RZ
{
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
        size_t m_numUses;
        T m_componentData;
    };

    template <typename T>
    struct ComponentArray : public IComponentArray
    {
    public:
        ComponentArray();
        ~ComponentArray();

        void AddComponent(EntityId entity, T componentData)
        {

        }

        void ShareComponent(EntityId originalEntity, EntityId newEntity)
        {
            
        }

        void RemoveComponent(EntityId entity) override
        {
            
        }

        bool HasComponent(EntityId entity)
        {
            
        }

        T& GetComponent(EntityId entity)
        {
            
        }

    private:
        EntityId* m_entityToIndex;
        size_t* m_indexToEntity;
        MultiUseComponent<T>* m_arr;
    };
}