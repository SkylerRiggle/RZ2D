/**
 *******************************************************
 *                                                     *
 *          Razor2D Engine Testing Application         *
 *                                                     *
 *******************************************************
*/

#define RZ_DEBUG

#include "../Razor2D/Razor2D.h"

// Initializing New Systems ///////////////////////////////////////////////////
class TestSystem : public RZ::System
{
public:
    void Update() override
    {
        // Do cool stuff here
    }
};

int main(int argc, char* argv[])
{
    std::cout << '\n';
    LOG("Running Razor2D Engine Tests...");

    RZ::ECSCoordinator* coordinator = new RZ::ECSCoordinator();

    // Entity Creating / Deletion Tests ///////////////////////////////////////

    EntityId entityA = coordinator->CreateEntity();
    coordinator->DestroyEntity(entityA);
    EntityId entityB = coordinator->CreateEntity();
    coordinator->DestroyEntity(entityB);

    ASSERT(entityA == entityB, "Error With Entity ID Stack!");

    entityA = coordinator->CreateEntity();
    entityB = coordinator->CreateEntity();

    ASSERT(entityA != entityB, "Entity IDs Are Not Unique!");

    SUCCESS("Entity Creation / Deletion Tests Passed!");

    // Single Component Life-Cycle Tests //////////////////////////////////////

    const int SOME_DATA = 10;

    coordinator->AddComponent<int>(entityA, SOME_DATA);
    ASSERT(coordinator->HasComponent<int>(entityA), "Error Creating Entity Component!");
    ASSERT(coordinator->GetComponent<int>(entityA) == SOME_DATA, "Error Retrieving Entity Component!");
    coordinator->GetComponent<int>(entityA) += SOME_DATA;
    ASSERT(coordinator->GetComponent<int>(entityA) == SOME_DATA + SOME_DATA, "Error Updating Component Data!");
    coordinator->RemoveComponent<int>(entityA);
    ASSERT(!coordinator->HasComponent<int>(entityA), "Error Removing Entity Component!");

    SUCCESS("Single Component Life-Cycle Tests Passed!");

    // System Tests ///////////////////////////////////////////////////////////

    // TODO Write Base System Test

    // Cleanup ////////////////////////////////////////////////////////////////
    
    coordinator->DestroyEntity(entityA);
    coordinator->DestroyEntity(entityB);
    delete coordinator;

    SUCCESS("All Tests Passed!\n");

    return 0;
}