#pragma once
#include <map>
#include <string>
#include <initializer_list>

std::map<std::string, int> createMap();
void printMap(const std::map<std::string, int>& myMap);
void printMap(const std::map<std::string, std::string>& myMap);
void removeKeys(std::map<std::string, int>& m, const std::initializer_list<std::string>& keys);

void addSubscriber(std::map<std::string, std::string>& phoneBook, const std::string& name, const std::string& number);
std::string findNumberByName(const std::map<std::string, std::string>& phoneBook, const std::string& name);
void removeSubscriber(std::map<std::string, std::string>& phoneBook, const std::string& name);
