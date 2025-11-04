#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    // ==================== CONSTRUCTORS ====================

    // 1. Default constructor
    unordered_map<int, string> m1;

    // 2. Range constructor
    pair<int, string> arr[] = {{1, "one"}, {2, "two"}, {3, "three"}};
    unordered_map<int, string> m2(arr, arr + 3);

    // 3. Copy constructor
    unordered_map<int, string> m3(m2);

    // 4. Initializer list
    unordered_map<int, string> m4 = {{10, "ten"}, {20, "twenty"}, {30, "thirty"}};

    // ==================== CAPACITY FUNCTIONS ====================

    // 5. size() - Returns number of elements
    cout << "Size: " << m4.size() << endl;

    // 6. empty() - Checks if container is empty
    cout << "Is empty: " << m4.empty() << endl;

    // 7. max_size() - Returns maximum possible number of elements
    cout << "Max size: " << m4.max_size() << endl;

    // ==================== ELEMENT ACCESS ====================

    // 8. operator[] - Access or insert element
    m4[40] = "forty";
    cout << "m4[40]: " << m4[40] << endl;

    // 9. at() - Access element with bounds checking
    try
    {
        cout << "m4.at(20): " << m4.at(20) << endl;
        // cout << m4.at(100) << endl; // Would throw out_of_range exception
    }
    catch (const out_of_range &e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    // ==================== MODIFIERS ====================

    // 10. insert() - Insert single element (pair)
    m4.insert({50, "fifty"});

    // 11. insert() - Insert single element (make_pair)
    m4.insert(make_pair(60, "sixty"));

    // 12. insert() - Insert range
    pair<int, string> arr2[] = {{70, "seventy"}, {80, "eighty"}};
    m4.insert(arr2, arr2 + 2);

    // 13. insert() - Insert initializer list
    m4.insert({{90, "ninety"}, {100, "hundred"}});

    // 14. insert() - Insert with hint
    auto it = m4.begin();
    m4.insert(it, {110, "one-ten"});

    // 15. insert_or_assign() - Insert or update element (C++17)
    m4.insert_or_assign(20, "TWENTY");

    // 16. emplace() - Constructs element in-place
    m4.emplace(120, "one-twenty");

    // 17. emplace_hint() - Constructs element with hint
    it = m4.begin();
    m4.emplace_hint(it, 130, "one-thirty");

    // 18. try_emplace() - Insert if key doesn't exist (C++17)
    m4.try_emplace(140, "one-forty");
    m4.try_emplace(140, "WILL NOT INSERT"); // Won't insert as 140 exists

    // 19. erase() - Erase by iterator
    it = m4.find(10);
    if (it != m4.end())
    {
        m4.erase(it);
    }

    // 20. erase() - Erase by key
    m4.erase(20);

    // 21. erase() - Erase range
    // auto it1 = m4.begin();
    // auto it2 = m4.begin();
    // advance(it2, 2);
    // m4.erase(it1, it2);

    // 22. clear() - Removes all elements
    unordered_map<int, string> temp = {{1, "a"}, {2, "b"}};
    temp.clear();

    // 23. swap() - Swaps contents
    unordered_map<int, string> m5 = {{200, "two-hundred"}, {300, "three-hundred"}};
    m5.swap(temp);

    // 24. extract() - Extract node from map (C++17)
    auto node = m4.extract(30);
    if (!node.empty())
    {
        cout << "Extracted key: " << node.key() << ", value: " << node.mapped() << endl;
    }

    // 25. merge() - Merge another map (C++17)
    unordered_map<int, string> m6 = {{150, "one-fifty"}, {160, "one-sixty"}};
    m4.merge(m6);

    // ==================== LOOKUP/SEARCH FUNCTIONS ====================

    // 26. find() - Finds element with specific key
    it = m4.find(40);
    if (it != m4.end())
    {
        cout << "Found key 40: " << it->second << endl;
    }

    // 27. count() - Returns number of elements matching key (0 or 1)
    cout << "Count of key 50: " << m4.count(50) << endl;

    // 28. equal_range() - Returns range of elements matching key
    auto range = m4.equal_range(60);
    if (range.first != range.second)
    {
        cout << "Equal range for 60: " << range.first->second << endl;
    }

    // 29. contains() - Checks if element exists (C++20)
    // cout << "Contains key 70: " << m4.contains(70) << endl;

    // ==================== ITERATORS ====================

    // 30. begin() - Returns iterator to beginning
    it = m4.begin();

    // 31. end() - Returns iterator to end
    auto end_it = m4.end();

    // 32. cbegin() - Returns const iterator to beginning
    auto cit = m4.cbegin();

    // 33. cend() - Returns const iterator to end
    auto cend_it = m4.cend();

    // Iterate through map
    cout << "\nAll elements in map:" << endl;
    for (auto i = m4.begin(); i != m4.end(); i++)
    {
        cout << "Key: " << i->first << ", Value: " << i->second << endl;
    }

    // Range-based for loop
    cout << "\nUsing range-based for loop:" << endl;
    for (const auto &pair : m4)
    {
        cout << pair.first << " => " << pair.second << endl;
    }

    // Structured binding (C++17)
    cout << "\nUsing structured binding:" << endl;
    for (const auto &[key, value] : m4)
    {
        cout << key << " => " << value << endl;
    }

    // ==================== BUCKET INTERFACE ====================

    // 34. bucket_count() - Returns number of buckets
    cout << "\nBucket count: " << m4.bucket_count() << endl;

    // 35. max_bucket_count() - Returns maximum number of buckets
    cout << "Max bucket count: " << m4.max_bucket_count() << endl;

    // 36. bucket_size() - Returns number of elements in specific bucket
    cout << "Bucket 0 size: " << m4.bucket_size(0) << endl;

    // 37. bucket() - Returns bucket number for specific key
    if (m4.find(40) != m4.end())
    {
        cout << "Bucket for key 40: " << m4.bucket(40) << endl;
    }

    // 38. begin(n) - Returns iterator to beginning of bucket n
    size_t bucket_num = 0;
    auto bucket_it = m4.begin(bucket_num);

    // 39. end(n) - Returns iterator to end of bucket n
    auto bucket_end = m4.end(bucket_num);

    // 40. cbegin(n) - Returns const iterator to beginning of bucket n
    auto cbucket_it = m4.cbegin(bucket_num);

    // 41. cend(n) - Returns const iterator to end of bucket n
    auto cbucket_end = m4.cend(bucket_num);

    // ==================== HASH POLICY ====================

    // 42. load_factor() - Returns current load factor
    cout << "Load factor: " << m4.load_factor() << endl;

    // 43. max_load_factor() - Gets/sets maximum load factor
    cout << "Max load factor: " << m4.max_load_factor() << endl;
    m4.max_load_factor(0.75);

    // 44. rehash() - Sets number of buckets
    m4.rehash(20);

    // 45. reserve() - Reserves space for at least specified number of elements
    m4.reserve(100);

    // ==================== OBSERVERS ====================

    // 46. hash_function() - Returns hash function object
    auto hash_fn = m4.hash_function();
    cout << "Hash of key 100: " << hash_fn(100) << endl;

    // 47. key_eq() - Returns key equality comparison function
    auto key_eq_fn = m4.key_eq();
    cout << "Keys 100 and 100 equal: " << key_eq_fn(100, 100) << endl;

    // 48. get_allocator() - Returns allocator object
    auto alloc = m4.get_allocator();

    // ==================== NON-MEMBER FUNCTIONS ====================

    // 49. operator== - Compares two unordered_maps for equality
    unordered_map<int, string> m7 = {{1, "one"}, {2, "two"}};
    unordered_map<int, string> m8 = {{1, "one"}, {2, "two"}};
    cout << "\nm7 == m8: " << (m7 == m8) << endl;

    // 50. operator!= - Compares two unordered_maps for inequality
    cout << "m7 != m8: " << (m7 != m8) << endl;

    // 51. swap() - Non-member swap
    swap(m7, m8);

    // ==================== ADDITIONAL EXAMPLES ====================

    // Using with different data types
    unordered_map<string, int> wordCount = {
        {"apple", 5},
        {"banana", 3},
        {"cherry", 7}};

    // Update existing or insert new
    wordCount["apple"]++;
    wordCount["date"] = 1;

    cout << "\nWord count map:" << endl;
    for (const auto &[word, count] : wordCount)
    {
        cout << word << ": " << count << endl;
    }

    // Check if key exists before accessing
    string key = "grape";
    if (wordCount.find(key) != wordCount.end())
    {
        cout << key << " exists with count: " << wordCount[key] << endl;
    }
    else
    {
        cout << key << " does not exist" << endl;
    }

    // Using count() for existence check (returns 0 or 1)
    if (wordCount.count("banana"))
    {
        cout << "Banana exists" << endl;
    }

    // Nested unordered_map
    unordered_map<string, unordered_map<string, int>> nestedMap = {
        {"fruits", {{"apple", 10}, {"banana", 5}}},
        {"vegetables", {{"carrot", 8}, {"potato", 12}}}};

    cout << "\nNested map - fruits/apple: " << nestedMap["fruits"]["apple"] << endl;

    // Using custom hash function and equality (example structure)
    /*
    struct Point {
        int x, y;
        bool operator==(const Point& other) const {
            return x == other.x && y == other.y;
        }
    };

    struct PointHash {
        size_t operator()(const Point& p) const {
            return hash<int>()(p.x) ^ (hash<int>()(p.y) << 1);
        }
    };

    unordered_map<Point, string, PointHash> pointMap;
    */

    return 0;
}
