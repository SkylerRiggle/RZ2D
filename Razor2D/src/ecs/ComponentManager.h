#pragma once

#include "ComponentArray.h"

namespace RZ
{
    /**
     * Ensures a unique and static id for each component type.
     * IDs may change between runs of the program.
     */
    static ComponentId s_componentCounter = 0;
    template <typename T>
    ComponentId GetComponentId()
    {
        ASSERT(s_componentCounter < 65534, "Maximum Number of Component Types Exceeded!");
        static ComponentId id = s_componentCounter++;
        return id;
    }

    class ComponentManager
    {
    public:
        ComponentManager();
        ~ComponentManager();

        void DestroyEntity(EntityId entity);

        template <typename T>
        void AddComponent(EntityId entity, T componentData)
        {
            ComponentArray<T>& arr = this->GetArray<T>();

            if (arr == nullptr)
            {
                arr = this->CreateArray<T>();
            }

            arr.AddComponent(entity, componentData);
        }

        template <typename T>
        void ShareComponent(EntityId originalEntity, EntityId newEntity)
        {
            ASSERT(this->HasComponent(originalEntity), "Original Entity has no Component to Share!");

            ComponentArray<T>& arr = this->GetArray<T>();
            arr.ShareComponent(originalEntity, newEntity);
        }

        template <typename T>
        void RemoveComponent(EntityId entity)
        {
            ASSERT(this->HasComponent<T>(entity), "Attempting to Remove Non-Existent Component From Entity!");

            ComponentArray<T>& arr = this->GetArray<T>();
            arr.RemoveComponent(entity);
        }

        template <typename T>
        bool HasComponent(EntityId entity)
        {
            ComponentArray<T>& arr = this->GetArray<T>();
            return (arr == nullptr) ? false : arr.HasComponent(entity);
        }

        template <typename T>
        T& GetComponent(EntityId entity)
        {
            ASSERT(this->HasComponent<T>(entity), "Attempting to Access Non-Existent Component From Entity!");

            ComponentArray<T>& arr = this->GetArray<T>();
            return arr.GetComponent(entity);
        }

    private:
        IComponentArray* m_arrays;
        size_t m_numArrays;

        template <typename T>
        ComponentArray<T>& CreateArray()
        {

        }

        template <typename T>
        ComponentArray<T>& GetArray()
        {

        }
    };
}