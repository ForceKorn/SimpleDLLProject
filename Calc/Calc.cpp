#include "pch.h"
#include "Calc.h"

inline static constexpr char addOperation = '+';
inline static constexpr char subOperation = '-';
inline static constexpr char mulOperation = '*';
inline static constexpr char divOperation = '/';
inline static constexpr char calcOperation = '=';

inline const char* MSG_INPUT_FIRST_NUMBER = "Enter first number: ";
inline const char* MSG_INPUT_OPERATOR = "Enter your next operation: select from(+-*/=): ";
inline const char* MSG_INPUT_NEXT_NUMBER = "Enter next number: ";

inline const char* MSG_ERROR_DIVIDE_BY_ZERO = "Can`t divide by zero. Opertaion ignored. Try again!\n";
inline const char* MSG_ERROR_WRONG_OPERTAOR = "Wrong operation input. Please Try again!\n";

extern "C"
{
    void calculateWithConsole(void* pGetUserInputNumber, void* pGetUserInputOperation)
    {
        GetNumber_t    getUserInputNumber    = reinterpret_cast<GetNumber_t>(pGetUserInputNumber);
        GetOperation_t getUserInputOperation = reinterpret_cast<GetOperation_t>(pGetUserInputOperation);

        long double  accumulatedNumber = 0.0;
        long double  nextNumber = 0.0;
        char         operationSign = ' ';

        accumulatedNumber = getUserInputNumber(MSG_INPUT_FIRST_NUMBER);

        while (true)
        {
            operationSign = getUserInputOperation(MSG_INPUT_OPERATOR);

            if (operationSign == calcOperation)
            {
                std::cout << accumulatedNumber << std::endl;
                break;
            }

            nextNumber = getUserInputNumber(MSG_INPUT_NEXT_NUMBER);

            if (operationSign == addOperation)
            {
                accumulatedNumber += nextNumber;
            }
            else if (operationSign == subOperation)
            {
                accumulatedNumber -= nextNumber;
            }
            else if (operationSign == mulOperation)
            {
                accumulatedNumber *= nextNumber;
            }
            else if (operationSign == divOperation)
            {
                if (nextNumber != 0)
                {
                    accumulatedNumber /= nextNumber;
                }
                else
                {
                    std::cout << MSG_ERROR_DIVIDE_BY_ZERO;
                    continue;
                }
            }
            else
            {
                std::cout << MSG_ERROR_WRONG_OPERTAOR;
                continue;
            }
        }
    }

    char getUserOperation(const char* message)
    {
        char operation = ' ';
        std::cout << message;
        std::cin >> operation;
        return operation;
    }

    long double getUserNumber(const char* message)
    {
        long double accumulatedNumber = .0;
        std::cout << message;
        std::cin >> accumulatedNumber;
        return accumulatedNumber;
    }

}
