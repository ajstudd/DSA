#include <iostream>
#include <list>
#include <vector>
using namespace std;

// Custom HashMap Class
class HashMap
{
private:
    static const int TABLE_SIZE = 10;      // Fixed table size
    vector<list<pair<string, int>>> table; // Array of linked lists

    // Hash Function
    // int hashFunction(const string &key) const
    // {
    //     int hash = 0;
    //     for (char ch : key)
    //     {
    //         hash = (hash + ch) % TABLE_SIZE; // Sum ASCII values and take modulus
    //     }
    //     return hash;
    // }

    // INFO: improved hash function
    int hashFunction(const string &key) const
    {
        const int p = 31; // A prime number chosen as the base of the polynomial hash.
                          // Common choices are small primes like 31 or 37.

        const int m = TABLE_SIZE; // The size of the hash table.
                                  // Ensures the resulting hash value fits within the table range [0, m-1].

        int hash = 0; // Initialize hash value to 0.
                      // This will store the cumulative hash of the string.

        int p_pow = 1; // Initialize p^0 = 1.
                       // This represents powers of p (p^0, p^1, p^2, ...).
                       // It helps in assigning weights to character positions.

        for (char ch : key) // Loop through each character of the string.
        {
            // (ch - 'a' + 1): Converts the character to a numeric value (1 for 'a', 2 for 'b', ..., 26 for 'z').
            // Multiply by the current power of p and add to the hash.
            // Take modulo m to ensure the hash value doesn’t overflow.
            hash = (hash + (ch - 'a' + 1) * p_pow) % m;

            // Update p_pow for the next character. Multiply by p and take modulo m to avoid overflow.
            p_pow = (p_pow * p) % m;
        }

        return hash; // Return the computed hash value for the input string.
    }

public:
    // Constructor
    HashMap() : table(TABLE_SIZE) {}

    // Insert key-value pair
    void insert(const string &key, int value)
    {
        int index = hashFunction(key);
        for (auto &pair : table[index])
        {
            if (pair.first == key)
            { // Key exists, update value
                pair.second = value;
                return;
            }
        }
        table[index].emplace_back(key, value); // Insert new key-value pair
    }

    // Search for a key
    int search(const string &key)
    {
        int index = hashFunction(key);
        for (const auto &pair : table[index])
        {
            if (pair.first == key)
            {
                return pair.second; // Key found, return value
            }
        }
        throw runtime_error("Key not found");
    }

    // Delete a key-value pair
    void erase(const string &key)
    {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it)
        {
            if (it->first == key)
            {
                table[index].erase(it); // Remove the key-value pair
                return;
            }
        }
        cout << "Key not found for deletion!" << endl;
    }

    // Display the HashMap
    void display() const
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            cout << "Bucket " << i << ": ";
            for (const auto &pair : table[i])
            {
                cout << "{" << pair.first << ": " << pair.second << "} ";
            }
            cout << endl;
        }
    }
};

int main()
{
    HashMap hashMap;

    // Insert elements
    hashMap.insert("Alice", 25);
    hashMap.insert("Bob", 30);
    hashMap.insert("Charlie", 35);
    hashMap.insert("Dave", 40);

    // Display the HashMap
    cout << "HashMap Contents:" << endl;
    hashMap.display();

    // Search for an element
    try
    {
        cout << "Bob's age: " << hashMap.search("Bob") << endl;
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }

    // Delete an element
    hashMap.erase("Alice");
    cout << "After deleting Alice:" << endl;
    hashMap.display();

    return 0;
}
