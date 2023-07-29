#include <iostream>
#include <windows.h>
#include "../Calc/Calc.h"


int main()
{
    HMODULE dllModule = LoadLibraryA("Calc.dll");
    if (dllModule)
    {
        std::cout << "Dll loaded with address: 0x" << dllModule << '\n';

        auto procCalculate       = GetProcAddress(dllModule, (LPCSTR)0x1);
        auto procOperationReader = GetProcAddress(dllModule, (LPCSTR)0x2);
        auto procNumberReader    = GetProcAddress(dllModule, (LPCSTR)0x3);
        
        if (procCalculate && procOperationReader && procNumberReader)
        {
            Calculate_t calculator = reinterpret_cast<Calculate_t>(procCalculate);
            calculator(procNumberReader, procOperationReader);
        }
        
        FreeLibrary(dllModule);
    }
    else
    {
        std::cout << "Can`t open dll\n";
    }

    system("pause");
    return 0;
}