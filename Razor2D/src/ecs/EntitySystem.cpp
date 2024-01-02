#include "EntitySystem.h"

using namespace RZ;

EntitySystem::EntitySystem()
{
    for (EntityId newEntity = 0; newEntity < MAX_ENTITIES; newEntity++)
    {
        m_entityPool[newEntity] = newEntity;
        m_statuses[newEntity] = false;
    }
}

EntitySystem::~EntitySystem()
{
    delete[] m_entityPool;
}

const EntityId EntitySystem::CreateEntity()
{
    ASSERT(m_topIndex > 0, "Creating More Entities Than Allowed!");

    m_topIndex--;
    const EntityId entity = m_entityPool[m_topIndex];
    m_statuses[entity] = true;
    return entity;
}

void EntitySystem::DestroyEntity(const EntityId entity)
{
    ASSERT(m_topIndex < MAX_ENTITIES && entity < MAX_ENTITIES, "Destroyed More Entities Than Created!");

    m_entityPool[m_topIndex] = entity;
    m_statuses[entity] = false;
    m_topIndex++;
}

bool EntitySystem::IsEnabled(const EntityId entity)
{
    ASSERT(entity < MAX_ENTITIES, "Attempting to Access Out-Of-Bounds Entity!");
    return m_statuses[entity];
}

void EntitySystem::SetEnabled(const EntityId entity, const bool enabled)
{
    ASSERT(entity < MAX_ENTITIES, "Attempting to Enable/Disable Out-Of-Bounds Entity!");
    m_statuses[entity] = enabled;
}