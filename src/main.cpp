#include <iostream>
#include "collections/myvector.h"
#include "product/product.h"
#include "app/app.h"

int main() {
    MyVector<Product*> products;

    products.add_element(new Detail("Detail1", 10, 100, "Metal"));
    products.add_element(new Detail("Detail2", 20, 200, "Plastic"));
    products.add_element(new Assembly());

    std::cout << "Initial container:" << std::endl;
    print(products);

    std::cout << "\nRemoving element at index 1:" << std::endl;
    remove(products, 1);
    print(products);

    std::cout << "\nClearing container:" << std::endl;
    clear(products);
    print(products);

    return 0;
}
