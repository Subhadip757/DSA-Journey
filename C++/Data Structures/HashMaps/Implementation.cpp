#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

template <typename K, typename V>
class HashMap {
private:
    vector<list<pair<K, V>>> table; // Array of buckets containing linked lists
    int numBuckets;                // Total number of buckets
    int size;                      // Number of elements in the hashmap

    int hashFunction(K key) {
        return hash<K>()(key) % numBuckets; // Generate an index using std::hash
    }

public:
    HashMap(int bucketCount = 10) {
        numBuckets = bucketCount;
        table.resize(numBuckets);
        size = 0;
    }

    void insert(K key, V value) {
        int index = hashFunction(key);
        // Check if the key already exists and update the value
        for (auto &pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        // Otherwise, insert the new key-value pair
        table[index].emplace_back(key, value);
        size++;
    }

    void erase(K key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                size--;
                return;
            }
        }
        cout << "Key not found!" << endl;
    }

    V get(K key) {
        int index = hashFunction(key);
        for (auto &pair : table[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        throw runtime_error("Key not found!");
    }

    bool contains(K key) {
        int index = hashFunction(key);
        for (auto &pair : table[index]) {
            if (pair.first == key) {
                return true;
            }
        }
        return false;
    }

    int getSize() {
        return size;
    }

    void print() {
        for (int i = 0; i < numBuckets; i++) {
            cout << "Bucket " << i << ": ";
            for (auto &pair : table[i]) {
                cout << "{" << pair.first << ": " << pair.second << "} ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap<string, int> myHashMap(5);

    // Insert key-value pairs
    myHashMap.insert("Alice", 25);
    myHashMap.insert("Bob", 30);
    myHashMap.insert("Charlie", 35);

    // Print the hashmap
    cout << "Initial HashMap:" << endl;
    myHashMap.print();

    // Get value for a key
    cout << "\nValue for 'Bob': " << myHashMap.get("Bob") << endl;

    // Check if a key exists
    cout << "\nContains 'Alice'? " << (myHashMap.contains("Alice") ? "Yes" : "No") << endl;

    // Remove a key
    myHashMap.erase("Alice");
    cout << "\nAfter removing 'Alice':" << endl;
    myHashMap.print();

    // Try to access a non-existent key
    try {
        myHashMap.get("Alice");
    } catch (runtime_error &e) {
        cout << "\nException: " << e.what() << endl;
    }

    return 0;
}