#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

void demoMap() {
    // Creating a map
    map<int, string> m;

    // 1. Insert elements using insert() and []
    m.insert({1, "one"});
    m[2] = "two";

    // 2. Access elements using []
    cout << "Key 1 has value: " << m[1] << endl;

    // 3. Using at()
    cout << "Key 2 has value: " << m.at(2) << endl;

    // 4. Check if a key exists using find()
    if (m.find(3) != m.end()) {
        cout << "Key 3 exists" << endl;
    } else {
        cout << "Key 3 does not exist" << endl;
    }

    // 5. Iterating over a map
    for (auto it : m) {
        cout << it.first << " -> " << it.second << endl;
    }

    // 6. Size of the map
    cout << "Size of map: " << m.size() << endl;

    // 7. Erase a key
    m.erase(1);
    cout << "After erasing key 1, size of map: " << m.size() << endl;

    // 8. Clear the map
    m.clear();
    cout << "Map is empty? " << m.empty() << endl;
}

void demoUnorderedMap() {
    // Creating an unordered_map
    unordered_map<int, string> um;

    // 1. Insert elements using insert() and []
    um.insert({1, "one"});
    um[2] = "two";

    // 2. Access elements using []
    cout << "Key 1 has value: " << um[1] << endl;

    // 3. Using at()
    cout << "Key 2 has value: " << um.at(2) << endl;

    // 4. Check if a key exists using find()
    if (um.find(3) != um.end()) {
        cout << "Key 3 exists" << endl;
    } else {
        cout << "Key 3 does not exist" << endl;
    }

    // 5. Iterating over an unordered_map
    for (auto it : um) {
        cout << it.first << " -> " << it.second << endl;
    }

    // 6. Size of the unordered_map
    cout << "Size of unordered_map: " << um.size() << endl;

    // 7. Erase a key
    um.erase(1);
    cout << "After erasing key 1, size of unordered_map: " << um.size() << endl;

    // 8. Clear the unordered_map
    um.clear();
    cout << "Unordered_map is empty? " << um.empty() << endl;
}

int main() {
    cout << "Map demonstration:" << endl;
    demoMap();

    cout << "\nUnordered Map demonstration:" << endl;
    demoUnorderedMap();

    return 0;
}
