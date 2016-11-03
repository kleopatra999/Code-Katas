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
#include "FizzBuzzVariation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FizzBuzz_UnitTests
{
    TEST_CLASS(FizzBuzzVariationTests)
    {
    public:
        TEST_METHOD(Is3Fizz)
        {
            FizzBuzzVariation fizzbuzz;
            Assert::IsTrue(fizzbuzz.IsFizz(3));
        }

        TEST_METHOD(Is5Fizz)
        {
            FizzBuzzVariation fizzbuzz;
            Assert::IsFalse(fizzbuzz.IsFizz(5));
        }

        TEST_METHOD(Is13Fizz)
        {
            FizzBuzzVariation fizzbuzz;
            Assert::IsTrue(fizzbuzz.IsFizz(13));
        }

        TEST_METHOD(Is51Buzz)
        {
            FizzBuzzVariation fizzbuzz;
            Assert::IsTrue(fizzbuzz.IsBuzz(51));
        }

        TEST_METHOD(Is5Buzz)
        {
            FizzBuzzVariation fizzbuzz;
            Assert::IsTrue(fizzbuzz.IsBuzz(5));
        }

        TEST_METHOD(Is3Buzz)
        {
            FizzBuzzVariation fizzbuzz;
            Assert::IsFalse(fizzbuzz.IsBuzz(3));
        }

        TEST_METHOD(Is25Buzz)
        {
            FizzBuzzVariation fizzbuzz;
            Assert::IsTrue(fizzbuzz.IsBuzz(25));
        }

        TEST_METHOD(Is50Buzz)
        {
            FizzBuzzVariation fizzbuzz;
            Assert::IsTrue(fizzbuzz.IsBuzz(50));
        }

        TEST_METHOD(Is15Fizz)
        {
            FizzBuzzVariation fizzbuzz;
            Assert::IsTrue(fizzbuzz.IsFizz(15));
        }

        TEST_METHOD(Is30Fizz)
        {
            FizzBuzzVariation fizzbuzz;
            Assert::IsTrue(fizzbuzz.IsFizz(30));
        }
    };
}