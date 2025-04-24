#include "product.h"
#include <cstring>
#include <iostream>

// Product
Product::Product() : name(nullptr), weight(0), cost(0), material(nullptr) {}

Product::Product(char* name, int weight, int cost, char* material) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->weight = weight;
    this->cost = cost;
    this->material = new char[strlen(material) + 1];
    strcpy(this->material, material);
}

Product::~Product() {
    delete[] name;
    delete[] material;
}

char* Product::getName() {
    return name;
}

int Product::getWeight() {
    return weight;
}

int Product::getCost() {
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
Detail::Detail() : Product() {}

Detail::Detail(char* name, int weight, int cost, char* material) : Product(name, weight, cost, material) {}

Detail::~Detail() {}

void Detail::show() {
    std::cout << "Detail -> ";
    Product::show();
}

// Assembly
int Assembly::getWeight() {
    int totalWeight = weight;
    for (int i = 0; i < components.get_size(); ++i) {
        totalWeight += components[i]->getWeight();
    }
    return totalWeight;
}

int Assembly::getCost() {
    int totalCost = cost;
    for (int i = 0; i < components.get_size(); ++i) {
        totalCost += components[i]->getCost();
    }
    return totalCost;
}
