#include "set.h"
#include <iostream>

using namespace std;

int main()
{
    Set<int> maksiSet;

    maksiSet.add(3);
    maksiSet.add(2);
    maksiSet.add(1);

    cout << "Initial set:" << endl;
    maksiSet.print();

    cout << "Size of set: " << maksiSet.getSize() << endl;

    int elementToCheck = 2;
    if (maksiSet.contain(elementToCheck))
        cout << elementToCheck << " is in the set" << endl;
    else
        cout << elementToCheck << " is not in the set" << endl;

    int elementToRemove = 3;
    maksiSet.remove(elementToRemove);
    cout << "After removing " << elementToRemove << ":" << endl;
    maksiSet.print();

    Set<int> secondSet;
    secondSet.add(3);
    secondSet.add(4);
    secondSet.add(5);

    Set<int> unionResult = maksiSet.unionSet(secondSet);
    cout << "Union of sets:" << endl;
    unionResult.print();

    Set<int> intersectionResult = maksiSet.intersect(secondSet);
    cout << "Intersection of sets:" << endl;
    intersectionResult.print();

    Set<int> differenceResult = maksiSet.difference(secondSet);
    cout << "Difference of sets:" << endl;
    differenceResult.print();

    Set<int> symmetricDifferenceResult = maksiSet.sym_difference(secondSet);
    cout << "Symmetric difference of sets:" << endl;
    symmetricDifferenceResult.print();

    return 0;
}
