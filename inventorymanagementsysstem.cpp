#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

struct Product {
    int id;
    std::string name;
    int quantity;
    double price;

    Product(int i, std::string n, int q, double p) : id(i), name(n), quantity(q), price(p) {}
};

class Inventory {
private:
    std::vector<Product> products;
    const std::string inventoryFile = "inventory.txt";
    const std::string salesFile = "sales.txt";

    void loadInventory() {
        std::ifstream infile(inventoryFile);
        if (!infile.is_open()) return;

        int id, quantity;
        std::string name;
        double price;

        while (infile >> id >> name >> quantity >> price) {
            products.push_back(Product(id, name, quantity, price));
        }
        infile.close();
    }

    void saveInventory() {
        std::ofstream outfile(inventoryFile);
        for (const auto& product : products) {
            outfile << product.id << " " << product.name << " " << product.quantity << " " << product.price << "\n";
        }
        outfile.close();
    }

public:
    Inventory() {
        loadInventory();
    }

    ~Inventory() {
        saveInventory();
    }

    void addProduct(int id, std::string name, int quantity, double price) {
        products.push_back(Product(id, name, quantity, price));
    }

    void displayProducts() {
        std::cout << std::setw(5) << "ID" << std::setw(15) << "Name" << std::setw(10) << "Quantity" << std::setw(10) << "Price" << "\n";
        for (const auto& product : products) {
            std::cout << std::setw(5) << product.id << std::setw(15) << product.name << std::setw(10) << product.quantity << std::setw(10) << product.price << "\n";
        }
    }

    void updateStock(int id, int quantity) {
        for (auto& product : products) {
            if (product.id == id) {
                product.quantity += quantity;
                if (product.quantity < 0) {
                    product.quantity = 0;
                }
                break;
            }
        }
    }

    void recordSale(int id, int quantity) {
        for (auto& product : products) {
            if (product.id == id && product.quantity >= quantity) {
                product.quantity -= quantity;
                std::ofstream outfile(salesFile, std::ios::app);
                outfile << id << " " << quantity << " " << product.price * quantity << "\n";
                outfile.close();
                break;
            }
        }
    }

    void generateReport() {
        std::cout << "\nSales Report:\n";
        std::ifstream infile(salesFile);
        if (!infile.is_open()) return;

        int id, quantity;
        double total;
        double grandTotal = 0;

        std::cout << std::setw(5) << "ID" << std::setw(10) << "Quantity" << std::setw(10) << "Total" << "\n";
        while (infile >> id >> quantity >> total) {
            std::cout << std::setw(5) << id << std::setw(10) << quantity << std::setw(10) << total << "\n";
            grandTotal += total;
        }
        infile.close();

        std::cout << "\nGrand Total: " << grandTotal << "\n";
    }
};

int main() {
    Inventory inventory;

    inventory.addProduct(1, "Apple", 50, 0.5);
    inventory.addProduct(2, "Banana", 100, 0.2);
    inventory.addProduct(3, "Orange", 80, 0.3);

    std::cout << "Current Inventory:\n";
    inventory.displayProducts();

    inventory.updateStock(1, -10);
    inventory.recordSale(2, 20);

    std::cout << "\nUpdated Inventory:\n";
    inventory.displayProducts();

    inventory.generateReport();

    return 0;
}
