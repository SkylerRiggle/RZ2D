#pragma once

#include "../core/Types.h"
#include "../debug/Logging.h"
#include <array>
#include <unordered_map>

namespace RZ
{
    static ComponentId s_componentCounter = 0;
    template <typename T>
    ComponentId GetComponentId()
    {
        ASSERT(s_componentCounter < 65534, "Maximum Number of Component Types Exceeded!");
        static ComponentId id = s_componentCounter++;
        return id;
    }

    class IComponentArray
    {
    public:
        virtual ~IComponentArray() = default;
        virtual void Remove(EntityId entity) = 0;
        virtual bool Has(EntityId entity) = 0;
    };

    template <typename T>
    class ComponentArray : public IComponentArray
    {
    public:
        void Add(EntityId entity, T componentData)
        {
            ASSERT(!this->Has(entity), "Attempting to Add Duplicate Component to Entity!");

            m_entityIndex[entity] = m_size;
            m_indexEntity[m_size] = entity;
            m_components[m_size] = componentData;
            m_size++;
        }

        void Remove(EntityId entity) override
        {
            ASSERT(this->Has(entity), "Attempting to Remove Non-Existant Component!");

            m_size--;
            const size_t removeIndex = m_entityIndex[entity];
            m_components[removeIndex] = m_components[m_size];

            const EntityId lastEntity = m_indexEntity[m_size];
            m_indexEntity[removeIndex] = lastEntity;
            m_entityIndex[lastEntity] = removeIndex;

            m_entityIndex.erase(entity);
            m_indexEntity.erase(m_size);
        }

        bool Has(EntityId entity) override
        {
            return m_entityIndex.find(entity) != m_entityIndex.end();
        }

        T& Get(EntityId entity)
        {
            ASSERT(this->Has(entity), "Attempting to Gather Non-Existant Component!");
            return m_components[m_entityIndex[entity]];
        }

    private:
        size_t m_size = 0;
        std::unordered_map<EntityId, size_t> m_entityIndex {};
        std::unordered_map<size_t, EntityId> m_indexEntity {};
        std::array<T, MAX_ENTITIES> m_components {};
    };

    class ComponentManager
    {
    public:
        template <typename T>
        void AddComponent(EntityId entity, T componentData)
        {
            // TODO
        }

        template <typename T>
        void RemoveComponent(EntityId entity)
        {
            // TODO
        }

        template <typename T>
        bool HasComponent(EntityId entity)
        {
            // TODO
            return false;
        }

        template <typename T>
        T& GetComponent(EntityId entity)
        {
            // TODO
            return nullptr;
        }

    private:
        std::unordered_map<ComponentId, IComponentArray> m_arrays {};
    };
}