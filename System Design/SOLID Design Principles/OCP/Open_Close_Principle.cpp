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

// Abstract
class Percistence
{
private:
    ShoppingCart *cart;

public:
    virtual void save(ShoppingCart *cart) = 0;
};

class SqlPercistence : public Percistence
{
public:
    void save(ShoppingCart *cart) override
    {
        cout << "Saving Cart into SQL Database" << endl;
    }
};

class MongoDBPercistence : public Percistence
{
public:
    void save(ShoppingCart *cart) override
    {
        cout << "Saving Cart into Mongo DB database" << endl;
    }
};

class FilePercistence : public Percistence
{
public:
    void save(ShoppingCart *cart) override
    {
        cout << "Saving cart into File" << endl;
    }
};

int main()
{
    ShoppingCart *cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 40000));
    cart->addProduct(new Product("Iphone", 59000));

    ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    Percistence* db = new SqlPercistence();
    Percistence* mongo = new MongoDBPercistence();
    Percistence* fl = new FilePercistence();

    db->save(cart);
    mongo->save(cart);
    fl->save(cart);

    return 0;
}