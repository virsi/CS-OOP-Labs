#pragma once
#include "../collections/myvector.h"

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
        virtual int getWeight() const;
        virtual int getCost() const;
        char* getMaterial();

        void setName(const char* newName);
        void setWeight(int newWeight);
        void setCost(int newCost);
        void setMaterial(const char* newMaterial);

        void show();
};

class Detail : public Product {
    public:
        Detail();
        Detail(char* name, int weight, int cost, char* material);
        virtual ~Detail();
};

class Assembly : public Product {
    private:
        MyVector<Product*> components;

    public:
        Assembly();
        Assembly(char* name, int weight, int cost, char* material);
        ~Assembly() override;
        int getWeight() const override;
        int getCost() const override;
        MyVector<Product*>& getComponents() {
            return components;
        }
};

class Mechanism : public Product {
    private:
        MyVector<Product*> components;
    public:
        Mechanism(); // Конструктор по умолчанию
        Mechanism(char* name, int weight, int cost, char* material);
        ~Mechanism() override;

        void addComponent(Product* item) {
            components.add_element(item);
        }

        int getWeight() const override;
        int getCost() const override;
};
