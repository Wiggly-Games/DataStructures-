#include "Bag.h"
#include <iostream>

void CheckBag(){
    srand(time(0));

    // Add items into a bag
    DataStructures::Bag<int> bag;
    bag.Add(0);
    bag.Add(1);
    bag.Add(2);
    bag.Add(0);
    bag.Add(2);
    bag.Add(0);
    bag.Add(0);

    for (int i = bag.Count(); i > 0; i--) {
        std::cout << "Pulled value: " << bag.Remove() << std::endl;
    }
}

int main() {
    CheckBag();
    return 0;
}