#pragma once
class unorderedSetType
{
    unorderedSetType.h
#ifndef UNORDERED_SET_TYPE_H
#define UNORDERED_SET_TYPE_H

#include "unorderedArrayListType.h"

        template <class elmType>
    class unorderedSetType : public unorderedArrayListType<elmType>
    {
    public:
        unorderedSetType();
        ~unorderedSetType();

        void insertEnd(const elmType& newElement);
        void insertAt(int index, const elmType& newElement);
        void replaceAt(int index, const elmType& newElement);

        unorderedSetType<elmType> operator+(const unorderedSetType<elmType>& set);
        unorderedSetType<elmType> operator-(const unorderedSetType<elmType>& set);

    private:
        bool isPresent(const elmType& element);
    };

    template <class elmType>
    unorderedSetType<elmType>::unorderedSetType() : unorderedArrayListType<elmType>()
    {
    }

    template <class elmType>
    unorderedSetType<elmType>::~unorderedSetType()
    {
    }

    template <class elmType>
    void unorderedSetType<elmType>::insertEnd(const elmType& newElement)
    {
        if (!isPresent(newElement))
            this->unorderedArrayListType<elmType>::insertEnd(newElement);
    }

    template <class elmType>
    void unorderedSetType<elmType>::insertAt(int index, const elmType& newElement)
    {
        if (!isPresent(newElement))
            this->unorderedArrayListType<elmType>::insertAt(index, newElement);
    }

    template <class elmType>
    void unorderedSetType<elmType>::replaceAt(int index, const elmType& newElement)
    {
        if (!isPresent(newElement))
            this->unorderedArrayListType<elmType>::replaceAt(index, newElement);
    }

    template <class elmType>
    unorderedSetType<elmType> unorderedSetType<elmType>::operator+(const unorderedSetType<elmType>& set)
    {
        unorderedSetType<elmType> result = *this;
        for (int i = 0; i < set.length(); i++)
        {
            if (!isPresent(set.getEntry(i)))
                result.insertEnd(set.getEntry(i));
        }
        return result;
    }

    template <class elmType>
    unorderedSetType<elmType> unorderedSetType<elmType>::operator-(const unorderedSetType<elmType>& set)
    {
        unorderedSetType<elmType> result;
        for (int i = 0; i < this->length(); i++)
        {
            if (!set.isPresent(this->getEntry(i)))
                result.insertEnd(this->getEntry(i));
        }
        return result;
    }

    template <class elmType>
    bool unorderedSetType<elmType>::isPresent(const elmType& element)
    {
        return this->unorderedArrayListType<elmType>::seqSearch(element) != -1;
    }

#endif // UNORDERED_SET_TYPE_H
};

