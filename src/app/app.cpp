#include "../collections/myvector.h"
#include "../product/product.h"

void print(const MyVector<Product*>& container) {
    for (int i = 0; i < container.get_size(); ++i) {
        std::cout << "Index " << i << ": ";
        container[i]->show();
    }
}

void remove(MyVector<Product*>& container, int index) {
    if (index < 0 || index >= container.get_size()) {
        std::cerr << "Invalid index!" << std::endl;
        return;
    }
    delete container[index];
    container.delete_element(container[index]);
}

void clear(MyVector<Product*>& container) {
    while (container.get_size() > 0) {
        delete container[container.get_size() - 1];
        container.delete_element(container[container.get_size() - 1]);
    }
}
