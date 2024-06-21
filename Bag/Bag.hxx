/*
    This file implements the Bag, as defined within Bag.h.
*/

#include "Bag.h"
#include <unordered_map>
#include <iostream>

// Constructor - Initialize the underlying map
template <typename T>
DataStructures::Bag<T>::Bag() {
    this->Counter = 0;
}

// Adds a new element to the bag
template <typename T>
void DataStructures::Bag<T>::Add(T element) {
    short counter = this->Contents[element];
    this->Contents[element] = counter + 1;

    this->Counter++;
}

// Returns the count of all items in the bag
template <typename T>
int DataStructures::Bag<T>::Count() {
    return this->Counter;
}

// Pull a random item from the bag, placing it back in after.
template <typename T>
T DataStructures::Bag<T>::Pull() {
    if (this->Counter == 0) {
        throw "Could not pull an item; bag is empty";
    }

    // Pick a random value - goes from 0 to the number of items in the bag, exclusive
    int check = rand() % this->Counter;

    // Look for our result
    // This is whatever counter ends up dropping check to 0
    T result;
    for (const auto& keyValue : this->Contents) {
        // If check drops to 0 here, return this item
        if (check < keyValue.second) {
            result = keyValue.first;
            break;
        }
        // Otherwise, drop check and keep going
        check -= keyValue.second;
    }

    // Should have a result, so return that item
    return result;
}

// Pulls an item from the bag, then removes it.
template <typename T>
T DataStructures::Bag<T>::Remove() {
    // Take an item at random
    T item = this->Pull();

    // Drop its counter by one
    auto count = (this->Contents)[item];
    (this->Contents)[item] = count - 1;

    // If the item no longer exists, we can remove it
    if (count <= 1) {
        this->Contents.erase(item);
    }
    
    // Update the counter
    this->Counter -= 1;

    return item;
}

// Clear all contents of the map.
// Note that if the elements are pointers, this will not delete the pointers.
// Pointer memory must be handled separately.
template <typename T>
void DataStructures::Bag<T>::Clear() {
    this->Contents.clear();
    this->Counter = 0;
}