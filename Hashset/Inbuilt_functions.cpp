#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main()
{
    // ==================== CONSTRUCTORS ====================

    // 1. Default constructor
    unordered_set<int> s1;

    // 2. Range constructor
    int arr[] = {1, 2, 3, 4, 5};
    unordered_set<int> s2(arr, arr + 5);

    // 3. Copy constructor
    unordered_set<int> s3(s2);

    // 4. Initializer list
    unordered_set<int> s4 = {10, 20, 30, 40, 50};

    // ==================== CAPACITY FUNCTIONS ====================

    // 5. size() - Returns number of elements
    cout << "Size: " << s4.size() << endl;

    // 6. empty() - Checks if container is empty
    cout << "Is empty: " << s4.empty() << endl;

    // 7. max_size() - Returns maximum possible number of elements
    cout << "Max size: " << s4.max_size() << endl;

    // ==================== MODIFIERS ====================

    // 8. insert() - Inserts element
    s4.insert(60);

    // 9. insert() - Insert range
    int arr2[] = {70, 80, 90};
    s4.insert(arr2, arr2 + 3);

    // 10. insert() - Insert initializer list
    s4.insert({100, 110});

    // 11. emplace() - Constructs element in-place
    s4.emplace(120);

    // 12. emplace_hint() - Constructs element with hint
    auto it = s4.begin();
    s4.emplace_hint(it, 130);

    // 13. erase() - Erase by iterator
    it = s4.find(10);
    if (it != s4.end())
    {
        s4.erase(it);
    }

    // 14. erase() - Erase by value
    s4.erase(20);

    // 15. erase() - Erase range
    // it = s4.begin();
    // auto it2 = s4.begin();
    // advance(it2, 2);
    // s4.erase(it, it2);

    // 16. clear() - Removes all elements
    unordered_set<int> temp = {1, 2, 3};
    temp.clear();

    // 17. swap() - Swaps contents
    unordered_set<int> s5 = {200, 300};
    s5.swap(temp);

    // ==================== LOOKUP/SEARCH FUNCTIONS ====================

    // 18. find() - Finds element with specific key
    it = s4.find(30);
    if (it != s4.end())
    {
        cout << "Element 30 found" << endl;
    }

    // 19. count() - Returns number of elements matching key (0 or 1)
    cout << "Count of 40: " << s4.count(40) << endl;

    // 20. equal_range() - Returns range of elements matching key
    auto range = s4.equal_range(50);

    // 21. contains() - Checks if element exists (C++20)
    // cout << "Contains 60: " << s4.contains(60) << endl;

    // ==================== ITERATORS ====================

    // 22. begin() - Returns iterator to beginning
    it = s4.begin();

    // 23. end() - Returns iterator to end
    auto end_it = s4.end();

    // 24. cbegin() - Returns const iterator to beginning
    auto cit = s4.cbegin();

    // 25. cend() - Returns const iterator to end
    auto cend_it = s4.cend();

    // Iterate through set
    cout << "Elements: ";
    for (auto i = s4.begin(); i != s4.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    // ==================== BUCKET INTERFACE ====================

    // 26. bucket_count() - Returns number of buckets
    cout << "Bucket count: " << s4.bucket_count() << endl;

    // 27. max_bucket_count() - Returns maximum number of buckets
    cout << "Max bucket count: " << s4.max_bucket_count() << endl;

    // 28. bucket_size() - Returns number of elements in specific bucket
    cout << "Bucket 0 size: " << s4.bucket_size(0) << endl;

    // 29. bucket() - Returns bucket number for specific key
    if (s4.find(30) != s4.end())
    {
        cout << "Bucket for 30: " << s4.bucket(30) << endl;
    }

    // ==================== HASH POLICY ====================

    // 30. load_factor() - Returns current load factor
    cout << "Load factor: " << s4.load_factor() << endl;

    // 31. max_load_factor() - Gets/sets maximum load factor
    cout << "Max load factor: " << s4.max_load_factor() << endl;
    s4.max_load_factor(0.8);

    // 32. rehash() - Sets number of buckets
    s4.rehash(20);

    // 33. reserve() - Reserves space for at least specified number of elements
    s4.reserve(100);

    // ==================== OBSERVERS ====================

    // 34. hash_function() - Returns hash function object
    auto hash_fn = s4.hash_function();
    cout << "Hash of 100: " << hash_fn(100) << endl;

    // 35. key_eq() - Returns key equality comparison function
    auto key_eq_fn = s4.key_eq();
    cout << "Keys 100 and 100 equal: " << key_eq_fn(100, 100) << endl;

    // 36. get_allocator() - Returns allocator object
    auto alloc = s4.get_allocator();

    // ==================== NON-MEMBER FUNCTIONS ====================

    // 37. operator== - Compares two unordered_sets for equality
    unordered_set<int> s6 = {1, 2, 3};
    unordered_set<int> s7 = {1, 2, 3};
    cout << "s6 == s7: " << (s6 == s7) << endl;

    // 38. operator!= - Compares two unordered_sets for inequality
    cout << "s6 != s7: " << (s6 != s7) << endl;

    // 39. swap() - Non-member swap
    swap(s6, s7);

    // ==================== ADDITIONAL EXAMPLES ====================

    // Using with different data types
    unordered_set<string> stringSet = {"apple", "banana", "cherry"};
    stringSet.insert("date");

    cout << "\nString set: ";
    for (const auto &str : stringSet)
    {
        cout << str << " ";
    }
    cout << endl;

    // Check and insert
    if (stringSet.find("apple") != stringSet.end())
    {
        cout << "Apple exists in set" << endl;
    }

    // Using count for existence check
    if (stringSet.count("grape") == 0)
    {
        cout << "Grape does not exist" << endl;
    }

    return 0;
}
