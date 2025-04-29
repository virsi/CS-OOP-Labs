#include "tasks.h"
#include <iostream>
#include <map>

std::map<std::string, int> createMap() {
    return {
        {"one", 100},
        {"two", 200},
        {"three", 300},
        {"four", 400},
        {"five", 500},
        {"six", 600}
    };
}


void removeKeys(std::map<std::string, int>& m, const std::initializer_list<std::string>& keys) {
    for (const auto& key : keys) {
        m.erase(key);
    }
}

void addSubscriber(std::map<std::string, std::string>& phoneBook, const std::string& name, const std::string& number) {
    phoneBook[name] = number;
}

std::string findNumberByName(const std::map<std::string, std::string>& phoneBook, const std::string& name) {
    auto it = phoneBook.find(name);
    if (it != phoneBook.end()) {
        return it->second;
    }
    return "";
}

void removeSubscriber(std::map<std::string, std::string>& phoneBook, const std::string& name) {
    phoneBook.erase(name);
}

void printMap(const std::map<std::string, int>& myMap) {
    for (const auto& [key, value] : myMap) {
        std::cout << key << ": " << value << std::endl;
    }
}

void printMap(const std::map<std::string, std::string>& myMap) {
    for (const auto& [key, value] : myMap) {
        std::cout << key << ": " << value << std::endl;
    }
}
