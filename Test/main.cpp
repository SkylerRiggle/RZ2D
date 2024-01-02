/**
 *******************************************************
 *                                                     *
 *          Razor2D Engine Testing Application         *
 *                                                     *
 *******************************************************
*/

#define RZ_DEBUG

#include "../Razor2D/Razor2D.h"

struct Stats {
    uint8_t health;
    uint8_t defence;
};

struct Position {
    float x;
    float y;
};

struct Input {
    float x;
    float y;
};

int main(int argc, char* argv[])
{
    std::cout << '\n';
    LOG("Running Razor2D Engine Tests...");

    RZ::EntitySystem* ecs = new RZ::EntitySystem();

    const EntityId entityA = ecs->CreateEntity();
    const EntityId entityB = ecs->CreateEntity();
    const EntityId entityC = ecs->CreateEntity();

    const Archetype healthArch = ecs->CreateArchetype({
        RZ::GetComponentId<Stats>()
    }, 1);
    const Archetype positionArch = ecs->CreateArchetype({
        RZ::GetComponentId<Position>()
    }, 2);
    const Archetype inputArch = ecs->CreateArchetype({
        RZ::GetComponentId<Input>()
    });

    ecs->AttachArchetype(entityA, inputArch);

    ecs->AttachArchetype(entityA, healthArch);
    ecs->AttachArchetype(entityB, healthArch);

    ecs->AttachArchetype(entityA, positionArch);
    ecs->AttachArchetype(entityB, positionArch);
    ecs->AttachArchetype(entityC, positionArch);

    ecs->DestroyEntity(entityA);
    ecs->DestroyEntity(entityB);
    ecs->DestroyEntity(entityC);

    delete ecs;

    SUCCESS("All Tests Passed!\n");

    return 0;
}