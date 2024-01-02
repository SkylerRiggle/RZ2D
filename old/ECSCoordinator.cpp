#include "ECSCoordinator.h"

using namespace RZ;

ECSCoordinator::ECSCoordinator()
{
    m_entityManager = new EntityManager();
    m_componentManager = new ComponentManager();
}

ECSCoordinator::~ECSCoordinator()
{
    delete m_entityManager;
    delete m_componentManager;
}

const EntityId ECSCoordinator::CreateEntity()
{
    return m_entityManager->CreateEntity();
}

void ECSCoordinator::DestroyEntity(const EntityId entity)
{
    m_entityManager->DestroyEntity(entity);
    m_componentManager->DestroyEntity(entity);
}

void ECSCoordinator::SetEnabled(const EntityId entity, const bool enabled))
{

}