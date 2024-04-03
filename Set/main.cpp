#include "Set.h" // Assuming your Set class is defined in Set.h

int main() {
    // Creating sets
    Set<int> set1;
    Set<int> set2;

    // Adding elements to set1
    set1.add(1).add(2).add(3).add(4).add(5);

    // Adding elements to set2
    set2.add(4).add(5).add(6).add(7).add(8);

    // Printing the initial sets
    std::cout << "Set 1:" << std::endl;
    set1.print();
    std::cout << "Set 2:" << std::endl;
    set2.print();

    // Testing operations
    Set<int> set_union = set1.unionSet(set2);
    Set<int> set_intersect = set1.intersect(set2);
    Set<int> set_difference = set1.difference(set2);
    Set<int> set_sym_difference = set1.sym_difference(set2);

    // Printing the results
    std::cout << "Union of Set 1 and Set 2:" << std::endl;
    set_union.print();
    std::cout << "Intersection of Set 1 and Set 2:" << std::endl;
    set_intersect.print();
    std::cout << "Difference of Set 1 and Set 2:" << std::endl;
    set_difference.print();
    std::cout << "Symmetric Difference of Set 1 and Set 2:" << std::endl;
    set_sym_difference.print();

    return 0;
}
