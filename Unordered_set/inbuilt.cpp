#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main()
{

    // ==================== CONSTRUCTORS ====================

    // 1. Default constructor - creates empty unordered_set
    unordered_set<int> s1;

    // 2. Range constructor - from iterators
    int arr[] = {1, 2, 3, 4, 5};
    unordered_set<int> s2(arr, arr + 5);

    // 3. Copy constructor
    unordered_set<int> s3(s2);

    // 4. Initializer list constructor
    unordered_set<int> s4 = {10, 20, 30, 40, 50};

    // 5. Constructor with bucket count
    unordered_set<int> s5(100); // with 100 buckets

    // ==================== CAPACITY FUNCTIONS ====================

    // 1. size() - returns number of elements
    cout << "Size: " << s4.size() << endl;

    // 2. empty() - checks if container is empty
    cout << "Is empty: " << s4.empty() << endl;

    // 3. max_size() - returns maximum possible number of elements
    cout << "Max size: " << s4.max_size() << endl;

    // ==================== MODIFIER FUNCTIONS ====================

    // 1. insert() - inserts element(s)
    s4.insert(60);           // single element
    s4.insert({70, 80, 90}); // initializer list
    int arr2[] = {100, 110};
    s4.insert(arr2, arr2 + 2); // range insert

    // 2. emplace() - constructs element in-place
    s4.emplace(120);

    // 3. emplace_hint() - constructs element with hint
    auto it = s4.begin();
    s4.emplace_hint(it, 130);

    // 4. erase() - removes element(s)
    s4.erase(10);         // erase by value
    s4.erase(s4.begin()); // erase by iterator
    auto it1 = s4.find(30);
    auto it2 = s4.find(50);
    if (it1 != s4.end() && it2 != s4.end())
    {
        s4.erase(it1, it2); // erase range
    }

    // 5. clear() - removes all elements
    unordered_set<int> temp = {1, 2, 3};
    temp.clear();

    // 6. swap() - swaps contents with another unordered_set
    unordered_set<int> s6 = {1, 2, 3};
    unordered_set<int> s7 = {4, 5, 6};
    s6.swap(s7);

    // ==================== LOOKUP FUNCTIONS ====================

    // 1. find() - finds element and returns iterator
    auto findIt = s4.find(60);
    if (findIt != s4.end())
    {
        cout << "Found: " << *findIt << endl;
    }

    // 2. count() - returns count of elements (0 or 1 for unordered_set)
    cout << "Count of 60: " << s4.count(60) << endl;
    cout << "Count of 999: " << s4.count(999) << endl;

    // 3. contains() - checks if element exists (C++20)
    // cout << "Contains 60: " << s4.contains(60) << endl;

    // 4. equal_range() - returns range of elements matching key
    auto range = s4.equal_range(60);
    cout << "Equal range for 60: ";
    for (auto i = range.first; i != range.second; ++i)
    {
        cout << *i << " ";
    }
    cout << endl;

    // ==================== ITERATOR FUNCTIONS ====================

    // 1. begin() - returns iterator to beginning
    auto beginIt = s4.begin();

    // 2. end() - returns iterator to end
    auto endIt = s4.end();

    // 3. cbegin() - returns const iterator to beginning
    auto cbeginIt = s4.cbegin();

    // 4. cend() - returns const iterator to end
    auto cendIt = s4.cend();

    // Iterating through unordered_set
    cout << "Elements in s4: ";
    for (auto it = s4.begin(); it != s4.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Range-based for loop
    cout << "Elements (range-based): ";
    for (const auto &elem : s4)
    {
        cout << elem << " ";
    }
    cout << endl;

    // ==================== BUCKET INTERFACE ====================

    // 1. bucket_count() - returns number of buckets
    cout << "Bucket count: " << s4.bucket_count() << endl;

    // 2. max_bucket_count() - returns maximum number of buckets
    cout << "Max bucket count: " << s4.max_bucket_count() << endl;

    // 3. bucket_size(n) - returns number of elements in bucket n
    cout << "Bucket 0 size: " << s4.bucket_size(0) << endl;

    // 4. bucket(key) - returns bucket number for key
    if (s4.count(60))
    {
        cout << "Bucket for 60: " << s4.bucket(60) << endl;
    }

    // ==================== HASH POLICY ====================

    // 1. load_factor() - returns average number of elements per bucket
    cout << "Load factor: " << s4.load_factor() << endl;

    // 2. max_load_factor() - returns or sets maximum load factor
    cout << "Max load factor: " << s4.max_load_factor() << endl;
    s4.max_load_factor(0.5); // set max load factor

    // 3. rehash(n) - sets number of buckets to n or more
    s4.rehash(50);

    // 4. reserve(n) - reserves space for at least n elements
    s4.reserve(100);

    // ==================== OBSERVERS ====================

    // 1. hash_function() - returns hash function object
    auto hashFn = s4.hash_function();
    cout << "Hash of 60: " << hashFn(60) << endl;

    // 2. key_eq() - returns key equivalence comparison object
    auto keyEq = s4.key_eq();
    cout << "60 == 60: " << keyEq(60, 60) << endl;

    // 3. get_allocator() - returns allocator object
    auto alloc = s4.get_allocator();

    // ==================== BUCKET ITERATORS ====================

    // begin(n) and end(n) - iterators for bucket n
    size_t bucketIdx = s4.bucket(60);
    cout << "Elements in bucket " << bucketIdx << ": ";
    for (auto it = s4.begin(bucketIdx); it != s4.end(bucketIdx); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // cbegin(n) and cend(n) - const iterators for bucket n
    cout << "Elements in bucket " << bucketIdx << " (const): ";
    for (auto it = s4.cbegin(bucketIdx); it != s4.cend(bucketIdx); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // ==================== NON-MEMBER FUNCTIONS ====================

    // 1. operator== and operator!= - comparison operators
    unordered_set<int> s8 = {1, 2, 3};
    unordered_set<int> s9 = {1, 2, 3};
    unordered_set<int> s10 = {4, 5, 6};

    cout << "s8 == s9: " << (s8 == s9) << endl;
    cout << "s8 != s10: " << (s8 != s10) << endl;

    // 2. std::swap() - swaps two unordered_sets
    swap(s8, s10);

    // ==================== EXAMPLE WITH CUSTOM TYPE ====================

    unordered_set<string> stringSet;
    stringSet.insert("apple");
    stringSet.insert("banana");
    stringSet.insert("cherry");

    cout << "\nString set contents: ";
    for (const auto &str : stringSet)
    {
        cout << str << " ";
    }
    cout << endl;

    // ==================== PRACTICAL EXAMPLES ====================

    // Example 1: Remove duplicates from array
    int nums[] = {1, 2, 2, 3, 4, 4, 5};
    unordered_set<int> uniqueNums(nums, nums + 7);
    cout << "\nUnique numbers: ";
    for (int num : uniqueNums)
    {
        cout << num << " ";
    }
    cout << endl;

    // Example 2: Check for duplicates
    unordered_set<int> checker;
    int testArr[] = {1, 2, 3, 4, 5, 3};
    bool hasDuplicate = false;
    for (int num : testArr)
    {
        if (checker.count(num))
        {
            hasDuplicate = true;
            break;
        }
        checker.insert(num);
    }
    cout << "Has duplicate: " << hasDuplicate << endl;

    // Example 3: Fast membership testing
    unordered_set<int> validIds = {101, 102, 103, 104, 105};
    int testId = 103;
    if (validIds.find(testId) != validIds.end())
    {
        cout << "ID " << testId << " is valid" << endl;
    }

    return 0;
}

/*
==================== SUMMARY OF ALL FUNCTIONS ====================

CONSTRUCTORS:
- unordered_set() - default constructor
- unordered_set(first, last) - range constructor
- unordered_set(other) - copy constructor
- unordered_set(il) - initializer list constructor
- unordered_set(n) - constructor with bucket count

CAPACITY:
- size() - number of elements
- empty() - check if empty
- max_size() - maximum possible size

MODIFIERS:
- insert(val) - insert element
- emplace(args) - construct element in-place
- emplace_hint(hint, args) - construct with hint
- erase(key/iterator/range) - remove elements
- clear() - remove all elements
- swap(other) - swap contents

LOOKUP:
- find(key) - find element
- count(key) - count elements (0 or 1)
- contains(key) - check if exists (C++20)
- equal_range(key) - get range of elements

ITERATORS:
- begin() / end() - iterators
- cbegin() / cend() - const iterators

BUCKETS:
- bucket_count() - number of buckets
- max_bucket_count() - max buckets
- bucket_size(n) - elements in bucket n
- bucket(key) - bucket for key
- begin(n) / end(n) - bucket iterators
- cbegin(n) / cend(n) - const bucket iterators

HASH POLICY:
- load_factor() - elements per bucket
- max_load_factor() - get/set max load factor
- rehash(n) - set bucket count
- reserve(n) - reserve space

OBSERVERS:
- hash_function() - get hash function
- key_eq() - get key equality function
- get_allocator() - get allocator

TIME COMPLEXITIES:
- Insert: O(1) average, O(n) worst
- Delete: O(1) average, O(n) worst
- Search: O(1) average, O(n) worst
- Space: O(n)
*/
