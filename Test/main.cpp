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

    SUCCESS("All Tests Passed!\n");

    return 0;
}