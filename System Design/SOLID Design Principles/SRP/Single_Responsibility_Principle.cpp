#include <bits/stdc++.h>
using namespace std;

class Product
{
public:
    string name;
    double price;

    Product(string n, double p)
    {
        this->name = n;
        this->price = p;
    }
};

// ShoppingCart to calculate total price
class ShoppingCart
{
private:
    vector<Product *> products;

public:
    void addProduct(Product *p)
    {
        products.push_back(p);
    }

    const vector<Product *> getProducts()
    {
        return products;
    }

    // Calculate total cart price
    double calculateTotal()
    {
        double total = 0;
        for (auto p : products)
        {
            total += p->price;
        }
        return total;
    }
};

// Class to print invoice of cart
class ShoppingCartPrinter
{
private:
    ShoppingCart *cart;

public:
    ShoppingCartPrinter(ShoppingCart *c)
    {
        this->cart = c;
    }

    void printInvoice()
    {
        cout << "Shopping cart details: \n";
        for (auto p : cart->getProducts())
        {
            cout << p->name << " - $" << p->price << endl;
        }
        cout << "Total Price - " << cart->calculateTotal() << endl;
    }
};

// Class to store the cart into database
class ShoppingCartStorage
{
private:
    ShoppingCart *cart;

public:
    ShoppingCartStorage(ShoppingCart *c)
    {
        this->cart = c;
    }

    void storeIntoDatabase()
    {
        cout << "Cart stored into database" << endl;
    }
};

int main()
{
    ShoppingCart *cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 40000));
    cart->addProduct(new Product("Iphone", 59000));

    ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage *store = new ShoppingCartStorage(cart);
    store->storeIntoDatabase();
    return 0;
}