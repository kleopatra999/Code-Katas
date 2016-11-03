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
#include "PriorityQueueAccess.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PriorityQueue_UnitTest
{
    TEST_CLASS(PriorityQueueTests)
    {
    public:
        std::wstring Convert(PriorityQueueAccess<int>& queue)
        {
            std::wstring result = L"";
            auto current = queue.GetHead();
            current = current->Next; // Skip Head Node

            while (current != nullptr)
            {
                result += L"(" + std::to_wstring(current->Value) +
                    L"," + std::to_wstring(current->Priority) + L")";
                current = current->Next;
            }
            return result;
        }

        TEST_METHOD(EnqueueItem_Count)
        {
            PriorityQueueAccess<int> queue;
            queue.Enqueue(1, 5);
            Assert::AreEqual(1, queue.Count());
        }

        TEST_METHOD(EnqueueItem)
        {
            PriorityQueueAccess<int> queue;
            queue.Enqueue(1, 5);
            Assert::AreEqual(std::wstring(L"(1,5)"), Convert(queue));
        }

        TEST_METHOD(EnqueueTwoItem)
        {
            PriorityQueueAccess<int> queue;
            queue.Enqueue(1, 5);
            queue.Enqueue(2, 5);
            Assert::AreEqual(std::wstring(L"(1,5)(2,5)"), Convert(queue));
        }

        TEST_METHOD(DequequeItem)
        {
            PriorityQueueAccess<int> queue;
            queue.Enqueue(1, 5);
            queue.Enqueue(2, 5);
            Assert::AreEqual(1, queue.Dequeue());
        }

        TEST_METHOD(DequequeItemAssertQueue)
        {
            PriorityQueueAccess<int> queue;
            queue.Enqueue(1, 5);
            queue.Enqueue(2, 5);
            queue.Dequeue();
            Assert::AreEqual(std::wstring(L"(2,5)"), Convert(queue));
        }

        TEST_METHOD(EnqueueAfterDequeque)
        {
            PriorityQueueAccess<int> queue;
            queue.Enqueue(1, 5);
            queue.Enqueue(2, 5);
            queue.Dequeue();
            queue.Enqueue(3, 7);
            Assert::AreEqual(std::wstring(L"(3,7)(2,5)"), Convert(queue));
        }

        TEST_METHOD(EnqueueTwoAfterDequeque)
        {
            PriorityQueueAccess<int> queue;
            queue.Enqueue(1, 5);
            queue.Enqueue(2, 5);
            queue.Dequeue();
            queue.Enqueue(3, 7);
            queue.Enqueue(4, 7);
            Assert::AreEqual(std::wstring(L"(3,7)(4,7)(2,5)"), Convert(queue));
        }

        TEST_METHOD(EnqueueThreeAfterDequeque)
        {
            PriorityQueueAccess<int> queue;
            queue.Enqueue(1, 5);
            queue.Enqueue(2, 5);
            queue.Dequeue();
            queue.Enqueue(3, 7);
            queue.Enqueue(4, 7);
            queue.Enqueue(5, 3);
            Assert::AreEqual(std::wstring(L"(3,7)(4,7)(2,5)(5,3)"), Convert(queue));
        }

        TEST_METHOD(EnqueueThreeAfterDequeque_Count)
        {
            PriorityQueueAccess<int> queue;
            queue.Enqueue(1, 5);
            queue.Enqueue(2, 5);
            queue.Dequeue();
            queue.Enqueue(3, 7);
            queue.Enqueue(4, 7);
            queue.Enqueue(5, 3);
            Assert::AreEqual(4, queue.Count());
        }
    };
}