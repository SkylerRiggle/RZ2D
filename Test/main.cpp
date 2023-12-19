/**
 *******************************************************
 *                                                     *
 *          Razor2D Engine Testing Application         *
 *                                                     *
 *******************************************************
*/

#include <iostream>
#include "../Razor2D/Razor2D.h"

int main(int argc, char* argv[])
{
    std::cout << "\nRunning Test Application...\n";

    RZ::ECSCoordinator* coordinator = new RZ::ECSCoordinator();

    EntityId entityA = coordinator->CreateEntity();
    coordinator->DestroyEntity(entityA);
    EntityId entityB = coordinator->CreateEntity();

    std::cout << entityA << " " << entityB << '\n';

    delete coordinator;

    std::cout << "Tests Completed Successfully!\n\n";
    return 0;
}