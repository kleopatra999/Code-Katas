// Code-Katas
//
// Copyright (C) 2016 David Roller
//
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgement in the product documentation would be
//    appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.

#pragma once

#include "stdafx.h"
#include "RomanNumerals.h"

RomanNumerals::RomanNumerals()
{

}

RomanNumerals::~RomanNumerals()
{

}

int RomanNumerals::Convert(const std::wstring& roman)
{
    int decimalValue = 0;
    for (unsigned int i = 0; i < roman.length(); ++i)
    {
        auto currentRomanLiteral = roman[i];
        auto currentDecimalValue = ConvertRomanLiteral(currentRomanLiteral);

        if (i < roman.length() - 1)
        {
            auto nextRomanLiteral = roman[i+1];
            auto nextDecimalValue = ConvertRomanLiteral(nextRomanLiteral);

            if (nextDecimalValue > currentDecimalValue)
            {
                currentDecimalValue = nextDecimalValue - currentDecimalValue;
                i = i + 1;
            }
        }

        decimalValue += currentDecimalValue;
    }
    return decimalValue;
}

int RomanNumerals::ConvertRomanLiteral(wchar_t romanLiteral)
{
    switch (romanLiteral)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        throw std::runtime_error("Unknown roman literal: " + romanLiteral);
    }
}
