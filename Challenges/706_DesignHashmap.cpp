#include <iostream>
#include <vector>
#include <list>

class MyHashMap
{
private:
    static const int TABLE_SIZE = 10000; // Size of the table
    // Size of the table becomes important as small table will have more collision( more element having same hash )
    // and larger tables will have more unused memory
    std::vector<std::list<std::pair<int, int>>> table; // Array of lists to store key-value pairs

    // Hash function to get the index in the array
    int hash(int key)
    {
        return key % TABLE_SIZE;
    }

public:
    // Constructor
    MyHashMap() : table(TABLE_SIZE) {}

    // Insert or update key-value pair
    void put(int key, int value)
    {
        int index = hash(key);
        for (auto &pair : table[index])
        {
            if (pair.first == key)
            {
                pair.second = value; // Update value if key already exists
                return;
            }
        }
        table[index].push_back({key, value}); // Insert new key-value pair
    }

    // Get the value for the given key, or return -1 if the key doesn't exist
    int get(int key)
    {
        int index = hash(key);
        for (auto &pair : table[index])
        {
            if (pair.first == key)
            {
                return pair.second; // Key found, return value
            }
        }
        return -1; // Key not found
    }

    // Remove the key-value pair with the given key
    void remove(int key)
    {
        int index = hash(key);
        auto &list = table[index];
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            if (it->first == key)
            {
                list.erase(it); // Remove the pair from the list
                return;
            }
        }
    }
};

/**
 * Example usage:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key, value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
