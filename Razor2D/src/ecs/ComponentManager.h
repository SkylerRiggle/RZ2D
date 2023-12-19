#pragma once

#include "ComponentArray.h"
#include "../debug/Logging.h"

namespace RZ
{
    /**
     * Ensures a unique and static id for each component type.
     * IDs may change between runs of the program.
     */
    static ComponentId s_componentCounter = 0;
    template <typename T>
    constexpr ComponentId GetComponentId()
    {
        ASSERT(s_componentCounter < MAX_COMPONENT_TYPES, "Maximum Number of Component Types Exceeded!");
        static ComponentId id = s_componentCounter++;
        return id;
    }

    class ComponentManager
    {
    public:
        ~ComponentManager();

        void DestroyEntity(EntityId entity);

        template <typename T>
        void AddComponent(EntityId entity, T componentData)
        {
            ASSERT(!this->HasComponent<T>(entity), "Attempting to Add Duplicate Component to Entity!");

            ComponentArray<T>* arr = this->GetArray<T>();

            if (arr == nullptr)
            {
                arr = this->CreateArray<T>();
            }

            arr->AddComponent(entity, componentData);
        }

        template <typename T>
        void ShareComponent(EntityId originalEntity, EntityId newEntity)
        {
            ASSERT(this->HasComponent(originalEntity), "Original Entity has no Component to Share!");

            ComponentArray<T>* arr = this->GetArray<T>();
            arr->ShareComponent(originalEntity, newEntity);
        }

        template <typename T>
        void RemoveComponent(EntityId entity)
        {
            ASSERT(this->HasComponent<T>(entity), "Attempting to Remove Non-Existent Component From Entity!");

            ComponentArray<T>* arr = this->GetArray<T>();
            arr->RemoveComponent(entity);
        }

        template <typename T>
        bool HasComponent(EntityId entity)
        {
            ComponentArray<T>* arr = this->GetArray<T>();
            return (arr == nullptr) ? false : arr->HasComponent(entity);
        }

        template <typename T>
        T& GetComponent(EntityId entity)
        {
            ASSERT(this->HasComponent<T>(entity), "Attempting to Access Non-Existent Component From Entity!");

            ComponentArray<T>* arr = this->GetArray<T>();
            return arr->GetComponent(entity);
        }

    private:
        IComponentArray* m_arrays[MAX_COMPONENT_TYPES];
        size_t m_numArrays = 0;

        template <typename T>
        ComponentArray<T>* CreateArray()
        {
            ComponentArray<T>* arr = new ComponentArray<T>();
            m_arrays[GetComponentId<T>() - 1] = arr;
            m_numArrays++;
            return arr;
        }

        template <typename T>
        ComponentArray<T>* GetArray()
        {
            return (ComponentArray<T>*)m_arrays[GetComponentId<T>() - 1];
        }
    };
}