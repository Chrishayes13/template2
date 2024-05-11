// template2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "unorderedSetType.h"

using namespace std;

int main()
{
    int intArray[] = { 1, 2, 3, 4, 5, 2, 3 };
    string strArray[] = { "apple", "banana", "cherry", "apple", "date" };

    unorderedSetType<int> intSet;
    unorderedSetType<string> strSet;

    // Add elements to integer set
    for (int i = 0; i < 7; i++)
        intSet.insertEnd(intArray[i]);

    // Add elements to string set
    for (int i = 0; i < 5; i++)
        strSet.insertEnd(strArray[i]);

    cout << "Integer Set: ";
    intSet.print();
    cout << "String Set: ";
    strSet.print();

    // Test insertAt and replaceAt
    intSet.insertAt(2, 10);
    strSet.replaceAt(1, "orange");

    cout << "\nAfter insertAt and replaceAt:\n";
    cout << "Integer Set: ";
    intSet.print();
    cout << "String Set: ";
    strSet.print();

    // Test union and intersection
    unorderedSetType<int> intSet1, intSet2, intUnion, intIntersection;
    unorderedSetType<string> strSet1, strSet2, strUnion, strIntersection;

    intSet1.insertEnd(1);
    intSet1.insertEnd(3);
    intSet1.insertEnd(5);

    intSet2.insertEnd(2);
    intSet2.insertEnd(4);
    intSet2.insertEnd(6);

    strSet1.insertEnd("apple");
    strSet1.insertEnd("banana");
    strSet1.insertEnd("cherry");

    strSet2.insertEnd("date");
    strSet2.insertEnd("fig");
    strSet2.insertEnd("cherry");

    intUnion = intSet1 + intSet2;
    intIntersection = intSet1 - intSet2;

    strUnion = strSet1 + strSet2;
    strIntersection = strSet1 - strSet2;

    cout << "\nUnion and Intersection:\n";
    cout << "Integer Union: ";
    intUnion.print();
    cout << "Integer Intersection: ";
    intIntersection.print();
    cout << "String Union: ";
    strUnion.print();
    cout << "String Intersection: ";
    strIntersection.print();

    return 0;
}