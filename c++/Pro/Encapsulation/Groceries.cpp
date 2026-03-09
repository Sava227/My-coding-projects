#include <iostream>
#include <vector>
#include <variant>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

class Product {
protected:
    string name;
    double price = 0.0;

public:
    void set_data() {
        cout << "Name: ";
        getline(cin >> ws, name);

        cout << "Price: ";
        while (!(cin >> price) || price < 0) {
            cout << "Enter a valid non-negative price: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void get_data() const {
        cout << left << setw(20) << "Name"  << ": " << name << "\n";
        cout << left << setw(20) << "Price" << ": " << fixed << setprecision(2) << price << "\n";
    }
};

class ProductWithManufacturer : public Product {
private:
    string manufacturer;

public:
    void set_data() {
        Product::set_data();
        cout << "Manufacturer: ";
        getline(cin, manufacturer);
    }

    void get_data() const {
        Product::get_data();
        cout << left << setw(20) << "Manufacturer" << ": " << manufacturer << "\n";
    }
};

class ProductWithComposition : public Product {
private:
    string composition;

public:
    void set_data() {
        Product::set_data();
        cout << "Composition: ";
        getline(cin, composition);
    }

    void get_data() const {
        Product::get_data();
        cout << left << setw(20) << "Composition" << ": " << composition << "\n";
    }
};

void print_menu() {
    cout << "\n=== Store database menu ===\n";
    cout << "1) Add simple product (name + price)\n";
    cout << "2) Add product with manufacturer\n";
    cout << "3) Add product with composition\n";
    cout << "4) Show ассортимент (all products)\n";
    cout << "0) Exit\n";
    cout << "Choose: ";
}

int main() {
    using Item = variant<Product, ProductWithManufacturer, ProductWithComposition>;
    vector<Item> db;

    while (true) {
        print_menu();

        int choice = -1;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 0) {
            cout << "Bye!\n";
            break;
        }

        if (choice == 4) {
            if (db.empty()) {
                cout << "\nDatabase is empty.\n";
                continue;
            }

            cout << "\n=== Assortment ===\n";
            for (size_t i = 0; i < db.size(); ++i) {
                cout << "\n-- Item #" << (i + 1) << " --\n";
                visit([](const auto& item) {
                    item.get_data();
                }, db[i]);
            }
            continue;
        }

        if (choice == 1) {
            Product p;
            cout << "\nEnter product data:\n";
            p.set_data();
            db.push_back(p);
            cout << "Added!\n";
        } else if (choice == 2) {
            ProductWithManufacturer p;
            cout << "\nEnter product data:\n";
            p.set_data();
            db.push_back(p);
            cout << "Added!\n";
        } else if (choice == 3) {
            ProductWithComposition p;
            cout << "\nEnter product data:\n";
            p.set_data();
            db.push_back(p);
            cout << "Added!\n";
        } else {
            cout << "No such option.\n";
        }
    }

    return 0;
}
