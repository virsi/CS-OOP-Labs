#include "product.h"
#include <cstring>
#include <iostream>

// Product
Product::Product() : name(nullptr), weight(0), cost(0), material(nullptr) {
    std::cout << "Product()" << std::endl;
}

Product::Product(char* name, int weight, int cost, char* material)
    : name(new char[strlen(name) + 1]), weight(weight), cost(cost), material(new char[strlen(material) + 1]) {
    strcpy(this->name, name);
    strcpy(this->material, material);
    std::cout << "Product(char*, int, int, char*)" << std::endl;
}

Product::~Product() {
    std::cout << "~Product()" << std::endl;
    delete[] name;
    delete[] material;
}

char* Product::getName() {
    return name;
}

int Product::getWeight() const {
    return weight;
}

int Product::getCost() const {
    return cost;
}

char* Product::getMaterial() {
    return material;
}

void Product::setName(const char* newName) {
    delete[] name;
    name = new char[strlen(newName) + 1];
    strcpy(name, newName);
}

void Product::setWeight(int newWeight) {
    weight = newWeight;
}

void Product::setCost(int newCost) {
    cost = newCost;
}

void Product::setMaterial(const char* newMaterial) {
    delete[] material;
    material = new char[strlen(newMaterial) + 1];
    strcpy(material, newMaterial);
}

void Product::show() {
    std::cout << "Name: " << (name ? name : "N/A") << ", Weight: " << weight
              << ", Cost: " << cost << ", Material: " << (material ? material : "N/A") << std::endl;
}

// Detail
Detail::Detail() : Product() {
    std::cout << "Detail()" << std::endl;
}

Detail::Detail(char* name, int weight, int cost, char* material)
    : Product(name, weight, cost, material) {
    std::cout << "Detail(char*, int, int, char*)" << std::endl;
}

Detail::~Detail() {
    std::cout << "~Detail()" << std::endl;
    ;
}

void Detail::show() {
    std::cout << "Detail -> ";
    Product::show();
}

// Assembly
Assembly::Assembly() : Product() {
    std::cout << "Assembly()" << std::endl;
}

Assembly::Assembly(char* name, int weight, int cost, char* material)
    : Product(name, weight, cost, material) {
    std::cout << "Assembly(char*, int, int, char*)" << std::endl;
}

Assembly::~Assembly() {
    std::cout << "~Assembly()" << std::endl;
    for (int i = 0; i < components.get_size(); ++i) {
        delete components[i];
    }
}

int Assembly::getWeight() const {
    int totalWeight = weight;
    for (int i = 0; i < components.get_size(); ++i) {
        totalWeight += components[i]->getWeight();
    }
    return totalWeight;
}

int Assembly::getCost() const {
    int totalCost = cost;
    for (int i = 0; i < components.get_size(); ++i) {
        totalCost += components[i]->getCost();
    }
    return totalCost;
}

// Mechanism
Mechanism::Mechanism() : Product() {
    std::cout << "Mechanism()" << std::endl;
}

Mechanism::Mechanism(char* name, int weight, int cost, char* material)
    : Product(name, weight, cost, material) {
    std::cout << "Mechanism(char*, int, int, char*)" << std::endl;
}

Mechanism::~Mechanism() {
    std::cout << "~Mechanism()" << std::endl;
    for (int i = 0; i < components.get_size(); ++i) {
        delete components[i];
    }
}

int Mechanism::getWeight() const {
    int totalWeight = 0;
    for (int i = 0; i < components.get_size(); ++i) {
        totalWeight += components[i]->getWeight();
    }
    return totalWeight;
}

int Mechanism::getCost() const {
    int totalCost = 0;
    for (int i = 0; i < components.get_size(); ++i) {
        totalCost += components[i]->getCost();
    }
    return totalCost;
}
