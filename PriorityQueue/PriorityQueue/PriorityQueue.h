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

#include <memory>

template<typename T>
class PriorityQueue
{
public:
    PriorityQueue()
    {
        m_Head = std::make_shared<Element>();
    }

    void Enqueue(T element, int priority) 
    {
        auto newElement = std::make_shared<Element>();
        newElement->Value = element;
        newElement->Priority = priority;

        std::shared_ptr<Element> previous = m_Head;
        auto current = m_Head->Next;

        while (current != nullptr &&
            current->Priority > newElement->Priority)
        {
            previous = current;
            current = current->Next;
        }
        
        if (current != nullptr &&
            current->Priority == newElement->Priority)
        {
            newElement->Next = current->Next;
            current->Next = newElement;
        }
        else
        {
            previous->Next = newElement;
            newElement->Next = current;
        }
    }

    T Dequeue()
    {
        std::shared_ptr<Element> current = m_Head;
        if (current->Next == nullptr)
        {
            throw std::runtime_error("Queue is empty");
        }
        current = current->Next;
        m_Head->Next = current->Next;
        return current->Value;
    }

    int Count()
    {
        int count = 0;
        std::shared_ptr<Element> current = m_Head;
        while (current->Next != nullptr)
        {
            ++count;
            current = current->Next;
        }
        return count;
    }

protected:
    struct Element
    {
        int Priority;
        T Value;
        std::shared_ptr<Element> Next;
    };

    std::shared_ptr<Element> m_Head = nullptr;
};
