#include <iostream>
#include "collections/myvector.h"
#include "product/product.h"
#include "app/app.h"

int main() {
    // Демонстрация работы класса Product
    Product product("Generic Product", 5, 50, "Wood");
    std::cout << "Product details:" << std::endl;
    product.show();

    product.setName("Updated Product");
    product.setWeight(10);
    product.setCost(100);
    product.setMaterial("Steel");
    std::cout << "\nUpdated Product details:" << std::endl;
    product.show();

    // Демонстрация работы класса Detail
    Detail detail("Detail1", 2, 20, "Plastic");
    std::cout << "\nDetail details:" << std::endl;
    detail.show();

    // Демонстрация работы класса Assembly
    Assembly assembly;
    assembly.setName("Assembly1");
    assembly.setWeight(3);
    assembly.setCost(30);
    assembly.setMaterial("Composite");
    std::cout << "\nAssembly details before adding components:" << std::endl;
    assembly.show();

    assembly.getComponents().add_element(new Detail("Component1", 1, 10, "Rubber"));
    assembly.getComponents().add_element(new Detail("Component2", 2, 15, "Metal"));
    std::cout << "\nAssembly details after adding components:" << std::endl;
    assembly.show();

    // Демонстрация работы контейнера MyVector
    MyVector<Product*> products;
    products.add_element(new Detail("Detail1", 10, 100, "Metal"));
    products.add_element(new Detail("Detail2", 20, 200, "Plastic"));
    products.add_element(new Assembly());

    std::cout << "\nInitial container:" << std::endl;
    print(products);

    std::cout << "\nRemoving element at index 1:" << std::endl;
    remove(products, 1);
    print(products);

    std::cout << "\nClearing container:" << std::endl;
    clear(products);
    print(products);

    // Демонстрация работы класса Mechanism
    Mechanism mechanism("Mechanism1", 15, 150, "Alloy");
    std::cout << "\nMechanism details:" << std::endl;
    mechanism.show();

    mechanism.setName("Updated Mechanism");
    mechanism.setWeight(20);
    mechanism.setCost(200);
    mechanism.setMaterial("Titanium");
    std::cout << "\nUpdated Mechanism details:" << std::endl;
    mechanism.show();

    mechanism.addComponent(new Detail("Mechanism Component1", 5, 50, "Plastic"));
    mechanism.addComponent(new Detail("Mechanism Component2", 10, 100, "Steel"));
    std::cout << "\nMechanism details after adding components:" << std::endl;
    mechanism.show();

    return 0;
}
