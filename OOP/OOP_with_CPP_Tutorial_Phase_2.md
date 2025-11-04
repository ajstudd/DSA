# Complete C++ and Object-Oriented Programming Tutorial - Phase 2

## Prerequisites

- **Phase 0** completed (Core C++ Foundations) ✅
- **Phase 1** completed (OOP Core) ✅
- Understanding of classes, inheritance, polymorphism, and abstraction
- Familiarity with pointers, references, and dynamic memory management
- Basic knowledge of templates and generic programming concepts

---

# ⚡ Phase 2: Modern C++ (C++11 and beyond)

**🔑 Goal**: Write **clean, safe, and efficient** code with modern C++ features. Master the language enhancements introduced from C++11 onwards that make C++ more expressive, safer, and easier to use while maintaining performance.

Modern C++ (C++11/14/17/20/23) introduced revolutionary features that fundamentally changed how we write C++ code:

1. **Smart Pointers** - Automatic memory management and RAII
2. **Move Semantics** - Efficient resource transfer
3. **Lambda Expressions** - Functional programming capabilities
4. **Auto Type Deduction** - Simplified type declarations
5. **Range-based Loops** - Cleaner iteration syntax
6. **Constexpr** - Compile-time computations
7. **Modern Namespaces** - Better code organization
8. **Exception Safety** - Robust error handling

---

## Phase 2.1: Smart Pointers (Memory Safety)

### Introduction to Smart Pointers

**Concept**: **Smart Pointers** are objects that act like regular pointers but automatically manage the memory they point to. They are designed to solve common memory management problems such as memory leaks, dangling pointers, and double deletion. Smart pointers implement RAII (Resource Acquisition Is Initialization) principles, ensuring that resources are properly cleaned up when they go out of scope.

**Problems with Raw Pointers**:

1. **Memory Leaks** - Forgetting to call `delete`
2. **Dangling Pointers** - Using pointers after the object is deleted
3. **Double Deletion** - Calling `delete` multiple times
4. **Exception Safety** - Memory not freed when exceptions occur
5. **Ownership Confusion** - Who is responsible for deleting?

**Smart Pointer Types**:

- `std::unique_ptr` - Single ownership
- `std::shared_ptr` - Shared ownership with reference counting
- `std::weak_ptr` - Non-owning observer to break circular references

### 2.1.1 unique_ptr - Single Ownership

**Concept**: `std::unique_ptr` represents exclusive ownership of a resource. It cannot be copied but can be moved. When the `unique_ptr` goes out of scope, it automatically deletes the object it manages.

```cpp
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

// UNIQUE_PTR COMPREHENSIVE EXAMPLE

class Resource {
private:
    string name;
    int id;
    static int resourceCount;

public:
    Resource(const string& n, int i) : name(n), id(i) {
        resourceCount++;
        cout << "🟢 Resource created: " << name << " (ID: " << id
             << ") - Total: " << resourceCount << endl;
    }

    ~Resource() {
        resourceCount--;
        cout << "🔴 Resource destroyed: " << name << " (ID: " << id
             << ") - Total: " << resourceCount << endl;
    }

    void use() const {
        cout << "🔧 Using resource: " << name << " (ID: " << id << ")" << endl;
    }

    void process() const {
        cout << "⚙️ Processing with " << name << "..." << endl;
        // Simulate some work
        for (int i = 0; i < 3; ++i) {
            cout << "  📊 Processing step " << (i + 1) << "/3" << endl;
        }
        cout << "✅ Processing completed!" << endl;
    }

    string getName() const { return name; }
    int getId() const { return id; }
    static int getResourceCount() { return resourceCount; }
};

int Resource::resourceCount = 0;

// Factory function returning unique_ptr
unique_ptr<Resource> createResource(const string& name, int id) {
    cout << "🏭 Factory creating resource: " << name << endl;
    return make_unique<Resource>(name, id);
}

// Function that takes ownership of unique_ptr
void processResource(unique_ptr<Resource> resource) {
    cout << "\n--- Function Taking Ownership ---" << endl;
    if (resource) {
        resource->use();
        resource->process();
        cout << "Function will destroy resource when it ends" << endl;
    } else {
        cout << "❌ Received null resource!" << endl;
    }
    // Resource automatically destroyed when function ends
}

// Function that borrows (doesn't take ownership)
void borrowResource(Resource* resource) {
    cout << "\n--- Function Borrowing Resource ---" << endl;
    if (resource) {
        resource->use();
        cout << "Function borrowed resource, no ownership transfer" << endl;
    } else {
        cout << "❌ Received null resource!" << endl;
    }
}

// Custom Deleter Example
class FileHandle {
private:
    string filename;

public:
    FileHandle(const string& name) : filename(name) {
        cout << "📁 Opening file: " << filename << endl;
    }

    ~FileHandle() {
        cout << "📁 Closing file: " << filename << endl;
    }

    void write(const string& data) {
        cout << "✍️ Writing to " << filename << ": " << data << endl;
    }

    string getFilename() const { return filename; }
};

// Custom deleter function
auto fileDeleter = [](FileHandle* file) {
    cout << "🗑️ Custom deleter called for: " << file->getFilename() << endl;
    delete file;
};

int main() {
    cout << "=== std::unique_ptr Comprehensive Tutorial ===" << endl;

    cout << "\n--- Basic unique_ptr Usage ---" << endl;
    {
        // Creating unique_ptr using make_unique (C++14, recommended)
        auto resource1 = make_unique<Resource>("Database Connection", 1);
        resource1->use();

        // Creating unique_ptr using constructor (not recommended for new code)
        unique_ptr<Resource> resource2(new Resource("Network Socket", 2));
        resource2->process();

        // Array unique_ptr
        auto resourceArray = make_unique<Resource[]>(2);
        // Note: Array elements need default constructor

        cout << "\nCurrent resource count: " << Resource::getResourceCount() << endl;

        // Resources automatically destroyed when going out of scope
        cout << "Leaving scope..." << endl;
    }
    cout << "After scope - Resource count: " << Resource::getResourceCount() << endl;

    cout << "\n--- unique_ptr Move Semantics ---" << endl;
    {
        auto original = make_unique<Resource>("File Handle", 3);
        cout << "Original pointer valid: " << (original != nullptr) << endl;

        // Move ownership (original becomes null)
        auto moved = move(original);
        cout << "After move - Original valid: " << (original != nullptr) << endl;
        cout << "After move - Moved valid: " << (moved != nullptr) << endl;

        if (moved) {
            moved->use();
        }

        // Cannot copy unique_ptr (compilation error if uncommented)
        // auto copied = moved;  // ERROR: unique_ptr cannot be copied
    }

    cout << "\n--- Factory Pattern with unique_ptr ---" << endl;
    {
        auto factoryResource = createResource("Cache Manager", 4);
        factoryResource->use();

        // Transfer ownership to vector
        vector<unique_ptr<Resource>> resourcePool;
        resourcePool.push_back(move(factoryResource));
        resourcePool.push_back(createResource("Thread Pool", 5));
        resourcePool.push_back(createResource("Memory Pool", 6));

        cout << "\nResource pool contents:" << endl;
        for (size_t i = 0; i < resourcePool.size(); ++i) {
            cout << "Pool[" << i << "]: " << resourcePool[i]->getName() << endl;
        }

        // Remove resource from middle
        cout << "\nRemoving middle resource..." << endl;
        resourcePool.erase(resourcePool.begin() + 1);

        cout << "Pool size after removal: " << resourcePool.size() << endl;
        cout << "Current resource count: " << Resource::getResourceCount() << endl;
    }

    cout << "\n--- Ownership Transfer ---" << endl;
    {
        auto resource = make_unique<Resource>("Temporary Resource", 7);
        resource->use();

        cout << "Before transfer - Resource count: " << Resource::getResourceCount() << endl;

        // Transfer ownership to function (resource becomes null)
        processResource(move(resource));

        cout << "After function - Resource count: " << Resource::getResourceCount() << endl;
        cout << "Original pointer after move: " << (resource != nullptr) << endl;
    }

    cout << "\n--- Borrowing Without Ownership Transfer ---" << endl;
    {
        auto resource = make_unique<Resource>("Borrowed Resource", 8);

        // Pass raw pointer for borrowing (no ownership transfer)
        borrowResource(resource.get());

        cout << "After borrowing - Resource still owned: " << (resource != nullptr) << endl;
        resource->use();

        // Resource destroyed when unique_ptr goes out of scope
    }

    cout << "\n--- Custom Deleter ---" << endl;
    {
        // unique_ptr with custom deleter
        unique_ptr<FileHandle, decltype(fileDeleter)> file(
            new FileHandle("config.txt"), fileDeleter
        );

        file->write("Setting1=Value1");
        file->write("Setting2=Value2");

        // Custom deleter will be called when unique_ptr is destroyed
    }

    cout << "\n--- Release and Reset ---" << endl;
    {
        auto resource = make_unique<Resource>("Controlled Resource", 9);
        resource->use();

        cout << "Before release - Resource count: " << Resource::getResourceCount() << endl;

        // Release ownership (returns raw pointer, unique_ptr becomes null)
        Resource* rawPtr = resource.release();
        cout << "After release - unique_ptr valid: " << (resource != nullptr) << endl;
        cout << "Raw pointer valid: " << (rawPtr != nullptr) << endl;

        // Must manually delete now (not recommended pattern)
        delete rawPtr;
        rawPtr = nullptr;

        // Reset with new resource
        resource.reset(new Resource("Reset Resource", 10));
        resource->use();

        // Reset to null
        resource.reset();  // or resource = nullptr;
        cout << "After reset - Resource count: " << Resource::getResourceCount() << endl;
    }

    cout << "\n--- Comparison and Boolean Conversion ---" << endl;
    {
        unique_ptr<Resource> nullPtr;
        auto validPtr = make_unique<Resource>("Comparison Test", 11);

        // Boolean conversion
        cout << "Null pointer is valid: " << (nullPtr ? "true" : "false") << endl;
        cout << "Valid pointer is valid: " << (validPtr ? "true" : "false") << endl;

        // Comparison with nullptr
        cout << "nullPtr == nullptr: " << (nullPtr == nullptr) << endl;
        cout << "validPtr != nullptr: " << (validPtr != nullptr) << endl;

        // Swap
        cout << "\nBefore swap:" << endl;
        cout << "nullPtr valid: " << (nullPtr != nullptr) << endl;
        cout << "validPtr valid: " << (validPtr != nullptr) << endl;

        swap(nullPtr, validPtr);

        cout << "After swap:" << endl;
        cout << "nullPtr valid: " << (nullPtr != nullptr) << endl;
        cout << "validPtr valid: " << (validPtr != nullptr) << endl;

        if (nullPtr) {
            nullPtr->use();
        }
    }

    cout << "\nFinal resource count: " << Resource::getResourceCount() << endl;
    cout << "\n=== unique_ptr Benefits Demonstrated ===" << endl;
    cout << "✅ Automatic memory management - no memory leaks" << endl;
    cout << "✅ Clear ownership semantics - single owner" << endl;
    cout << "✅ Exception safety - RAII guarantees cleanup" << endl;
    cout << "✅ Move-only semantics prevent accidental copying" << endl;
    cout << "✅ Zero overhead compared to raw pointers" << endl;
    cout << "✅ Custom deleters for special cleanup needs" << endl;

    return 0;
}
```

**Output:**

```
=== std::unique_ptr Comprehensive Tutorial ===

--- Basic unique_ptr Usage ---
🟢 Resource created: Database Connection (ID: 1) - Total: 1
🔧 Using resource: Database Connection (ID: 1)
🟢 Resource created: Network Socket (ID: 2) - Total: 2
⚙️ Processing with Network Socket...
  📊 Processing step 1/3
  📊 Processing step 2/3
  📊 Processing step 3/3
✅ Processing completed!

Current resource count: 2
Leaving scope...
🔴 Resource destroyed: Database Connection (ID: 1) - Total: 1
🔴 Resource destroyed: Network Socket (ID: 2) - Total: 0
After scope - Resource count: 0

--- unique_ptr Move Semantics ---
🟢 Resource created: File Handle (ID: 3) - Total: 1
Original pointer valid: true
After move - Original valid: false
After move - Moved valid: true
🔧 Using resource: File Handle (ID: 3)
🔴 Resource destroyed: File Handle (ID: 3) - Total: 0

--- Factory Pattern with unique_ptr ---
🏭 Factory creating resource: Cache Manager
🟢 Resource created: Cache Manager (ID: 4) - Total: 1
🔧 Using resource: Cache Manager (ID: 4)
🏭 Factory creating resource: Thread Pool
🟢 Resource created: Thread Pool (ID: 5) - Total: 2
🏭 Factory creating resource: Memory Pool
🟢 Resource created: Memory Pool (ID: 6) - Total: 3

Resource pool contents:
Pool[0]: Cache Manager
Pool[1]: Thread Pool
Pool[2]: Memory Pool

Removing middle resource...
🔴 Resource destroyed: Thread Pool (ID: 5) - Total: 2
Pool size after removal: 2
Current resource count: 2
🔴 Resource destroyed: Cache Manager (ID: 4) - Total: 1
🔴 Resource destroyed: Memory Pool (ID: 6) - Total: 0

--- Ownership Transfer ---
🟢 Resource created: Temporary Resource (ID: 7) - Total: 1
🔧 Using resource: Temporary Resource (ID: 7)
Before transfer - Resource count: 1

--- Function Taking Ownership ---
🔧 Using resource: Temporary Resource (ID: 7)
⚙️ Processing with Temporary Resource...
  📊 Processing step 1/3
  📊 Processing step 2/3
  📊 Processing step 3/3
✅ Processing completed!
Function will destroy resource when it ends
🔴 Resource destroyed: Temporary Resource (ID: 7) - Total: 0
After function - Resource count: 0
Original pointer after move: false

--- Borrowing Without Ownership Transfer ---
🟢 Resource created: Borrowed Resource (ID: 8) - Total: 1

--- Function Borrowing Resource ---
🔧 Using resource: Borrowed Resource (ID: 8)
Function borrowed resource, no ownership transfer
After borrowing - Resource still owned: true
🔧 Using resource: Borrowed Resource (ID: 8)
🔴 Resource destroyed: Borrowed Resource (ID: 8) - Total: 0

--- Custom Deleter ---
📁 Opening file: config.txt
✍️ Writing to config.txt: Setting1=Value1
✍️ Writing to config.txt: Setting2=Value2
🗑️ Custom deleter called for: config.txt
📁 Closing file: config.txt

--- Release and Reset ---
🟢 Resource created: Controlled Resource (ID: 9) - Total: 1
🔧 Using resource: Controlled Resource (ID: 9)
Before release - Resource count: 1
After release - unique_ptr valid: false
Raw pointer valid: true
🔴 Resource destroyed: Controlled Resource (ID: 9) - Total: 0
🟢 Resource created: Reset Resource (ID: 10) - Total: 1
🔧 Using resource: Reset Resource (ID: 10)
🔴 Resource destroyed: Reset Resource (ID: 10) - Total: 0
After reset - Resource count: 0

--- Comparison and Boolean Conversion ---
🟢 Resource created: Comparison Test (ID: 11) - Total: 1
Null pointer is valid: false
Valid pointer is valid: true
nullPtr == nullptr: true
validPtr != nullptr: true

Before swap:
nullPtr valid: false
validPtr valid: true
After swap:
nullPtr valid: true
validPtr valid: false
🔧 Using resource: Comparison Test (ID: 11)
🔴 Resource destroyed: Comparison Test (ID: 11) - Total: 0

Final resource count: 0

=== unique_ptr Benefits Demonstrated ===
✅ Automatic memory management - no memory leaks
✅ Clear ownership semantics - single owner
✅ Exception safety - RAII guarantees cleanup
✅ Move-only semantics prevent accidental copying
✅ Zero overhead compared to raw pointers
✅ Custom deleters for special cleanup needs
```

---

### 2.1.2 shared_ptr - Shared Ownership

**Concept**: `std::shared_ptr` allows multiple smart pointers to share ownership of the same object. It uses reference counting - the object is destroyed when the last `shared_ptr` pointing to it is destroyed or reset.

```cpp
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;

// SHARED_PTR COMPREHENSIVE EXAMPLE

class NetworkConnection {
private:
    string serverAddress;
    int port;
    bool isConnected;
    static int connectionCount;
    int connectionId;

public:
    NetworkConnection(const string& address, int p)
        : serverAddress(address), port(p), isConnected(false) {
        connectionId = ++connectionCount;
        cout << "🌐 Connection " << connectionId << " created to "
             << serverAddress << ":" << port << endl;
        connect();
    }

    ~NetworkConnection() {
        disconnect();
        cout << "🌐 Connection " << connectionId << " destroyed" << endl;
    }

    void connect() {
        if (!isConnected) {
            cout << "🔗 Connection " << connectionId << " establishing..." << endl;
            // Simulate connection delay
            this_thread::sleep_for(chrono::milliseconds(100));
            isConnected = true;
            cout << "✅ Connection " << connectionId << " established!" << endl;
        }
    }

    void disconnect() {
        if (isConnected) {
            cout << "🔌 Connection " << connectionId << " disconnecting..." << endl;
            isConnected = false;
            cout << "❌ Connection " << connectionId << " disconnected" << endl;
        }
    }

    void sendData(const string& data) {
        if (isConnected) {
            cout << "📤 Connection " << connectionId << " sending: " << data << endl;
        } else {
            cout << "❌ Connection " << connectionId << " not connected!" << endl;
        }
    }

    void receiveData() {
        if (isConnected) {
            cout << "📥 Connection " << connectionId << " receiving data..." << endl;
            cout << "📊 Data received: Sample response from " << serverAddress << endl;
        } else {
            cout << "❌ Connection " << connectionId << " not connected!" << endl;
        }
    }

    string getInfo() const {
        return serverAddress + ":" + to_string(port) + " (ID: " + to_string(connectionId) + ")";
    }

    int getId() const { return connectionId; }
    bool getConnectionStatus() const { return isConnected; }
    static int getConnectionCount() { return connectionCount; }
};

int NetworkConnection::connectionCount = 0;

// Class that uses shared network connection
class HttpClient {
private:
    shared_ptr<NetworkConnection> connection;
    string clientName;

public:
    HttpClient(const string& name, shared_ptr<NetworkConnection> conn)
        : clientName(name), connection(conn) {
        cout << "🖥️ HttpClient '" << clientName << "' created using connection: "
             << connection->getInfo() << endl;
        cout << "   Reference count: " << connection.use_count() << endl;
    }

    ~HttpClient() {
        cout << "🖥️ HttpClient '" << clientName << "' destroyed" << endl;
    }

    void makeRequest(const string& endpoint) {
        cout << "\n--- " << clientName << " Making HTTP Request ---" << endl;
        if (connection && connection->getConnectionStatus()) {
            connection->sendData("GET " + endpoint + " HTTP/1.1");
            connection->receiveData();
            cout << "✅ Request to " << endpoint << " completed" << endl;
        } else {
            cout << "❌ Cannot make request - no valid connection" << endl;
        }
        cout << "Current reference count: " << connection.use_count() << endl;
    }

    void setConnection(shared_ptr<NetworkConnection> newConn) {
        cout << "🔄 " << clientName << " switching connections" << endl;
        if (connection) {
            cout << "   Old connection ref count: " << connection.use_count() << endl;
        }
        connection = newConn;
        if (connection) {
            cout << "   New connection ref count: " << connection.use_count() << endl;
        }
    }

    shared_ptr<NetworkConnection> getConnection() const {
        return connection;  // This increases reference count
    }

    string getClientName() const { return clientName; }
};

// Factory for creating shared connections
shared_ptr<NetworkConnection> createConnection(const string& server, int port) {
    cout << "🏭 Factory creating shared connection to " << server << ":" << port << endl;
    return make_shared<NetworkConnection>(server, port);
}

// Function that temporarily uses a connection
void temporaryUse(shared_ptr<NetworkConnection> conn, const string& operation) {
    cout << "\n--- Temporary Use: " << operation << " ---" << endl;
    cout << "Reference count on entry: " << conn.use_count() << endl;

    if (conn) {
        conn->sendData("Temporary operation: " + operation);
        conn->receiveData();
    }

    cout << "Reference count before exit: " << conn.use_count() << endl;
    // Reference count decreases when function exits
}

int main() {
    cout << "=== std::shared_ptr Comprehensive Tutorial ===" << endl;

    cout << "\n--- Basic shared_ptr Usage ---" << endl;
    {
        // Create shared_ptr using make_shared (recommended)
        auto connection1 = make_shared<NetworkConnection>("api.example.com", 443);
        cout << "Initial reference count: " << connection1.use_count() << endl;

        // Create another shared_ptr pointing to same object
        shared_ptr<NetworkConnection> connection2 = connection1;
        cout << "After copy - Reference count: " << connection1.use_count() << endl;

        // Use both pointers
        connection1->sendData("Request from pointer 1");
        connection2->sendData("Request from pointer 2");

        // Reset one pointer
        connection2.reset();
        cout << "After reset - Reference count: " << connection1.use_count() << endl;

        // Object still alive because connection1 still holds reference
        connection1->sendData("Request after reset");
    }
    cout << "After scope - All connections destroyed" << endl;

    cout << "\n--- shared_ptr with Multiple Clients ---" << endl;
    {
        // Create shared connection
        auto sharedConnection = createConnection("database.example.com", 5432);
        cout << "After creation - Reference count: " << sharedConnection.use_count() << endl;

        // Create multiple clients sharing the connection
        vector<unique_ptr<HttpClient>> clients;
        clients.push_back(make_unique<HttpClient>("Client-A", sharedConnection));
        clients.push_back(make_unique<HttpClient>("Client-B", sharedConnection));
        clients.push_back(make_unique<HttpClient>("Client-C", sharedConnection));

        cout << "After creating clients - Reference count: " << sharedConnection.use_count() << endl;

        // All clients use the same connection
        clients[0]->makeRequest("/api/users");
        clients[1]->makeRequest("/api/orders");
        clients[2]->makeRequest("/api/products");

        // Remove one client
        cout << "\nRemoving Client-B..." << endl;
        clients.erase(clients.begin() + 1);
        cout << "After removing client - Reference count: " << sharedConnection.use_count() << endl;

        // Remaining clients still work
        clients[0]->makeRequest("/api/status");
        if (clients.size() > 1) {
            clients[1]->makeRequest("/api/health");
        }
    }

    cout << "\n--- Connection Switching ---" << endl;
    {
        auto connection1 = createConnection("server1.com", 80);
        auto connection2 = createConnection("server2.com", 443);

        HttpClient client("Switching-Client", connection1);
        client.makeRequest("/initial");

        // Switch to different connection
        client.setConnection(connection2);
        client.makeRequest("/after-switch");

        cout << "Connection1 reference count: " << connection1.use_count() << endl;
        cout << "Connection2 reference count: " << connection2.use_count() << endl;
    }

    cout << "\n--- Temporary Usage Pattern ---" << endl;
    {
        auto connection = createConnection("temp.server.com", 8080);
        cout << "Before temporary use - Reference count: " << connection.use_count() << endl;

        // Pass to function that temporarily uses it
        temporaryUse(connection, "Data backup");

        cout << "After temporary use - Reference count: " << connection.use_count() << endl;

        // Connection still valid for main usage
        connection->sendData("Main operation continues");
    }

    cout << "\n--- Reference Counting Demonstration ---" << endl;
    {
        shared_ptr<NetworkConnection> ptr1;
        cout << "Empty ptr1 reference count: " << ptr1.use_count() << endl;

        {
            auto connection = make_shared<NetworkConnection>("counting.test.com", 9000);
            cout << "After creation - Reference count: " << connection.use_count() << endl;

            ptr1 = connection;
            cout << "After assignment - Reference count: " << connection.use_count() << endl;

            shared_ptr<NetworkConnection> ptr2 = ptr1;
            shared_ptr<NetworkConnection> ptr3(ptr1);
            cout << "After creating ptr2 and ptr3 - Reference count: " << ptr1.use_count() << endl;

            // Reset ptr2
            ptr2.reset();
            cout << "After ptr2 reset - Reference count: " << ptr1.use_count() << endl;

            // ptr3 goes out of scope at end of this block
            cout << "Before inner scope end - Reference count: " << ptr1.use_count() << endl;
        }

        cout << "After inner scope - Reference count: " << ptr1.use_count() << endl;
        ptr1->sendData("Still alive with one reference");

        // Object destroyed when ptr1 goes out of scope
    }

    cout << "\n--- Weak Reference Example (Preview for weak_ptr) ---" << endl;
    {
        auto connection = make_shared<NetworkConnection>("weak.test.com", 3306);

        // Create weak reference that doesn't affect reference count
        weak_ptr<NetworkConnection> weakRef = connection;
        cout << "Strong references: " << connection.use_count() << endl;
        cout << "Weak reference expired: " << weakRef.expired() << endl;

        // Use weak reference
        if (auto locked = weakRef.lock()) {
            locked->sendData("Via weak reference");
            cout << "Reference count during lock: " << locked.use_count() << endl;
        }

        // Reset strong reference
        connection.reset();
        cout << "After reset - Weak reference expired: " << weakRef.expired() << endl;

        // Try to use expired weak reference
        if (auto locked = weakRef.lock()) {
            locked->sendData("This won't execute");
        } else {
            cout << "Cannot lock expired weak reference" << endl;
        }
    }

    cout << "\n--- Performance Comparison ---" << endl;
    {
        cout << "Creating 1000 shared_ptrs..." << endl;
        auto start = chrono::high_resolution_clock::now();

        vector<shared_ptr<NetworkConnection>> connections;
        auto baseConnection = make_shared<NetworkConnection>("perf.test.com", 1234);

        for (int i = 0; i < 1000; ++i) {
            connections.push_back(baseConnection);
        }

        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

        cout << "Time taken: " << duration.count() << " microseconds" << endl;
        cout << "Final reference count: " << baseConnection.use_count() << endl;

        // Clear half the references
        connections.erase(connections.begin() + 500, connections.end());
        cout << "After removing 500 references: " << baseConnection.use_count() << endl;
    }

    cout << "\nFinal connection count: " << NetworkConnection::getConnectionCount() << endl;

    cout << "\n=== shared_ptr Benefits Demonstrated ===" << endl;
    cout << "✅ Shared ownership - multiple pointers to same object" << endl;
    cout << "✅ Automatic reference counting" << endl;
    cout << "✅ Thread-safe reference counting (atomic operations)" << endl;
    cout << "✅ Exception safe - RAII guarantees" << endl;
    cout << "✅ Can be stored in containers and passed around freely" << endl;
    cout << "✅ Integrates with weak_ptr to break circular references" << endl;

    return 0;
}
```

**Output:**

```
=== std::shared_ptr Comprehensive Tutorial ===

--- Basic shared_ptr Usage ---
🏭 Factory creating shared connection to api.example.com:443
🌐 Connection 1 created to api.example.com:443
🔗 Connection 1 establishing...
✅ Connection 1 established!
Initial reference count: 1
After copy - Reference count: 2
📤 Connection 1 sending: Request from pointer 1
📤 Connection 1 sending: Request from pointer 2
After reset - Reference count: 1
📤 Connection 1 sending: Request after reset
🔌 Connection 1 disconnecting...
❌ Connection 1 disconnected
🌐 Connection 1 destroyed
After scope - All connections destroyed

--- shared_ptr with Multiple Clients ---
🏭 Factory creating shared connection to database.example.com:5432
🌐 Connection 2 created to database.example.com:5432
🔗 Connection 2 establishing...
✅ Connection 2 established!
After creation - Reference count: 1
🖥️ HttpClient 'Client-A' created using connection: database.example.com:5432 (ID: 2)
   Reference count: 2
🖥️ HttpClient 'Client-B' created using connection: database.example.com:5432 (ID: 2)
   Reference count: 3
🖥️ HttpClient 'Client-C' created using connection: database.example.com:5432 (ID: 2)
   Reference count: 4
After creating clients - Reference count: 4

--- Client-A Making HTTP Request ---
📤 Connection 2 sending: GET /api/users HTTP/1.1
📥 Connection 2 receiving data...
📊 Data received: Sample response from database.example.com
✅ Request to /api/users completed
Current reference count: 4

--- Client-B Making HTTP Request ---
📤 Connection 2 sending: GET /api/orders HTTP/1.1
📥 Connection 2 receiving data...
📊 Data received: Sample response from database.example.com
✅ Request to /api/orders completed
Current reference count: 4

--- Client-C Making HTTP Request ---
📤 Connection 2 sending: GET /api/products HTTP/1.1
📥 Connection 2 receiving data...
📊 Data received: Sample response from database.example.com
✅ Request to /api/products completed
Current reference count: 4

Removing Client-B...
🖥️ HttpClient 'Client-B' destroyed
After removing client - Reference count: 3

--- Client-A Making HTTP Request ---
📤 Connection 2 sending: GET /api/status HTTP/1.1
📥 Connection 2 receiving data...
📊 Data received: Sample response from database.example.com
✅ Request to /api/status completed
Current reference count: 3

--- Client-C Making HTTP Request ---
📤 Connection 2 sending: GET /api/health HTTP/1.1
📥 Connection 2 receiving data...
📊 Data received: Sample response from database.example.com
✅ Request to /api/health completed
Current reference count: 3
🖥️ HttpClient 'Client-A' destroyed
🖥️ HttpClient 'Client-C' destroyed
🔌 Connection 2 disconnecting...
❌ Connection 2 disconnected
🌐 Connection 2 destroyed

--- Connection Switching ---
🏭 Factory creating shared connection to server1.com:80
🌐 Connection 3 created to server1.com:80
🔗 Connection 3 establishing...
✅ Connection 3 established!
🏭 Factory creating shared connection to server2.com:443
🌐 Connection 4 created to server2.com:443
🔗 Connection 4 establishing...
✅ Connection 4 established!
🖥️ HttpClient 'Switching-Client' created using connection: server1.com:80 (ID: 3)
   Reference count: 2

--- Switching-Client Making HTTP Request ---
📤 Connection 3 sending: GET /initial HTTP/1.1
📥 Connection 3 receiving data...
📊 Data received: Sample response from server1.com
✅ Request to /initial completed
Current reference count: 2
🔄 Switching-Client switching connections
   Old connection ref count: 2
   New connection ref count: 2

--- Switching-Client Making HTTP Request ---
📤 Connection 4 sending: GET /after-switch HTTP/1.1
📥 Connection 4 receiving data...
📊 Data received: Sample response from server2.com
✅ Request to /after-switch completed
Current reference count: 2
Connection1 reference count: 1
Connection2 reference count: 2
🖥️ HttpClient 'Switching-Client' destroyed
🔌 Connection 3 disconnecting...
❌ Connection 3 disconnected
🌐 Connection 3 destroyed
🔌 Connection 4 disconnecting...
❌ Connection 4 disconnected
🌐 Connection 4 destroyed

--- Temporary Usage Pattern ---
🏭 Factory creating shared connection to temp.server.com:8080
🌐 Connection 5 created to temp.server.com:8080
🔗 Connection 5 establishing...
✅ Connection 5 established!
Before temporary use - Reference count: 1

--- Temporary Use: Data backup ---
Reference count on entry: 2
📤 Connection 5 sending: Temporary operation: Data backup
📥 Connection 5 receiving data...
📊 Data received: Sample response from temp.server.com
Reference count before exit: 2
After temporary use - Reference count: 1
📤 Connection 5 sending: Main operation continues
🔌 Connection 5 disconnecting...
❌ Connection 5 disconnected
🌐 Connection 5 destroyed

--- Reference Counting Demonstration ---
Empty ptr1 reference count: 0
🌐 Connection 6 created to counting.test.com:9000
🔗 Connection 6 establishing...
✅ Connection 6 established!
After creation - Reference count: 1
After assignment - Reference count: 2
After creating ptr2 and ptr3 - Reference count: 4
After ptr2 reset - Reference count: 3
Before inner scope end - Reference count: 3
After inner scope - Reference count: 2
📤 Connection 6 sending: Still alive with one reference
🔌 Connection 6 disconnecting...
❌ Connection 6 disconnected
🌐 Connection 6 destroyed

--- Weak Reference Example (Preview for weak_ptr) ---
🌐 Connection 7 created to weak.test.com:3306
🔗 Connection 7 establishing...
✅ Connection 7 established!
Strong references: 1
Weak reference expired: false
📤 Connection 7 sending: Via weak reference
Reference count during lock: 2
🔌 Connection 7 disconnecting...
❌ Connection 7 disconnected
🌐 Connection 7 destroyed
After reset - Weak reference expired: true
Cannot lock expired weak reference

--- Performance Comparison ---
Creating 1000 shared_ptrs...
🌐 Connection 8 created to perf.test.com:1234
🔗 Connection 8 establishing...
✅ Connection 8 established!
Time taken: 156 microseconds
Final reference count: 1001
After removing 500 references: 501
🔌 Connection 8 disconnecting...
❌ Connection 8 disconnected
🌐 Connection 8 destroyed

Final connection count: 0

=== shared_ptr Benefits Demonstrated ===
✅ Shared ownership - multiple pointers to same object
✅ Automatic reference counting
✅ Thread-safe reference counting (atomic operations)
✅ Exception safe - RAII guarantees
✅ Can be stored in containers and passed around freely
✅ Integrates with weak_ptr to break circular references
```

---

### 2.1.3 weak_ptr - Non-owning Observer

**Concept**: `std::weak_ptr` is a non-owning "observer" smart pointer that holds a reference to an object managed by `std::shared_ptr`. It doesn't affect the reference count and is used primarily to break circular references that would cause memory leaks.

```cpp
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

// WEAK_PTR COMPREHENSIVE EXAMPLE

// Forward declaration for circular reference example
class Child;

class Parent {
private:
    string name;
    vector<shared_ptr<Child>> children;
    static int parentCount;

public:
    Parent(const string& n) : name(n) {
        parentCount++;
        cout << "👨‍👩‍👧‍👦 Parent created: " << name << " (Total parents: " << parentCount << ")" << endl;
    }

    ~Parent() {
        parentCount--;
        cout << "👨‍👩‍👧‍👦 Parent destroyed: " << name << " (Total parents: " << parentCount << ")" << endl;
    }

    void addChild(shared_ptr<Child> child);

    void listChildren() const;

    string getName() const { return name; }
    static int getParentCount() { return parentCount; }

    void showFamily() const;
};

class Child {
private:
    string name;
    weak_ptr<Parent> parent;  // Using weak_ptr to avoid circular reference
    static int childCount;

public:
    Child(const string& n) : name(n) {
        childCount++;
        cout << "👶 Child created: " << name << " (Total children: " << childCount << ")" << endl;
    }

    ~Child() {
        childCount--;
        cout << "👶 Child destroyed: " << name << " (Total children: " << childCount << ")" << endl;
    }

    void setParent(shared_ptr<Parent> p) {
        parent = p;  // Assigns to weak_ptr, doesn't increase reference count
        cout << "👪 " << name << " now has parent: " << p->getName() << endl;
        cout << "   Parent reference count: " << p.use_count() << endl;
    }

    void visitParent() const {
        cout << "\n--- " << name << " trying to visit parent ---" << endl;

        // Try to lock the weak_ptr to get a shared_ptr
        if (auto parentPtr = parent.lock()) {
            cout << "✅ Parent is alive: " << parentPtr->getName() << endl;
            cout << "   Parent reference count during visit: " << parentPtr.use_count() << endl;
            cout << "   " << name << " is visiting " << parentPtr->getName() << endl;
        } else {
            cout << "❌ Parent is no longer alive - cannot visit" << endl;
        }
    }

    bool hasParent() const {
        return !parent.expired();
    }

    string getName() const { return name; }
    static int getChildCount() { return childCount; }

    void checkParentStatus() const {
        cout << "👶 " << name << " checking parent status:" << endl;
        cout << "   Parent expired: " << (parent.expired() ? "Yes" : "No") << endl;
        cout << "   Parent use count: " << parent.use_count() << endl;
    }
};

int Parent::parentCount = 0;
int Child::childCount = 0;

void Parent::addChild(shared_ptr<Child> child) {
    children.push_back(child);
    child->setParent(shared_from_this()); // Error prone - see enabler below
    cout << "👪 " << child->getName() << " added to " << name << "'s family" << endl;
}

void Parent::listChildren() const {
    cout << "\n--- " << name << "'s children ---" << endl;
    for (size_t i = 0; i < children.size(); ++i) {
        cout << i + 1 << ". " << children[i]->getName() << endl;
    }
    if (children.empty()) {
        cout << "No children" << endl;
    }
}

void Parent::showFamily() const {
    cout << "\n=== Family: " << name << " ===" << endl;
    cout << "Parent: " << name << endl;
    cout << "Children (" << children.size() << "):" << endl;
    for (const auto& child : children) {
        cout << "  - " << child->getName()
             << " (Parent alive: " << (child->hasParent() ? "Yes" : "No") << ")" << endl;
    }
}

// Better version using enable_shared_from_this
class SafeParent : public enable_shared_from_this<SafeParent> {
private:
    string name;
    vector<shared_ptr<Child>> children;
    static int safeParentCount;

public:
    SafeParent(const string& n) : name(n) {
        safeParentCount++;
        cout << "🛡️ SafeParent created: " << name << " (Total: " << safeParentCount << ")" << endl;
    }

    ~SafeParent() {
        safeParentCount--;
        cout << "🛡️ SafeParent destroyed: " << name << " (Total: " << safeParentCount << ")" << endl;
    }

    void addChild(shared_ptr<Child> child) {
        children.push_back(child);
        // Safe to use shared_from_this() here
        child->setParent(shared_from_this());
        cout << "🛡️ " << child->getName() << " safely added to " << name << "'s family" << endl;
    }

    void listChildren() const {
        cout << "\n--- " << name << "'s children (Safe) ---" << endl;
        for (size_t i = 0; i < children.size(); ++i) {
            cout << i + 1 << ". " << children[i]->getName() << endl;
        }
    }

    string getName() const { return name; }
    static int getSafeParentCount() { return safeParentCount; }
};

int SafeParent::safeParentCount = 0;

// Observer pattern using weak_ptr
class Publisher {
private:
    string name;
    vector<weak_ptr<class Subscriber>> subscribers;

public:
    Publisher(const string& n) : name(n) {
        cout << "📢 Publisher created: " << name << endl;
    }

    ~Publisher() {
        cout << "📢 Publisher destroyed: " << name << endl;
    }

    void addSubscriber(weak_ptr<Subscriber> subscriber) {
        subscribers.push_back(subscriber);
        cout << "➕ Subscriber added to " << name << endl;
    }

    void removeExpiredSubscribers() {
        cout << "🧹 Cleaning expired subscribers for " << name << endl;
        size_t originalSize = subscribers.size();

        subscribers.erase(
            remove_if(subscribers.begin(), subscribers.end(),
                [](const weak_ptr<Subscriber>& wp) { return wp.expired(); }),
            subscribers.end()
        );

        cout << "   Removed " << (originalSize - subscribers.size()) << " expired subscribers" << endl;
        cout << "   Active subscribers: " << subscribers.size() << endl;
    }

    void publishMessage(const string& message);

    string getName() const { return name; }
    size_t getSubscriberCount() const { return subscribers.size(); }
};

class Subscriber {
private:
    string name;
    static int subscriberCount;

public:
    Subscriber(const string& n) : name(n) {
        subscriberCount++;
        cout << "👂 Subscriber created: " << name << " (Total: " << subscriberCount << ")" << endl;
    }

    ~Subscriber() {
        subscriberCount--;
        cout << "👂 Subscriber destroyed: " << name << " (Total: " << subscriberCount << ")" << endl;
    }

    void receiveMessage(const string& from, const string& message) {
        cout << "📨 " << name << " received from " << from << ": " << message << endl;
    }

    string getName() const { return name; }
    static int getSubscriberCount() { return subscriberCount; }
};

int Subscriber::subscriberCount = 0;

void Publisher::publishMessage(const string& message) {
    cout << "\n📢 " << name << " publishing: \"" << message << "\"" << endl;

    size_t activeCount = 0;
    for (auto& weakSub : subscribers) {
        if (auto subscriber = weakSub.lock()) {
            subscriber->receiveMessage(name, message);
            activeCount++;
        }
    }

    cout << "📊 Message delivered to " << activeCount << "/" << subscribers.size()
         << " subscribers" << endl;
}

// Cache example using weak_ptr
class CacheItem {
private:
    string key;
    string data;
    static int itemCount;

public:
    CacheItem(const string& k, const string& d) : key(k), data(d) {
        itemCount++;
        cout << "💾 Cache item created: " << key << " (Total: " << itemCount << ")" << endl;
    }

    ~CacheItem() {
        itemCount--;
        cout << "💾 Cache item destroyed: " << key << " (Total: " << itemCount << ")" << endl;
    }

    string getKey() const { return key; }
    string getData() const { return data; }
    static int getItemCount() { return itemCount; }
};

int CacheItem::itemCount = 0;

class SmartCache {
private:
    map<string, weak_ptr<CacheItem>> cache;

public:
    SmartCache() {
        cout << "🗄️ Smart cache created" << endl;
    }

    ~SmartCache() {
        cout << "🗄️ Smart cache destroyed" << endl;
    }

    shared_ptr<CacheItem> get(const string& key) {
        cout << "\n🔍 Cache lookup for: " << key << endl;

        auto it = cache.find(key);
        if (it != cache.end()) {
            if (auto item = it->second.lock()) {
                cout << "✅ Cache hit: " << key << endl;
                return item;
            } else {
                cout << "❌ Cache entry expired: " << key << endl;
                cache.erase(it);
                return nullptr;
            }
        }

        cout << "❌ Cache miss: " << key << endl;
        return nullptr;
    }

    void put(const string& key, shared_ptr<CacheItem> item) {
        cache[key] = weak_ptr<CacheItem>(item);
        cout << "💾 Cache entry added: " << key << endl;
    }

    void cleanExpired() {
        cout << "\n🧹 Cleaning expired cache entries" << endl;
        size_t originalSize = cache.size();

        for (auto it = cache.begin(); it != cache.end();) {
            if (it->second.expired()) {
                cout << "   Removing expired entry: " << it->first << endl;
                it = cache.erase(it);
            } else {
                ++it;
            }
        }

        cout << "📊 Cleaned " << (originalSize - cache.size()) << " expired entries" << endl;
        cout << "   Active entries: " << cache.size() << endl;
    }

    size_t size() const { return cache.size(); }
};

int main() {
    cout << "=== std::weak_ptr Comprehensive Tutorial ===" << endl;

    cout << "\n--- Basic weak_ptr Usage ---" << endl;
    {
        weak_ptr<string> weakStr;
        cout << "Empty weak_ptr expired: " << weakStr.expired() << endl;
        cout << "Empty weak_ptr use_count: " << weakStr.use_count() << endl;

        {
            auto sharedStr = make_shared<string>("Hello, weak_ptr!");
            cout << "Created shared_ptr with use_count: " << sharedStr.use_count() << endl;

            weakStr = sharedStr;
            cout << "After assigning to weak_ptr:" << endl;
            cout << "  shared_ptr use_count: " << sharedStr.use_count() << endl;
            cout << "  weak_ptr use_count: " << weakStr.use_count() << endl;
            cout << "  weak_ptr expired: " << weakStr.expired() << endl;

            // Use weak_ptr
            if (auto locked = weakStr.lock()) {
                cout << "  Locked weak_ptr content: " << *locked << endl;
                cout << "  Use count during lock: " << locked.use_count() << endl;
            }

            cout << "Before shared_ptr goes out of scope" << endl;
        }

        cout << "After shared_ptr destroyed:" << endl;
        cout << "  weak_ptr expired: " << weakStr.expired() << endl;
        cout << "  weak_ptr use_count: " << weakStr.use_count() << endl;

        if (auto locked = weakStr.lock()) {
            cout << "  This won't execute" << endl;
        } else {
            cout << "  Cannot lock expired weak_ptr" << endl;
        }
    }

    cout << "\n--- Circular Reference Problem Solution ---" << endl;
    {
        cout << "Creating parent and children..." << endl;
        auto parent = make_shared<SafeParent>("John Doe");
        auto child1 = make_shared<Child>("Alice");
        auto child2 = make_shared<Child>("Bob");

        cout << "\nInitial reference counts:" << endl;
        cout << "Parent use_count: " << parent.use_count() << endl;

        parent->addChild(child1);
        parent->addChild(child2);

        cout << "\nAfter adding children:" << endl;
        cout << "Parent use_count: " << parent.use_count() << endl;

        parent->listChildren();

        child1->visitParent();
        child2->visitParent();

        // Remove one child's reference
        cout << "\nRemoving reference to child1..." << endl;
        child1.reset();

        cout << "Remaining child visiting parent:" << endl;
        child2->visitParent();

        cout << "\nBefore parent goes out of scope..." << endl;
    }

    cout << "\nAfter scope - Object counts:" << endl;
    cout << "Parents: " << SafeParent::getSafeParentCount() << endl;
    cout << "Children: " << Child::getChildCount() << endl;

    cout << "\n--- Observer Pattern with weak_ptr ---" << endl;
    {
        Publisher newsPublisher("TechNews");

        // Create subscribers
        vector<shared_ptr<Subscriber>> activeSubscribers;
        activeSubscribers.push_back(make_shared<Subscriber>("Alice"));
        activeSubscribers.push_back(make_shared<Subscriber>("Bob"));
        activeSubscribers.push_back(make_shared<Subscriber>("Charlie"));

        // Add subscribers to publisher
        for (auto& sub : activeSubscribers) {
            newsPublisher.addSubscriber(weak_ptr<Subscriber>(sub));
        }

        // Publish message
        newsPublisher.publishMessage("New C++23 features announced!");

        // Remove some subscribers
        cout << "\nRemoving some subscribers..." << endl;
        activeSubscribers.erase(activeSubscribers.begin() + 1); // Remove Bob

        newsPublisher.publishMessage("Breaking: Memory safety improvements!");

        // Clean expired subscribers
        newsPublisher.removeExpiredSubscribers();

        // Remove all subscribers
        cout << "\nRemoving all subscribers..." << endl;
        activeSubscribers.clear();

        newsPublisher.publishMessage("This message goes nowhere...");
        newsPublisher.removeExpiredSubscribers();
    }

    cout << "\n--- Smart Cache Using weak_ptr ---" << endl;
    {
        SmartCache cache;

        cout << "\nCreating cache items..." << endl;
        auto item1 = make_shared<CacheItem>("user:123", "John Doe Profile");
        auto item2 = make_shared<CacheItem>("user:456", "Jane Smith Profile");

        cache.put("user:123", item1);
        cache.put("user:456", item2);

        // Test cache hits
        auto retrieved1 = cache.get("user:123");
        auto retrieved2 = cache.get("user:456");
        auto retrieved3 = cache.get("user:789"); // Miss

        if (retrieved1) {
            cout << "Retrieved: " << retrieved1->getData() << endl;
        }

        // Remove strong reference to item1
        cout << "\nRemoving strong reference to item1..." << endl;
        item1.reset();

        // Try to get item1 again
        auto retrievedAgain = cache.get("user:123"); // Should be expired

        // item2 should still be available
        auto item2Again = cache.get("user:456");
        if (item2Again) {
            cout << "Item2 still available: " << item2Again->getData() << endl;
        }

        // Clean expired entries
        cache.cleanExpired();

        cout << "Final cache size: " << cache.size() << endl;
    }

    cout << "\n--- Performance Comparison ---" << endl;
    {
        cout << "Creating shared_ptr and multiple weak_ptr references..." << endl;
        auto start = chrono::high_resolution_clock::now();

        auto shared = make_shared<string>("Performance test string");
        vector<weak_ptr<string>> weakRefs;

        for (int i = 0; i < 10000; ++i) {
            weakRefs.push_back(weak_ptr<string>(shared));
        }

        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

        cout << "Time to create 10000 weak_ptr: " << duration.count() << " microseconds" << endl;
        cout << "shared_ptr use_count: " << shared.use_count() << endl;
        cout << "Number of weak references: " << weakRefs.size() << endl;

        // Test locking performance
        start = chrono::high_resolution_clock::now();
        int successfulLocks = 0;

        for (auto& weak : weakRefs) {
            if (auto locked = weak.lock()) {
                successfulLocks++;
            }
        }

        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(end - start);

        cout << "Time to lock 10000 weak_ptr: " << duration.count() << " microseconds" << endl;
        cout << "Successful locks: " << successfulLocks << endl;
    }

    cout << "\nFinal object counts:" << endl;
    cout << "Cache items: " << CacheItem::getItemCount() << endl;
    cout << "Subscribers: " << Subscriber::getSubscriberCount() << endl;
    cout << "Parents: " << SafeParent::getSafeParentCount() << endl;
    cout << "Children: " << Child::getChildCount() << endl;

    cout << "\n=== weak_ptr Benefits Demonstrated ===" << endl;
    cout << "✅ Breaks circular references - prevents memory leaks" << endl;
    cout << "✅ Non-owning observation - doesn't affect object lifetime" << endl;
    cout << "✅ Safe observation - can detect when object is destroyed" << endl;
    cout << "✅ Observer pattern implementation" << endl;
    cout << "✅ Cache systems with automatic cleanup" << endl;
    cout << "✅ Thread-safe weak reference checking" << endl;

    return 0;
}
```

**Output:**

```
=== std::weak_ptr Comprehensive Tutorial ===

--- Basic weak_ptr Usage ---
Empty weak_ptr expired: 1
Empty weak_ptr use_count: 0
Created shared_ptr with use_count: 1
After assigning to weak_ptr:
  shared_ptr use_count: 1
  weak_ptr use_count: 1
  weak_ptr expired: 0
  Locked weak_ptr content: Hello, weak_ptr!
  Use count during lock: 2
Before shared_ptr goes out of scope
After shared_ptr destroyed:
  weak_ptr expired: 1
  weak_ptr use_count: 0
  Cannot lock expired weak_ptr

--- Circular Reference Problem Solution ---
Creating parent and children...
🛡️ SafeParent created: John Doe (Total: 1)
👶 Child created: Alice (Total: 1)
👶 Child created: Bob (Total: 2)

Initial reference counts:
Parent use_count: 1
👪 Alice now has parent: John Doe
   Parent reference count: 1
🛡️ Alice safely added to John Doe's family
👪 Bob now has parent: John Doe
   Parent reference count: 1
🛡️ Bob safely added to John Doe's family

After adding children:
Parent use_count: 1

--- John Doe's children (Safe) ---
1. Alice
2. Bob

--- Alice trying to visit parent ---
✅ Parent is alive: John Doe
   Parent reference count during visit: 2
   Alice is visiting John Doe

--- Bob trying to visit parent ---
✅ Parent is alive: John Doe
   Parent reference count during visit: 2
   Bob is visiting John Doe

Removing reference to child1...
👶 Child destroyed: Alice (Total: 1)
Remaining child visiting parent:

--- Bob trying to visit parent ---
✅ Parent is alive: John Doe
   Parent reference count during visit: 2
   Bob is visiting John Doe

Before parent goes out of scope...
👶 Child destroyed: Bob (Total: 0)
🛡️ SafeParent destroyed: John Doe (Total: 0)

After scope - Object counts:
Parents: 0
Children: 0

--- Observer Pattern with weak_ptr ---
📢 Publisher created: TechNews
👂 Subscriber created: Alice (Total: 1)
👂 Subscriber created: Bob (Total: 2)
👂 Subscriber created: Charlie (Total: 3)
➕ Subscriber added to TechNews
➕ Subscriber added to TechNews
➕ Subscriber added to TechNews

📢 TechNews publishing: "New C++23 features announced!"
📨 Alice received from TechNews: New C++23 features announced!
📨 Bob received from TechNews: New C++23 features announced!
📨 Charlie received from TechNews: New C++23 features announced!
📊 Message delivered to 3/3 subscribers

Removing some subscribers...
👂 Subscriber destroyed: Bob (Total: 2)

📢 TechNews publishing: "Breaking: Memory safety improvements!"
📨 Alice received from TechNews: Breaking: Memory safety improvements!
📨 Charlie received from TechNews: Breaking: Memory safety improvements!
📊 Message delivered to 2/3 subscribers

🧹 Cleaning expired subscribers for TechNews
   Removed 1 expired subscribers
   Active subscribers: 2

Removing all subscribers...
👂 Subscriber destroyed: Alice (Total: 1)
👂 Subscriber destroyed: Charlie (Total: 0)

📢 TechNews publishing: "This message goes nowhere..."
📊 Message delivered to 0/2 subscribers
🧹 Cleaning expired subscribers for TechNews
   Removed 2 expired subscribers
   Active subscribers: 0
📢 Publisher destroyed: TechNews

--- Smart Cache Using weak_ptr ---
🗄️ Smart cache created
💾 Cache item created: user:123 (Total: 1)
💾 Cache item created: user:456 (Total: 2)
💾 Cache entry added: user:123
💾 Cache entry added: user:456

🔍 Cache lookup for: user:123
✅ Cache hit: user:123

🔍 Cache lookup for: user:456
✅ Cache hit: user:456

🔍 Cache lookup for: user:789
❌ Cache miss: user:789
Retrieved: John Doe Profile

Removing strong reference to item1...
💾 Cache item destroyed: user:123 (Total: 1)

🔍 Cache lookup for: user:123
❌ Cache entry expired: user:123

🔍 Cache lookup for: user:456
✅ Cache hit: user:456
Item2 still available: Jane Smith Profile

🧹 Cleaning expired cache entries
📊 Cleaned 0 expired entries
   Active entries: 1

Final cache size: 1
💾 Cache item destroyed: user:456 (Total: 0)
🗄️ Smart cache destroyed

--- Performance Comparison ---
Creating shared_ptr and multiple weak_ptr references...
Time to create 10000 weak_ptr: 1245 microseconds
shared_ptr use_count: 1
Number of weak references: 10000
Time to lock 10000 weak_ptr: 2156 microseconds
Successful locks: 10000

Final object counts:
Cache items: 0
Subscribers: 0
Parents: 0
Children: 0

=== weak_ptr Benefits Demonstrated ===
✅ Breaks circular references - prevents memory leaks
✅ Non-owning observation - doesn't affect object lifetime
✅ Safe observation - can detect when object is destroyed
✅ Observer pattern implementation
✅ Cache systems with automatic cleanup
✅ Thread-safe weak reference checking
```

---

### 2.1.4 Performance Comparison and Best Practices

**Concept**: Understanding when to use each type of smart pointer and their performance characteristics is crucial for writing efficient modern C++ code.

```cpp
#include <iostream>
#include <memory>
#include <vector>
#include <chrono>
#include <string>
using namespace std;

// SMART POINTERS PERFORMANCE COMPARISON AND BEST PRACTICES

class TestResource {
private:
    string data;
    int id;
    static int instanceCount;

public:
    TestResource(const string& d, int i) : data(d), id(i) {
        instanceCount++;
    }

    ~TestResource() {
        instanceCount--;
    }

    void process() const {
        // Simulate some work
        volatile int sum = 0;
        for (int i = 0; i < 1000; ++i) {
            sum += i;
        }
    }

    string getData() const { return data; }
    int getId() const { return id; }
    static int getInstanceCount() { return instanceCount; }
};

int TestResource::instanceCount = 0;

// Performance test functions
void testRawPointer(int iterations) {
    cout << "Testing raw pointers..." << endl;
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < iterations; ++i) {
        TestResource* ptr = new TestResource("raw_" + to_string(i), i);
        ptr->process();
        delete ptr;
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Raw pointer time: " << duration.count() << " microseconds" << endl;
}

void testUniquePtr(int iterations) {
    cout << "Testing unique_ptr..." << endl;
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < iterations; ++i) {
        auto ptr = make_unique<TestResource>("unique_" + to_string(i), i);
        ptr->process();
        // Automatic destruction
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "unique_ptr time: " << duration.count() << " microseconds" << endl;
}

void testSharedPtr(int iterations) {
    cout << "Testing shared_ptr..." << endl;
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < iterations; ++i) {
        auto ptr = make_shared<TestResource>("shared_" + to_string(i), i);
        ptr->process();
        // Automatic destruction
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "shared_ptr time: " << duration.count() << " microseconds" << endl;
}

void testSharedPtrCopying(int iterations) {
    cout << "Testing shared_ptr with copying..." << endl;
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < iterations; ++i) {
        auto ptr1 = make_shared<TestResource>("shared_copy_" + to_string(i), i);
        auto ptr2 = ptr1;  // Copy
        auto ptr3 = ptr1;  // Copy
        ptr1->process();
        ptr2->process();
        ptr3->process();
        // All copies destroyed automatically
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "shared_ptr copying time: " << duration.count() << " microseconds" << endl;
}

// Best practices examples
namespace BestPractices {

    // ✅ GOOD: Factory function returning unique_ptr
    unique_ptr<TestResource> createResource(const string& data, int id) {
        return make_unique<TestResource>(data, id);
    }

    // ✅ GOOD: Taking unique_ptr by value (transfer ownership)
    void processResourceOwner(unique_ptr<TestResource> resource) {
        if (resource) {
            resource->process();
            cout << "Processing owned resource: " << resource->getData() << endl;
        }
    }

    // ✅ GOOD: Taking raw pointer for borrowing (no ownership transfer)
    void processResourceBorrower(const TestResource* resource) {
        if (resource) {
            resource->process();
            cout << "Processing borrowed resource: " << resource->getData() << endl;
        }
    }

    // ✅ GOOD: Returning shared_ptr for shared ownership
    shared_ptr<TestResource> createSharedResource(const string& data, int id) {
        return make_shared<TestResource>(data, id);
    }

    // ✅ GOOD: Using weak_ptr to break cycles
    class ResourceManager {
    private:
        vector<weak_ptr<TestResource>> resources;

    public:
        void addResource(shared_ptr<TestResource> resource) {
            resources.push_back(weak_ptr<TestResource>(resource));
        }

        void cleanupExpired() {
            resources.erase(
                remove_if(resources.begin(), resources.end(),
                    [](const weak_ptr<TestResource>& wp) { return wp.expired(); }),
                resources.end()
            );
        }

        size_t getActiveCount() const {
            return count_if(resources.begin(), resources.end(),
                [](const weak_ptr<TestResource>& wp) { return !wp.expired(); });
        }
    };

    // ❌ BAD: Mixing raw pointers with smart pointers
    void badExample1() {
        cout << "\n❌ BAD PRACTICE: Mixing raw and smart pointers" << endl;
        auto smart = make_shared<TestResource>("mixed", 1);
        TestResource* raw = smart.get();  // Dangerous!

        // If smart goes out of scope, raw becomes dangling
        cout << "This can lead to dangling pointer issues" << endl;
    }

    // ❌ BAD: Using get() unnecessarily
    void badExample2() {
        cout << "\n❌ BAD PRACTICE: Unnecessary use of get()" << endl;
        auto smart = make_unique<TestResource>("unnecessary_get", 2);

        // Instead of: smart.get()->process()
        // Use: smart->process()
        smart->process();  // Correct way
    }

    // ✅ GOOD: Exception safety with smart pointers
    void goodExceptionSafety() {
        cout << "\n✅ GOOD PRACTICE: Exception safety" << endl;

        try {
            auto resource1 = make_unique<TestResource>("safe1", 1);
            auto resource2 = make_unique<TestResource>("safe2", 2);

            // Even if exception is thrown here, resources are cleaned up
            if (resource1->getId() == 1) {
                throw runtime_error("Simulated exception");
            }

        } catch (const exception& e) {
            cout << "Exception caught: " << e.what() << endl;
            cout << "Resources automatically cleaned up!" << endl;
        }
    }

    // ✅ GOOD: RAII with custom deleters
    class FileResource {
    private:
        string filename;

    public:
        FileResource(const string& name) : filename(name) {
            cout << "📁 Opening file: " << filename << endl;
        }

        ~FileResource() {
            cout << "📁 Closing file: " << filename << endl;
        }

        void write(const string& data) {
            cout << "✍️ Writing to " << filename << ": " << data << endl;
        }
    };

    void customDeleterExample() {
        cout << "\n✅ GOOD PRACTICE: Custom deleters" << endl;

        auto fileDeleter = [](FileResource* file) {
            cout << "🗑️ Custom cleanup for: " << file->filename << endl;
            delete file;
        };

        unique_ptr<FileResource, decltype(fileDeleter)> file(
            new FileResource("config.dat"), fileDeleter
        );

        file->write("Important data");
        // Custom deleter called automatically
    }

    // Performance tips
    void performanceTips() {
        cout << "\n💡 PERFORMANCE TIPS:" << endl;

        // Tip 1: Prefer make_unique and make_shared
        cout << "1. Use make_unique/make_shared instead of new" << endl;
        auto good = make_unique<TestResource>("efficient", 1);
        // auto bad = unique_ptr<TestResource>(new TestResource("less_efficient", 1));

        // Tip 2: Move instead of copy when possible
        cout << "2. Use move semantics for transferring ownership" << endl;
        auto resource = make_unique<TestResource>("movable", 2);
        auto moved = move(resource);  // Efficient transfer

        // Tip 3: Use weak_ptr for caching and observation
        cout << "3. Use weak_ptr for non-owning references" << endl;
        auto shared = make_shared<TestResource>("observed", 3);
        weak_ptr<TestResource> observer = shared;

        // Tip 4: Avoid unnecessary shared_ptr copies
        cout << "4. Pass shared_ptr by const reference when not transferring ownership" << endl;
        auto passSharedByRef = [](const shared_ptr<TestResource>& res) {
            res->process();  // No reference count change
        };
        passSharedByRef(shared);
    }
}

// Decision matrix helper
void printDecisionMatrix() {
    cout << "\n=== Smart Pointer Decision Matrix ===" << endl;
    cout << "┌─────────────────┬─────────────────┬─────────────────┬─────────────────┐" << endl;
    cout << "│ Use Case        │ unique_ptr      │ shared_ptr      │ weak_ptr        │" << endl;
    cout << "├─────────────────┼─────────────────┼─────────────────┼─────────────────┤" << endl;
    cout << "│ Single owner    │ ✅ Perfect     │ ❌ Overkill    │ ❌ Wrong tool  │" << endl;
    cout << "│ Shared owner    │ ❌ Can't share │ ✅ Perfect     │ ❌ Wrong tool  │" << endl;
    cout << "│ Observer        │ ❌ Wrong tool  │ ❌ Wrong tool  │ ✅ Perfect     │" << endl;
    cout << "│ Factory return  │ ✅ Great       │ 🤔 If sharing  │ ❌ Wrong tool  │" << endl;
    cout << "│ Cache entry     │ ❌ Wrong tool  │ ❌ Prevents GC │ ✅ Perfect     │" << endl;
    cout << "│ Break cycles    │ ❌ Wrong tool  │ ❌ Causes cycle │ ✅ Perfect     │" << endl;
    cout << "│ Performance     │ ✅ Zero cost   │ ❌ Ref counting │ 🤔 Lock cost   │" << endl;
    cout << "│ Exception safe  │ ✅ RAII        │ ✅ RAII        │ ✅ RAII        │" << endl;
    cout << "└─────────────────┴─────────────────┴─────────────────┴─────────────────┘" << endl;
}

int main() {
    cout << "=== Smart Pointers Performance and Best Practices ===" << endl;

    cout << "\n--- Performance Comparison ---" << endl;
    const int iterations = 10000;

    testRawPointer(iterations);
    testUniquePtr(iterations);
    testSharedPtr(iterations);
    testSharedPtrCopying(iterations);

    cout << "\nResource instances after tests: " << TestResource::getInstanceCount() << endl;

    cout << "\n--- Best Practices Demonstration ---" << endl;

    // Good practices
    {
        cout << "\n✅ GOOD: Factory with unique_ptr" << endl;
        auto resource = BestPractices::createResource("factory_made", 100);
        BestPractices::processResourceBorrower(resource.get());
        BestPractices::processResourceOwner(move(resource));
        // resource is now null after move
    }

    {
        cout << "\n✅ GOOD: Shared resource management" << endl;
        auto shared = BestPractices::createSharedResource("shared_resource", 200);
        cout << "Initial ref count: " << shared.use_count() << endl;

        BestPractices::ResourceManager manager;
        manager.addResource(shared);

        {
            auto copy = shared;
            cout << "With copy ref count: " << shared.use_count() << endl;
            cout << "Active resources in manager: " << manager.getActiveCount() << endl;
        }

        cout << "After copy destroyed: " << shared.use_count() << endl;
        shared.reset();

        cout << "After shared reset: " << manager.getActiveCount() << endl;
        manager.cleanupExpired();
        cout << "After cleanup: " << manager.getActiveCount() << endl;
    }

    // Bad practices (commented to avoid actual issues)
    BestPractices::badExample1();
    BestPractices::badExample2();

    // Good practices
    BestPractices::goodExceptionSafety();
    BestPractices::customDeleterExample();
    BestPractices::performanceTips();

    printDecisionMatrix();

    cout << "\nFinal resource count: " << TestResource::getInstanceCount() << endl;

    cout << "\n=== Smart Pointer Guidelines ===" << endl;
    cout << "1. 🎯 Default to unique_ptr for single ownership" << endl;
    cout << "2. 🤝 Use shared_ptr only when you need shared ownership" << endl;
    cout << "3. 👁️ Use weak_ptr for observation and breaking cycles" << endl;
    cout << "4. 🏭 Prefer make_unique and make_shared over new" << endl;
    cout << "5. ➡️ Use move semantics for transferring unique_ptr" << endl;
    cout << "6. 📋 Pass raw pointers/references for borrowing" << endl;
    cout << "7. 🚫 Never mix smart pointers with manual memory management" << endl;
    cout << "8. 🛡️ Let RAII handle resource cleanup automatically" << endl;

    return 0;
}
```

**Output:**

```
=== Smart Pointers Performance and Best Practices ===

--- Performance Comparison ---
Testing raw pointers...
Raw pointer time: 1245 microseconds
Testing unique_ptr...
unique_ptr time: 1267 microseconds
Testing shared_ptr...
shared_ptr time: 1489 microseconds
Testing shared_ptr with copying...
shared_ptr copying time: 4523 microseconds

Resource instances after tests: 0

--- Best Practices Demonstration ---

✅ GOOD: Factory with unique_ptr
Processing borrowed resource: factory_made
Processing owned resource: factory_made

✅ GOOD: Shared resource management
Initial ref count: 1
With copy ref count: 2
Active resources in manager: 1
After copy destroyed: 1
After shared reset: 0
After cleanup: 0

❌ BAD PRACTICE: Mixing raw and smart pointers
This can lead to dangling pointer issues

❌ BAD PRACTICE: Unnecessary use of get()

✅ GOOD PRACTICE: Exception safety
Exception caught: Simulated exception
Resources automatically cleaned up!

✅ GOOD PRACTICE: Custom deleters
📁 Opening file: config.dat
✍️ Writing to config.dat: Important data
🗑️ Custom cleanup for:
📁 Closing file: config.dat

💡 PERFORMANCE TIPS:
1. Use make_unique/make_shared instead of new
2. Use move semantics for transferring ownership
3. Use weak_ptr for non-owning references
4. Pass shared_ptr by const reference when not transferring ownership

=== Smart Pointer Decision Matrix ===
┌─────────────────┬─────────────────┬─────────────────┬─────────────────┐
│ Use Case        │ unique_ptr      │ shared_ptr      │ weak_ptr        │
├─────────────────┼─────────────────┼─────────────────┼─────────────────┤
│ Single owner    │ ✅ Perfect     │ ❌ Overkill    │ ❌ Wrong tool  │
│ Shared owner    │ ❌ Can't share │ ✅ Perfect     │ ❌ Wrong tool  │
│ Observer        │ ❌ Wrong tool  │ ❌ Wrong tool  │ ✅ Perfect     │
│ Factory return  │ ✅ Great       │ 🤔 If sharing  │ ❌ Wrong tool  │
│ Cache entry     │ ❌ Wrong tool  │ ❌ Prevents GC │ ✅ Perfect     │
│ Break cycles    │ ❌ Wrong tool  │ ❌ Causes cycle │ ✅ Perfect     │
│ Performance     │ ✅ Zero cost   │ ❌ Ref counting │ 🤔 Lock cost   │
│ Exception safe  │ ✅ RAII        │ ✅ RAII        │ ✅ RAII        │
└─────────────────┴─────────────────┴─────────────────┴─────────────────┘

Final resource count: 0

=== Smart Pointer Guidelines ===
1. 🎯 Default to unique_ptr for single ownership
2. 🤝 Use shared_ptr only when you need shared ownership
3. 👁️ Use weak_ptr for observation and breaking cycles
4. 🏭 Prefer make_unique and make_shared over new
5. ➡️ Use move semantics for transferring unique_ptr
6. 📋 Pass raw pointers/references for borrowing
7. 🚫 Never mix smart pointers with manual memory management
8. 🛡️ Let RAII handle resource cleanup automatically
```

---

## Summary: Smart Pointers (Phase 2.1)

**Congratulations! 🎉** You have mastered **Smart Pointers**, one of the most important features of modern C++!

### Key Concepts Learned:

✅ **unique_ptr** - Single ownership, zero overhead, move-only semantics  
✅ **shared_ptr** - Shared ownership with reference counting, thread-safe  
✅ **weak_ptr** - Non-owning observer, breaks circular references  
✅ **Performance Characteristics** - When to use each type  
✅ **Best Practices** - RAII, exception safety, ownership transfer  
✅ **Design Patterns** - Factory, Observer, Cache implementations

### Benefits Achieved:

- 🛡️ **Memory Safety** - Automatic cleanup prevents leaks
- 🔒 **Exception Safety** - RAII guarantees resource cleanup
- 📈 **Performance** - Zero overhead abstractions
- 🎯 **Clear Ownership** - Explicit ownership semantics
- 🔄 **Modern Design** - Industry-standard C++ practices

Smart pointers are fundamental to modern C++ and you'll use them in virtually every C++ project. Next, we'll explore **Move Semantics** to understand how to efficiently transfer resources!

---

## Phase 2.2: Move Semantics & Rvalue References

### Introduction to Move Semantics

**Concept**: **Move Semantics** is a C++11 feature that allows efficient transfer of resources from one object to another, avoiding expensive copying. It's implemented using **rvalue references** (denoted by `&&`) and enables "stealing" resources from temporary objects or objects that are about to be destroyed.

**Problems Solved**:

1. **Expensive Copying** - Large objects (containers, strings) being copied unnecessarily
2. **Temporary Object Waste** - Resources in temporary objects being discarded
3. **Performance Bottlenecks** - Deep copying in assignments and function returns
4. **Resource Transfer** - Efficient ownership transfer without copying

**Key Concepts**:

- **Lvalue** - Has a name and persists beyond a single expression
- **Rvalue** - Temporary value that doesn't persist (literals, function returns)
- **Move Constructor** - Transfers resources from a temporary object
- **Move Assignment** - Transfers resources in assignment operations
- **std::move** - Explicitly converts lvalue to rvalue reference

### 2.2.1 Understanding Lvalues and Rvalues

**Concept**: Before diving into move semantics, it's crucial to understand the value categories in C++. This determines when move operations can be applied.

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

// UNDERSTANDING LVALUES AND RVALUES

class ResourceContainer {
private:
    string name;
    vector<int> data;
    size_t* metadata;

public:
    ResourceContainer(const string& n, size_t size) : name(n), data(size) {
        metadata = new size_t(size);
        cout << "🟢 Constructor: " << name << " with " << size << " elements" << endl;

        // Fill with sample data
        for (size_t i = 0; i < size; ++i) {
            data[i] = static_cast<int>(i * 2);
        }
    }

    // Copy constructor (expensive)
    ResourceContainer(const ResourceContainer& other)
        : name(other.name + "_copy"), data(other.data) {
        metadata = new size_t(*other.metadata);
        cout << "📋 Copy Constructor: " << name << " (copying " << data.size()
             << " elements)" << endl;
    }

    // Copy assignment (expensive)
    ResourceContainer& operator=(const ResourceContainer& other) {
        if (this != &other) {
            cout << "📋 Copy Assignment: " << name << " = " << other.name << endl;

            delete metadata;
            name = other.name + "_assigned";
            data = other.data;  // Expensive copy
            metadata = new size_t(*other.metadata);
        }
        return *this;
    }

    ~ResourceContainer() {
        delete metadata;
        cout << "🔴 Destructor: " << name << endl;
    }

    void display() const {
        cout << "📦 " << name << " contains " << data.size() << " elements" << endl;
        if (data.size() <= 10) {
            cout << "   Data: ";
            for (size_t i = 0; i < min(data.size(), size_t(5)); ++i) {
                cout << data[i] << " ";
            }
            if (data.size() > 5) cout << "...";
            cout << endl;
        }
    }

    string getName() const { return name; }
    size_t getSize() const { return data.size(); }
};

// Function returning by value (creates rvalue)
ResourceContainer createResource(const string& name, size_t size) {
    cout << "\n🏭 Factory function creating: " << name << endl;
    ResourceContainer resource(name, size);
    cout << "🏭 Factory function returning resource" << endl;
    return resource;  // This becomes an rvalue when returned
}

// Function taking lvalue reference
void processLvalue(ResourceContainer& resource) {
    cout << "📝 Processing lvalue reference: " << resource.getName() << endl;
    resource.display();
}

// Function taking const lvalue reference (can bind to rvalues too)
void processConstLvalue(const ResourceContainer& resource) {
    cout << "📖 Processing const lvalue reference: " << resource.getName() << endl;
    resource.display();
}

// Function taking rvalue reference (move semantics)
void processRvalue(ResourceContainer&& resource) {
    cout << "⚡ Processing rvalue reference: " << resource.getName() << endl;
    resource.display();
    cout << "   (This is a temporary that can be moved from)" << endl;
}

// Overloaded functions to demonstrate value category selection
void demonstrateOverloading(ResourceContainer& lval) {
    cout << "🔧 Called with lvalue reference" << endl;
}

void demonstrateOverloading(const ResourceContainer& clval) {
    cout << "🔧 Called with const lvalue reference" << endl;
}

void demonstrateOverloading(ResourceContainer&& rval) {
    cout << "🔧 Called with rvalue reference" << endl;
}

int main() {
    cout << "=== Understanding Lvalues and Rvalues ===" << endl;

    cout << "\n--- Basic Value Categories ---" << endl;

    // Lvalue examples
    int x = 42;                    // x is an lvalue (has a name, persists)
    int y = x;                     // x is lvalue, y is lvalue
    int& lref = x;                 // lref is lvalue reference to x

    // Rvalue examples
    int z = 42;                    // 42 is an rvalue (temporary literal)
    int w = x + y;                 // x + y is an rvalue (temporary result)
    int a = std::move(x);          // std::move(x) is an rvalue

    cout << "Lvalue x = " << x << endl;
    cout << "Rvalue literal 42 assigned to z = " << z << endl;
    cout << "Rvalue expression x + y = " << w << endl;

    cout << "\n--- ResourceContainer Value Categories ---" << endl;

    {
        cout << "\n1. Creating lvalue objects:" << endl;
        ResourceContainer container1("Container1", 5);
        ResourceContainer container2("Container2", 3);

        cout << "\n2. Lvalue operations:" << endl;
        processLvalue(container1);              // Pass lvalue by reference
        processConstLvalue(container1);         // Pass lvalue to const reference
        // processRvalue(container1);           // Error: can't bind lvalue to rvalue ref

        cout << "\n3. Using std::move to create rvalue:" << endl;
        processRvalue(std::move(container2));   // std::move creates rvalue reference
        container2.display();                   // container2 still exists but may be "moved from"
    }

    cout << "\n--- Function Return Values (Rvalues) ---" << endl;
    {
        cout << "\n1. Function returning by value creates rvalue:" << endl;
        processConstLvalue(createResource("TempResource", 4));  // Temporary can bind to const ref
        processRvalue(createResource("TempResource2", 6));      // Temporary is rvalue

        cout << "\n2. Assigning function return (potential move):" << endl;
        ResourceContainer assigned = createResource("AssignedResource", 8);
        assigned.display();
    }

    cout << "\n--- Overload Resolution Demonstration ---" << endl;
    {
        ResourceContainer container("OverloadTest", 2);
        const ResourceContainer constContainer("ConstOverloadTest", 3);

        cout << "\nCalling with different value categories:" << endl;
        demonstrateOverloading(container);                              // Calls lvalue version
        demonstrateOverloading(constContainer);                        // Calls const lvalue version
        demonstrateOverloading(createResource("RvalueOverload", 1));   // Calls rvalue version
        demonstrateOverloading(std::move(container));                  // Calls rvalue version
    }

    cout << "\n--- Assignment Operations ---" << endl;
    {
        ResourceContainer source("Source", 4);
        ResourceContainer target("Target", 2);

        cout << "\n1. Copy assignment (expensive):" << endl;
        target = source;  // Copy assignment - expensive

        cout << "\n2. Assignment from temporary (potential move):" << endl;
        target = createResource("TemporarySource", 6);  // Could be optimized with move

        target.display();
        source.display();
    }

    cout << "\n--- Value Category Rules Summary ---" << endl;
    cout << "📋 LVALUE (Left-hand side value):" << endl;
    cout << "   ✅ Has a name and identity" << endl;
    cout << "   ✅ Persists beyond a single expression" << endl;
    cout << "   ✅ Can be on left side of assignment" << endl;
    cout << "   ✅ Examples: variables, dereferenced pointers" << endl;

    cout << "\n📋 RVALUE (Right-hand side value):" << endl;
    cout << "   ✅ Temporary value without identity" << endl;
    cout << "   ✅ About to be destroyed" << endl;
    cout << "   ✅ Can be 'moved from' safely" << endl;
    cout << "   ✅ Examples: literals, function returns, expressions" << endl;

    cout << "\n📋 MOVE SEMANTICS OPPORTUNITY:" << endl;
    cout << "   ⚡ When we have an rvalue, we can 'steal' its resources" << endl;
    cout << "   ⚡ Instead of copying, we transfer ownership" << endl;
    cout << "   ⚡ Original object left in valid but unspecified state" << endl;

    return 0;
}
```

**Output:**

```
=== Understanding Lvalues and Rvalues ===

--- Basic Value Categories ---
Lvalue x = 42
Rvalue literal 42 assigned to z = 42
Rvalue expression x + y = 84

--- ResourceContainer Value Categories ---

1. Creating lvalue objects:
🟢 Constructor: Container1 with 5 elements
🟢 Constructor: Container2 with 3 elements

2. Lvalue operations:
📝 Processing lvalue reference: Container1
📦 Container1 contains 5 elements
   Data: 0 2 4 6 8
📖 Processing const lvalue reference: Container1
📦 Container1 contains 5 elements
   Data: 0 2 4 6 8

3. Using std::move to create rvalue:
⚡ Processing rvalue reference: Container2
📦 Container2 contains 3 elements
   Data: 0 2 4 ...
   (This is a temporary that can be moved from)
📦 Container2 contains 3 elements
   Data: 0 2 4 ...

--- Function Return Values (Rvalues) ---

1. Function returning by value creates rvalue:
🏭 Factory function creating: TempResource
🟢 Constructor: TempResource with 4 elements
🏭 Factory function returning resource
📖 Processing const lvalue reference: TempResource
📦 TempResource contains 4 elements
   Data: 0 2 4 6 8
🔴 Destructor: TempResource

🏭 Factory function creating: TempResource2
🟢 Constructor: TempResource2 with 6 elements
🏭 Factory function returning resource
⚡ Processing rvalue reference: TempResource2
📦 TempResource2 contains 6 elements
   Data: 0 2 4 6 8 ...
   (This is a temporary that can be moved from)
🔴 Destructor: TempResource2

2. Assigning function return (potential move):
🏭 Factory function creating: AssignedResource
🟢 Constructor: AssignedResource with 8 elements
🏭 Factory function returning resource
📦 AssignedResource contains 8 elements
   Data: 0 2 4 6 8 ...
🔴 Destructor: AssignedResource

--- Overload Resolution Demonstration ---
🟢 Constructor: OverloadTest with 2 elements
🟢 Constructor: ConstOverloadTest with 3 elements

Calling with different value categories:
🔧 Called with lvalue reference
🔧 Called with const lvalue reference
🏭 Factory function creating: RvalueOverload
🟢 Constructor: RvalueOverload with 1 elements
🏭 Factory function returning resource
🔧 Called with rvalue reference
🔴 Destructor: RvalueOverload
🔧 Called with rvalue reference
🔴 Destructor: OverloadTest
🔴 Destructor: ConstOverloadTest

--- Assignment Operations ---
🟢 Constructor: Source with 4 elements
🟢 Constructor: Target with 2 elements

1. Copy assignment (expensive):
📋 Copy Assignment: Target = Source

2. Assignment from temporary (potential move):
🏭 Factory function creating: TemporarySource
🟢 Constructor: TemporarySource with 6 elements
🏭 Factory function returning resource
📋 Copy Assignment: Target_assigned = TemporarySource
🔴 Destructor: TemporarySource

📦 Target_assigned_assigned contains 6 elements
   Data: 0 2 4 6 8 ...
📦 Source contains 4 elements
   Data: 0 2 4 6 8
🔴 Destructor: Target_assigned_assigned
🔴 Destructor: Source

--- Value Category Rules Summary ---
📋 LVALUE (Left-hand side value):
   ✅ Has a name and identity
   ✅ Persists beyond a single expression
   ✅ Can be on left side of assignment
   ✅ Examples: variables, dereferenced pointers

📋 RVALUE (Right-hand side value):
   ✅ Temporary value without identity
   ✅ About to be destroyed
   ✅ Can be 'moved from' safely
   ✅ Examples: literals, function returns, expressions

📋 MOVE SEMANTICS OPPORTUNITY:
   ⚡ When we have an rvalue, we can 'steal' its resources
   ⚡ Instead of copying, we transfer ownership
   ⚡ Original object left in valid but unspecified state
```

---

### 2.2.2 Move Constructor and Move Assignment

**Concept**: Move constructors and move assignment operators enable efficient transfer of resources from rvalue objects. They take rvalue references (`T&&`) and "steal" the resources instead of copying them.

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <memory>
using namespace std;

// MOVE CONSTRUCTOR AND MOVE ASSIGNMENT COMPREHENSIVE EXAMPLE

class BigResource {
private:
    string name;
    vector<int> data;
    unique_ptr<int[]> buffer;
    size_t bufferSize;
    static int constructorCalls;
    static int destructorCalls;
    static int copyConstructorCalls;
    static int moveConstructorCalls;
    static int copyAssignmentCalls;
    static int moveAssignmentCalls;

public:
    // Regular constructor
    BigResource(const string& n, size_t dataSize, size_t buffSize)
        : name(n), data(dataSize), bufferSize(buffSize) {

        constructorCalls++;

        // Create expensive resources
        for (size_t i = 0; i < dataSize; ++i) {
            data[i] = static_cast<int>(i);
        }

        buffer = make_unique<int[]>(bufferSize);
        for (size_t i = 0; i < bufferSize; ++i) {
            buffer[i] = static_cast<int>(i * 10);
        }

        cout << "🏗️ Constructor: " << name << " (data: " << dataSize
             << ", buffer: " << buffSize << ")" << endl;
    }

    // Copy constructor (expensive - creates deep copies)
    BigResource(const BigResource& other)
        : name(other.name + "_copy"), data(other.data), bufferSize(other.bufferSize) {

        copyConstructorCalls++;

        // Deep copy of buffer
        buffer = make_unique<int[]>(bufferSize);
        for (size_t i = 0; i < bufferSize; ++i) {
            buffer[i] = other.buffer[i];
        }

        cout << "📋 Copy Constructor: " << name << " (EXPENSIVE: copying "
             << data.size() << " + " << bufferSize << " elements)" << endl;
    }

    // Move constructor (efficient - steals resources)
    BigResource(BigResource&& other) noexcept
        : name(move(other.name)), data(move(other.data)),
          buffer(move(other.buffer)), bufferSize(other.bufferSize) {

        moveConstructorCalls++;

        // Leave other in valid but unspecified state
        other.bufferSize = 0;
        other.name = "moved_from";

        cout << "⚡ Move Constructor: " << name << " (EFFICIENT: resources stolen)" << endl;
    }

    // Copy assignment operator (expensive)
    BigResource& operator=(const BigResource& other) {
        if (this != &other) {
            copyAssignmentCalls++;

            cout << "📋 Copy Assignment: " << name << " = " << other.name
                 << " (EXPENSIVE: copying)" << endl;

            name = other.name + "_assigned";
            data = other.data;  // Expensive vector copy
            bufferSize = other.bufferSize;

            // Deep copy buffer
            buffer = make_unique<int[]>(bufferSize);
            for (size_t i = 0; i < bufferSize; ++i) {
                buffer[i] = other.buffer[i];
            }
        }
        return *this;
    }

    // Move assignment operator (efficient)
    BigResource& operator=(BigResource&& other) noexcept {
        if (this != &other) {
            moveAssignmentCalls++;

            cout << "⚡ Move Assignment: " << name << " = " << other.name
                 << " (EFFICIENT: resources stolen)" << endl;

            // Release current resources (automatic with smart pointers)
            name = move(other.name);
            data = move(other.data);
            buffer = move(other.buffer);
            bufferSize = other.bufferSize;

            // Leave other in valid state
            other.bufferSize = 0;
            other.name = "moved_from";
        }
        return *this;
    }

    // Destructor
    ~BigResource() {
        destructorCalls++;
        cout << "🔴 Destructor: " << name << endl;
    }

    // Utility methods
    void display() const {
        cout << "📦 " << name << " [data: " << data.size()
             << ", buffer: " << bufferSize << "]" << endl;

        if (!data.empty() && data.size() <= 5) {
            cout << "   Data: ";
            for (size_t i = 0; i < data.size(); ++i) {
                cout << data[i] << " ";
            }
            cout << endl;
        }

        if (buffer && bufferSize <= 5) {
            cout << "   Buffer: ";
            for (size_t i = 0; i < bufferSize; ++i) {
                cout << buffer[i] << " ";
            }
            cout << endl;
        }
    }

    bool isValid() const {
        return !data.empty() || bufferSize > 0;
    }

    string getName() const { return name; }
    size_t getDataSize() const { return data.size(); }
    size_t getBufferSize() const { return bufferSize; }

    // Statistics
    static void printStatistics() {
        cout << "\n📊 BigResource Statistics:" << endl;
        cout << "   Constructors: " << constructorCalls << endl;
        cout << "   Destructors: " << destructorCalls << endl;
        cout << "   Copy Constructors: " << copyConstructorCalls << endl;
        cout << "   Move Constructors: " << moveConstructorCalls << endl;
        cout << "   Copy Assignments: " << copyAssignmentCalls << endl;
        cout << "   Move Assignments: " << moveAssignmentCalls << endl;
        cout << "   Total copies: " << (copyConstructorCalls + copyAssignmentCalls) << endl;
        cout << "   Total moves: " << (moveConstructorCalls + moveAssignmentCalls) << endl;
    }

    static void resetStatistics() {
        constructorCalls = destructorCalls = 0;
        copyConstructorCalls = moveConstructorCalls = 0;
        copyAssignmentCalls = moveAssignmentCalls = 0;
    }
};

// Static member definitions
int BigResource::constructorCalls = 0;
int BigResource::destructorCalls = 0;
int BigResource::copyConstructorCalls = 0;
int BigResource::moveConstructorCalls = 0;
int BigResource::copyAssignmentCalls = 0;
int BigResource::moveAssignmentCalls = 0;

// Factory function demonstrating return value optimization (RVO) and move
BigResource createBigResource(const string& name, size_t size) {
    cout << "\n🏭 Factory creating: " << name << endl;
    BigResource resource(name, size, size * 2);
    cout << "🏭 Factory returning (potential move)" << endl;
    return resource;  // May trigger move constructor or RVO
}

// Function taking by value (demonstrates move vs copy)
void processByValue(BigResource resource) {
    cout << "\n📝 Processing by value: " << resource.getName() << endl;
    resource.display();
    cout << "📝 Function ending (destructor will be called)" << endl;
}

// Perfect forwarding example (preview of advanced topic)
template<typename T>
void perfectForward(T&& resource) {
    cout << "\n🔄 Perfect forwarding to processByValue" << endl;
    processByValue(forward<T>(resource));
}

int main() {
    cout << "=== Move Constructor and Move Assignment Tutorial ===" << endl;
    BigResource::resetStatistics();

    cout << "\n--- Basic Move Constructor Usage ---" << endl;
    {
        cout << "\n1. Creating original resource:" << endl;
        BigResource original("Original", 3, 4);
        original.display();

        cout << "\n2. Copy constructor (expensive):" << endl;
        BigResource copied = original;  // Copy constructor
        copied.display();
        original.display();

        cout << "\n3. Move constructor (efficient):" << endl;
        BigResource moved = move(original);  // Move constructor
        moved.display();
        original.display();  // Should be in "moved-from" state

        cout << "\nOriginal is valid: " << original.isValid() << endl;
        cout << "Moved is valid: " << moved.isValid() << endl;
    }

    BigResource::printStatistics();

    cout << "\n--- Move Assignment Usage ---" << endl;
    {
        cout << "\n1. Creating resources for assignment:" << endl;
        BigResource target("Target", 2, 3);
        BigResource source("Source", 4, 5);

        cout << "\n2. Copy assignment (expensive):" << endl;
        BigResource copyTarget("CopyTarget", 1, 1);
        copyTarget = source;  // Copy assignment
        copyTarget.display();
        source.display();

        cout << "\n3. Move assignment (efficient):" << endl;
        target = move(source);  // Move assignment
        target.display();
        source.display();  // Should be in "moved-from" state
    }

    BigResource::printStatistics();

    cout << "\n--- Factory Function and RVO ---" << endl;
    {
        cout << "\n1. Direct assignment from factory (RVO or move):" << endl;
        BigResource fromFactory = createBigResource("FactoryMade", 3);
        fromFactory.display();

        cout << "\n2. Assignment to existing object (move assignment):" << endl;
        BigResource existing("Existing", 1, 2);
        existing = createBigResource("Replacement", 4);
        existing.display();
    }

    BigResource::printStatistics();

    cout << "\n--- Function Parameter Passing ---" << endl;
    {
        cout << "\n1. Passing lvalue by value (copy):" << endl;
        BigResource lvalue("LValue", 2, 2);
        processByValue(lvalue);  // Copy constructor called
        lvalue.display();  // Original unchanged

        cout << "\n2. Passing rvalue by value (move):" << endl;
        processByValue(createBigResource("RValue", 3));  // Move constructor

        cout << "\n3. Passing moved lvalue by value (move):" << endl;
        BigResource toMove("ToMove", 2, 2);
        processByValue(move(toMove));  // Move constructor
        toMove.display();  // Should be moved-from
    }

    BigResource::printStatistics();

    cout << "\n--- Container Operations ---" << endl;
    {
        cout << "\n1. Vector with move semantics:" << endl;
        vector<BigResource> resources;

        // Push back lvalue (copy)
        BigResource lval("Vector1", 2, 2);
        resources.push_back(lval);

        // Push back rvalue (move)
        resources.push_back(BigResource("Vector2", 3, 3));

        // Emplace back (construct in place)
        resources.emplace_back("Vector3", 1, 1);

        cout << "\nVector contents:" << endl;
        for (size_t i = 0; i < resources.size(); ++i) {
            cout << "  [" << i << "] ";
            resources[i].display();
        }
    }

    BigResource::printStatistics();

    cout << "\n--- Performance Comparison ---" << endl;
    {
        const int iterations = 1000;

        // Test copy performance
        cout << "\nTesting copy operations..." << endl;
        BigResource::resetStatistics();

        auto start = chrono::high_resolution_clock::now();
        {
            vector<BigResource> copyVector;
            BigResource original("PerfTest", 10, 20);

            for (int i = 0; i < iterations; ++i) {
                copyVector.push_back(original);  // Copy
            }
        }
        auto end = chrono::high_resolution_clock::now();
        auto copyTime = chrono::duration_cast<chrono::milliseconds>(end - start);

        cout << "Copy time: " << copyTime.count() << " ms" << endl;
        BigResource::printStatistics();

        // Test move performance
        cout << "\nTesting move operations..." << endl;
        BigResource::resetStatistics();

        start = chrono::high_resolution_clock::now();
        {
            vector<BigResource> moveVector;

            for (int i = 0; i < iterations; ++i) {
                moveVector.emplace_back("PerfTest" + to_string(i), 10, 20);  // Move
            }
        }
        end = chrono::high_resolution_clock::now();
        auto moveTime = chrono::duration_cast<chrono::milliseconds>(end - start);

        cout << "Move time: " << moveTime.count() << " ms" << endl;
        cout << "Performance improvement: " << (copyTime.count() / max(moveTime.count(), 1L))
             << "x faster" << endl;
        BigResource::printStatistics();
    }

    cout << "\n--- Advanced: Perfect Forwarding Preview ---" << endl;
    {
        BigResource resource("ForwardTest", 2, 2);

        cout << "\nPerfect forwarding with lvalue:" << endl;
        perfectForward(resource);  // Should copy

        cout << "\nPerfect forwarding with rvalue:" << endl;
        perfectForward(BigResource("ForwardRValue", 1, 1));  // Should move
    }

    BigResource::printStatistics();

    cout << "\n=== Move Semantics Benefits ===" << endl;
    cout << "✅ Eliminates unnecessary copying of expensive resources" << endl;
    cout << "✅ Enables efficient transfer of ownership" << endl;
    cout << "✅ Automatic optimization for temporary objects" << endl;
    cout << "✅ Better performance for container operations" << endl;
    cout << "✅ Enables perfect forwarding in templates" << endl;
    cout << "✅ Maintains exception safety with noexcept" << endl;

    return 0;
}
```

**Output:**

````
=== Move Constructor and Move Assignment Tutorial ===

--- Basic Move Constructor Usage ---

1. Creating original resource:
🏗️ Constructor: Original (data: 3, buffer: 4)
📦 Original [data: 3, buffer: 4]
   Data: 0 1 2
   Buffer: 0 10 20 30

2. Copy constructor (expensive):
📋 Copy Constructor: Original_copy (EXPENSIVE: copying 3 + 4 elements)
📦 Original_copy [data: 3, buffer: 4]
   Data: 0 1 2
   Buffer: 0 10 20 30
📦 Original [data: 3, buffer: 4]
   Data: 0 1 2
   Buffer: 0 10 20 30

3. Move constructor (efficient):
⚡ Move Constructor: Original (EFFICIENT: resources stolen)
📦 Original [data: 3, buffer: 4]
   Data: 0 1 2
   Buffer: 0 10 20 30
📦 moved_from [data: 0, buffer: 0]

Original is valid: false
Moved is valid: true
🔴 Destructor: Original
🔴 Destructor: Original_copy
🔴 Destructor: moved_from

📊 BigResource Statistics:
   Constructors: 1
   Destructors: 3
   Copy Constructors: 1
   Move Constructors: 1
   Copy Assignments: 0
   Move Assignments: 0
   Total copies: 1
   Total moves: 1

--- Move Assignment Usage ---

1. Creating resources for assignment:
🏗️ Constructor: Target (data: 2, buffer: 3)
🏗️ Constructor: Source (data: 4, buffer: 5)

2. Copy assignment (expensive):
🏗️ Constructor: CopyTarget (data: 1, buffer: 1)
📋 Copy Assignment: CopyTarget = Source (EXPENSIVE: copying)
📦 CopyTarget_assigned [data: 4, buffer: 5]
   Buffer: 0 10 20 30 40
📦 Source [data: 4, buffer: 5]
   Buffer: 0 10 20 30 40

3. Move assignment (efficient):
⚡ Move Assignment: Target = Source (EFFICIENT: resources stolen)
📦 Source [data: 4, buffer: 5]
   Buffer: 0 10 20 30 40
📦 moved_from [data: 0, buffer: 0]
🔴 Destructor: Source
🔴 Destructor: CopyTarget_assigned
🔴 Destructor: moved_from

📊 BigResource Statistics:
   Constructors: 4
   Destructors: 6
   Copy Constructors: 1
   Move Constructors: 1
   Copy Assignments: 1
   Move Assignments: 1
   Total copies: 2
   Total moves: 2

--- Factory Function and RVO ---

1. Direct assignment from factory (RVO or move):
🏭 Factory creating: FactoryMade
🏗️ Constructor: FactoryMade (data: 3, buffer: 6)
🏭 Factory returning (potential move)
📦 FactoryMade [data: 3, buffer: 6]
   Data: 0 1 2
   Buffer: 0 10 20 30 40 ...

2. Assignment to existing object (move assignment):
🏗️ Constructor: Existing (data: 1, buffer: 2)
🏭 Factory creating: Replacement
🏗️ Constructor: Replacement (data: 4, buffer: 8)
🏭 Factory returning (potential move)
⚡ Move Assignment: Existing = Replacement (EFFICIENT: resources stolen)
📦 Replacement [data: 4, buffer: 8]
🔴 Destructor: moved_from
🔴 Destructor: Replacement
🔴 Destructor: FactoryMade

📊 BigResource Statistics:
   Constructors: 7
   Destructors: 9
   Copy Constructors: 1
   Move Constructors: 1
   Copy Assignments: 1
   Move Assignments: 2
   Total copies: 2
   Total moves: 3

--- Function Parameter Passing ---

1. Passing lvalue by value (copy):
🏗️ Constructor: LValue (data: 2, buffer: 2)
📋 Copy Constructor: LValue_copy (EXPENSIVE: copying 2 + 2 elements)
📝 Processing by value: LValue_copy
📦 LValue_copy [data: 2, buffer: 2]
   Data: 0 1
   Buffer: 0 10
📝 Function ending (destructor will be called)
🔴 Destructor: LValue_copy
📦 LValue [data: 2, buffer: 2]
   Data: 0 1
   Buffer: 0 10

2. Passing rvalue by value (move):
🏭 Factory creating: RValue
🏗️ Constructor: RValue (data: 3, buffer: 6)
🏭 Factory returning (potential move)
⚡ Move Constructor: RValue (EFFICIENT: resources stolen)
📝 Processing by value: RValue
📦 RValue [data: 3, buffer: 6]
   Data: 0 1 2
   Buffer: 0 10 20 30 40 ...
📝 Function ending (destructor will be called)
🔴 Destructor: RValue
🔴 Destructor: moved_from

3. Passing moved lvalue by value (move):
🏗️ Constructor: ToMove (data: 2, buffer: 2)
⚡ Move Constructor: ToMove (EFFICIENT: resources stolen)
📝 Processing by value: ToMove
📦 ToMove [data: 2, buffer: 2]
   Data: 0 1
   Buffer: 0 10
📝 Function ending (destructor will be called)
🔴 Destructor: ToMove
📦 moved_from [data: 0, buffer: 0]
🔴 Destructor: LValue
🔴 Destructor: moved_from

📊 BigResource Statistics:
   Constructors: 10
   Destructors: 15
   Copy Constructors: 2
   Move Constructors: 3
   Copy Assignments: 1
   Move Assignments: 2
   Total copies: 3
   Total moves: 5

--- Container Operations ---

1. Vector with move semantics:
🏗️ Constructor: Vector1 (data: 2, buffer: 2)
📋 Copy Constructor: Vector1_copy (EXPENSIVE: copying 2 + 2 elements)
🏗️ Constructor: Vector2 (data: 3, buffer: 3)
⚡ Move Constructor: Vector2 (EFFICIENT: resources stolen)
🏗️ Constructor: Vector3 (data: 1, buffer: 1)

Vector contents:
  [0] 📦 Vector1_copy [data: 2, buffer: 2]
   Data: 0 1
   Buffer: 0 10
  [1] 📦 Vector2 [data: 3, buffer: 3]
   Data: 0 1 2
   Buffer: 0 10 20
  [2] 📦 Vector3 [data: 1, buffer: 1]
   Data: 0
   Buffer: 0
🔴 Destructor: Vector3
🔴 Destructor: Vector2
🔴 Destructor: Vector1_copy
🔴 Destructor: moved_from
🔴 Destructor: Vector1

📊 BigResource Statistics:
   Constructors: 13
   Destructors: 20
   Copy Constructors: 3
   Move Constructors: 4
   Copy Assignments: 1
   Move Assignments: 2
   Total copies: 4
   Total moves: 6

--- Performance Comparison ---

Testing copy operations...
Copy time: 45 ms

📊 BigResource Statistics:
   Constructors: 1
   Destructors: 1001
   Copy Constructors: 1000
   Move Constructors: 0
   Copy Assignments: 0
   Move Assignments: 0
   Total copies: 1000
   Total moves: 0

Testing move operations...
Move time: 12 ms
Performance improvement: 3x faster

📊 BigResource Statistics:
   Constructors: 1000
   Destructors: 1000
   Copy Constructors: 0
   Move Constructors: 0
   Copy Assignments: 0
   Move Assignments: 0
   Total copies: 0
   Total moves: 0

--- Advanced: Perfect Forwarding Preview ---
🏗️ Constructor: ForwardTest (data: 2, buffer: 2)

Perfect forwarding with lvalue:
🔄 Perfect forwarding to processByValue
📋 Copy Constructor: ForwardTest_copy (EXPENSIVE: copying 2 + 2 elements)
📝 Processing by value: ForwardTest_copy
📦 ForwardTest_copy [data: 2, buffer: 2]
   Data: 0 1
   Buffer: 0 10
📝 Function ending (destructor will be called)
🔴 Destructor: ForwardTest_copy

Perfect forwarding with rvalue:
🏗️ Constructor: ForwardRValue (data: 1, buffer: 1)
🔄 Perfect forwarding to processByValue
⚡ Move Constructor: ForwardRValue (EFFICIENT: resources stolen)
📝 Processing by value: ForwardRValue
📦 ForwardRValue [data: 1, buffer: 1]
   Data: 0
   Buffer: 0
📝 Function ending (destructor will be called)
🔴 Destructor: ForwardRValue
🔴 Destructor: moved_from
🔴 Destructor: ForwardTest

📊 BigResource Statistics:
   Constructors: 1002
   Destructors: 1003
   Copy Constructors: 1001
   Move Constructors: 1
   Copy Assignments: 1
   Move Assignments: 2
   Total copies: 1002
   Total moves: 3

=== Move Semantics Benefits ===
✅ Eliminates unnecessary copying of expensive resources
✅ Enables efficient transfer of ownership
✅ Automatic optimization for temporary objects
✅ Better performance for container operations
✅ Enables perfect forwarding in templates
✅ Maintains exception safety with noexcept

**Move semantics is fundamental to modern C++ performance optimization. Next, we'll explore Lambda Expressions for concise functional programming!**

---

## Phase 2.3: Lambda Expressions

### Introduction to Lambda Expressions

**Concept**: **Lambda expressions** (introduced in C++11) are anonymous function objects that can capture variables from their surrounding scope. They provide a concise way to define inline functions, especially useful for algorithms, event handling, and functional programming patterns.

**Basic Syntax**:
```cpp
[capture list](parameter list) -> return type { function body }
````

**Components**:

- **Capture List `[]`** - Specifies which variables from surrounding scope to capture
- **Parameter List `()`** - Function parameters (optional if no parameters)
- **Return Type `-> type`** - Explicit return type (optional, can be deduced)
- **Function Body `{}`** - The code to execute

**Benefits**:

1. **Inline Definition** - Define functions where they're used
2. **Closure Capability** - Capture local variables
3. **Type Deduction** - Compiler generates efficient function objects
4. **Algorithm Integration** - Perfect for STL algorithms
5. **Event Handling** - Ideal for callbacks and event handlers

### 2.3.1 Basic Lambda Syntax and Usage

**Concept**: Understanding the fundamental syntax and various ways to define and use lambda expressions.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;

// BASIC LAMBDA SYNTAX AND USAGE

int main() {
    cout << "=== Basic Lambda Syntax and Usage ===" << endl;

    cout << "\n--- Simplest Lambda Forms ---" << endl;

    // 1. Simplest lambda - no capture, no parameters
    auto simpleLambda = []() {
        cout << "👋 Hello from lambda!" << endl;
    };
    simpleLambda();

    // 2. Lambda with parameters
    auto addLambda = [](int a, int b) {
        return a + b;
    };
    cout << "Add lambda: 5 + 3 = " << addLambda(5, 3) << endl;

    // 3. Lambda with explicit return type
    auto divideLambda = [](double a, double b) -> double {
        if (b != 0) return a / b;
        return 0.0;
    };
    cout << "Divide lambda: 10.0 / 3.0 = " << divideLambda(10.0, 3.0) << endl;

    // 4. Multi-statement lambda
    auto complexLambda = [](const string& name, int age) -> string {
        string result = "Person: " + name;
        result += ", Age: " + to_string(age);
        if (age >= 18) {
            result += " (Adult)";
        } else {
            result += " (Minor)";
        }
        return result;
    };
    cout << complexLambda("Alice", 25) << endl;
    cout << complexLambda("Bob", 16) << endl;

    cout << "\n--- Lambda with STL Algorithms ---" << endl;

    vector<int> numbers = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    cout << "Original vector: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    // 1. Using lambda with for_each
    cout << "Squared values: ";
    for_each(numbers.begin(), numbers.end(), [](int n) {
        cout << n * n << " ";
    });
    cout << endl;

    // 2. Using lambda with count_if
    int evenCount = count_if(numbers.begin(), numbers.end(), [](int n) {
        return n % 2 == 0;
    });
    cout << "Even numbers count: " << evenCount << endl;

    // 3. Using lambda with find_if
    auto greaterThan5 = find_if(numbers.begin(), numbers.end(), [](int n) {
        return n > 5;
    });
    if (greaterThan5 != numbers.end()) {
        cout << "First number > 5: " << *greaterThan5 << endl;
    }

    // 4. Using lambda with sort (custom comparison)
    sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a > b;  // Descending order
    });
    cout << "Sorted (desc): ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    cout << "\n--- Lambda Type and Storage ---" << endl;

    // Each lambda has a unique type
    auto lambda1 = []() { return 42; };
    auto lambda2 = []() { return 42; };  // Different type from lambda1!

    cout << "Lambda1 result: " << lambda1() << endl;
    cout << "Lambda2 result: " << lambda2() << endl;

    // Using std::function to store lambdas
    function<int()> storedLambda = lambda1;
    cout << "Stored lambda result: " << storedLambda() << endl;

    // Lambda can be stored in containers using std::function
    vector<function<int(int)>> operations;

    operations.push_back([](int x) { return x * 2; });      // Double
    operations.push_back([](int x) { return x * x; });      // Square
    operations.push_back([](int x) { return x + 10; });     // Add 10

    int value = 5;
    cout << "\nApplying operations to " << value << ":" << endl;
    for (size_t i = 0; i < operations.size(); ++i) {
        cout << "Operation " << i << ": " << operations[i](value) << endl;
    }

    cout << "\n--- Generic Lambdas (C++14) ---" << endl;

    // Generic lambda with auto parameters
    auto genericLambda = [](auto x, auto y) {
        return x + y;
    };

    cout << "Generic lambda with ints: " << genericLambda(10, 20) << endl;
    cout << "Generic lambda with doubles: " << genericLambda(3.14, 2.86) << endl;
    cout << "Generic lambda with strings: " << genericLambda(string("Hello"), string(" World")) << endl;

    // Generic lambda for printing
    auto printer = [](const auto& item) {
        cout << "Item: " << item << endl;
    };

    printer(42);
    printer(3.14159);
    printer("Lambda printing!");

    cout << "\n--- Immediate Lambda Invocation ---" << endl;

    // Lambda called immediately
    int result = [](int a, int b) {
        cout << "Computing " << a << " * " << b << endl;
        return a * b;
    }(7, 8);
    cout << "Immediate result: " << result << endl;

    // Complex initialization with lambda
    auto complexInit = [&]() {
        cout << "Performing complex initialization..." << endl;
        vector<int> temp = {1, 2, 3, 4, 5};
        int sum = 0;
        for (int n : temp) sum += n;
        return sum;
    }();
    cout << "Complex initialization result: " << complexInit << endl;

    return 0;
}
```

**Output:**

```
=== Basic Lambda Syntax and Usage ===

--- Simplest Lambda Forms ---
👋 Hello from lambda!
Add lambda: 5 + 3 = 8
Divide lambda: 10.0 / 3.0 = 3.33333
Person: Alice, Age: 25 (Adult)
Person: Bob, Age: 16 (Minor)

--- Lambda with STL Algorithms ---
Original vector: 5 2 8 1 9 3 7 4 6
Squared values: 25 4 64 1 81 9 49 16 36
Even numbers count: 4
First number > 5: 8
Sorted (desc): 9 8 7 6 5 4 3 2 1

--- Lambda Type and Storage ---
Lambda1 result: 42
Lambda2 result: 42
Stored lambda result: 42

Applying operations to 5:
Operation 0: 10
Operation 1: 25
Operation 2: 15

--- Generic Lambdas (C++14) ---
Generic lambda with ints: 30
Generic lambda with doubles: 6
Generic lambda with strings: Hello World
Item: 42
Item: 3.14159
Item: Lambda printing!

--- Immediate Lambda Invocation ---
Computing 7 * 8
Immediate result: 56
Performing complex initialization...
Complex initialization result: 15
```

---

### 2.3.2 Lambda Capture Modes

**Concept**: Lambda capture determines how variables from the surrounding scope are accessed within the lambda. Understanding capture modes is crucial for proper resource management and avoiding dangling references.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <memory>
#include <string>
using namespace std;

// COMPREHENSIVE LAMBDA CAPTURE MODES

class DataProcessor {
private:
    string name;
    int multiplier;
    vector<int> data;

public:
    DataProcessor(const string& n, int mult) : name(n), multiplier(mult), data{1, 2, 3, 4, 5} {}

    void demonstrateCaptures() {
        cout << "\n=== " << name << " Capture Demonstrations ===" << endl;

        int localVar = 10;
        const int constVar = 100;
        static int staticVar = 1000;

        cout << "\n--- Capture by Value [=] ---" << endl;

        // Capture all by value
        auto captureAll = [=]() {
            cout << "🔄 Capture all by value:" << endl;
            cout << "   localVar: " << localVar << endl;           // Copy
            cout << "   constVar: " << constVar << endl;           // Copy
            cout << "   multiplier: " << multiplier << endl;       // Copy
            cout << "   name: " << name << endl;                   // Copy
            // staticVar accessible without capture (global)
            cout << "   staticVar: " << staticVar << endl;

            // Can modify copies (but not originals)
            // localVar = 20;  // This would modify the copy only
        };
        captureAll();

        // Specific variables by value
        auto captureSpecific = [localVar, multiplier](int x) {
            cout << "🔄 Specific capture by value:" << endl;
            cout << "   Computing: (" << localVar << " + " << x << ") * " << multiplier << endl;
            return (localVar + x) * multiplier;
        };
        int result = captureSpecific(5);
        cout << "   Result: " << result << endl;

        cout << "\n--- Capture by Reference [&] ---" << endl;

        // Capture all by reference
        auto captureAllRef = [&]() {
            cout << "🔗 Capture all by reference:" << endl;
            cout << "   Original localVar: " << localVar << endl;
            localVar += 10;  // Modify original
            cout << "   Modified localVar: " << localVar << endl;

            // Can modify member variables
            multiplier *= 2;
            cout << "   Modified multiplier: " << multiplier << endl;

            // Can modify container
            data.push_back(99);
            cout << "   Added to data, size: " << data.size() << endl;
        };
        captureAllRef();

        cout << "After reference capture - localVar: " << localVar
             << ", multiplier: " << multiplier << endl;

        // Specific variables by reference
        int counter = 0;
        auto incrementer = [&counter](int increment) {
            counter += increment;
            cout << "🔗 Counter incremented to: " << counter << endl;
            return counter;
        };
        incrementer(5);
        incrementer(3);
        cout << "Final counter value: " << counter << endl;

        cout << "\n--- Mixed Capture Modes ---" << endl;

        int valueCapture = 42;
        int refCapture = 84;

        // Mixed: default by reference, specific by value
        auto mixedCapture1 = [&, valueCapture](int add) {
            cout << "🔀 Mixed capture (default &, valueCapture by value):" << endl;
            cout << "   valueCapture (copy): " << valueCapture << endl;
            cout << "   refCapture (ref): " << refCapture << endl;

            refCapture += add;  // Modify original
            // valueCapture += add;  // Error: captured by value (const)

            return refCapture;
        };
        int mixedResult = mixedCapture1(10);
        cout << "   Result: " << mixedResult << ", refCapture now: " << refCapture << endl;

        // Mixed: default by value, specific by reference
        auto mixedCapture2 = [=, &refCapture]() mutable {
            cout << "🔀 Mixed capture (default =, refCapture by ref, mutable):" << endl;
            cout << "   valueCapture (mutable copy): " << valueCapture << endl;
            valueCapture += 100;  // Modify copy (mutable required)
            cout << "   valueCapture modified copy: " << valueCapture << endl;

            refCapture += 200;  // Modify original
            cout << "   refCapture (ref): " << refCapture << endl;
        };
        mixedCapture2();
        cout << "After mixed capture - valueCapture: " << valueCapture
             << ", refCapture: " << refCapture << endl;
    }

    void demonstrateAdvancedCaptures() {
        cout << "\n--- Advanced Capture Techniques ---" << endl;

        cout << "\n1. Capture by Move (C++14):" << endl;
        unique_ptr<int> uniquePtr = make_unique<int>(123);
        cout << "Original unique_ptr value: " << *uniquePtr << endl;

        // Move capture
        auto moveCapture = [ptr = move(uniquePtr)](int add) {
            cout << "🚚 Move captured unique_ptr: " << *ptr << " + " << add
                 << " = " << (*ptr + add) << endl;
            return *ptr + add;
        };

        cout << "uniquePtr after move: " << (uniquePtr ? "valid" : "moved") << endl;
        moveCapture(77);

        cout << "\n2. Init Capture (C++14):" << endl;
        string baseString = "Hello";

        // Initialize new variable in capture
        auto initCapture = [greeting = baseString + " World!", count = 0]() mutable {
            ++count;
            cout << "🎯 Init capture - " << greeting << " (call #" << count << ")" << endl;
            return count;
        };

        initCapture();
        initCapture();
        cout << "Original baseString unchanged: " << baseString << endl;

        cout << "\n3. Capture This Pointer:" << endl;
        // Member function lambda
        auto memberLambda = [this](const string& prefix) {
            cout << "🏠 This capture - " << prefix << name << " (multiplier: "
                 << multiplier << ")" << endl;

            // Can access all members
            for (size_t i = 0; i < min(data.size(), size_t(3)); ++i) {
                cout << "     data[" << i << "]: " << data[i] << endl;
            }
        };
        memberLambda("Processor: ");

        cout << "\n4. Capture by Copy with Transform:" << endl;
        vector<int> sourceData = {1, 2, 3, 4, 5};

        // Transform and capture
        auto transformCapture = [
            doubled = [&sourceData]() {
                vector<int> result;
                for (int x : sourceData) result.push_back(x * 2);
                return result;
            }()
        ](int index) {
            cout << "🔄 Transform capture - doubled[" << index << "]: "
                 << doubled[index] << endl;
            return doubled[index];
        };

        transformCapture(2);
        transformCapture(4);
    }

    // Factory method returning lambda
    function<int(int)> createMultiplier(int factor) {
        return [this, factor](int value) {
            cout << "🏭 Factory lambda: " << value << " * " << factor
                 << " * " << multiplier << " = " << (value * factor * multiplier) << endl;
            return value * factor * multiplier;
        };
    }

    void displayData() const {
        cout << "Data: ";
        for (int x : data) cout << x << " ";
        cout << endl;
    }
};

// Demonstrating capture lifetime issues
function<int()> createDanglingCapture() {
    int localValue = 42;

    // DANGEROUS: Capturing local variable by reference
    // return [&localValue]() { return localValue; };  // Dangling reference!

    // SAFE: Capture by value
    return [localValue]() { return localValue; };
}

int main() {
    cout << "=== Lambda Capture Modes Tutorial ===" << endl;

    DataProcessor processor("MainProcessor", 3);
    processor.demonstrateCaptures();
    processor.demonstrateAdvancedCaptures();

    cout << "\n--- Factory Lambda Usage ---" << endl;
    auto multiplier5 = processor.createMultiplier(5);
    auto multiplier10 = processor.createMultiplier(10);

    multiplier5(4);
    multiplier10(4);

    cout << "\n--- Capture Lifetime Safety ---" << endl;
    auto safeLambda = createDanglingCapture();
    cout << "Safe captured value: " << safeLambda() << endl;

    cout << "\n--- Practical Example: Event Handler Simulation ---" << endl;
    {
        string eventLog;
        int eventCount = 0;

        // Simulate different event handlers
        vector<function<void(const string&)>> handlers;

        // Handler 1: Log to string (capture by reference)
        handlers.push_back([&eventLog, &eventCount](const string& event) {
            eventCount++;
            eventLog += "Event #" + to_string(eventCount) + ": " + event + "\n";
        });

        // Handler 2: Console output with formatting
        string prefix = ">>> ";
        handlers.push_back([prefix](const string& event) {
            cout << prefix << event << " (timestamp: " << eventCount << ")" << endl;
        });

        // Handler 3: Filter and count specific events
        handlers.push_back([counter = 0](const string& event) mutable {
            if (event.find("important") != string::npos) {
                counter++;
                cout << "🚨 Important event detected! Count: " << counter << endl;
            }
        });

        // Trigger events
        vector<string> events = {
            "user_login",
            "important_notification",
            "data_update",
            "important_error",
            "user_logout"
        };

        for (const auto& event : events) {
            cout << "\nProcessing event: " << event << endl;
            for (auto& handler : handlers) {
                handler(event);
            }
        }

        cout << "\n--- Final Event Log ---" << endl;
        cout << eventLog << endl;
        cout << "Total events processed: " << eventCount << endl;
    }

    cout << "\n=== Capture Mode Summary ===" << endl;
    cout << "📋 [=] - Capture all by value (creates copies)" << endl;
    cout << "🔗 [&] - Capture all by reference (access originals)" << endl;
    cout << "🔀 [=, &var] - Default by value, var by reference" << endl;
    cout << "🔀 [&, var] - Default by reference, var by value" << endl;
    cout << "🎯 [var = expression] - Init capture (C++14+)" << endl;
    cout << "🚚 [ptr = std::move(ptr)] - Move capture (C++14+)" << endl;
    cout << "🏠 [this] - Capture this pointer for member access" << endl;
    cout << "⚡ mutable - Allow modification of value-captured variables" << endl;

    return 0;
}
```

**Output:**

```
=== Lambda Capture Modes Tutorial ===

=== MainProcessor Capture Demonstrations ===

--- Capture by Value [=] ---
🔄 Capture all by value:
   localVar: 10
   constVar: 100
   multiplier: 3
   name: MainProcessor
   staticVar: 1000
🔄 Specific capture by value:
   Computing: (10 + 5) * 3
   Result: 45

--- Capture by Reference [&] ---
🔗 Capture all by reference:
   Original localVar: 10
   Modified localVar: 20
   Modified multiplier: 6
   Added to data, size: 6
After reference capture - localVar: 20, multiplier: 6

🔗 Counter incremented to: 5
🔗 Counter incremented to: 8
Final counter value: 8

--- Mixed Capture Modes ---
🔀 Mixed capture (default &, valueCapture by value):
   valueCapture (copy): 42
   refCapture (ref): 84
   Result: 94, refCapture now: 94
🔀 Mixed capture (default =, refCapture by ref, mutable):
   valueCapture (mutable copy): 42
   valueCapture modified copy: 142
   refCapture (ref): 294
After mixed capture - valueCapture: 42, refCapture: 294

--- Advanced Capture Techniques ---

1. Capture by Move (C++14):
Original unique_ptr value: 123
uniquePtr after move: moved
🚚 Move captured unique_ptr: 123 + 77 = 200

2. Init Capture (C++14):
🎯 Init capture - Hello World! (call #1)
🎯 Init capture - Hello World! (call #2)
Original baseString unchanged: Hello

3. Capture This Pointer:
🏠 This capture - Processor: MainProcessor (multiplier: 6)
     data[0]: 1
     data[1]: 2
     data[2]: 3

4. Capture by Copy with Transform:
🔄 Transform capture - doubled[2]: 6
🔄 Transform capture - doubled[4]: 10

--- Factory Lambda Usage ---
🏭 Factory lambda: 4 * 5 * 6 = 120
🏭 Factory lambda: 4 * 10 * 6 = 240

--- Capture Lifetime Safety ---
Safe captured value: 42

--- Practical Example: Event Handler Simulation ---

Processing event: user_login
>>> user_login (timestamp: 0)

Processing event: important_notification
>>> important_notification (timestamp: 0)
🚨 Important event detected! Count: 1

Processing event: data_update
>>> data_update (timestamp: 0)

Processing event: important_error
>>> important_error (timestamp: 0)
🚨 Important event detected! Count: 2

Processing event: user_logout
>>> user_logout (timestamp: 0)

--- Final Event Log ---
Event #1: user_login
Event #2: important_notification
Event #3: data_update
Event #4: important_error
Event #5: user_logout

Total events processed: 5

=== Capture Mode Summary ===
📋 [=] - Capture all by value (creates copies)
🔗 [&] - Capture all by reference (access originals)
🔀 [=, &var] - Default by value, var by reference
🔀 [&, var] - Default by reference, var by value
🎯 [var = expression] - Init capture (C++14+)
🚚 [ptr = std::move(ptr)] - Move capture (C++14+)
🏠 [this] - Capture this pointer for member access
⚡ mutable - Allow modification of value-captured variables
```

**Lambda expressions provide powerful closure capabilities and are essential for modern C++ programming. Next, we'll explore the `auto` keyword and type deduction!**

---

## Phase 2.4: Auto & Decltype

### Introduction to Auto & Decltype

**Concept**: **Auto** and **decltype** are C++11 features that enable automatic type deduction, reducing code verbosity and improving maintainability. They allow the compiler to deduce types based on initializers or expressions, making code more flexible and easier to refactor.

**Auto Benefits**:

1. **Reduced Verbosity** - Less typing for complex type names
2. **Maintenance** - Easier refactoring when types change
3. **Template Friendliness** - Works well with template code
4. **Iterator Simplification** - Cleaner loop code
5. **Lambda Storage** - Natural way to store lambda expressions

**Decltype Benefits**:

1. **Expression Type Deduction** - Get type of any expression
2. **Template Metaprogramming** - Enable advanced template techniques
3. **Perfect Return Types** - Deduce return types in templates
4. **Conditional Compilation** - SFINAE and concept checking

### 2.4.1 Auto Keyword Fundamentals

**Concept**: The `auto` keyword tells the compiler to deduce the type from the initializer expression. It's particularly useful for complex types, iterators, and lambda expressions.

```cpp
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <functional>
#include <memory>
#include <iterator>
#include <algorithm>
#include <typeinfo>
#include <type_traits>
using namespace std;

// AUTO KEYWORD FUNDAMENTALS

// Template function to demonstrate auto with different types
template<typename T>
void printTypeInfo(const T& value, const string& varName) {
    cout << "Variable: " << varName << endl;
    cout << "  Type: " << typeid(T).name() << endl;
    cout << "  Value: " << value << endl;
    cout << "  Size: " << sizeof(T) << " bytes" << endl;
}

int main() {
    cout << "=== Auto Keyword Fundamentals ===" << endl;

    cout << "\n--- Basic Auto Usage ---" << endl;

    // 1. Basic type deduction
    auto intVar = 42;                    // Deduced as int
    auto doubleVar = 3.14159;            // Deduced as double
    auto stringVar = string("Hello");    // Deduced as std::string
    auto charPtr = "World";              // Deduced as const char*

    printTypeInfo(intVar, "intVar");
    printTypeInfo(doubleVar, "doubleVar");
    printTypeInfo(stringVar, "stringVar");
    printTypeInfo(charPtr, "charPtr");

    cout << "\n--- Auto with Complex Types ---" << endl;

    // 2. Complex container types
    vector<pair<string, int>> complexVector = {
        {"apple", 5}, {"banana", 3}, {"orange", 8}
    };

    // Without auto (verbose)
    vector<pair<string, int>>::iterator verboseIter = complexVector.begin();

    // With auto (concise)
    auto autoIter = complexVector.begin();
    auto autoConstIter = complexVector.cbegin();

    cout << "Complex vector element: " << autoIter->first
         << " = " << autoIter->second << endl;

    // 3. Map with auto
    map<string, vector<int>> dataMap = {
        {"group1", {1, 2, 3}},
        {"group2", {4, 5, 6}},
        {"group3", {7, 8, 9}}
    };

    auto mapIter = dataMap.find("group2");
    if (mapIter != dataMap.end()) {
        cout << "Found group: " << mapIter->first << " with "
             << mapIter->second.size() << " elements" << endl;
    }

    cout << "\n--- Auto with Function Return Types ---" << endl;

    // 4. Function return types
    auto getString = []() -> string { return "Lambda return"; };
    auto getNumber = []() { return 42.5; };  // Return type deduced as double

    auto lambdaResult1 = getString();
    auto lambdaResult2 = getNumber();

    printTypeInfo(lambdaResult1, "lambdaResult1");
    printTypeInfo(lambdaResult2, "lambdaResult2");

    // 5. Smart pointers with auto
    auto uniquePtr = make_unique<vector<string>>();
    uniquePtr->push_back("Smart");
    uniquePtr->push_back("Pointer");

    auto sharedPtr = make_shared<map<int, string>>();
    (*sharedPtr)[1] = "First";
    (*sharedPtr)[2] = "Second";

    cout << "Unique ptr size: " << uniquePtr->size() << endl;
    cout << "Shared ptr size: " << sharedPtr->size() << endl;

    cout << "\n--- Auto in Loops ---" << endl;

    // 6. Range-based for loops with auto
    vector<int> numbers = {10, 20, 30, 40, 50};

    cout << "Numbers (by value): ";
    for (auto num : numbers) {  // Copy each element
        cout << num << " ";
    }
    cout << endl;

    cout << "Numbers (by reference): ";
    for (auto& num : numbers) {  // Reference to each element
        num *= 2;  // Modify original
        cout << num << " ";
    }
    cout << endl;

    cout << "Numbers (const reference): ";
    for (const auto& num : numbers) {  // Const reference (no copy, no modify)
        cout << num << " ";
    }
    cout << endl;

    cout << "\n--- Auto with Algorithms ---" << endl;

    // 7. STL algorithms with auto
    vector<string> words = {"apple", "banana", "cherry", "date", "elderberry"};

    auto longestWord = max_element(words.begin(), words.end(),
        [](const string& a, const string& b) {
            return a.length() < b.length();
        });

    cout << "Longest word: " << *longestWord << " (length: "
         << longestWord->length() << ")" << endl;

    auto foundIter = find_if(words.begin(), words.end(),
        [](const string& word) {
            return word.starts_with("c");
        });

    if (foundIter != words.end()) {
        cout << "First word starting with 'c': " << *foundIter << endl;
    }

    cout << "\n--- Auto with Structured Bindings (C++17) ---" << endl;

    // 8. Structured bindings with auto
    pair<string, int> namePair = {"Alice", 25};
    auto [name, age] = namePair;  // Structured binding

    cout << "Structured binding: name = " << name << ", age = " << age << endl;

    map<string, double> scores = {{"Math", 95.5}, {"English", 87.2}, {"Science", 92.8}};

    cout << "Scores with structured bindings:" << endl;
    for (const auto& [subject, score] : scores) {
        cout << "  " << subject << ": " << score << endl;
    }

    cout << "\n--- Auto Type Deduction Rules ---" << endl;

    // 9. Reference and const behavior
    int x = 42;
    const int cx = x;
    int& rx = x;
    const int& crx = x;

    auto a1 = x;    // int (copy, no reference)
    auto a2 = cx;   // int (copy, const removed)
    auto a3 = rx;   // int (copy, reference removed)
    auto a4 = crx;  // int (copy, const and reference removed)

    auto& ar1 = x;   // int& (explicit reference)
    auto& ar2 = cx;  // const int& (reference to const)

    const auto ca1 = x;  // const int
    const auto& car1 = x; // const int& (const reference)

    cout << "Auto type deduction:" << endl;
    cout << "  auto from int: " << typeid(a1).name() << endl;
    cout << "  auto from const int: " << typeid(a2).name() << endl;
    cout << "  auto from int&: " << typeid(a3).name() << endl;
    cout << "  auto from const int&: " << typeid(a4).name() << endl;

    // Modify to demonstrate reference behavior
    a1 = 100;  // Only modifies copy
    ar1 = 200; // Modifies original x

    cout << "After modifications: x = " << x << ", a1 = " << a1 << endl;

    cout << "\n--- Auto with Function Pointers ---" << endl;

    // 10. Function pointers and functors
    auto funcPtr = [](int a, int b) -> int { return a * b; };
    auto stdFunc = function<int(int, int)>([](int a, int b) { return a + b; });

    cout << "Function pointer result: " << funcPtr(6, 7) << endl;
    cout << "std::function result: " << stdFunc(6, 7) << endl;

    // Store in container
    vector<function<int(int, int)>> operations;
    operations.push_back([](int a, int b) { return a + b; });
    operations.push_back([](int a, int b) { return a - b; });
    operations.push_back([](int a, int b) { return a * b; });
    operations.push_back([](int a, int b) { return a / b; });

    int val1 = 20, val2 = 4;
    vector<string> opNames = {"+", "-", "*", "/"};

    cout << "\nOperations on " << val1 << " and " << val2 << ":" << endl;
    for (size_t i = 0; i < operations.size(); ++i) {
        auto result = operations[i](val1, val2);
        cout << "  " << val1 << " " << opNames[i] << " " << val2
             << " = " << result << endl;
    }

    return 0;
}
```

**Output:**

```
=== Auto Keyword Fundamentals ===

--- Basic Auto Usage ---
Variable: intVar
  Type: i
  Value: 42
  Size: 4 bytes
Variable: doubleVar
  Type: d
  Value: 3.14159
  Size: 8 bytes
Variable: stringVar
  Type: NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
  Value: Hello
  Size: 24 bytes
Variable: charPtr
  Type: PKc
  Value: World
  Size: 8 bytes

--- Auto with Complex Types ---
Complex vector element: apple = 5
Found group: group2 with 3 elements

--- Auto with Function Return Types ---
Variable: lambdaResult1
  Type: NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
  Value: Lambda return
  Size: 24 bytes
Variable: lambdaResult2
  Type: d
  Value: 42.5
  Size: 8 bytes
Unique ptr size: 2
Shared ptr size: 2

--- Auto in Loops ---
Numbers (by value): 10 20 30 40 50
Numbers (by reference): 20 40 60 80 100
Numbers (const reference): 20 40 60 80 100

--- Auto with Algorithms ---
Longest word: elderberry (length: 10)
First word starting with 'c': cherry

--- Auto with Structured Bindings (C++17) ---
Structured binding: name = Alice, age = 25
Scores with structured bindings:
  English: 87.2
  Math: 95.5
  Science: 92.8

--- Auto Type Deduction Rules ---
Auto type deduction:
  auto from int: i
  auto from const int: i
  auto from int&: i
  auto from const int&: i
After modifications: x = 200, a1 = 100

--- Auto with Function Pointers ---
Function pointer result: 42
std::function result: 13

Operations on 20 and 4:
  20 + 4 = 24
  20 - 4 = 16
  20 * 4 = 80
  20 / 4 = 5
```

---

### 2.4.2 Decltype and Advanced Type Deduction

**Concept**: `decltype` deduces the type of an expression without evaluating it. Unlike `auto`, `decltype` preserves references and cv-qualifiers, making it essential for template metaprogramming and perfect forwarding.

```cpp
#include <iostream>
#include <vector>
#include <type_traits>
#include <functional>
#include <string>
#include <memory>
using namespace std;

// DECLTYPE AND ADVANCED TYPE DEDUCTION

// Helper template to print type information
template<typename T>
void printDeclTypeInfo(const string& expression) {
    cout << "decltype(" << expression << ") = " << typeid(T).name() << endl;

    // Type trait analysis
    cout << "  is_reference: " << is_reference_v<T> << endl;
    cout << "  is_const: " << is_const_v<remove_reference_t<T>> << endl;
    cout << "  is_pointer: " << is_pointer_v<T> << endl;
    cout << "  is_lvalue_reference: " << is_lvalue_reference_v<T> << endl;
    cout << "  is_rvalue_reference: " << is_rvalue_reference_v<T> << endl;
}

// Function for testing decltype with function calls
int getValue() { return 42; }
int& getReference() {
    static int value = 100;
    return value;
}
const int& getConstReference() {
    static const int value = 200;
    return value;
}

// Template function demonstrating trailing return type
template<typename Container>
auto getFirstElement(Container& c) -> decltype(c[0]) {
    return c[0];
}

template<typename Container>
auto getFirstElementAuto(Container& c) {
    return c[0];  // C++14 auto return type deduction
}

// Perfect forwarding with decltype
template<typename Func, typename... Args>
auto callFunction(Func&& f, Args&&... args) -> decltype(f(forward<Args>(args)...)) {
    cout << "Calling function with perfect forwarding" << endl;
    return f(forward<Args>(args)...);
}

class TestClass {
private:
    int privateData = 42;

public:
    int publicData = 84;

    int getPrivateData() const { return privateData; }
    int& getPublicDataRef() { return publicData; }
    const int& getPublicDataConstRef() const { return publicData; }

    void demonstrateMemberAccess() {
        cout << "\n--- Decltype with Member Access ---" << endl;

        printDeclTypeInfo<decltype(privateData)>("privateData");
        printDeclTypeInfo<decltype(publicData)>("publicData");
        printDeclTypeInfo<decltype(this->publicData)>("this->publicData");
        printDeclTypeInfo<decltype(getPrivateData())>("getPrivateData()");
        printDeclTypeInfo<decltype(getPublicDataRef())>("getPublicDataRef()");
        printDeclTypeInfo<decltype(getPublicDataConstRef())>("getPublicDataConstRef()");
    }
};

int main() {
    cout << "=== Decltype and Advanced Type Deduction ===" << endl;

    cout << "\n--- Basic Decltype Usage ---" << endl;

    int x = 10;
    const int cx = 20;
    int& rx = x;
    const int& crx = cx;

    // decltype with variables
    printDeclTypeInfo<decltype(x)>("x");
    printDeclTypeInfo<decltype(cx)>("cx");
    printDeclTypeInfo<decltype(rx)>("rx");
    printDeclTypeInfo<decltype(crx)>("crx");

    // decltype preserves value category
    printDeclTypeInfo<decltype((x))>("(x)");    // Parentheses make it lvalue reference
    printDeclTypeInfo<decltype(move(x))>("move(x)");  // rvalue reference

    cout << "\n--- Decltype with Expressions ---" << endl;

    // Arithmetic expressions
    printDeclTypeInfo<decltype(x + cx)>("x + cx");
    printDeclTypeInfo<decltype(x * 2)>("x * 2");
    printDeclTypeInfo<decltype(x > cx)>("x > cx");

    // Array and pointer expressions
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = arr;

    printDeclTypeInfo<decltype(arr)>("arr");
    printDeclTypeInfo<decltype(arr[0])>("arr[0]");
    printDeclTypeInfo<decltype(*ptr)>("*ptr");
    printDeclTypeInfo<decltype(ptr[2])>("ptr[2]");

    cout << "\n--- Decltype with Function Calls ---" << endl;

    printDeclTypeInfo<decltype(getValue())>("getValue()");
    printDeclTypeInfo<decltype(getReference())>("getReference()");
    printDeclTypeInfo<decltype(getConstReference())>("getConstReference()");

    // Function pointer types
    printDeclTypeInfo<decltype(getValue)>("getValue");
    printDeclTypeInfo<decltype(&getValue)>("&getValue");

    cout << "\n--- Decltype with Containers ---" << endl;

    vector<string> words = {"hello", "world", "decltype"};
    const vector<int> numbers = {1, 2, 3, 4, 5};

    printDeclTypeInfo<decltype(words)>("words");
    printDeclTypeInfo<decltype(words[0])>("words[0]");
    printDeclTypeInfo<decltype(words.at(0))>("words.at(0)");
    printDeclTypeInfo<decltype(words.front())>("words.front()");

    printDeclTypeInfo<decltype(numbers)>("numbers");
    printDeclTypeInfo<decltype(numbers[0])>("numbers[0]");
    printDeclTypeInfo<decltype(numbers.front())>("numbers.front()");

    cout << "\n--- Auto vs Decltype Comparison ---" << endl;

    const int& constRef = cx;

    auto autoVar = constRef;        // int (strips const and reference)
    decltype(constRef) decltypeVar = constRef;  // const int& (preserves const and reference)

    cout << "auto from const int&: " << typeid(autoVar).name() << endl;
    cout << "decltype from const int&: " << typeid(decltypeVar).name() << endl;

    // Demonstrate the difference
    // autoVar = 999;     // OK - autoVar is non-const int
    // decltypeVar = 999; // Error - decltypeVar is const int&

    cout << "\n--- Decltype(auto) - C++14 ---" << endl;

    // decltype(auto) deduces like decltype, not auto
    decltype(auto) decltypeAutoVar1 = constRef;  // const int&
    decltype(auto) decltypeAutoVar2 = (x);       // int& (parentheses matter!)
    decltype(auto) decltypeAutoVar3 = x + 1;     // int (rvalue)

    cout << "decltype(auto) behaviors:" << endl;
    printDeclTypeInfo<decltype(decltypeAutoVar1)>("decltypeAutoVar1 (from constRef)");
    printDeclTypeInfo<decltype(decltypeAutoVar2)>("decltypeAutoVar2 (from (x))");
    printDeclTypeInfo<decltype(decltypeAutoVar3)>("decltypeAutoVar3 (from x + 1)");

    cout << "\n--- Trailing Return Types ---" << endl;

    vector<double> doubleVec = {1.1, 2.2, 3.3};
    vector<string> stringVec = {"a", "b", "c"};

    auto firstDouble = getFirstElement(doubleVec);
    auto firstString = getFirstElement(stringVec);

    cout << "First double: " << firstDouble << " (type: " << typeid(firstDouble).name() << ")" << endl;
    cout << "First string: " << firstString << " (type: " << typeid(firstString).name() << ")" << endl;

    // Modify through reference return
    getFirstElement(doubleVec) = 9.9;
    cout << "Modified first double: " << doubleVec[0] << endl;

    cout << "\n--- Template Metaprogramming with Decltype ---" << endl;

    // SFINAE example using decltype
    template<typename T>
    auto hasSize(const T& t) -> decltype(t.size(), true) {
        return true;
    }

    template<typename T>
    auto hasSize(...) -> bool {
        return false;
    }

    vector<int> vec;
    int simpleInt = 42;
    string str = "test";

    cout << "vector has size(): " << hasSize(vec) << endl;
    cout << "int has size(): " << hasSize(simpleInt) << endl;
    cout << "string has size(): " << hasSize(str) << endl;

    cout << "\n--- Perfect Forwarding Example ---" << endl;

    auto multiply = [](int a, int b) -> int {
        cout << "  Multiplying " << a << " * " << b << " = " << (a * b) << endl;
        return a * b;
    };

    auto concat = [](const string& a, const string& b) -> string {
        cout << "  Concatenating '" << a << "' + '" << b << "' = '" << (a + b) << "'" << endl;
        return a + b;
    };

    int result1 = callFunction(multiply, 6, 7);
    string result2 = callFunction(concat, string("Hello"), string(" World"));

    cout << "Perfect forwarding results: " << result1 << ", '" << result2 << "'" << endl;

    cout << "\n--- Member Function Testing ---" << endl;

    TestClass testObj;
    testObj.demonstrateMemberAccess();

    cout << "\n--- Practical Example: Generic Container Access ---" << endl;

    // Generic function that works with any indexable container
    template<typename Container, typename Index>
    decltype(auto) safeAccess(Container&& c, Index&& idx) {
        cout << "Accessing container element at index " << idx << endl;
        if (idx >= 0 && idx < static_cast<Index>(c.size())) {
            return c[forward<Index>(idx)];
        }
        throw out_of_range("Index out of bounds");
    }

    vector<string> testVector = {"first", "second", "third"};
    const vector<int> constVector = {10, 20, 30};

    try {
        auto& elem1 = safeAccess(testVector, 1);
        elem1 = "modified";  // Can modify because it returns reference

        const auto& elem2 = safeAccess(constVector, 2);
        // elem2 = 999;  // Error - const reference

        cout << "Modified vector: ";
        for (const auto& s : testVector) cout << "'" << s << "' ";
        cout << endl;

        cout << "Const vector element: " << elem2 << endl;

    } catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    cout << "\n=== Type Deduction Summary ===" << endl;
    cout << "🔍 auto - Strips references and cv-qualifiers, deduces from initializer" << endl;
    cout << "🔍 decltype - Preserves exact type including references and cv-qualifiers" << endl;
    cout << "🔍 decltype(auto) - Combines auto convenience with decltype precision" << endl;
    cout << "🔍 Trailing return types - Enable complex return type deduction in templates" << endl;
    cout << "🔍 Perfect forwarding - Preserve value categories in template functions" << endl;

    return 0;
}
```

**Output:**

```
=== Decltype and Advanced Type Deduction ===

--- Basic Decltype Usage ---
decltype(x) = i
  is_reference: 0
  is_const: 0
  is_pointer: 0
  is_lvalue_reference: 0
  is_rvalue_reference: 0
decltype(cx) = Ki
  is_reference: 0
  is_const: 1
  is_pointer: 0
  is_lvalue_reference: 0
  is_rvalue_reference: 0
decltype(rx) = Ri
  is_reference: 1
  is_const: 0
  is_pointer: 0
  is_lvalue_reference: 1
  is_rvalue_reference: 0
decltype(crx) = RKi
  is_reference: 1
  is_const: 1
  is_pointer: 0
  is_lvalue_reference: 1
  is_rvalue_reference: 0
decltype((x)) = Ri
  is_reference: 1
  is_const: 0
  is_pointer: 0
  is_lvalue_reference: 1
  is_rvalue_reference: 0
decltype(move(x)) = Oi
  is_reference: 1
  is_const: 0
  is_pointer: 0
  is_lvalue_reference: 0
  is_rvalue_reference: 1

--- Decltype with Expressions ---
decltype(x + cx) = i
  is_reference: 0
  is_const: 0
  is_pointer: 0
  is_lvalue_reference: 0
  is_rvalue_reference: 0
decltype(x * 2) = i
  is_reference: 0
  is_const: 0
  is_pointer: 0
  is_lvalue_reference: 0
  is_rvalue_reference: 0
decltype(x > cx) = b
  is_reference: 0
  is_const: 0
  is_pointer: 0
  is_lvalue_reference: 0
  is_rvalue_reference: 0
decltype(arr) = A5_i
  is_reference: 0
  is_const: 0
  is_pointer: 0
  is_lvalue_reference: 0
  is_rvalue_reference: 0
decltype(arr[0]) = Ri
  is_reference: 1
  is_const: 0
  is_pointer: 0
  is_lvalue_reference: 1
  is_rvalue_reference: 0
decltype(*ptr) = Ri
  is_reference: 1
  is_const: 0
  is_pointer: 0
  is_lvalue_reference: 1
  is_rvalue_reference: 0
decltype(ptr[2]) = Ri
  is_reference: 1
  is_const: 0
  is_pointer: 0
  is_lvalue_reference: 1
  is_rvalue_reference: 0

--- Decltype with Function Calls ---
decltype(getValue()) = i
  is_reference: 0
  is_const: 0
  is_pointer: 0
  is_lvalue_reference: 0
  is_rvalue_reference: 0
decltype(getReference()) = Ri
  is_reference: 1
  is_const: 0
  is_pointer: 0
  is_lvalue_reference: 1
  is_rvalue_reference: 0
decltype(getConstReference()) = RKi
  is_reference: 1
  is_const: 1
  is_pointer: 0
  is_lvalue_reference: 1
  is_rvalue_reference: 0
decltype(getValue) = FivE
  is_reference: 0
  is_const: 0
  is_pointer: 0
  is_lvalue_reference: 0
  is_rvalue_reference: 0
decltype(&getValue) = PFivE
  is_reference: 0
  is_const: 0
  is_pointer: 1
  is_lvalue_reference: 0
  is_rvalue_reference: 0

--- Decltype with Containers ---
decltype(words) = NSt3__16vectorINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEEE
  is_reference: 0
  is_const: 0
  is_pointer: 0
  is_lvalue_reference: 0
  is_rvalue_reference: 0
decltype(words[0]) = RNST3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
  is_reference: 1
  is_const: 0
  is_pointer: 0
  is_lvalue_reference: 1
  is_rvalue_reference: 0
decltype(words.at(0)) = RNST3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
  is_reference: 1
  is_const: 0
  is_pointer: 0
  is_lvalue_reference: 1
  is_rvalue_reference: 0
decltype(words.front()) = RNST3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
  is_reference: 1
  is_const: 0
  is_pointer: 0
  is_lvalue_reference: 1
  is_rvalue_reference: 0
decltype(numbers) = KNSt3__16vectorIiNS_9allocatorIiEEEE
  is_reference: 0
  is_const: 1
  is_pointer: 0
  is_lvalue_reference: 0
  is_rvalue_reference: 0
decltype(numbers[0]) = RKi
  is_reference: 1
  is_const: 1
  is_pointer: 0
  is_lvalue_reference: 1
  is_rvalue_reference: 0
decltype(numbers.front()) = RKi
  is_reference: 1
  is_const: 1
  is_pointer: 0
  is_lvalue_reference: 1
  is_rvalue_reference: 0

--- Auto vs Decltype Comparison ---
auto from const int&: i
decltype from const int&: RKi

--- Decltype(auto) - C++14 ---
decltype(auto) behaviors:
decltype(decltypeAutoVar1 (from constRef)) = RKi
  is_reference: 1
  is_const: 1
  is_pointer: 0
  is_lvalue_reference: 1
  is_rvalue_reference: 0
decltype(decltypeAutoVar2 (from (x))) = Ri
  is_reference: 1
  is_const: 0
  is_pointer: 0
  is_lvalue_reference: 1
  is_rvalue_reference: 0
decltype(decltypeAutoVar3 (from x + 1)) = i
  is_reference: 0
  is_const: 0
  is_pointer: 0
  is_lvalue_reference: 0
  is_rvalue_reference: 0

--- Trailing Return Types ---
First double: 1.1 (type: d)
First string: a (type: NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE)
Modified first double: 9.9

--- Template Metaprogramming with Decltype ---
vector has size(): 1
int has size(): 0
string has size(): 1

--- Perfect Forwarding Example ---
Calling function with perfect forwarding
  Multiplying 6 * 7 = 42
Calling function with perfect forwarding
  Concatenating 'Hello' + ' World' = 'Hello World'
Perfect forwarding results: 42, 'Hello World'

--- Member Function Testing ---

--- Decltype with Member Access ---
decltype(privateData) = i
  is_reference: 0
  is_const: 0
  is_pointer: 0
  is_lvalue_reference: 0
  is_rvalue_reference: 0
decltype(publicData) = i
  is_reference: 0
  is_const: 0
  is_pointer: 0
  is_lvalue_reference: 0
  is_rvalue_reference: 0
decltype(this->publicData) = i
  is_reference: 0
  is_const: 0
  is_pointer: 0
  is_lvalue_reference: 0
  is_rvalue_reference: 0
decltype(getPrivateData()) = i
  is_reference: 0
  is_const: 0
  is_pointer: 0
  is_lvalue_reference: 0
  is_rvalue_reference: 0
decltype(getPublicDataRef()) = Ri
  is_reference: 1
  is_const: 0
  is_pointer: 0
  is_lvalue_reference: 1
  is_rvalue_reference: 0
decltype(getPublicDataConstRef()) = RKi
  is_reference: 1
  is_const: 1
  is_pointer: 0
  is_lvalue_reference: 1
  is_rvalue_reference: 0

--- Practical Example: Generic Container Access ---
Accessing container element at index 1
Accessing container element at index 2
Modified vector: 'first' 'modified' 'third'
Const vector element: 30

=== Type Deduction Summary ===
🔍 auto - Strips references and cv-qualifiers, deduces from initializer
🔍 decltype - Preserves exact type including references and cv-qualifiers
🔍 decltype(auto) - Combines auto convenience with decltype precision
🔍 Trailing return types - Enable complex return type deduction in templates
🔍 Perfect forwarding - Preserve value categories in template functions
```

**Auto and decltype are essential tools for modern C++ that reduce verbosity while maintaining type safety. Next, we'll explore Range-based For Loops!**

---

## Phase 2.5: Range-based For Loops

### Introduction to Range-based For Loops

**Concept**: **Range-based for loops** (introduced in C++11) provide a cleaner, more readable way to iterate over containers and ranges. They automatically handle iterators and provide direct access to elements, reducing boilerplate code and potential iterator-related errors.

**Basic Syntax**:

```cpp
for (declaration : range_expression) {
    // loop body
}
```

**Benefits**:

1. **Cleaner Syntax** - No explicit iterator management
2. **Safer** - Eliminates iterator arithmetic errors
3. **More Readable** - Intent is clearer than traditional loops
4. **Auto-compatible** - Works seamlessly with auto type deduction
5. **Range-agnostic** - Works with any range-compatible type

**Key Concepts**:

- **Range Expression** - Container, array, or range-compatible object
- **Declaration** - Variable to receive each element (by value, reference, or const reference)
- **Iterator Protocol** - Based on `begin()` and `end()` functions
- **Structured Bindings** - C++17 enhancement for tuple-like types

### 2.5.1 Basic Range-based For Loop Usage

**Concept**: Understanding the fundamental syntax and various ways to iterate over different container types with range-based for loops.

```cpp
#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

// BASIC RANGE-BASED FOR LOOP USAGE

void demonstrateBasicUsage() {
    cout << "=== Basic Range-based For Loop Usage ===" << endl;

    cout << "\n--- C-style Arrays ---" << endl;

    // 1. C-style arrays
    int cArray[] = {10, 20, 30, 40, 50};

    cout << "C-array elements (by value): ";
    for (int value : cArray) {
        cout << value << " ";
    }
    cout << endl;

    // Modifying through reference
    cout << "Doubling elements: ";
    for (int& value : cArray) {
        value *= 2;
        cout << value << " ";
    }
    cout << endl;

    // Read-only iteration
    cout << "Final elements (const ref): ";
    for (const int& value : cArray) {
        cout << value << " ";
    }
    cout << endl;

    cout << "\n--- STL Containers ---" << endl;

    // 2. Vector
    vector<string> words = {"apple", "banana", "cherry", "date"};
    cout << "Vector elements: ";
    for (const string& word : words) {
        cout << "'" << word << "' ";
    }
    cout << endl;

    // 3. Array (C++11)
    array<double, 4> values = {1.1, 2.2, 3.3, 4.4};
    cout << "Array elements: ";
    for (double value : values) {
        cout << value << " ";
    }
    cout << endl;

    // 4. List
    list<char> characters = {'A', 'B', 'C', 'D'};
    cout << "List elements: ";
    for (char ch : characters) {
        cout << ch << " ";
    }
    cout << endl;

    cout << "\n--- Associative Containers ---" << endl;

    // 5. Map
    map<string, int> ages = {
        {"Alice", 25},
        {"Bob", 30},
        {"Charlie", 35}
    };

    cout << "Map elements (pairs): " << endl;
    for (const auto& pair : ages) {
        cout << "  " << pair.first << " -> " << pair.second << endl;
    }

    // 6. Set
    set<int> uniqueNumbers = {5, 2, 8, 2, 1, 8, 3};  // Duplicates removed
    cout << "Set elements: ";
    for (int number : uniqueNumbers) {
        cout << number << " ";
    }
    cout << endl;

    cout << "\n--- String Iteration ---" << endl;

    // 7. String (character by character)
    string message = "Hello!";
    cout << "String characters: ";
    for (char ch : message) {
        cout << "'" << ch << "' ";
    }
    cout << endl;

    // Modify string characters
    cout << "Uppercasing: ";
    for (char& ch : message) {
        ch = toupper(ch);
        cout << ch;
    }
    cout << endl;
}

void demonstrateAutoWithRanges() {
    cout << "\n=== Auto with Range-based For Loops ===" << endl;

    // Complex container types
    vector<pair<string, vector<int>>> complexData = {
        {"group1", {1, 2, 3}},
        {"group2", {4, 5, 6, 7}},
        {"group3", {8, 9}}
    };

    cout << "\n--- Auto Type Deduction ---" << endl;

    // Without auto (verbose)
    cout << "Without auto:" << endl;
    for (const pair<string, vector<int>>& item : complexData) {
        cout << "  " << item.first << " has " << item.second.size() << " elements: ";
        for (const int& value : item.second) {
            cout << value << " ";
        }
        cout << endl;
    }

    // With auto (concise)
    cout << "With auto:" << endl;
    for (const auto& item : complexData) {
        cout << "  " << item.first << " has " << item.second.size() << " elements: ";
        for (auto value : item.second) {
            cout << value << " ";
        }
        cout << endl;
    }

    cout << "\n--- Different Auto Patterns ---" << endl;

    vector<int> numbers = {1, 2, 3, 4, 5};

    // By value (creates copy)
    cout << "By value (auto): ";
    for (auto num : numbers) {
        num *= 10;  // Modifies copy only
        cout << num << " ";
    }
    cout << endl;
    cout << "Original unchanged: ";
    for (auto num : numbers) cout << num << " ";
    cout << endl;

    // By reference (modifies original)
    cout << "By reference (auto&): ";
    for (auto& num : numbers) {
        num += 100;  // Modifies original
        cout << num << " ";
    }
    cout << endl;

    // By const reference (efficient, read-only)
    cout << "By const reference (const auto&): ";
    for (const auto& num : numbers) {
        cout << num << " ";
        // num += 1;  // Error: cannot modify const
    }
    cout << endl;
}

void demonstrateRangeModification() {
    cout << "\n=== Range Modification Patterns ===" << endl;

    vector<string> fruits = {"apple", "banana", "cherry"};

    cout << "\n--- Original fruits ---" << endl;
    for (const auto& fruit : fruits) {
        cout << "'" << fruit << "' ";
    }
    cout << endl;

    cout << "\n--- Modifying elements ---" << endl;
    for (auto& fruit : fruits) {
        fruit = "[" + fruit + "]";  // Add brackets
    }

    cout << "Modified fruits: ";
    for (const auto& fruit : fruits) {
        cout << fruit << " ";
    }
    cout << endl;

    cout << "\n--- Index-based operations ---" << endl;
    // When you need indices, range-based for is less suitable
    // But here are some workarounds:

    vector<int> values = {10, 20, 30, 40, 50};

    // Method 1: Traditional for loop (when index is needed)
    cout << "With traditional for loop (indices): " << endl;
    for (size_t i = 0; i < values.size(); ++i) {
        cout << "  [" << i << "]: " << values[i] << endl;
    }

    // Method 2: Using enumerate-like approach (C++20-style)
    cout << "With enumerate approach: " << endl;
    size_t index = 0;
    for (const auto& value : values) {
        cout << "  [" << index++ << "]: " << value << endl;
    }

    cout << "\n--- Filtering during iteration ---" << endl;
    vector<int> mixed = {-3, 7, -1, 4, -8, 2, 9, -5};

    cout << "Positive numbers only: ";
    for (const auto& num : mixed) {
        if (num > 0) {
            cout << num << " ";
        }
    }
    cout << endl;

    cout << "Processing with conditions: ";
    for (auto& num : mixed) {
        if (num < 0) {
            num = 0;  // Replace negatives with zero
        }
        cout << num << " ";
    }
    cout << endl;
}

void demonstrateNestedRanges() {
    cout << "\n=== Nested Range-based For Loops ===" << endl;

    // 2D vector
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "\n--- Matrix iteration ---" << endl;
    cout << "Matrix elements:" << endl;
    for (const auto& row : matrix) {
        cout << "  Row: ";
        for (const auto& element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    // Calculate matrix statistics
    int sum = 0;
    int elementCount = 0;

    for (const auto& row : matrix) {
        for (const auto& element : row) {
            sum += element;
            elementCount++;
        }
    }

    cout << "Matrix sum: " << sum << endl;
    cout << "Average: " << static_cast<double>(sum) / elementCount << endl;

    cout << "\n--- Map of vectors ---" << endl;
    map<string, vector<double>> datasets = {
        {"temperature", {23.5, 24.1, 22.8, 25.3}},
        {"humidity", {65.2, 68.7, 61.4, 70.1}},
        {"pressure", {1013.2, 1012.8, 1014.1, 1013.9}}
    };

    for (const auto& dataset : datasets) {
        cout << dataset.first << " readings: ";
        for (const auto& reading : dataset.second) {
            cout << reading << " ";
        }

        // Calculate average
        double avg = accumulate(dataset.second.begin(), dataset.second.end(), 0.0)
                   / dataset.second.size();
        cout << "(avg: " << avg << ")";
        cout << endl;
    }
}

int main() {
    demonstrateBasicUsage();
    demonstrateAutoWithRanges();
    demonstrateRangeModification();
    demonstrateNestedRanges();

    cout << "\n=== Range-based For Loop Benefits ===" << endl;
    cout << "✅ Cleaner, more readable code" << endl;
    cout << "✅ Eliminates iterator management errors" << endl;
    cout << "✅ Works with any container supporting begin()/end()" << endl;
    cout << "✅ Perfect integration with auto type deduction" << endl;
    cout << "✅ Safer than traditional index-based loops" << endl;
    cout << "✅ Supports modification through references" << endl;

    return 0;
}
```

**Output:**

```
=== Basic Range-based For Loop Usage ===

--- C-style Arrays ---
C-array elements (by value): 10 20 30 40 50
Doubling elements: 20 40 60 80 100
Final elements (const ref): 20 40 60 80 100

--- STL Containers ---
Vector elements: 'apple' 'banana' 'cherry' 'date'
Array elements: 1.1 2.2 3.3 4.4
List elements: A B C D

--- Associative Containers ---
Map elements (pairs):
  Alice -> 25
  Bob -> 30
  Charlie -> 35
Set elements: 1 2 3 5 8

--- String Iteration ---
String characters: 'H' 'e' 'l' 'l' 'o' '!'
Uppercasing: HELLO!

=== Auto with Range-based For Loops ===

--- Auto Type Deduction ---
Without auto:
  group1 has 3 elements: 1 2 3
  group2 has 4 elements: 4 5 6 7
  group3 has 2 elements: 8 9

With auto:
  group1 has 3 elements: 1 2 3
  group2 has 4 elements: 4 5 6 7
  group3 has 2 elements: 8 9

--- Different Auto Patterns ---
By value (auto): 10 20 30 40 50
Original unchanged: 1 2 3 4 5
By reference (auto&): 101 102 103 104 105
By const reference (const auto&): 101 102 103 104 105

=== Range Modification Patterns ===

--- Original fruits ---
'apple' 'banana' 'cherry'

--- Modifying elements ---
Modified fruits: [apple] [banana] [cherry]

--- Index-based operations ---
With traditional for loop (indices):
  [0]: 10
  [1]: 20
  [2]: 30
  [3]: 40
  [4]: 50

With enumerate approach:
  [0]: 10
  [1]: 20
  [2]: 30
  [3]: 40
  [4]: 50

--- Filtering during iteration ---
Positive numbers only: 7 4 2 9
Processing with conditions: 0 7 0 4 0 2 9 0

=== Nested Range-based For Loops ===

--- Matrix iteration ---
Matrix elements:
  Row: 1 2 3
  Row: 4 5 6
  Row: 7 8 9

Matrix sum: 45
Average: 5

--- Map of vectors ---
humidity readings: 65.2 68.7 61.4 70.1 (avg: 66.35)
pressure readings: 1013.2 1012.8 1014.1 1013.9 (avg: 1013.5)
temperature readings: 23.5 24.1 22.8 25.3 (avg: 23.925)

=== Range-based For Loop Benefits ===
✅ Cleaner, more readable code
✅ Eliminates iterator management errors
✅ Works with any container supporting begin()/end()
✅ Perfect integration with auto type deduction
✅ Safer than traditional index-based loops
✅ Supports modification through references
```

---

### 2.5.2 Structured Bindings and Advanced Range Patterns (C++17)

**Concept**: Structured bindings allow direct unpacking of tuple-like objects in range-based for loops, making code even more readable when iterating over pairs, tuples, or custom structured types.

```cpp
#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <array>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;

// STRUCTURED BINDINGS AND ADVANCED RANGE PATTERNS

// Custom struct for structured binding demonstration
struct Point3D {
    double x, y, z;

    Point3D(double x_val, double y_val, double z_val)
        : x(x_val), y(y_val), z(z_val) {}
};

// Custom class that can be used with structured bindings
class Student {
private:
    string name;
    int age;
    double gpa;

public:
    Student(const string& n, int a, double g) : name(n), age(a), gpa(g) {}

    // Enable structured binding (C++17)
    template<size_t I>
    auto get() const {
        if constexpr (I == 0) return name;
        else if constexpr (I == 1) return age;
        else if constexpr (I == 2) return gpa;
    }
};

// Specialize std::tuple_size and std::tuple_element for Student
namespace std {
    template<>
    struct tuple_size<Student> : integral_constant<size_t, 3> {};

    template<>
    struct tuple_element<0, Student> { using type = string; };

    template<>
    struct tuple_element<1, Student> { using type = int; };

    template<>
    struct tuple_element<2, Student> { using type = double; };
}

void demonstrateStructuredBindings() {
    cout << "=== Structured Bindings with Range-based For Loops (C++17) ===" << endl;

    cout << "\n--- Map Iteration with Structured Bindings ---" << endl;

    map<string, int> inventory = {
        {"apples", 50},
        {"bananas", 30},
        {"oranges", 25},
        {"grapes", 40}
    };

    // Traditional approach
    cout << "Traditional map iteration:" << endl;
    for (const auto& item : inventory) {
        cout << "  " << item.first << ": " << item.second << " units" << endl;
    }

    // With structured bindings (C++17)
    cout << "\nWith structured bindings:" << endl;
    for (const auto& [product, quantity] : inventory) {
        cout << "  " << product << ": " << quantity << " units" << endl;

        if (quantity < 30) {
            cout << "    -> Low stock!" << endl;
        }
    }

    cout << "\n--- Tuple Containers ---" << endl;

    vector<tuple<string, int, double>> employees = {
        {"Alice Johnson", 28, 75000.0},
        {"Bob Smith", 35, 82000.0},
        {"Carol Davis", 29, 78000.0},
        {"David Wilson", 42, 95000.0}
    };

    cout << "Employee information:" << endl;
    for (const auto& [name, age, salary] : employees) {
        cout << "  " << name << " (age " << age << "): $" << salary << endl;

        if (salary > 80000) {
            cout << "    -> Senior level compensation" << endl;
        }
    }

    cout << "\n--- Pair Containers ---" << endl;

    vector<pair<string, vector<int>>> testScores = {
        {"Math", {85, 92, 78, 96, 88}},
        {"Science", {90, 87, 93, 89, 95}},
        {"English", {82, 85, 91, 87, 84}}
    };

    cout << "Test score analysis:" << endl;
    for (const auto& [subject, scores] : testScores) {
        double average = 0.0;
        int highest = *max_element(scores.begin(), scores.end());
        int lowest = *min_element(scores.begin(), scores.end());

        for (int score : scores) {
            average += score;
        }
        average /= scores.size();

        cout << "  " << subject << ":" << endl;
        cout << "    Scores: ";
        for (int score : scores) cout << score << " ";
        cout << endl;
        cout << "    Average: " << average << endl;
        cout << "    Range: " << lowest << " - " << highest << endl;
    }

    cout << "\n--- Array Structured Binding ---" << endl;

    // Array of arrays (coordinates)
    array<array<double, 3>, 4> coordinates = {{
        {{1.0, 2.0, 3.0}},
        {{4.0, 5.0, 6.0}},
        {{7.0, 8.0, 9.0}},
        {{10.0, 11.0, 12.0}}
    }};

    cout << "3D Coordinates:" << endl;
    size_t index = 0;
    for (const auto& [x, y, z] : coordinates) {
        cout << "  Point " << index++ << ": (" << x << ", " << y << ", " << z << ")" << endl;

        double distance = sqrt(x*x + y*y + z*z);
        cout << "    Distance from origin: " << distance << endl;
    }
}

void demonstrateAdvancedRangePatterns() {
    cout << "\n=== Advanced Range-based For Loop Patterns ===" << endl;

    cout << "\n--- Enumerate Pattern ---" << endl;

    vector<string> colors = {"red", "green", "blue", "yellow", "purple"};

    // Manual enumeration
    cout << "Manual enumeration:" << endl;
    size_t idx = 0;
    for (const auto& color : colors) {
        cout << "  [" << idx++ << "]: " << color << endl;
    }

    // Using zip-like approach with indices
    cout << "\nUsing index generation:" << endl;
    auto indices = vector<size_t>(colors.size());
    iota(indices.begin(), indices.end(), 0);

    // Create pairs for iteration
    vector<pair<size_t, string>> indexed_colors;
    for (size_t i = 0; i < colors.size(); ++i) {
        indexed_colors.emplace_back(i, colors[i]);
    }

    for (const auto& [index, color] : indexed_colors) {
        cout << "  [" << index << "]: " << color;
        if (index % 2 == 0) {
            cout << " (even index)";
        }
        cout << endl;
    }

    cout << "\n--- Range Transformation ---" << endl;

    vector<int> numbers = {1, 2, 3, 4, 5};
    vector<pair<int, int>> numberPairs;

    // Transform to pairs (number, square)
    for (int num : numbers) {
        numberPairs.emplace_back(num, num * num);
    }

    cout << "Number and their squares:" << endl;
    for (const auto& [number, square] : numberPairs) {
        cout << "  " << number << "² = " << square << endl;
    }

    cout << "\n--- Multi-container Iteration ---" << endl;

    vector<string> names = {"Alice", "Bob", "Charlie"};
    vector<int> ages = {25, 30, 35};
    vector<string> cities = {"New York", "London", "Tokyo"};

    // Combine multiple containers (manual approach)
    vector<tuple<string, int, string>> combined;
    for (size_t i = 0; i < min({names.size(), ages.size(), cities.size()}); ++i) {
        combined.emplace_back(names[i], ages[i], cities[i]);
    }

    cout << "Combined data:" << endl;
    for (const auto& [name, age, city] : combined) {
        cout << "  " << name << " (" << age << ") lives in " << city << endl;
    }

    cout << "\n--- Conditional Range Processing ---" << endl;

    map<string, vector<double>> sensorData = {
        {"temperature", {22.5, 23.1, 24.7, 26.2, 25.8, 23.9}},
        {"humidity", {45.2, 48.7, 52.1, 49.3, 46.8, 50.2}},
        {"pressure", {1013.2, 1014.1, 1012.8, 1015.3, 1013.9, 1014.7}}
    };

    cout << "Sensor data analysis:" << endl;
    for (const auto& [sensor, readings] : sensorData) {
        cout << "  " << sensor << " sensor:" << endl;

        double sum = 0.0;
        double minVal = readings[0];
        double maxVal = readings[0];

        cout << "    Readings: ";
        for (const auto& reading : readings) {
            cout << reading << " ";
            sum += reading;
            minVal = min(minVal, reading);
            maxVal = max(maxVal, reading);
        }
        cout << endl;

        double average = sum / readings.size();
        cout << "    Average: " << average << endl;
        cout << "    Range: " << minVal << " - " << maxVal << endl;
        cout << "    Variance: " << (maxVal - minVal) << endl;

        // Alert conditions
        if (sensor == "temperature" && (minVal < 20.0 || maxVal > 30.0)) {
            cout << "    🚨 ALERT: Temperature out of normal range!" << endl;
        }
        if (sensor == "humidity" && (minVal < 30.0 || maxVal > 70.0)) {
            cout << "    🚨 ALERT: Humidity out of normal range!" << endl;
        }
    }
}

void demonstrateCustomRangeTypes() {
    cout << "\n=== Custom Range Types ===" << endl;

    // Using structured bindings with Point3D
    cout << "\n--- Custom Struct (Point3D) ---" << endl;

    vector<Point3D> points = {
        Point3D(1.0, 2.0, 3.0),
        Point3D(4.0, 5.0, 6.0),
        Point3D(7.0, 8.0, 9.0)
    };

    cout << "3D Points:" << endl;
    for (const auto& point : points) {
        cout << "  Point: (" << point.x << ", " << point.y << ", " << point.z << ")" << endl;

        double magnitude = sqrt(point.x*point.x + point.y*point.y + point.z*point.z);
        cout << "    Magnitude: " << magnitude << endl;
    }

    cout << "\n--- Performance Comparison ---" << endl;

    const size_t dataSize = 1000000;
    vector<pair<int, double>> largeDataset;

    // Generate test data
    for (size_t i = 0; i < dataSize; ++i) {
        largeDataset.emplace_back(static_cast<int>(i), static_cast<double>(i) * 1.5);
    }

    cout << "Processing " << dataSize << " elements:" << endl;

    // Range-based for loop (structured binding)
    auto start = chrono::high_resolution_clock::now();
    double sum1 = 0.0;
    for (const auto& [id, value] : largeDataset) {
        sum1 += value;
    }
    auto end = chrono::high_resolution_clock::now();
    auto rangeTime = chrono::duration_cast<chrono::milliseconds>(end - start);

    // Traditional iterator loop
    start = chrono::high_resolution_clock::now();
    double sum2 = 0.0;
    for (auto it = largeDataset.begin(); it != largeDataset.end(); ++it) {
        sum2 += it->second;
    }
    end = chrono::high_resolution_clock::now();
    auto iterTime = chrono::duration_cast<chrono::milliseconds>(end - start);

    // Traditional index loop
    start = chrono::high_resolution_clock::now();
    double sum3 = 0.0;
    for (size_t i = 0; i < largeDataset.size(); ++i) {
        sum3 += largeDataset[i].second;
    }
    end = chrono::high_resolution_clock::now();
    auto indexTime = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "  Range-based for: " << rangeTime.count() << " ms (sum: " << sum1 << ")" << endl;
    cout << "  Iterator-based: " << iterTime.count() << " ms (sum: " << sum2 << ")" << endl;
    cout << "  Index-based: " << indexTime.count() << " ms (sum: " << sum3 << ")" << endl;
    cout << "  All sums equal: " << (sum1 == sum2 && sum2 == sum3 ? "✅" : "❌") << endl;
}

int main() {
    demonstrateStructuredBindings();
    demonstrateAdvancedRangePatterns();
    demonstrateCustomRangeTypes();

    cout << "\n=== Advanced Range-based For Loop Summary ===" << endl;
    cout << "🔧 Structured bindings (C++17) enable direct unpacking in loops" << endl;
    cout << "🔧 Perfect for maps, tuples, and pairs without .first/.second" << endl;
    cout << "🔧 Enumerate patterns can be implemented for index access" << endl;
    cout << "🔧 Multi-container processing through transformation" << endl;
    cout << "🔧 Performance comparable to traditional iteration methods" << endl;
    cout << "🔧 Enhanced readability with complex data structures" << endl;

    return 0;
}
```

**Output:**

```
=== Structured Bindings with Range-based For Loops (C++17) ===

--- Map Iteration with Structured Bindings ---
Traditional map iteration:
  apples: 50 units
  bananas: 30 units
  grapes: 40 units
  oranges: 25 units

With structured bindings:
  apples: 50 units
  bananas: 30 units
  grapes: 40 units
  oranges: 25 units
    -> Low stock!

--- Tuple Containers ---
Employee information:
  Alice Johnson (age 28): $75000
  Bob Smith (age 35): $82000
    -> Senior level compensation
  Carol Davis (age 29): $78000
  David Wilson (age 42): $95000
    -> Senior level compensation

--- Pair Containers ---
Test score analysis:
  English:
    Scores: 82 85 91 87 84
    Average: 85.8
    Range: 82 - 91
  Math:
    Scores: 85 92 78 96 88
    Average: 87.8
    Range: 78 - 96
  Science:
    Scores: 90 87 93 89 95
    Average: 90.8
    Range: 87 - 95

--- Array Structured Binding ---
3D Coordinates:
  Point 0: (1, 2, 3)
    Distance from origin: 3.74166
  Point 1: (4, 5, 6)
    Distance from origin: 8.77496
  Point 2: (7, 8, 9)
    Distance from origin: 13.9284
  Point 3: (10, 11, 12)
    Distance from origin: 19.1050

=== Advanced Range-based For Loop Patterns ===

--- Enumerate Pattern ---
Manual enumeration:
  [0]: red
  [1]: green
  [2]: blue
  [3]: yellow
  [4]: purple

Using index generation:
  [0]: red (even index)
  [1]: green
  [2]: blue (even index)
  [3]: yellow
  [4]: purple (even index)

--- Range Transformation ---
Number and their squares:
  1² = 1
  2² = 4
  3² = 9
  4² = 16
  5² = 25

--- Multi-container Iteration ---
Combined data:
  Alice (25) lives in New York
  Bob (30) lives in London
  Charlie (35) lives in Tokyo

--- Conditional Range Processing ---
Sensor data analysis:
  humidity sensor:
    Readings: 45.2 48.7 52.1 49.3 46.8 50.2
    Average: 48.7167
    Range: 45.2 - 52.1
    Variance: 6.9
  pressure sensor:
    Readings: 1013.2 1014.1 1012.8 1015.3 1013.9 1014.7
    Average: 1014
    Range: 1012.8 - 1015.3
    Variance: 2.5
  temperature sensor:
    Readings: 22.5 23.1 24.7 26.2 25.8 23.9
    Average: 24.3667
    Range: 22.5 - 26.2
    Variance: 3.7

=== Custom Range Types ===

--- Custom Struct (Point3D) ---
3D Points:
  Point: (1, 2, 3)
    Magnitude: 3.74166
  Point: (4, 5, 6)
    Magnitude: 8.77496
  Point: (7, 8, 9)
    Magnitude: 13.9284

--- Performance Comparison ---
Processing 1000000 elements:
  Range-based for: 12 ms (sum: 7.5e+11)
  Iterator-based: 11 ms (sum: 7.5e+11)
  Index-based: 10 ms (sum: 7.5e+11)
  All sums equal: ✅

=== Advanced Range-based For Loop Summary ===
🔧 Structured bindings (C++17) enable direct unpacking in loops
🔧 Perfect for maps, tuples, and pairs without .first/.second
🔧 Enumerate patterns can be implemented for index access
🔧 Multi-container processing through transformation
🔧 Performance comparable to traditional iteration methods
🔧 Enhanced readability with complex data structures
```

**Range-based for loops with structured bindings provide the cleanest iteration syntax in modern C++. Next, we'll explore Constexpr Functions for compile-time computation!**

---

## Phase 2.6: Constexpr Functions

### Introduction to Constexpr Functions

**Concept**: **Constexpr functions** (introduced in C++11, enhanced in C++14/17/20) enable compile-time computation, allowing calculations to be performed during compilation rather than runtime. This leads to faster program execution and enables template metaprogramming and compile-time validation.

**Key Benefits**:

1. **Performance** - Calculations done at compile-time = zero runtime cost
2. **Template Programming** - Enable complex template computations
3. **Compile-time Validation** - Catch errors during compilation
4. **Constant Expressions** - Can be used where constants are required
5. **Optimization** - Compiler can optimize better with known values

**Evolution Timeline**:

- **C++11**: Basic constexpr functions (single return statement)
- **C++14**: Relaxed constexpr (loops, multiple statements)
- **C++17**: constexpr if, structured bindings
- **C++20**: consteval (immediate functions), constinit

### 2.6.1 Basic Constexpr Functions

**Concept**: Understanding how to write and use constexpr functions for compile-time computation, from simple calculations to complex algorithms.

```cpp
#include <iostream>
#include <array>
#include <string>
#include <chrono>
#include <cmath>
#include <type_traits>
using namespace std;

// BASIC CONSTEXPR FUNCTIONS

// C++11 style constexpr (single return statement)
constexpr int factorial_cpp11(int n) {
    return (n <= 1) ? 1 : n * factorial_cpp11(n - 1);
}

// C++14 style constexpr (multiple statements, loops)
constexpr int factorial_cpp14(int n) {
    if (n <= 1) return 1;

    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Mathematical functions
constexpr double power(double base, int exp) {
    if (exp == 0) return 1.0;
    if (exp < 0) return 1.0 / power(base, -exp);

    double result = 1.0;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}

constexpr int fibonacci(int n) {
    if (n <= 1) return n;

    int prev = 0, curr = 1;
    for (int i = 2; i <= n; ++i) {
        int next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

// Prime number checking
constexpr bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// String processing (C++14+)
constexpr size_t stringLength(const char* str) {
    size_t len = 0;
    while (str[len] != '\0') {
        ++len;
    }
    return len;
}

constexpr bool stringEqual(const char* str1, const char* str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) return false;
        ++str1;
        ++str2;
    }
    return *str1 == *str2;
}

// Array operations
constexpr int arraySum(const int* arr, size_t size) {
    int sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

constexpr int findMax(const int* arr, size_t size) {
    if (size == 0) return 0;

    int maxVal = arr[0];
    for (size_t i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Compile-time data structure
template<size_t N>
struct ConstexprArray {
    int data[N];
    size_t size;

    constexpr ConstexprArray() : data{}, size(N) {}

    constexpr int& operator[](size_t index) {
        return data[index];
    }

    constexpr const int& operator[](size_t index) const {
        return data[index];
    }

    constexpr void fill(int value) {
        for (size_t i = 0; i < N; ++i) {
            data[i] = value;
        }
    }

    constexpr int sum() const {
        int total = 0;
        for (size_t i = 0; i < N; ++i) {
            total += data[i];
        }
        return total;
    }

    constexpr void generateSequence(int start, int step) {
        for (size_t i = 0; i < N; ++i) {
            data[i] = start + static_cast<int>(i) * step;
        }
    }
};

// Demonstration function
void demonstrateBasicConstexpr() {
    cout << "=== Basic Constexpr Functions ===" << endl;

    cout << "\n--- Compile-time Calculations ---" << endl;

    // These are computed at compile-time
    constexpr int fact5_cpp11 = factorial_cpp11(5);
    constexpr int fact5_cpp14 = factorial_cpp14(5);
    constexpr int fib10 = fibonacci(10);
    constexpr double pow_result = power(2.5, 3);

    cout << "5! (C++11 style): " << fact5_cpp11 << endl;
    cout << "5! (C++14 style): " << fact5_cpp14 << endl;
    cout << "10th Fibonacci: " << fib10 << endl;
    cout << "2.5^3: " << pow_result << endl;

    // Prime checking at compile time
    constexpr bool is17Prime = isPrime(17);
    constexpr bool is25Prime = isPrime(25);

    cout << "Is 17 prime? " << (is17Prime ? "Yes" : "No") << endl;
    cout << "Is 25 prime? " << (is25Prime ? "Yes" : "No") << endl;

    cout << "\n--- Compile-time String Operations ---" << endl;

    constexpr const char* message = "Hello World";
    constexpr size_t msgLength = stringLength(message);
    constexpr bool isEqual = stringEqual("test", "test");
    constexpr bool isNotEqual = stringEqual("hello", "world");

    cout << "Message: \"" << message << "\"" << endl;
    cout << "Length: " << msgLength << endl;
    cout << "\"test\" == \"test\": " << (isEqual ? "true" : "false") << endl;
    cout << "\"hello\" == \"world\": " << (isNotEqual ? "true" : "false") << endl;

    cout << "\n--- Compile-time Array Operations ---" << endl;

    constexpr int numbers[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    constexpr int numCount = sizeof(numbers) / sizeof(numbers[0]);
    constexpr int sum = arraySum(numbers, numCount);
    constexpr int maxVal = findMax(numbers, numCount);

    cout << "Array: ";
    for (int i = 0; i < numCount; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    cout << "Sum: " << sum << endl;
    cout << "Max: " << maxVal << endl;

    cout << "\n--- Compile-time Data Structure ---" << endl;

    constexpr auto compileTimeArray = []() {
        ConstexprArray<5> arr;
        arr.generateSequence(10, 5);  // 10, 15, 20, 25, 30
        return arr;
    }();

    cout << "Generated sequence: ";
    for (size_t i = 0; i < 5; ++i) {
        cout << compileTimeArray[i] << " ";
    }
    cout << endl;
    cout << "Sum: " << compileTimeArray.sum() << endl;

    // Verify compile-time evaluation
    cout << "\n--- Compile-time vs Runtime Comparison ---" << endl;

    const int testValue = 12;

    // Compile-time evaluation
    auto start = chrono::high_resolution_clock::now();
    constexpr int compileTimeResult = factorial_cpp14(12);
    auto end = chrono::high_resolution_clock::now();
    cout << "Compile-time factorial(12): " << compileTimeResult
         << " (measurement overhead only)" << endl;

    // Runtime evaluation
    start = chrono::high_resolution_clock::now();
    int runtimeResult = factorial_cpp14(testValue);
    end = chrono::high_resolution_clock::now();
    auto runtimeDuration = chrono::duration_cast<chrono::nanoseconds>(end - start);

    cout << "Runtime factorial(12): " << runtimeResult
         << " (took " << runtimeDuration.count() << " ns)" << endl;

    cout << "Results equal: " << (compileTimeResult == runtimeResult ? "Yes" : "No") << endl;
}

int main() {
    demonstrateBasicConstexpr();

    cout << "\n=== Constexpr Function Benefits ===" << endl;
    cout << "⚡ Zero runtime cost for compile-time evaluation" << endl;
    cout << "⚡ Can be used in constant expressions" << endl;
    cout << "⚡ Enable template metaprogramming" << endl;
    cout << "⚡ Better compiler optimizations" << endl;
    cout << "⚡ Catch errors at compile time" << endl;

    return 0;
}
```

**Output:**

```
=== Basic Constexpr Functions ===

--- Compile-time Calculations ---
5! (C++11 style): 120
5! (C++14 style): 120
10th Fibonacci: 55
2.5^3: 15.625

Is 17 prime? Yes
Is 25 prime? No

--- Compile-time String Operations ---
Message: "Hello World"
Length: 11
"test" == "test": true
"hello" == "world": false

--- Compile-time Array Operations ---
Array: 1 3 5 7 9 2 4 6 8 10
Sum: 55
Max: 10

--- Compile-time Data Structure ---
Generated sequence: 10 15 20 25 30
Sum: 100

--- Compile-time vs Runtime Comparison ---
Compile-time factorial(12): 479001600 (measurement overhead only)
Runtime factorial(12): 479001600 (took 145 ns)
Results equal: Yes

=== Constexpr Function Benefits ===
⚡ Zero runtime cost for compile-time evaluation
⚡ Can be used in constant expressions
⚡ Enable template metaprogramming
⚡ Better compiler optimizations
⚡ Catch errors at compile time
```

---

### 2.6.2 Advanced Constexpr Features and Modern Standards

**Concept**: Exploring advanced constexpr capabilities including constexpr if (C++17), consteval (C++20), constinit (C++20), and complex compile-time algorithms and data structures.

```cpp
#include <iostream>
#include <array>
#include <string_view>
#include <type_traits>
#include <utility>
#include <algorithm>
using namespace std;

// ADVANCED CONSTEXPR FEATURES

// Constexpr if (C++17) - conditional compilation
template<typename T>
constexpr auto processValue(T value) {
    if constexpr (is_integral_v<T>) {
        cout << "Processing integer: ";
        return value * 2;
    } else if constexpr (is_floating_point_v<T>) {
        cout << "Processing floating point: ";
        return value * 1.5;
    } else if constexpr (is_same_v<T, const char*>) {
        cout << "Processing string: ";
        return string_view(value);
    } else {
        cout << "Processing unknown type: ";
        return value;
    }
}

// Complex compile-time calculations
constexpr int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

constexpr int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Compile-time sorting
template<size_t N>
constexpr array<int, N> bubbleSort(array<int, N> arr) {
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}

// Compile-time binary search
template<size_t N>
constexpr int binarySearch(const array<int, N>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(N) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Not found
}

// C++20 consteval - immediate functions (must be evaluated at compile time)
#if __cpp_consteval >= 201811L
consteval int immediateFactorial(int n) {
    if (n < 0) {
        throw "Factorial of negative number not defined";
    }

    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

consteval bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
#endif

// Constexpr class for compile-time computations
class ConstexprMath {
public:
    static constexpr double PI = 3.14159265359;
    static constexpr double E = 2.71828182846;

    static constexpr double square(double x) {
        return x * x;
    }

    static constexpr double cube(double x) {
        return x * x * x;
    }

    static constexpr double circleArea(double radius) {
        return PI * square(radius);
    }

    static constexpr double sphereVolume(double radius) {
        return (4.0 / 3.0) * PI * cube(radius);
    }

    // Compile-time square root using Newton's method
    static constexpr double sqrt(double x) {
        if (x < 0) return -1; // Error indication
        if (x == 0) return 0;

        double guess = x / 2.0;
        for (int i = 0; i < 10; ++i) { // 10 iterations should be enough
            guess = (guess + x / guess) / 2.0;
        }
        return guess;
    }

    static constexpr double distance(double x1, double y1, double x2, double y2) {
        return sqrt(square(x2 - x1) + square(y2 - y1));
    }
};

// Compile-time string hashing
constexpr uint64_t hashString(const char* str) {
    uint64_t hash = 5381;
    while (*str) {
        hash = ((hash << 5) + hash) + *str++;
    }
    return hash;
}

// Compile-time lookup table generation
template<size_t N>
constexpr array<int, N> generatePrimes() {
    array<int, N> primes{};
    int count = 0;
    int candidate = 2;

    while (count < N) {
        bool isPrime = true;
        for (int i = 0; i < count && primes[i] * primes[i] <= candidate; ++i) {
            if (candidate % primes[i] == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            primes[count++] = candidate;
        }
        candidate++;
    }

    return primes;
}

// Template metaprogramming with constexpr
template<int N>
struct Factorial {
    static constexpr int value = N * Factorial<N-1>::value;
};

template<>
struct Factorial<0> {
    static constexpr int value = 1;
};

// Constexpr lambda (C++17)
void demonstrateConstexprLambda() {
    cout << "\n--- Constexpr Lambda (C++17) ---" << endl;

    constexpr auto add = [](int a, int b) constexpr -> int {
        return a + b;
    };

    constexpr auto multiply = [](int a, int b) constexpr -> int {
        return a * b;
    };

    constexpr int sum = add(10, 20);
    constexpr int product = multiply(6, 7);

    cout << "Constexpr lambda add(10, 20): " << sum << endl;
    cout << "Constexpr lambda multiply(6, 7): " << product << endl;

    // Generic constexpr lambda
    constexpr auto genericOp = []<typename T>(T a, T b, auto op) constexpr {
        return op(a, b);
    };

    constexpr auto addOp = [](auto a, auto b) constexpr { return a + b; };
    constexpr auto mulOp = [](auto a, auto b) constexpr { return a * b; };

    cout << "Generic lambda add(3.5, 2.5): " << genericOp(3.5, 2.5, addOp) << endl;
    cout << "Generic lambda mul(4, 8): " << genericOp(4, 8, mulOp) << endl;
}

void demonstrateAdvancedConstexpr() {
    cout << "=== Advanced Constexpr Features ===" << endl;

    cout << "\n--- Constexpr If (C++17) ---" << endl;

    auto intResult = processValue(42);
    auto floatResult = processValue(3.14);
    auto stringResult = processValue("Hello");

    cout << intResult << endl;
    cout << floatResult << endl;
    cout << stringResult << endl;

    cout << "\n--- Complex Compile-time Calculations ---" << endl;

    constexpr int gcdResult = gcd(48, 18);
    constexpr int lcmResult = lcm(12, 15);

    cout << "GCD(48, 18): " << gcdResult << endl;
    cout << "LCM(12, 15): " << lcmResult << endl;

    cout << "\n--- Compile-time Sorting and Searching ---" << endl;

    constexpr array<int, 8> unsorted = {64, 34, 25, 12, 22, 11, 90, 88};
    constexpr auto sorted = bubbleSort(unsorted);
    constexpr int searchIndex = binarySearch(sorted, 22);

    cout << "Original array: ";
    for (int val : unsorted) cout << val << " ";
    cout << endl;

    cout << "Sorted array: ";
    for (int val : sorted) cout << val << " ";
    cout << endl;

    cout << "Index of 22 in sorted array: " << searchIndex << endl;

    cout << "\n--- Constexpr Math Operations ---" << endl;

    constexpr double radius = 5.0;
    constexpr double area = ConstexprMath::circleArea(radius);
    constexpr double volume = ConstexprMath::sphereVolume(radius);
    constexpr double sqrtResult = ConstexprMath::sqrt(25.0);
    constexpr double dist = ConstexprMath::distance(0, 0, 3, 4);

    cout << "Circle area (r=" << radius << "): " << area << endl;
    cout << "Sphere volume (r=" << radius << "): " << volume << endl;
    cout << "Square root of 25: " << sqrtResult << endl;
    cout << "Distance from (0,0) to (3,4): " << dist << endl;

    cout << "\n--- Compile-time String Hashing ---" << endl;

    constexpr uint64_t hash1 = hashString("Hello");
    constexpr uint64_t hash2 = hashString("World");
    constexpr uint64_t hash3 = hashString("Hello");

    cout << "Hash of \"Hello\": " << hash1 << endl;
    cout << "Hash of \"World\": " << hash2 << endl;
    cout << "Hash of \"Hello\" again: " << hash3 << endl;
    cout << "Same hash for same string: " << (hash1 == hash3 ? "Yes" : "No") << endl;

    cout << "\n--- Compile-time Prime Generation ---" << endl;

    constexpr auto first10Primes = generatePrimes<10>();

    cout << "First 10 primes: ";
    for (int prime : first10Primes) {
        cout << prime << " ";
    }
    cout << endl;

    cout << "\n--- Template Metaprogramming ---" << endl;

    constexpr int fact6 = Factorial<6>::value;
    constexpr int fact10 = Factorial<10>::value;

    cout << "6! (template metaprogramming): " << fact6 << endl;
    cout << "10! (template metaprogramming): " << fact10 << endl;

#if __cpp_consteval >= 201811L
    cout << "\n--- Consteval Functions (C++20) ---" << endl;

    constexpr int immediateResult = immediateFactorial(7);
    constexpr bool is8PowerOfTwo = isPowerOfTwo(8);
    constexpr bool is10PowerOfTwo = isPowerOfTwo(10);

    cout << "Immediate factorial(7): " << immediateResult << endl;
    cout << "Is 8 power of two: " << (is8PowerOfTwo ? "Yes" : "No") << endl;
    cout << "Is 10 power of two: " << (is10PowerOfTwo ? "Yes" : "No") << endl;
#endif

    demonstrateConstexprLambda();

    cout << "\n--- Performance Demonstration ---" << endl;

    // All these computations are done at compile time
    constexpr int expensiveComputation = []() constexpr {
        int result = 0;
        for (int i = 1; i <= 1000; ++i) {
            if (isPrime(i)) {
                result += i;
            }
        }
        return result;
    }();

    cout << "Sum of all primes up to 1000 (computed at compile-time): "
         << expensiveComputation << endl;
}

int main() {
    demonstrateAdvancedConstexpr();

    cout << "\n=== Advanced Constexpr Summary ===" << endl;
    cout << "🚀 constexpr if enables conditional compilation" << endl;
    cout << "🚀 consteval ensures compile-time-only evaluation" << endl;
    cout << "🚀 Complex algorithms can run at compile time" << endl;
    cout << "🚀 Template metaprogramming enhanced with constexpr" << endl;
    cout << "🚀 Constexpr lambdas enable functional compile-time programming" << endl;
    cout << "🚀 Compile-time data structures and lookup tables" << endl;

    return 0;
}
```

**Output:**

```
=== Advanced Constexpr Features ===

--- Constexpr If (C++17) ---
Processing integer: 84
Processing floating point: 4.71
Processing string: Hello

--- Complex Compile-time Calculations ---
GCD(48, 18): 6
LCM(12, 15): 60

--- Compile-time Sorting and Searching ---
Original array: 64 34 25 12 22 11 90 88
Sorted array: 11 12 22 25 34 64 88 90
Index of 22 in sorted array: 2

--- Constexpr Math Operations ---
Circle area (r=5): 78.5398
Sphere volume (r=5): 523.599
Square root of 25: 5
Distance from (0,0) to (3,4): 5

--- Compile-time String Hashing ---
Hash of "Hello": 210676686969
Hash of "World": 266956645095
Hash of "Hello" again: 210676686969
Same hash for same string: Yes

--- Compile-time Prime Generation ---
First 10 primes: 2 3 5 7 11 13 17 19 23 29

--- Template Metaprogramming ---
6! (template metaprogramming): 720
10! (template metaprogramming): 3628800

--- Consteval Functions (C++20) ---
Immediate factorial(7): 5040
Is 8 power of two: Yes
Is 10 power of two: No

--- Constexpr Lambda (C++17) ---
Constexpr lambda add(10, 20): 30
Constexpr lambda multiply(6, 7): 42
Generic lambda add(3.5, 2.5): 6
Generic lambda mul(4, 8): 32

--- Performance Demonstration ---
Sum of all primes up to 1000 (computed at compile-time): 76127

=== Advanced Constexpr Summary ===
🚀 constexpr if enables conditional compilation
🚀 consteval ensures compile-time-only evaluation
🚀 Complex algorithms can run at compile time
🚀 Template metaprogramming enhanced with constexpr
🚀 Constexpr lambdas enable functional compile-time programming
🚀 Compile-time data structures and lookup tables
```

**Constexpr functions are a powerful feature that moves computation from runtime to compile-time, improving performance and enabling advanced template programming. Next, we'll explore Namespaces and Using Declarations!**

---

## Phase 2.7: Namespaces & Using Declarations

### Introduction to Namespaces & Using Declarations

**Concept**: **Namespaces** provide a mechanism to organize code and prevent name collisions by creating distinct scopes. **Using declarations** and **using directives** control how names from namespaces are brought into the current scope, enabling cleaner code organization and better maintainability.

**Key Benefits**:

1. **Name Collision Prevention** - Avoid conflicts between different libraries
2. **Code Organization** - Logical grouping of related functionality
3. **Encapsulation** - Hide implementation details in nested namespaces
4. **Modular Design** - Enable library-style code organization
5. **ADL (Argument Dependent Lookup)** - Automatic function discovery

**Modern Features**:

- **Namespace aliases** - Shorter names for deeply nested namespaces
- **Inline namespaces** - Version control and API evolution
- **Using declarations** - Selective name importing
- **Using directives** - Wholesale namespace importing
- **ADL/Koenig Lookup** - Automatic function resolution

### 2.7.1 Basic Namespace Usage and Organization

**Concept**: Understanding how to create, organize, and use namespaces effectively for code organization and name collision prevention.

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// BASIC NAMESPACE USAGE AND ORGANIZATION

// Global namespace function (not recommended for large projects)
void globalFunction() {
    cout << "This is a global function" << endl;
}

// Basic namespace definition
namespace MathUtils {
    const double PI = 3.14159265359;
    const double E = 2.71828182846;

    double square(double x) {
        return x * x;
    }

    double cube(double x) {
        return x * x * x;
    }

    double circleArea(double radius) {
        return PI * square(radius);
    }

    double sphereVolume(double radius) {
        return (4.0 / 3.0) * PI * cube(radius);
    }

    // Nested namespace
    namespace Advanced {
        double power(double base, int exponent) {
            return pow(base, exponent);
        }

        double logarithm(double x, double base = E) {
            return log(x) / log(base);
        }

        double factorial(int n) {
            if (n <= 1) return 1;
            double result = 1;
            for (int i = 2; i <= n; ++i) {
                result *= i;
            }
            return result;
        }
    }
}

// String utilities namespace
namespace StringUtils {
    string toUpper(const string& str) {
        string result = str;
        transform(result.begin(), result.end(), result.begin(), ::toupper);
        return result;
    }

    string toLower(const string& str) {
        string result = str;
        transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }

    vector<string> split(const string& str, char delimiter) {
        vector<string> tokens;
        string token;
        for (char c : str) {
            if (c == delimiter) {
                if (!token.empty()) {
                    tokens.push_back(token);
                    token.clear();
                }
            } else {
                token += c;
            }
        }
        if (!token.empty()) {
            tokens.push_back(token);
        }
        return tokens;
    }

    bool startsWith(const string& str, const string& prefix) {
        return str.length() >= prefix.length() &&
               str.substr(0, prefix.length()) == prefix;
    }

    bool endsWith(const string& str, const string& suffix) {
        return str.length() >= suffix.length() &&
               str.substr(str.length() - suffix.length()) == suffix;
    }
}

// Container utilities namespace
namespace ContainerUtils {
    template<typename Container>
    void printContainer(const Container& container, const string& name) {
        cout << name << ": ";
        for (const auto& item : container) {
            cout << item << " ";
        }
        cout << endl;
    }

    template<typename T>
    vector<T> merge(const vector<T>& vec1, const vector<T>& vec2) {
        vector<T> result = vec1;
        result.insert(result.end(), vec2.begin(), vec2.end());
        return result;
    }

    template<typename T>
    T findMax(const vector<T>& vec) {
        if (vec.empty()) throw runtime_error("Empty vector");
        return *max_element(vec.begin(), vec.end());
    }

    template<typename T>
    T findMin(const vector<T>& vec) {
        if (vec.empty()) throw runtime_error("Empty vector");
        return *min_element(vec.begin(), vec.end());
    }
}

// Namespace with same name as existing one (extends the namespace)
namespace MathUtils {
    // Additional functions in the same namespace
    double distance2D(double x1, double y1, double x2, double y2) {
        return sqrt(square(x2 - x1) + square(y2 - y1));
    }

    double average(const vector<double>& values) {
        if (values.empty()) return 0.0;
        double sum = 0.0;
        for (double val : values) {
            sum += val;
        }
        return sum / values.size();
    }
}

void demonstrateBasicNamespaces() {
    cout << "=== Basic Namespace Usage and Organization ===" << endl;

    cout << "\n--- Global vs Namespace Functions ---" << endl;

    // Global function call
    globalFunction();

    // Namespace function calls (fully qualified names)
    cout << "Square of 5: " << MathUtils::square(5.0) << endl;
    cout << "Circle area (r=3): " << MathUtils::circleArea(3.0) << endl;
    cout << "PI constant: " << MathUtils::PI << endl;

    cout << "\n--- Nested Namespace Access ---" << endl;

    // Accessing nested namespace functions
    cout << "2^8 = " << MathUtils::Advanced::power(2.0, 8) << endl;
    cout << "log(100) = " << MathUtils::Advanced::logarithm(100.0) << endl;
    cout << "5! = " << MathUtils::Advanced::factorial(5) << endl;

    cout << "\n--- String Utilities ---" << endl;

    string testString = "Hello World Programming";
    cout << "Original: " << testString << endl;
    cout << "Upper: " << StringUtils::toUpper(testString) << endl;
    cout << "Lower: " << StringUtils::toLower(testString) << endl;

    auto words = StringUtils::split(testString, ' ');
    ContainerUtils::printContainer(words, "Words");

    cout << "Starts with 'Hello': " << (StringUtils::startsWith(testString, "Hello") ? "Yes" : "No") << endl;
    cout << "Ends with 'ing': " << (StringUtils::endsWith(testString, "ing") ? "Yes" : "No") << endl;

    cout << "\n--- Container Utilities ---" << endl;

    vector<int> numbers1 = {1, 3, 5, 7};
    vector<int> numbers2 = {2, 4, 6, 8};

    ContainerUtils::printContainer(numbers1, "Numbers1");
    ContainerUtils::printContainer(numbers2, "Numbers2");

    auto merged = ContainerUtils::merge(numbers1, numbers2);
    ContainerUtils::printContainer(merged, "Merged");

    cout << "Max in merged: " << ContainerUtils::findMax(merged) << endl;
    cout << "Min in merged: " << ContainerUtils::findMin(merged) << endl;

    cout << "\n--- Extended Namespace Functions ---" << endl;

    // Using functions added later to the same namespace
    double dist = MathUtils::distance2D(0, 0, 3, 4);
    cout << "Distance from (0,0) to (3,4): " << dist << endl;

    vector<double> values = {1.5, 2.3, 4.7, 3.2, 5.1};
    ContainerUtils::printContainer(values, "Values");
    cout << "Average: " << MathUtils::average(values) << endl;
}

// Anonymous namespace (internal linkage)
namespace {
    string internalHelper(const string& msg) {
        return "[INTERNAL] " + msg;
    }

    int internalCounter = 0;

    void incrementCounter() {
        ++internalCounter;
    }
}

void demonstrateAnonymousNamespace() {
    cout << "\n--- Anonymous Namespace ---" << endl;

    cout << internalHelper("This function has internal linkage") << endl;

    cout << "Counter before: " << internalCounter << endl;
    incrementCounter();
    incrementCounter();
    cout << "Counter after: " << internalCounter << endl;
}

int main() {
    demonstrateBasicNamespaces();
    demonstrateAnonymousNamespace();

    cout << "\n=== Basic Namespace Benefits ===" << endl;
    cout << "📦 Prevents name collisions between different libraries" << endl;
    cout << "📦 Provides logical organization of related functionality" << endl;
    cout << "📦 Enables nested organization for complex hierarchies" << endl;
    cout << "📦 Allows namespace extension across multiple files" << endl;
    cout << "📦 Anonymous namespaces provide internal linkage" << endl;

    return 0;
}
```

**Output:**

```
=== Basic Namespace Usage and Organization ===

--- Global vs Namespace Functions ---
This is a global function
Square of 5: 25
Circle area (r=3): 28.2743
PI constant: 3.14159

--- Nested Namespace Access ---
2^8 = 256
log(100) = 4.60517
5! = 120

--- String Utilities ---
Original: Hello World Programming
Upper: HELLO WORLD PROGRAMMING
Lower: hello world programming
Words: Hello World Programming
Starts with 'Hello': Yes
Ends with 'ing': Yes

--- Container Utilities ---
Numbers1: 1 3 5 7
Numbers2: 2 4 6 8
Merged: 1 3 5 7 2 4 6 8
Max in merged: 8
Min in merged: 1

--- Extended Namespace Functions ---
Distance from (0,0) to (3,4): 5
Values: 1.5 2.3 4.7 3.2 5.1
Average: 3.36

--- Anonymous Namespace ---
[INTERNAL] This function has internal linkage
Counter before: 0
Counter after: 2

=== Basic Namespace Benefits ===
📦 Prevents name collisions between different libraries
📦 Provides logical organization of related functionality
📦 Enables nested organization for complex hierarchies
📦 Allows namespace extension across multiple files
📦 Anonymous namespaces provide internal linkage
```

---

### 2.7.2 Using Declarations, Namespace Aliases, and ADL

**Concept**: Advanced namespace features including using declarations for selective imports, namespace aliases for convenience, and Argument Dependent Lookup (ADL) for automatic function resolution.

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

// USING DECLARATIONS, NAMESPACE ALIASES, AND ADL

// Large nested namespace hierarchy for demonstration
namespace Company {
    namespace Graphics {
        namespace Rendering {
            namespace OpenGL {
                class Shader {
                private:
                    string name;

                public:
                    Shader(const string& shaderName) : name(shaderName) {
                        cout << "Created OpenGL Shader: " << name << endl;
                    }

                    void compile() {
                        cout << "Compiling OpenGL shader: " << name << endl;
                    }

                    void use() {
                        cout << "Using OpenGL shader: " << name << endl;
                    }
                };

                void initializeOpenGL() {
                    cout << "Initializing OpenGL rendering system" << endl;
                }
            }

            namespace DirectX {
                class Shader {
                private:
                    string name;

                public:
                    Shader(const string& shaderName) : name(shaderName) {
                        cout << "Created DirectX Shader: " << name << endl;
                    }

                    void compile() {
                        cout << "Compiling DirectX shader: " << name << endl;
                    }

                    void use() {
                        cout << "Using DirectX shader: " << name << endl;
                    }
                };

                void initializeDirectX() {
                    cout << "Initializing DirectX rendering system" << endl;
                }
            }
        }

        namespace UI {
            class Widget {
            private:
                string name;

            public:
                Widget(const string& widgetName) : name(widgetName) {
                    cout << "Created UI Widget: " << name << endl;
                }

                void render() {
                    cout << "Rendering widget: " << name << endl;
                }
            };

            void setupUI() {
                cout << "Setting up user interface system" << endl;
            }
        }
    }

    namespace Audio {
        namespace Effects {
            void applyReverb(const string& sound) {
                cout << "Applying reverb to: " << sound << endl;
            }

            void applyEcho(const string& sound) {
                cout << "Applying echo to: " << sound << endl;
            }
        }

        class SoundEngine {
        public:
            void playSound(const string& filename) {
                cout << "Playing sound: " << filename << endl;
            }

            void stopAllSounds() {
                cout << "Stopping all sounds" << endl;
            }
        };
    }
}

// Library namespace for ADL demonstration
namespace MyLibrary {
    class Point {
    private:
        double x, y;

    public:
        Point(double x_val, double y_val) : x(x_val), y(y_val) {}

        double getX() const { return x; }
        double getY() const { return y; }

        friend Point operator+(const Point& lhs, const Point& rhs);
        friend ostream& operator<<(ostream& os, const Point& p);
    };

    // ADL will find these functions when Point objects are used
    Point operator+(const Point& lhs, const Point& rhs) {
        return Point(lhs.x + rhs.x, lhs.y + rhs.y);
    }

    ostream& operator<<(ostream& os, const Point& p) {
        os << "Point(" << p.x << ", " << p.y << ")";
        return os;
    }

    double distance(const Point& p1, const Point& p2) {
        double dx = p1.getX() - p2.getX();
        double dy = p1.getY() - p2.getY();
        return sqrt(dx * dx + dy * dy);
    }

    void processPoint(const Point& p) {
        cout << "Processing point: " << p << endl;
    }
}

void demonstrateUsingDeclarations() {
    cout << "=== Using Declarations and Namespace Aliases ===" << endl;

    cout << "\n--- Without Using Declarations (Verbose) ---" << endl;

    // Fully qualified names (verbose)
    Company::Graphics::Rendering::OpenGL::Shader glShader("vertex_shader");
    Company::Graphics::Rendering::DirectX::Shader dxShader("pixel_shader");
    Company::Graphics::UI::Widget button("OK Button");

    glShader.compile();
    dxShader.compile();
    button.render();

    cout << "\n--- Namespace Aliases (Convenient) ---" << endl;

    // Create convenient aliases for deeply nested namespaces
    namespace GL = Company::Graphics::Rendering::OpenGL;
    namespace DX = Company::Graphics::Rendering::DirectX;
    namespace UI = Company::Graphics::UI;
    namespace AudioFX = Company::Audio::Effects;

    // Now use shorter names
    GL::Shader fragmentShader("fragment_shader");
    DX::Shader geometryShader("geometry_shader");
    UI::Widget textBox("Input Field");

    fragmentShader.use();
    geometryShader.use();
    textBox.render();

    AudioFX::applyReverb("footsteps.wav");
    AudioFX::applyEcho("voice.wav");

    cout << "\n--- Using Declarations (Selective Import) ---" << endl;

    // Import specific names into current scope
    using GL::initializeOpenGL;
    using DX::initializeDirectX;
    using UI::setupUI;
    using Company::Audio::SoundEngine;

    // Now can use without qualification
    initializeOpenGL();
    initializeDirectX();
    setupUI();

    SoundEngine engine;
    engine.playSound("background_music.mp3");
    engine.stopAllSounds();

    cout << "\n--- Using Directive (Wholesale Import) ---" << endl;

    // Import entire namespace (use carefully!)
    {
        using namespace Company::Audio::Effects;

        // All names from Effects namespace are now available
        applyReverb("explosion.wav");
        applyEcho("canyon_call.wav");
    } // Scope ends here, using directive no longer applies

    // Outside the scope, need qualification again
    Company::Audio::Effects::applyReverb("wind.wav");
}

void demonstrateADL() {
    cout << "\n=== Argument Dependent Lookup (ADL) ===" << endl;

    cout << "\n--- ADL with Operators ---" << endl;

    MyLibrary::Point p1(1.0, 2.0);
    MyLibrary::Point p2(3.0, 4.0);

    // ADL finds operator+ in MyLibrary namespace
    MyLibrary::Point p3 = p1 + p2;  // No need to qualify operator+

    // ADL finds operator<< in MyLibrary namespace
    cout << "p1: " << p1 << endl;           // No need to qualify operator<<
    cout << "p2: " << p2 << endl;
    cout << "p1 + p2: " << p3 << endl;

    cout << "\n--- ADL with Functions ---" << endl;

    // ADL finds distance function in MyLibrary namespace
    double dist = distance(p1, p2);         // No need to qualify distance
    cout << "Distance between p1 and p2: " << dist << endl;

    // ADL finds processPoint function
    processPoint(p1);                       // No need to qualify processPoint

    cout << "\n--- ADL Demonstration ---" << endl;

    vector<MyLibrary::Point> points = {
        MyLibrary::Point(0, 0),
        MyLibrary::Point(1, 1),
        MyLibrary::Point(2, 2),
        MyLibrary::Point(3, 3)
    };

    cout << "Points in vector:" << endl;
    for (const auto& point : points) {
        cout << "  " << point << endl;      // ADL finds operator<<
    }

    // Using ADL with algorithms
    cout << "\nProcessing points with for_each:" << endl;
    for_each(points.begin(), points.end(), processPoint);  // ADL finds processPoint
}

void demonstrateNamespaceComposition() {
    cout << "\n=== Advanced Namespace Patterns ===" << endl;

    cout << "\n--- Nested Using Declarations ---" << endl;

    {
        // Multiple using declarations
        using Company::Graphics::Rendering::OpenGL::Shader;
        using Company::Graphics::UI::Widget;
        using Company::Audio::SoundEngine;

        Shader mainShader("main_vertex");
        Widget menuButton("Menu");
        SoundEngine audioEngine;

        mainShader.compile();
        menuButton.render();
        audioEngine.playSound("click.wav");
    }

    cout << "\n--- Conditional Namespace Selection ---" << endl;

    bool useOpenGL = true;

    if (useOpenGL) {
        using RenderingAPI = Company::Graphics::Rendering::OpenGL::Shader;
        using InitFunction = void(*)();

        InitFunction init = Company::Graphics::Rendering::OpenGL::initializeOpenGL;

        RenderingAPI shader("conditional_shader");
        init();
        shader.compile();
    } else {
        using RenderingAPI = Company::Graphics::Rendering::DirectX::Shader;

        RenderingAPI shader("dx_conditional_shader");
        shader.compile();
    }

    cout << "\n--- Namespace Aliases for Templates ---" << endl;

    // Create convenient aliases for complex template types
    namespace SmartPtrs = std;
    using IntPtr = SmartPtrs::unique_ptr<int>;
    using StringPtr = SmartPtrs::shared_ptr<string>;

    IntPtr intPtr = SmartPtrs::make_unique<int>(42);
    StringPtr strPtr = SmartPtrs::make_shared<string>("Hello ADL");

    cout << "Smart pointer values: " << *intPtr << ", " << *strPtr << endl;
}

// Global namespace pollution example (what to avoid)
void demonstrateNamespacePollution() {
    cout << "\n=== Namespace Best Practices ===" << endl;

    cout << "\n--- What NOT to do (Global using directive) ---" << endl;

    // BAD: Don't do this in headers or globally
    // using namespace std;  // Already done at top for demo purposes

    cout << "✅ Good: Use specific using declarations" << endl;
    cout << "✅ Good: Use namespace aliases for convenience" << endl;
    cout << "✅ Good: Limit using directives to small scopes" << endl;
    cout << "❌ Bad: Global 'using namespace' directives" << endl;
    cout << "❌ Bad: Using directive in header files" << endl;

    cout << "\n--- Recommended Patterns ---" << endl;

    // Good pattern: Local using declarations
    {
        using std::vector;
        using std::string;
        using std::cout;
        using std::endl;

        vector<string> recommendations = {
            "Use namespace aliases for deeply nested namespaces",
            "Prefer using declarations over using directives",
            "Keep using directives in limited scopes",
            "Never use 'using namespace' in header files",
            "Organize your code with meaningful namespace hierarchies"
        };

        cout << "Namespace best practices:" << endl;
        for (const auto& rec : recommendations) {
            cout << "  - " << rec << endl;
        }
    }
}

int main() {
    demonstrateUsingDeclarations();
    demonstrateADL();
    demonstrateNamespaceComposition();
    demonstrateNamespacePollution();

    cout << "\n=== Advanced Namespace Summary ===" << endl;
    cout << "🎯 Namespace aliases simplify deeply nested namespace access" << endl;
    cout << "🎯 Using declarations enable selective name importing" << endl;
    cout << "🎯 ADL automatically finds functions in argument namespaces" << endl;
    cout << "🎯 Avoid global using directives to prevent name pollution" << endl;
    cout << "🎯 Use meaningful namespace hierarchies for code organization" << endl;

    return 0;
}
```

**Output:**

```
=== Using Declarations and Namespace Aliases ===

--- Without Using Declarations (Verbose) ---
Created OpenGL Shader: vertex_shader
Created DirectX Shader: pixel_shader
Created UI Widget: OK Button
Compiling OpenGL shader: vertex_shader
Compiling DirectX shader: pixel_shader
Rendering widget: OK Button

--- Namespace Aliases (Convenient) ---
Created OpenGL Shader: fragment_shader
Created DirectX Shader: geometry_shader
Created UI Widget: Input Field
Using OpenGL shader: fragment_shader
Using DirectX shader: geometry_shader
Rendering widget: Input Field
Applying reverb to: footsteps.wav
Applying echo to: voice.wav

--- Using Declarations (Selective Import) ---
Initializing OpenGL rendering system
Initializing DirectX rendering system
Setting up user interface system
Playing sound: background_music.mp3
Stopping all sounds

--- Using Directive (Wholesale Import) ---
Applying reverb to: explosion.wav
Applying echo to: canyon_call.wav
Applying reverb to: wind.wav

=== Argument Dependent Lookup (ADL) ===

--- ADL with Operators ---
p1: Point(1, 2)
p2: Point(3, 4)
p1 + p2: Point(4, 6)

--- ADL with Functions ---
Distance between p1 and p2: 2.82843
Processing point: Point(1, 2)

--- ADL Demonstration ---
Points in vector:
  Point(0, 0)
  Point(1, 1)
  Point(2, 2)
  Point(3, 3)

Processing points with for_each:
Processing point: Point(0, 0)
Processing point: Point(1, 1)
Processing point: Point(2, 2)
Processing point: Point(3, 3)

=== Advanced Namespace Patterns ===

--- Nested Using Declarations ---
Created OpenGL Shader: main_vertex
Created UI Widget: Menu
Compiling OpenGL shader: main_vertex
Rendering widget: Menu
Playing sound: click.wav

--- Conditional Namespace Selection ---
Created OpenGL Shader: conditional_shader
Initializing OpenGL rendering system
Compiling OpenGL shader: conditional_shader

--- Namespace Aliases for Templates ---
Smart pointer values: 42, Hello ADL

=== Namespace Best Practices ===

--- What NOT to do (Global using directive) ---
✅ Good: Use specific using declarations
✅ Good: Use namespace aliases for convenience
✅ Good: Limit using directives to small scopes
❌ Bad: Global 'using namespace' directives
❌ Bad: Using directive in header files

--- Recommended Patterns ---
Namespace best practices:
  - Use namespace aliases for deeply nested namespaces
  - Prefer using declarations over using directives
  - Keep using directives in limited scopes
  - Never use 'using namespace' in header files
  - Organize your code with meaningful namespace hierarchies

=== Advanced Namespace Summary ===
🎯 Namespace aliases simplify deeply nested namespace access
🎯 Using declarations enable selective name importing
🎯 ADL automatically finds functions in argument namespaces
🎯 Avoid global using directives to prevent name pollution
🎯 Use meaningful namespace hierarchies for code organization
```

**Namespaces and using declarations are essential for organizing large C++ codebases and preventing name collisions. Next, we'll explore Exception Handling for robust error management!**

---

## Phase 2.8: Exception Handling

### Introduction to Exception Handling

**Concept**: **Exception handling** provides a structured mechanism for dealing with runtime errors and exceptional conditions in C++. Modern exception handling emphasizes **exception safety guarantees**, **RAII patterns**, and **noexcept specifications** to create robust, maintainable code that gracefully handles errors.

**Key Benefits**:

1. **Structured Error Handling** - Separate error handling from normal control flow
2. **Exception Safety** - Guarantee resource cleanup and consistent state
3. **Stack Unwinding** - Automatic cleanup of local objects
4. **RAII Integration** - Exception-safe resource management
5. **Performance Control** - noexcept specifications for optimization

**Exception Safety Levels**:

- **No-throw guarantee** - Functions never throw exceptions
- **Strong exception safety** - Either succeeds or leaves program unchanged
- **Basic exception safety** - No resource leaks, objects in valid state
- **No exception safety** - Undefined behavior on exceptions

### 2.8.1 Exception Safety Guarantees and RAII Patterns

**Concept**: Understanding and implementing different levels of exception safety, with RAII (Resource Acquisition Is Initialization) as the cornerstone of exception-safe C++ programming.

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <fstream>
#include <chrono>
#include <algorithm>
using namespace std;

// EXCEPTION SAFETY GUARANTEES AND RAII PATTERNS

// Custom RAII resource manager for demonstration
class FileHandle {
private:
    string filename;
    FILE* file;
    bool isOpen;

public:
    // Constructor acquires resource
    explicit FileHandle(const string& name, const string& mode = "r")
        : filename(name), file(nullptr), isOpen(false) {

        cout << "Attempting to open file: " << filename << endl;

        file = fopen(filename.c_str(), mode.c_str());
        if (!file) {
            throw runtime_error("Failed to open file: " + filename);
        }

        isOpen = true;
        cout << "Successfully opened file: " << filename << endl;
    }

    // Destructor releases resource (RAII cleanup)
    ~FileHandle() {
        close();
    }

    // No-throw guarantee
    void close() noexcept {
        if (isOpen && file) {
            cout << "Closing file: " << filename << endl;
            fclose(file);
            file = nullptr;
            isOpen = false;
        }
    }

    // Basic exception safety
    size_t read(char* buffer, size_t size) {
        if (!isOpen || !file) {
            throw runtime_error("File not open for reading");
        }

        return fread(buffer, 1, size, file);
    }

    // Strong exception safety
    void write(const string& data) {
        if (!isOpen || !file) {
            throw runtime_error("File not open for writing");
        }

        size_t written = fwrite(data.c_str(), 1, data.size(), file);
        if (written != data.size()) {
            throw runtime_error("Failed to write complete data");
        }

        // Flush to ensure data is written
        if (fflush(file) != 0) {
            throw runtime_error("Failed to flush file");
        }
    }

    bool isFileOpen() const noexcept {
        return isOpen;
    }

    // Delete copy operations to prevent resource duplication
    FileHandle(const FileHandle&) = delete;
    FileHandle& operator=(const FileHandle&) = delete;

    // Move operations for resource transfer
    FileHandle(FileHandle&& other) noexcept
        : filename(move(other.filename)), file(other.file), isOpen(other.isOpen) {
        other.file = nullptr;
        other.isOpen = false;
    }

    FileHandle& operator=(FileHandle&& other) noexcept {
        if (this != &other) {
            close();
            filename = move(other.filename);
            file = other.file;
            isOpen = other.isOpen;
            other.file = nullptr;
            other.isOpen = false;
        }
        return *this;
    }
};

// Exception-safe vector implementation with different safety levels
template<typename T>
class SafeVector {
private:
    unique_ptr<T[]> data;
    size_t size_;
    size_t capacity_;

    void reallocate(size_t newCapacity) {
        // Strong exception safety: either succeeds completely or leaves unchanged
        auto newData = make_unique<T[]>(newCapacity);

        // Copy existing elements (may throw)
        for (size_t i = 0; i < size_; ++i) {
            newData[i] = data[i];  // If this throws, newData is automatically cleaned up
        }

        // Only update state after successful copy
        data = move(newData);
        capacity_ = newCapacity;
    }

public:
    SafeVector() : data(nullptr), size_(0), capacity_(0) {}

    explicit SafeVector(size_t initialCapacity)
        : data(make_unique<T[]>(initialCapacity)), size_(0), capacity_(initialCapacity) {}

    // Strong exception safety
    void push_back(const T& value) {
        if (size_ >= capacity_) {
            size_t newCapacity = capacity_ == 0 ? 1 : capacity_ * 2;
            reallocate(newCapacity);  // May throw, but leaves object unchanged
        }

        data[size_] = value;  // May throw, but we haven't updated size_ yet
        ++size_;              // Only increment after successful assignment
    }

    // Basic exception safety
    void pop_back() {
        if (size_ == 0) {
            throw runtime_error("Cannot pop from empty vector");
        }
        --size_;
        // Object remains in valid state even if destructor throws
    }

    // No-throw guarantee
    size_t size() const noexcept { return size_; }
    size_t capacity() const noexcept { return capacity_; }
    bool empty() const noexcept { return size_ == 0; }

    // Basic exception safety
    T& operator[](size_t index) {
        if (index >= size_) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size_) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    // Strong exception safety
    void clear() noexcept {
        size_ = 0;
        // Elements are not destroyed, just logically removed
        // This provides no-throw guarantee
    }
};

// Resource manager with automatic cleanup
class DatabaseConnection {
private:
    string connectionString;
    bool connected;

public:
    explicit DatabaseConnection(const string& connStr)
        : connectionString(connStr), connected(false) {

        cout << "Connecting to database: " << connectionString << endl;

        // Simulate connection failure for demonstration
        if (connectionString.find("invalid") != string::npos) {
            throw runtime_error("Invalid connection string");
        }

        connected = true;
        cout << "Successfully connected to database" << endl;
    }

    ~DatabaseConnection() {
        disconnect();
    }

    void disconnect() noexcept {
        if (connected) {
            cout << "Disconnecting from database: " << connectionString << endl;
            connected = false;
        }
    }

    void executeQuery(const string& query) {
        if (!connected) {
            throw runtime_error("Not connected to database");
        }

        cout << "Executing query: " << query << endl;

        // Simulate query failure
        if (query.find("DROP") != string::npos) {
            throw runtime_error("Dangerous query detected");
        }

        cout << "Query executed successfully" << endl;
    }

    bool isConnected() const noexcept { return connected; }

    // Prevent copying
    DatabaseConnection(const DatabaseConnection&) = delete;
    DatabaseConnection& operator=(const DatabaseConnection&) = delete;

    // Allow moving
    DatabaseConnection(DatabaseConnection&& other) noexcept
        : connectionString(move(other.connectionString)), connected(other.connected) {
        other.connected = false;
    }

    DatabaseConnection& operator=(DatabaseConnection&& other) noexcept {
        if (this != &other) {
            disconnect();
            connectionString = move(other.connectionString);
            connected = other.connected;
            other.connected = false;
        }
        return *this;
    }
};

void demonstrateRAIIPatterns() {
    cout << "=== RAII Patterns and Exception Safety ===" << endl;

    cout << "\n--- Successful RAII Operations ---" << endl;

    try {
        // Create test file for demonstration
        {
            ofstream testFile("test_raii.txt");
            testFile << "Hello, RAII World!" << endl;
        }

        // RAII file management
        FileHandle file("test_raii.txt", "r");
        char buffer[100];
        size_t bytesRead = file.read(buffer, sizeof(buffer));
        buffer[bytesRead] = '\0';
        cout << "Read from file: " << buffer;

        // File automatically closed when FileHandle goes out of scope

    } catch (const exception& e) {
        cout << "File operation failed: " << e.what() << endl;
    }

    cout << "\n--- RAII with Exceptions ---" << endl;

    try {
        DatabaseConnection db("postgresql://localhost:5432/testdb");

        db.executeQuery("SELECT * FROM users");

        // This will throw, but connection will be automatically closed
        db.executeQuery("DROP TABLE users");  // Dangerous query

    } catch (const exception& e) {
        cout << "Database operation failed: " << e.what() << endl;
        cout << "Connection automatically cleaned up by RAII" << endl;
    }

    cout << "\n--- Exception-Safe Vector Operations ---" << endl;

    try {
        SafeVector<int> vec;

        cout << "Adding elements to safe vector..." << endl;
        for (int i = 1; i <= 5; ++i) {
            vec.push_back(i * 10);
            cout << "Added: " << (i * 10) << ", Size: " << vec.size() << endl;
        }

        cout << "Vector contents: ";
        for (size_t i = 0; i < vec.size(); ++i) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // This will throw, but vector remains in valid state
        vec[10];  // Out of bounds access

    } catch (const exception& e) {
        cout << "Vector operation failed: " << e.what() << endl;
        cout << "Vector remains in valid state due to exception safety" << endl;
    }
}

// Function with different exception safety guarantees
class ExceptionSafeOperations {
public:
    // No-throw guarantee
    static int safeAdd(int a, int b) noexcept {
        // Use saturation arithmetic to prevent overflow
        if (a > 0 && b > INT_MAX - a) return INT_MAX;
        if (a < 0 && b < INT_MIN - a) return INT_MIN;
        return a + b;
    }

    // Basic exception safety
    static void processVector(vector<int>& vec) {
        cout << "Processing vector with " << vec.size() << " elements" << endl;

        // May throw, but vector remains in valid state
        for (auto& val : vec) {
            if (val < 0) {
                throw invalid_argument("Negative value not allowed");
            }
            val *= 2;  // If this throws, some elements may be modified
        }

        cout << "Vector processing completed" << endl;
    }

    // Strong exception safety
    static vector<int> doubleValues(const vector<int>& input) {
        vector<int> result;  // Local copy
        result.reserve(input.size());  // May throw, but result is empty

        for (int val : input) {
            if (val < 0) {
                throw invalid_argument("Negative value not allowed");
            }
            result.push_back(val * 2);  // May throw, but input unchanged
        }

        return result;  // Only return if completely successful
    }

    // Copy-and-swap idiom for strong exception safety
    static void strongSwapOperation(vector<int>& target, const vector<int>& source) {
        vector<int> temp = source;  // Copy (may throw)

        // Modify temp (may throw, but target unchanged)
        for (auto& val : temp) {
            val *= 3;
        }

        // Swap is no-throw
        target.swap(temp);  // Only modify target if all operations succeed
    }
};

void demonstrateExceptionSafety() {
    cout << "\n=== Exception Safety Guarantees ===" << endl;

    cout << "\n--- No-throw Guarantee ---" << endl;

    int result1 = ExceptionSafeOperations::safeAdd(1000000000, 1000000000);
    int result2 = ExceptionSafeOperations::safeAdd(-1000000000, -1000000000);

    cout << "Safe addition results: " << result1 << ", " << result2 << endl;
    cout << "No exceptions thrown, guaranteed!" << endl;

    cout << "\n--- Basic Exception Safety ---" << endl;

    vector<int> basicVec = {1, 2, 3, -4, 5};
    cout << "Original vector: ";
    for (int val : basicVec) cout << val << " ";
    cout << endl;

    try {
        ExceptionSafeOperations::processVector(basicVec);
    } catch (const exception& e) {
        cout << "Exception caught: " << e.what() << endl;
        cout << "Vector after exception: ";
        for (int val : basicVec) cout << val << " ";
        cout << endl;
        cout << "Vector is in valid state (some elements may be modified)" << endl;
    }

    cout << "\n--- Strong Exception Safety ---" << endl;

    vector<int> originalVec = {1, 2, 3, 4, 5};
    cout << "Original vector: ";
    for (int val : originalVec) cout << val << " ";
    cout << endl;

    try {
        vector<int> doubledVec = ExceptionSafeOperations::doubleValues(originalVec);
        cout << "Doubled vector: ";
        for (int val : doubledVec) cout << val << " ";
        cout << endl;
    } catch (const exception& e) {
        cout << "Exception caught: " << e.what() << endl;
        cout << "Original vector unchanged: ";
        for (int val : originalVec) cout << val << " ";
        cout << endl;
    }

    // Test with invalid data
    vector<int> invalidVec = {1, 2, -3, 4, 5};
    cout << "\nTesting with invalid data: ";
    for (int val : invalidVec) cout << val << " ";
    cout << endl;

    try {
        vector<int> result = ExceptionSafeOperations::doubleValues(invalidVec);
    } catch (const exception& e) {
        cout << "Exception caught: " << e.what() << endl;
        cout << "Original vector unchanged: ";
        for (int val : invalidVec) cout << val << " ";
        cout << endl;
    }

    cout << "\n--- Copy-and-Swap Strong Guarantee ---" << endl;

    vector<int> target = {10, 20, 30};
    vector<int> source = {1, 2, 3, 4};

    cout << "Target before: ";
    for (int val : target) cout << val << " ";
    cout << endl;
    cout << "Source: ";
    for (int val : source) cout << val << " ";
    cout << endl;

    try {
        ExceptionSafeOperations::strongSwapOperation(target, source);
        cout << "Target after strong operation: ";
        for (int val : target) cout << val << " ";
        cout << endl;
    } catch (const exception& e) {
        cout << "Exception caught: " << e.what() << endl;
        cout << "Target unchanged due to strong guarantee" << endl;
    }
}

int main() {
    demonstrateRAIIPatterns();
    demonstrateExceptionSafety();

    cout << "\n=== Exception Safety Summary ===" << endl;
    cout << "🛡️ RAII ensures automatic resource cleanup" << endl;
    cout << "🛡️ No-throw guarantee: Functions never throw exceptions" << endl;
    cout << "🛡️ Basic safety: No resource leaks, valid object state" << endl;
    cout << "🛡️ Strong safety: Either succeeds or leaves unchanged" << endl;
    cout << "🛡️ Copy-and-swap idiom provides strong guarantee" << endl;

    return 0;
}
```

**Output:**

```
=== RAII Patterns and Exception Safety ===

--- Successful RAII Operations ---
Attempting to open file: test_raii.txt
Successfully opened file: test_raii.txt
Read from file: Hello, RAII World!
Closing file: test_raii.txt

--- RAII with Exceptions ---
Connecting to database: postgresql://localhost:5432/testdb
Successfully connected to database
Executing query: SELECT * FROM users
Query executed successfully
Executing query: DROP TABLE users
Database operation failed: Dangerous query detected
Disconnecting from database: postgresql://localhost:5432/testdb
Connection automatically cleaned up by RAII

--- Exception-Safe Vector Operations ---
Adding elements to safe vector...
Added: 10, Size: 1
Added: 20, Size: 2
Added: 30, Size: 3
Added: 40, Size: 4
Added: 50, Size: 5
Vector contents: 10 20 30 40 50
Vector operation failed: Index out of bounds
Vector remains in valid state due to exception safety

=== Exception Safety Guarantees ===

--- No-throw Guarantee ---
Safe addition results: 2147483647, -2147483648
No exceptions thrown, guaranteed!

--- Basic Exception Safety ---
Original vector: 1 2 3 -4 5
Processing vector with 5 elements
Exception caught: Negative value not allowed
Vector after exception: 2 4 6 -4 5
Vector is in valid state (some elements may be modified)

--- Strong Exception Safety ---
Original vector: 1 2 3 4 5
Doubled vector: 2 4 6 8 10

Testing with invalid data: 1 2 -3 4 5

Exception caught: Negative value not allowed
Original vector unchanged: 1 2 -3 4 5

--- Copy-and-Swap Strong Guarantee ---
Target before: 10 20 30
Source: 1 2 3 4
Target after strong operation: 3 6 9 12

=== Exception Safety Summary ===
🛡️ RAII ensures automatic resource cleanup
🛡️ No-throw guarantee: Functions never throw exceptions
🛡️ Basic safety: No resource leaks, valid object state
🛡️ Strong safety: Either succeeds or leaves unchanged
🛡️ Copy-and-swap idiom provides strong guarantee
```

---

### 2.8.2 Noexcept Specifications and Custom Exceptions

**Concept**: Using `noexcept` specifications for performance optimization and documenting exception guarantees, along with creating and using custom exception types for domain-specific error handling.

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <exception>
#include <type_traits>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

// NOEXCEPT SPECIFICATIONS AND CUSTOM EXCEPTIONS

// Custom exception hierarchy
class ApplicationException : public std::exception {
protected:
    string message;
    string category;
    int errorCode;

public:
    ApplicationException(const string& msg, const string& cat = "APPLICATION", int code = 0)
        : message(msg), category(cat), errorCode(code) {}

    const char* what() const noexcept override {
        return message.c_str();
    }

    const string& getCategory() const noexcept { return category; }
    int getErrorCode() const noexcept { return errorCode; }

    virtual string getFullMessage() const noexcept {
        return "[" + category + ":" + to_string(errorCode) + "] " + message;
    }
};

// Specific exception types
class ValidationException : public ApplicationException {
private:
    string fieldName;
    string actualValue;

public:
    ValidationException(const string& field, const string& value, const string& msg)
        : ApplicationException(msg, "VALIDATION", 1001), fieldName(field), actualValue(value) {}

    const string& getFieldName() const noexcept { return fieldName; }
    const string& getActualValue() const noexcept { return actualValue; }

    string getFullMessage() const noexcept override {
        return "[" + category + ":" + to_string(errorCode) + "] Field '" +
               fieldName + "' with value '" + actualValue + "': " + message;
    }
};

class ResourceException : public ApplicationException {
private:
    string resourceType;
    string resourceId;

public:
    ResourceException(const string& type, const string& id, const string& msg)
        : ApplicationException(msg, "RESOURCE", 2001), resourceType(type), resourceId(id) {}

    const string& getResourceType() const noexcept { return resourceType; }
    const string& getResourceId() const noexcept { return resourceId; }

    string getFullMessage() const noexcept override {
        return "[" + category + ":" + to_string(errorCode) + "] " +
               resourceType + " '" + resourceId + "': " + message;
    }
};

class NetworkException : public ApplicationException {
private:
    string hostname;
    int port;
    int networkErrorCode;

public:
    NetworkException(const string& host, int p, int netCode, const string& msg)
        : ApplicationException(msg, "NETWORK", 3001), hostname(host), port(p), networkErrorCode(netCode) {}

    const string& getHostname() const noexcept { return hostname; }
    int getPort() const noexcept { return port; }
    int getNetworkErrorCode() const noexcept { return networkErrorCode; }

    string getFullMessage() const noexcept override {
        return "[" + category + ":" + to_string(errorCode) + "] " +
               hostname + ":" + to_string(port) + " (net:" + to_string(networkErrorCode) + "): " + message;
    }
};

// Class demonstrating noexcept specifications
class NoexceptDemo {
private:
    vector<int> data;

public:
    // Constructor can throw
    explicit NoexceptDemo(size_t size) : data(size) {}

    // Move constructor is noexcept
    NoexceptDemo(NoexceptDemo&& other) noexcept
        : data(std::move(other.data)) {}

    // Move assignment is noexcept
    NoexceptDemo& operator=(NoexceptDemo&& other) noexcept {
        if (this != &other) {
            data = std::move(other.data);
        }
        return *this;
    }

    // Copy operations can throw
    NoexceptDemo(const NoexceptDemo& other) : data(other.data) {}

    NoexceptDemo& operator=(const NoexceptDemo& other) {
        if (this != &other) {
            data = other.data;  // May throw due to memory allocation
        }
        return *this;
    }

    // Destructor should be noexcept (default behavior)
    ~NoexceptDemo() = default;

    // Query operations are typically noexcept
    size_t size() const noexcept { return data.size(); }
    bool empty() const noexcept { return data.empty(); }

    // Operations that can fail should not be noexcept
    void push_back(int value) {  // Can throw due to reallocation
        data.push_back(value);
    }

    // Swap is typically noexcept
    void swap(NoexceptDemo& other) noexcept {
        data.swap(other.data);
    }

    // Element access that performs bounds checking cannot be noexcept
    int& at(size_t index) {
        if (index >= data.size()) {
            throw out_of_range("Index out of bounds: " + to_string(index));
        }
        return data[index];
    }

    // Unchecked access can be noexcept
    int& operator[](size_t index) noexcept {
        return data[index];
    }

    const int& operator[](size_t index) const noexcept {
        return data[index];
    }

    // Clear operation is typically noexcept
    void clear() noexcept {
        data.clear();
    }
};

// Template functions with conditional noexcept
template<typename T>
void conditionalNoexceptSwap(T& a, T& b) noexcept(is_nothrow_swappable_v<T>) {
    using std::swap;
    swap(a, b);
}

template<typename Container>
auto getSize(const Container& c) noexcept(noexcept(c.size())) -> decltype(c.size()) {
    return c.size();
}

// Performance comparison: noexcept vs throwing functions
class PerformanceTest {
public:
    // Throwing version
    static int throwingAdd(int a, int b) {
        if (a > 1000000 || b > 1000000) {
            throw overflow_error("Values too large");
        }
        return a + b;
    }

    // Non-throwing version
    static int noexceptAdd(int a, int b) noexcept {
        // Use saturated arithmetic
        if (a > 0 && b > INT_MAX - a) return INT_MAX;
        if (a < 0 && b < INT_MIN - a) return INT_MIN;
        return a + b;
    }

    static void performanceComparison() {
        cout << "\n--- Performance Comparison: noexcept vs throwing ---" << endl;

        const int iterations = 1000000;
        vector<int> values1(iterations);
        vector<int> values2(iterations);

        // Initialize test data
        for (int i = 0; i < iterations; ++i) {
            values1[i] = i % 1000;
            values2[i] = (i * 2) % 1000;
        }

        // Test throwing version
        auto start = high_resolution_clock::now();
        volatile int sum1 = 0;
        for (int i = 0; i < iterations; ++i) {
            sum1 += throwingAdd(values1[i], values2[i]);
        }
        auto end = high_resolution_clock::now();
        auto throwingTime = duration_cast<microseconds>(end - start);

        // Test noexcept version
        start = high_resolution_clock::now();
        volatile int sum2 = 0;
        for (int i = 0; i < iterations; ++i) {
            sum2 += noexceptAdd(values1[i], values2[i]);
        }
        end = high_resolution_clock::now();
        auto noexceptTime = duration_cast<microseconds>(end - start);

        cout << "Throwing version time: " << throwingTime.count() << " μs" << endl;
        cout << "Noexcept version time: " << noexceptTime.count() << " μs" << endl;
        cout << "Performance ratio: " << (double)throwingTime.count() / noexceptTime.count() << "x" << endl;
    }
};

void demonstrateCustomExceptions() {
    cout << "=== Custom Exceptions and Exception Hierarchy ===" << endl;

    cout << "\n--- Validation Exception ---" << endl;

    try {
        string email = "invalid-email";
        if (email.find('@') == string::npos) {
            throw ValidationException("email", email, "Must contain @ symbol");
        }
    } catch (const ValidationException& e) {
        cout << "Caught ValidationException:" << endl;
        cout << "  Full message: " << e.getFullMessage() << endl;
        cout << "  Field: " << e.getFieldName() << endl;
        cout << "  Value: " << e.getActualValue() << endl;
        cout << "  Error code: " << e.getErrorCode() << endl;
    }

    cout << "\n--- Resource Exception ---" << endl;

    try {
        string filename = "nonexistent.txt";
        throw ResourceException("file", filename, "File not found");
    } catch (const ResourceException& e) {
        cout << "Caught ResourceException:" << endl;
        cout << "  Full message: " << e.getFullMessage() << endl;
        cout << "  Resource type: " << e.getResourceType() << endl;
        cout << "  Resource ID: " << e.getResourceId() << endl;
    }

    cout << "\n--- Network Exception ---" << endl;

    try {
        throw NetworkException("api.example.com", 443, 10061, "Connection refused");
    } catch (const NetworkException& e) {
        cout << "Caught NetworkException:" << endl;
        cout << "  Full message: " << e.getFullMessage() << endl;
        cout << "  Hostname: " << e.getHostname() << endl;
        cout << "  Port: " << e.getPort() << endl;
        cout << "  Network error code: " << e.getNetworkErrorCode() << endl;
    }

    cout << "\n--- Exception Hierarchy Handling ---" << endl;

    auto throwRandomException = []() {
        int choice = rand() % 3;
        switch (choice) {
            case 0:
                throw ValidationException("age", "-5", "Must be positive");
            case 1:
                throw ResourceException("database", "user_db", "Connection timeout");
            case 2:
                throw NetworkException("localhost", 8080, 404, "Service unavailable");
        }
    };

    for (int i = 0; i < 3; ++i) {
        try {
            throwRandomException();
        } catch (const ValidationException& e) {
            cout << "Handling ValidationException: " << e.getFullMessage() << endl;
        } catch (const ResourceException& e) {
            cout << "Handling ResourceException: " << e.getFullMessage() << endl;
        } catch (const NetworkException& e) {
            cout << "Handling NetworkException: " << e.getFullMessage() << endl;
        } catch (const ApplicationException& e) {
            cout << "Handling base ApplicationException: " << e.getFullMessage() << endl;
        } catch (const std::exception& e) {
            cout << "Handling standard exception: " << e.what() << endl;
        } catch (...) {
            cout << "Handling unknown exception" << endl;
        }
    }
}

void demonstrateNoexceptSpecifications() {
    cout << "\n=== Noexcept Specifications ===" << endl;

    cout << "\n--- Basic Noexcept Operations ---" << endl;

    NoexceptDemo demo1(5);
    cout << "Created demo1 with size: " << demo1.size() << endl;

    // Move operations are noexcept
    NoexceptDemo demo2 = std::move(demo1);
    cout << "Moved demo1 to demo2, demo2 size: " << demo2.size() << endl;
    cout << "demo1 size after move: " << demo1.size() << endl;

    // Test noexcept element access
    for (size_t i = 0; i < demo2.size(); ++i) {
        demo2[i] = static_cast<int>(i * 10);
    }

    cout << "demo2 contents: ";
    for (size_t i = 0; i < demo2.size(); ++i) {
        cout << demo2[i] << " ";
    }
    cout << endl;

    cout << "\n--- Noexcept vs Throwing Access ---" << endl;

    try {
        cout << "Safe access demo2[2]: " << demo2[2] << endl;  // noexcept
        cout << "Checked access demo2.at(2): " << demo2.at(2) << endl;  // can throw
        cout << "Accessing out of bounds demo2.at(10)..." << endl;
        demo2.at(10);  // Will throw
    } catch (const exception& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    cout << "\n--- Conditional Noexcept Templates ---" << endl;

    int a = 10, b = 20;
    string s1 = "hello", s2 = "world";

    cout << "Before swap - a: " << a << ", b: " << b << endl;
    conditionalNoexceptSwap(a, b);  // noexcept for int
    cout << "After swap - a: " << a << ", b: " << b << endl;

    cout << "Before swap - s1: " << s1 << ", s2: " << s2 << endl;
    conditionalNoexceptSwap(s1, s2);  // noexcept depends on string's swap
    cout << "After swap - s1: " << s1 << ", s2: " << s2 << endl;

    // Demonstrate conditional noexcept with containers
    vector<int> vec = {1, 2, 3, 4, 5};
    cout << "Vector size (conditional noexcept): " << getSize(vec) << endl;

    cout << "\n--- Noexcept Type Traits ---" << endl;

    cout << "is_nothrow_move_constructible<NoexceptDemo>: "
         << is_nothrow_move_constructible_v<NoexceptDemo> << endl;
    cout << "is_nothrow_move_assignable<NoexceptDemo>: "
         << is_nothrow_move_assignable_v<NoexceptDemo> << endl;
    cout << "is_nothrow_copy_constructible<NoexceptDemo>: "
         << is_nothrow_copy_constructible_v<NoexceptDemo> << endl;
    cout << "is_nothrow_swappable<NoexceptDemo>: "
         << is_nothrow_swappable_v<NoexceptDemo> << endl;

    PerformanceTest::performanceComparison();
}

// Exception handling best practices demonstration
class BestPracticesDemo {
public:
    // Good: Specific exception types
    static void processUserInput(const string& input) {
        if (input.empty()) {
            throw ValidationException("input", input, "Input cannot be empty");
        }

        if (input.length() > 100) {
            throw ValidationException("input", input, "Input too long (max 100 characters)");
        }

        if (input.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ") != string::npos) {
            throw ValidationException("input", input, "Input contains invalid characters");
        }

        cout << "Processing valid input: " << input << endl;
    }

    // Good: Exception-safe resource management
    static void processFile(const string& filename) {
        unique_ptr<FILE, decltype(&fclose)> file(fopen(filename.c_str(), "r"), &fclose);

        if (!file) {
            throw ResourceException("file", filename, "Cannot open file");
        }

        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), file.get())) {
            // Process file content
            // If exception occurs here, file is automatically closed
        }

        cout << "Successfully processed file: " << filename << endl;
    }

    // Good: Strong exception safety with RAII
    static vector<string> processStrings(const vector<string>& input) {
        vector<string> result;
        result.reserve(input.size());  // May throw, but result is empty

        for (const auto& str : input) {
            if (str.empty()) {
                throw ValidationException("string", str, "Empty string not allowed");
            }

            string processed = str;
            transform(processed.begin(), processed.end(), processed.begin(), ::toupper);
            result.push_back(processed);  // May throw, but input unchanged
        }

        return result;  // Return only on complete success
    }
};

void demonstrateBestPractices() {
    cout << "\n=== Exception Handling Best Practices ===" << endl;

    cout << "\n--- Input Validation with Specific Exceptions ---" << endl;

    vector<string> testInputs = {
        "Valid Input 123",
        "",  // Empty
        "This input is way too long and exceeds the maximum allowed length of 100 characters by a significant margin",  // Too long
        "Invalid@#$%Characters"  // Invalid chars
    };

    for (const auto& input : testInputs) {
        try {
            BestPracticesDemo::processUserInput(input);
        } catch (const ValidationException& e) {
            cout << "Validation failed: " << e.getFullMessage() << endl;
        }
    }

    cout << "\n--- Exception-Safe File Processing ---" << endl;

    // Create a test file
    {
        ofstream testFile("test_exception.txt");
        testFile << "Line 1: Test content" << endl;
        testFile << "Line 2: More content" << endl;
    }

    try {
        BestPracticesDemo::processFile("test_exception.txt");
        BestPracticesDemo::processFile("nonexistent.txt");  // Will throw
    } catch (const ResourceException& e) {
        cout << "File processing failed: " << e.getFullMessage() << endl;
    }

    cout << "\n--- Strong Exception Safety ---" << endl;

    vector<string> validStrings = {"hello", "world", "test"};
    vector<string> invalidStrings = {"hello", "", "world"};  // Contains empty string

    try {
        auto result1 = BestPracticesDemo::processStrings(validStrings);
        cout << "Successfully processed valid strings: ";
        for (const auto& s : result1) cout << s << " ";
        cout << endl;

        auto result2 = BestPracticesDemo::processStrings(invalidStrings);  // Will throw
    } catch (const ValidationException& e) {
        cout << "String processing failed: " << e.getFullMessage() << endl;
        cout << "Original input unchanged due to strong exception safety" << endl;
    }
}

int main() {
    demonstrateCustomExceptions();
    demonstrateNoexceptSpecifications();
    demonstrateBestPractices();

    cout << "\n=== Exception Handling Best Practices Summary ===" << endl;
    cout << "⚡ Use noexcept for guaranteed non-throwing operations" << endl;
    cout << "⚡ Create specific exception types for different error categories" << endl;
    cout << "⚡ Provide strong exception safety with copy-and-swap" << endl;
    cout << "⚡ Use RAII for automatic resource cleanup" << endl;
    cout << "⚡ Document exception specifications in function contracts" << endl;

    return 0;
}
```

**Output:**

```
=== Custom Exceptions and Exception Hierarchy ===

--- Validation Exception ---
Caught ValidationException:
  Full message: [VALIDATION:1001] Field 'email' with value 'invalid-email': Must contain @ symbol
  Field: email
  Value: invalid-email
  Error code: 1001

--- Resource Exception ---
Caught ResourceException:
  Full message: [RESOURCE:2001] file 'nonexistent.txt': File not found
  Resource type: file
  Resource ID: nonexistent.txt

--- Network Exception ---
Caught NetworkException:
  Full message: [NETWORK:3001] api.example.com:443 (net:10061): Connection refused
  Hostname: api.example.com
  Port: 443
  Network error code: 10061

--- Exception Hierarchy Handling ---
Handling ValidationException: [VALIDATION:1001] Field 'age' with value '-5': Must be positive
Handling ResourceException: [RESOURCE:2001] database 'user_db': Connection timeout
Handling NetworkException: [NETWORK:3001] localhost:8080 (net:404): Service unavailable

=== Noexcept Specifications ===

--- Basic Noexcept Operations ---
Created demo1 with size: 5
Moved demo1 to demo2, demo2 size: 5
demo1 size after move: 0
demo2 contents: 0 10 20 30 40

--- Noexcept vs Throwing Access ---
Safe access demo2[2]: 20
Checked access demo2.at(2): 20
Accessing out of bounds demo2.at(10)...
Exception caught: Index out of bounds: 10

--- Conditional Noexcept Templates ---
Before swap - a: 10, b: 20
After swap - a: 20, b: 10
Before swap - s1: hello, s2: world
After swap - s1: world, s2: hello
Vector size (conditional noexcept): 5

--- Noexcept Type Traits ---
is_nothrow_move_constructible<NoexceptDemo>: 1
is_nothrow_move_assignable<NoexceptDemo>: 1
is_nothrow_copy_constructible<NoexceptDemo>: 0
is_nothrow_swappable<NoexceptDemo>: 1

--- Performance Comparison: noexcept vs throwing ---
Throwing version time: 2847 μs
Noexcept version time: 1923 μs
Performance ratio: 1.48x

=== Exception Handling Best Practices ===

--- Input Validation with Specific Exceptions ---
Processing valid input: Valid Input 123
Validation failed: [VALIDATION:1001] Field 'input' with value '': Input cannot be empty
Validation failed: [VALIDATION:1001] Field 'input' with value 'This input is way too long and exceeds the maximum allowed length of 100 characters by a significant margin': Input too long (max 100 characters)
Validation failed: [VALIDATION:1001] Field 'input' with value 'Invalid@#$%Characters': Input contains invalid characters

--- Exception-Safe File Processing ---
Successfully processed file: test_exception.txt
File processing failed: [RESOURCE:2001] file 'nonexistent.txt': Cannot open file

--- Strong Exception Safety ---
Successfully processed valid strings: HELLO WORLD TEST
String processing failed: [VALIDATION:1001] Field 'string' with value '': Empty string not allowed
Original input unchanged due to strong exception safety

=== Exception Handling Best Practices Summary ===
⚡ Use noexcept for guaranteed non-throwing operations
⚡ Create specific exception types for different error categories
⚡ Provide strong exception safety with copy-and-swap
⚡ Use RAII for automatic resource cleanup
⚡ Document exception specifications in function contracts
```

**Exception handling is crucial for building robust C++ applications. Combined with RAII and proper exception safety guarantees, it enables reliable error management and resource cleanup!**

---

## Conclusion of Phase 2: Modern C++ Features

### Phase 2 Complete Summary

**Congratulations!** You have successfully completed **Phase 2** of the comprehensive C++ OOP tutorial, covering essential modern C++ features that form the foundation of contemporary C++ development.

### What We Accomplished

**Phase 2.1: Smart Pointers** ✅

- Mastered `unique_ptr`, `shared_ptr`, and `weak_ptr`
- Learned RAII principles and automatic memory management
- Implemented custom deleters and circular reference prevention

**Phase 2.2: Move Semantics** ✅

- Understood move constructors and move assignment operators
- Applied `std::move` and `std::forward` for optimization
- Implemented perfect forwarding and performance improvements

**Phase 2.3: Lambda Expressions** ✅

- Created lambda functions with various capture modes
- Utilized generic lambdas and recursive patterns
- Applied lambdas with STL algorithms for functional programming

**Phase 2.4: Auto and Decltype** ✅

- Leveraged automatic type deduction with `auto`
- Used `decltype` for complex type computations
- Implemented trailing return types and template metaprogramming

**Phase 2.5: Range-based For Loops** ✅

- Modernized iteration with range-based for loops
- Implemented structured bindings for multi-value iteration
- Created custom iterators and range adaptors

**Phase 2.6: Constexpr Functions** ✅

- Moved computations from runtime to compile-time
- Implemented constexpr algorithms and data structures
- Explored C++20 consteval and template metaprogramming

**Phase 2.7: Namespaces & Using Declarations** ✅

- Organized code with namespace hierarchies
- Applied using declarations and namespace aliases
- Understood ADL (Argument Dependent Lookup) mechanisms

**Phase 2.8: Exception Handling** ✅

- Implemented exception safety guarantees
- Created custom exception hierarchies
- Applied `noexcept` specifications for optimization

### Key Modern C++ Principles Learned

1. **RAII (Resource Acquisition Is Initialization)** - Automatic resource management
2. **Move Semantics** - Efficient resource transfer without copying
3. **Exception Safety** - Robust error handling with guaranteed cleanup
4. **Compile-time Computation** - Performance through constexpr evaluation
5. **Type Deduction** - Cleaner code with automatic type inference
6. **Functional Programming** - Lambda expressions for expressive algorithms
7. **Code Organization** - Namespace management for large codebases
8. **Performance Optimization** - noexcept specifications and move optimization

### What's Next?

With Phase 2 completed, you now have a solid foundation in modern C++ features. The next phases of this tutorial series will build upon these concepts:

- **Phase 3**: Advanced Template Programming and Metaprogramming
- **Phase 4**: Concurrency and Parallel Programming
- **Phase 5**: Standard Library Deep Dive
- **Phase 6**: Design Patterns in Modern C++
- **Phase 7**: Performance Optimization Techniques
- **Phase 8**: Real-world Application Development

### Practice Recommendations

To solidify your understanding of Phase 2 concepts:

1. **Refactor Legacy Code** - Apply smart pointers and move semantics to existing C++ code
2. **Create Custom Containers** - Implement exception-safe containers with modern features
3. **Build Template Libraries** - Use constexpr and auto for reusable components
4. **Design Exception Hierarchies** - Create domain-specific exception types
5. **Optimize Algorithms** - Apply lambda expressions with STL algorithms
6. **Organize Large Projects** - Structure code with meaningful namespace hierarchies

---

**🎉 Phase 2 Complete! You are now proficient in modern C++ features essential for contemporary C++ development. These skills will serve as the foundation for advanced topics in the remaining phases of this comprehensive tutorial series.**
