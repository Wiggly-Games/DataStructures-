/*
    This file implements the Bag, as defined within Bag.h.
*/

#include "Bag.h"
#include <unordered_map>
#include <iostream>
#include <string>
#include <sstream>

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
int DataStructures::Bag<T>::Count() const {
    return this->Counter;
}

// Pull a random item from the bag, placing it back in after.
template <typename T>
T DataStructures::Bag<T>::Pull() const {
    if (this->Counter == 0) {
        throw std::runtime_error("Could not pull an item; bag is empty");
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

// Reads the bag contents from an input stream.
template <typename T>
void DataStructures::Bag<T>::Load(std::istream& input, T(parseKey)(std::string)) {
    std::string keyStr, valueStr;
    short counter;
    while (true) {
        std::getline(input, keyStr);

        // Stop once we hit an empty line - end of the bag
        if (keyStr == "") {
            break;
        }

        // If there's a key, there should also be a value. Value will be the next line.
        std::getline(input, valueStr);

        // Parse the key/value strings into their actual values
        T key = parseKey(keyStr);
        int value = std::stoi(valueStr);

        // Throw an error if we've already seen this value before; each value should only be added once
        if (this->Contents[key] != 0) {
            throw std::runtime_error(std::string("Loading failed; attempted to load duplicate of ").append(keyStr).c_str());
        }

        // Add it to our map, and increase how many items we have in the bag
        this->Contents[key] = value;
        counter += value;
    }
    this->Counter = counter;
}

// Saves the bag contents to an output stream.
template <typename T>
void DataStructures::Bag<T>::Save(std::ostream& output, std::string(parseKey)(T)) const {
    for (const auto& kv: this->Contents) {
        output << parseKey(kv.first) << std::endl << kv.second << std::endl;
    }
    output << std::endl;
}

template <typename T>
std::string DataStructures::Bag<T>::ToString(std::string(parseKey)(T)) const {
    std::stringstream str;
    for (const auto& kv: this->Contents) {
        str << parseKey(kv.first) << "=" << kv.second << "; ";
    }

    return str.str();
}