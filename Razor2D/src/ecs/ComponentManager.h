#pragma once

#include "ComponentArray.h"
#include "../debug/Logging.h"
#include <unordered_map>

namespace RZ
{
    class ComponentManager
    {
    public:
        ~ComponentManager();
        void DestroyEntity(const EntityId entity);

        template <typename T>
        inline void AddComponent(const EntityId entity, T componentData)
        {
            ComponentArray<T>* arr = this->HasArray<T>()
            ? this->GetArray<T>()
            : this->CreateArray<T>();

            ASSERT(!arr->HasComponent(entity), "Cannot Add Duplicate Component Type to Entity!");

            arr->AddComponent(entity, componentData);
        }

        template <typename T>
        inline void RemoveComponent(const EntityId entity)
        {
            ASSERT(this->HasComponent<T>(entity), "Attempting to Remove Non-Existent Component!");
            ComponentArray<T>* arr = this->GetArray<T>();
            arr->RemoveComponent(entity);
        }

        template <typename T>
        inline bool HasComponent(const EntityId entity)
        {
            if (!this->HasArray<T>()) { return false; }
            ComponentArray<T>* arr = this->GetArray<T>();
            return arr->HasComponent(entity);
        }

        template <typename T>
        inline T& GetComponent(const EntityId entity)
        {
            ASSERT(this->HasComponent<T>(entity), "Attempting to Access Non-Existent Component!");
            ComponentArray<T>* arr = this->GetArray<T>();
            return arr->GetComponent(entity);
        }

    private:
        std::unordered_map<ComponentId, IComponentArray*> m_arrays {};

        template <typename T>
        inline bool HasArray()
        {
            return m_arrays.find(GetComponentId<T>()) != m_arrays.end();
        }

        template <typename T>
        inline ComponentArray<T>* GetArray()
        {
            return (ComponentArray<T>*)m_arrays[GetComponentId<T>()];
        }

        template <typename T>
        inline ComponentArray<T>* CreateArray()
        {
            ComponentArray<T>* arr = new ComponentArray<T>();
            m_arrays[GetComponentId<T>()] = arr;
            return arr;
        }
    };
}