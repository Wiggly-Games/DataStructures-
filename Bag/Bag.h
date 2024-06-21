/*
 * This class defines a Bag.
 * Bags are a probabilistic data structure that stores several items of different types,
 * and then returns an element at random based on those previously added to the bag.
 * 
 * This is similar to the "bag" as defined in statistical problems.
 * For example: A bag contaisn 3 red balls, 5 blue balls, and 2 green balls.
 * You draw a ball at random - there will be a 30% chance of red, 50% of blue, 20% of green.
 * 
 * This data structure allows you to insert those balls and draw them out with the correct random percentages.
 * It also allows you to draw with replacement (Pull) vs. draw without replacement (Remove).
 * 
 * Add, Count, and Clear run in O(1) time, while Pull and Remove run in O(k) where k is the number of unique items within the bag.
*/

#include <unordered_map>
#include <iostream>

#ifndef BAG_H
#define BAG_H

namespace DataStructures {
    template <typename T>
    class Bag;

    template <typename T>
    Bag<T>* createBag();
}

template <typename T>
class DataStructures::Bag {
    private:
        std::unordered_map<T, short> Contents;
        int Counter;
    public:
        Bag();

        // Adds an item to the bag.
        void Add(T element);

        // Pulls an item out of the bag. Places it back into the bag after.
        T Pull();

        // Pull an item from the bag, and then remove it from the bag.
        T Remove();

        // Counts how many items total exist in the bag.
        int Count();

        // Clears the bag, deleting all data.
        // Note that if the Bag is storing pointers, the memory pointed to by each element will not be deleted.
        // This memory will need to be freed separately.
        void Clear();

        // Load from a file.
        void Load(char separator, std::istream& input, T(parseKey)(std::string));

        // Save into a file.
        void Save(char separator, std::ostream& output, std::string(parseKey)(T));
};

#include "Bag.hxx"

#endif