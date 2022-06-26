#pragma once

using GetNumber_t    = long double(*)(const char*);
using GetOperation_t = char(*)(const char*);
using Calculate_t    = void(*)(void*, void*);

extern "C"
{
    void calculateWithConsole(void* pGetNumberFunc, void* pGetOperationFunc);
    char getUserOperation(const char* message);
    long double getUserNumber(const char* message);
}
