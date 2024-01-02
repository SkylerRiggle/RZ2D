#include "EntityManager.h"

using namespace RZ;

EntityManager::EntityManager()
{
    m_entityPool = new EntityId[MAX_ENTITIES];
    m_topIndex = MAX_ENTITIES - 1;

    for (EntityId newEntity = 0; newEntity < MAX_ENTITIES; newEntity++)
    {
        m_entityPool[newEntity] = newEntity;
    }
}

EntityManager::~EntityManager()
{
    delete [] m_entityPool;
}

const EntityId EntityManager::CreateEntity()
{
    ASSERT(m_topIndex > -1, "Creating More Entities Than Allowed!");

    const EntityId entity = m_entityPool[m_topIndex];
    m_topIndex--;
    return entity;
}

void EntityManager::DestroyEntity(const EntityId entity)
{
    ASSERT(m_topIndex + 2 > MAX_ENTITIES, "Destroyed More Entities Than Created!");

    m_topIndex++;
    m_entityPool[m_topIndex] = entity;
}