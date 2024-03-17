#include<iostream>
using namespace std;

int main() {
    int total = 1330;
    int hundredNeeded = 0;
    int fiftyNeeded = 0;
    int twentyNeeded = 0;
    int oneNeeded = 0;
    int needNotes;
    cin >> needNotes;

    // Calculate the number of each denomination of notes
    switch (needNotes) {
        case 100:
            hundredNeeded = total / 100;
            total %= 100;
        case 50:
            fiftyNeeded = total / 50;
            total %= 50;
        case 20:
            twentyNeeded = total / 20;
            total %= 20;
        case 1:
            oneNeeded = total;
            break;
        default:
            cout << "Invalid input";
            break;
    }

    // Output the number of each denomination of notes
    cout << "Hundred notes needed: " << hundredNeeded << endl;
    cout << "Fifty notes needed: " << fiftyNeeded << endl;
    cout << "Twenty notes needed: " << twentyNeeded << endl;
    cout << "One notes needed: " << oneNeeded << endl;

    return 0;
}
