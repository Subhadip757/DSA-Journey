#include <iostream>
#include <iomanip>
using namespace std;

class SalesData {
private:
    int unitsSold; 
    float totalRevenue; 

public:
    SalesData(int units, double revenue){
        unitsSold = units;
        totalRevenue = revenue;
    }

    double avg(){
        return totalRevenue/unitsSold;
    }

    void displayData() {
        cout << "Units Sold: " << unitsSold << endl;
        cout << "Revenue Generated: " << fixed << setprecision(2) << totalRevenue << endl;
        cout << "Average Price: " << fixed << setprecision(2) << avg() << endl;
    }
};

int main() {
    double revenue;
    int units;

    // Input total revenue and units sold
    cin >> units >> revenue; 

    SalesData sales(units, revenue);
    sales.displayData();

    return 0;
}