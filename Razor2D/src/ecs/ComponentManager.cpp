#include "ComponentManager.h"

using namespace RZ;

ComponentManager::~ComponentManager()
{
    int idx = m_numArrays - 1;
    while (idx > -1)
    {
        delete m_arrays[idx];
        idx--;
    }
    delete [] m_arrays;
}

void ComponentManager::DestroyEntity(EntityId entity)
{
    for (IComponentArray* arr : m_arrays)
    {
        arr->RemoveComponent(entity);
    }
}