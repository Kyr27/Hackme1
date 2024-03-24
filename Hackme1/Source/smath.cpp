#include "smath.h"

int smath::GetDigits(int number)
{
    //int size = 1 + static_cast<int>(log10(number));
    int size = number == 0 ? 1 : (number < 0 ? static_cast<int>(log10(std::abs(number))) + 1 : static_cast<int>(log10(number)) + 1);
    return size;
}