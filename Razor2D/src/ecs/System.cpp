#include "System.h"

using namespace RZ;

System::System(Archetype archetype)
{
    
}

void System::RegisterEntity(const ECSCoordinator& coordinator, const EntityId entity)
{

}

void System::UnRegisterEntity(const ECSCoordinator& coordinator, const EntityId entity)
{

}

void System::UpdateSystem()
{
    for (size_t idx = 0; idx < m_numEntities; idx++)
    {
        this->Update(m_entities[idx]);
    }
}