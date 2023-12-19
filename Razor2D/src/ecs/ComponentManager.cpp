#include "ComponentManager.h"

using namespace RZ;

ComponentManager::~ComponentManager()
{
    for (const std::pair<const ComponentId, IComponentArray*> pair : m_arrays)
    {
        delete pair.second;
    }
}

void ComponentManager::DestroyEntity(EntityId entity)
{
    for (const std::pair<const ComponentId, IComponentArray*> pair : m_arrays)
    {
        // TODO Remove Entity's Components
    }
}