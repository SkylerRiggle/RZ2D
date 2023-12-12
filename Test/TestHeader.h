#pragma once

#include <stdint.h>

static uint16_t s_counter = 0;

template <class T>
uint16_t GetID()
{
    static uint16_t s_id = s_counter++;
    return s_id;
}