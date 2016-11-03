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

#include "stdafx.h"
#include "FizzBuzzVariation.h"

#include <string>

FizzBuzzVariation::FizzBuzzVariation()
{

}

FizzBuzzVariation::~FizzBuzzVariation()
{

}

bool FizzBuzzVariation::IsFizz(unsigned int value)
{
    auto div = value / 3;
    auto result = div * 3;

    auto digits = std::to_wstring(value);
    for (unsigned int i = 0; i != digits.length(); ++i)
    {
        if (digits[i] == '3')
        {
            return true;
        }
    }

    return result == value;
}

bool FizzBuzzVariation::IsBuzz(unsigned int value)
{
    auto div = value / 5;
    auto result = div * 5;

    auto digits = std::to_wstring(value);
    for (unsigned int i = 0; i != digits.length(); ++i)
    {
        if (digits[i] == '5')
        {
            return true;
        }
    }

    return result == value;
}
