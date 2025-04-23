#pragma once
#include "../pkg/myvector.h"

class Product {
    protected:
    char* name;
    int weight;
    int cost;
    char* material;

    public:
        Product();
        Product(char* name, int weight, int cost, char* material);
        virtual ~Product();

        char* getName();
        virtual int getWeight();
        virtual int getCost();
        char* getMaterial();

        void setName(const char* newName);
        void setWeight(int newWeight);
        void setCost(int newCost);
        void setMaterial(const char* newMaterial);

        virtual void show();
};

class Detail : public Product {
    public:
        Detail();
        Detail(char* name, int weight, int cost, char* material);
        virtual ~Detail();

        virtual void show();
};

class Assembly : public Product {
    private:
        MyVector<Product*> components;

    public:
        int getWeight() override;
        int getCost() override;
};
