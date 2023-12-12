/**
 *******************************************************
 *                                                     *
 *          Razor2D Engine Testing Application         *
 *                                                     *
 *******************************************************
*/

#include <stdio.h>
#include "TestHeader.h"
#include "../Razor2D/Razor2D.h"

int main(int argc, char* argv[])
{
    printf("\nRunning Test Application...\n");
    printf("ID int 1: %d\n", GetID<int>());
    printf("ID int 2: %d\n", GetID<int>());
    printf("ID float: %d\n", GetID<float>());
    printf("Tests Completed Successfully!\n\n");
    return 0;
}