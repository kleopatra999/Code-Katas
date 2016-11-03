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
#include "CppUnitTest.h"
#include "RomanNumerals.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FromRomanNumerals_UnitTests
{
    TEST_CLASS(RomanNumeralsTests)
    {
    public:
        TEST_METHOD(ConvertOne)
        {
            RomanNumerals num;
            Assert::AreEqual(1, num.Convert(L"I"));
        }

        TEST_METHOD(ConvertTwo)
        {
            RomanNumerals num;
            Assert::AreEqual(2, num.Convert(L"II"));
        }

        TEST_METHOD(ConvertFour)
        {
            RomanNumerals num;
            Assert::AreEqual(4, num.Convert(L"IV"));
        }

        TEST_METHOD(ConvertFive)
        {
            RomanNumerals num;
            Assert::AreEqual(5, num.Convert(L"V"));
        }

        TEST_METHOD(ConvertTen)
        {
            RomanNumerals num;
            Assert::AreEqual(10, num.Convert(L"X"));
        }

        TEST_METHOD(ConvertFourtyTwo)
        {
            RomanNumerals num;
            Assert::AreEqual(42, num.Convert(L"XLII"));
        }

        TEST_METHOD(ConvertFivty)
        {
            RomanNumerals num;
            Assert::AreEqual(50, num.Convert(L"L"));
        }

        TEST_METHOD(ConvertNinetyNine)
        {
            RomanNumerals num;
            Assert::AreEqual(99, num.Convert(L"XCIX"));
        }

        TEST_METHOD(ConvertOneHundred)
        {
            RomanNumerals num;
            Assert::AreEqual(100, num.Convert(L"C"));
        }

        TEST_METHOD(ConvertFiveHundred)
        {
            RomanNumerals num;
            Assert::AreEqual(500, num.Convert(L"D"));
        }

        TEST_METHOD(ConvertOneThousand)
        {
            RomanNumerals num;
            Assert::AreEqual(1000, num.Convert(L"M"));
        }

        TEST_METHOD(ConvertTwoThousandThirteen)
        {
            RomanNumerals num;
            Assert::AreEqual(2013, num.Convert(L"MMXIII"));
        }
    };
}