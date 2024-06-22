#include "Bag.h"
#include <iostream>
#include <fstream>
#include <string>

int parseStr(std::string str) {
    return std::stoi(str);
}

std::string toString(int key) {
    return std::to_string(key);
}

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

    // Save to file
    std::ofstream file;
    file.open("test/bag.txt");
    bag.Save(file, toString);
    file.close();

    // Load to file
    DataStructures::Bag<int> bag2;
    std::ifstream inputFile;
    inputFile.open("test/bag.txt");
    bag2.Load(inputFile, parseStr);
    inputFile.close();

    for (int i = bag2.Count(); i > 0; i--) {
        std::cout << bag2.Remove() << std::endl;
    }
}

int main() {
    CheckBag();
    return 0;
}