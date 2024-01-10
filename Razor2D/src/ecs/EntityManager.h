#pragma once

#include "../core/Types.h"

namespace RZ {
    class EntityManager {
    public:
        EntityManager();
        ~EntityManager();

        const EntityID CreateEntity();
        void DestroyEntity(const EntityID entity);
    };
}