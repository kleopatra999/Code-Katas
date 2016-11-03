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
#include "FizzBuzz.h"
#include <iostream>

int main()
{
    FizzBuzz fizzbuzz;
    for (unsigned int i = 1; i < 101; ++i)
    {
        auto fizz = fizzbuzz.IsFizz(i);
        auto buzz = fizzbuzz.IsBuzz(i);

        if (fizz && buzz)
        {
            std::wcout << L"FizzBuzz" << std::endl;
        }
        else if (fizz)
        {
            std::wcout << L"Fizz" << std::endl;
        }
        else if (buzz)
        {
            std::wcout << L"Buzz" << std::endl;
        }
        else
        {
            std::wcout << i << std::endl;
        }
    }
    return 0;
}

