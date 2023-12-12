/**
 *******************************************************
 *                                                     *
 *          Razor2D Engine Testing Application         *
 *                                                     *
 *******************************************************
*/

#include <stdio.h>
#include "../Razor2D/Razor2D.h"

int main(int argc, char* argv[])
{
    printf("\nRunning Test Application...\n");

    RZ::EntityManager* manager = new RZ::EntityManager();

    int i = 0;
    EntityId *arr = new EntityId[MAX_ENTITIES];
    for (; i < MAX_ENTITIES; i++)
    {
        arr[i] = manager->CreateEntity();
    }

    i--;
    for (; i > -1; i--)
    {
        manager->DestroyEntity(arr[i]);
    }

    delete arr;

    while (true);

    delete manager;

    printf("Tests Completed Successfully!\n\n");
    return 0;
}