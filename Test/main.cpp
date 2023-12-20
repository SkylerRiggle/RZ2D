/**
 *******************************************************
 *                                                     *
 *          Razor2D Engine Testing Application         *
 *                                                     *
 *******************************************************
*/

#define RZ_DEBUG

#include <iostream>
#include "../Razor2D/Razor2D.h"

int main(int argc, char* argv[])
{
    std::cout << "\nRunning Test Application...\n";

    RZ::ECSCoordinator* coordinator = new RZ::ECSCoordinator();

    // Entity Creating / Deletion Test ////////////////////////////////////////

    EntityId entityA = coordinator->CreateEntity();
    coordinator->DestroyEntity(entityA);
    EntityId entityB = coordinator->CreateEntity();
    coordinator->DestroyEntity(entityB);

    ASSERT (entityA == entityB, "Error With Entity ID Stack!");

    entityA = coordinator->CreateEntity();
    entityB = coordinator->CreateEntity();

    ASSERT (entityA != entityB, "Entity IDs Are Not Unique!");

    // Single Component Life-Cycle Test ///////////////////////////////////////

    coordinator->AddComponent<int>(entityA, 10);
    ASSERT(coordinator->HasComponent<int>(entityA), "Error Creating Entity Component!");
    ASSERT(coordinator->GetComponent<int>(entityA) == 10, "Error Retrieving Entity Component!");
    coordinator->RemoveComponent<int>(entityA);
    ASSERT(!coordinator->HasComponent<int>(entityA), "Error Removing Entity Component!");

    // Shared Component Life-Cycle Test ///////////////////////////////////////

    coordinator->AddComponent<int>(entityA, 5);
    ASSERT(coordinator->HasComponent<int>(entityA), "Error Creating Shared Entity Component!");
    coordinator->ShareComponent<int>(entityA, entityB);
    ASSERT(coordinator->HasComponent<int>(entityB), "Error Sharing Entity Component!");
    coordinator->GetComponent<int>(entityB) = 7;
    ASSERT(coordinator->GetComponent<int>(entityA) == 7, "Components Are Not Truly Shared!");
    coordinator->RemoveComponent<int>(entityA);
    ASSERT(coordinator->HasComponent<int>(entityB), "Deletion of Entity A's Component Propogated to Entity B!");
    
    coordinator->DestroyEntity(entityA);
    coordinator->DestroyEntity(entityB);
    delete coordinator;

    // Debug Logging Test /////////////////////////////////////////////////////

    LOG("Logging Statement Works!");
    WARN("Warning Statement Works!");
    ASSERT(false, "Assert Statement Works!\nTests Completed Successfully!\n");

    #ifndef RZ_DEBUG
    std::cout << "Tests Completed Successfully!\n\n";
    #endif

    return 0;
}