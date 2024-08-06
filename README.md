# Inventory Management System

## Description

The Inventory Management System is a C++ application designed for small businesses to efficiently manage their inventory. It provides functionalities for tracking product details, managing stock levels, recording sales transactions, and generating reports.

## Features

- **Manage Product Details**: Add, display, and update product information including ID, name, quantity, and price.
- **Stock Management**: Track stock levels and update inventory after sales.
- **Sales Transactions**: Record sales and adjust inventory accordingly.
- **Reports**: Generate detailed sales reports and view total sales.

## Technologies Used

- **C++**: Main programming language.
- **STL**: Standard Template Library for managing collections.
- **File I/O**: For reading and writing data to files.

## Installation

To build and run the Inventory Management System, follow these steps:

```
# Clone the repository
git clone https://github.com/yourusername/inventory-management-system.git
cd inventory-management-system

# Compile the code
g++ -o inventory_system main.cpp
```
## Usage

Run the application using:

```
./inventory_system
 ```
### Adding Products

Modify the `main()` function in `main.cpp` to add new products. Example:

```
inventory.addProduct(1, "Apple", 50, 0.5);
inventory.addProduct(2, "Banana", 100, 0.2);
inventory.addProduct(3, "Orange", 80, 0.3);
```
### Displaying Products

Call `displayProducts()` to view the current inventory:

```
inventory.displayProducts();
```
### Updating Stock

Update stock levels using:

```
inventory.updateStock(id, quantity);
```
### Recording Sales

Record sales transactions with:

```cpp
inventory.recordSale(id, quantity);
```
### Generating Reports

Generate sales reports using:

```cpp
inventory.generateReport();
```
## Sample Output

```plaintext
Current Inventory:
  ID           Name   Quantity     Price
   1          Apple        50        0.5
   2         Banana       100        0.2
   3         Orange        80        0.3

Updated Inventory:
  ID           Name   Quantity     Price
   1          Apple        40        0.5
   2         Banana        80        0.2
   3         Orange        80        0.3

Sales Report:
  ID  Quantity     Total
   2        20        4.0

Grand Total: 4
