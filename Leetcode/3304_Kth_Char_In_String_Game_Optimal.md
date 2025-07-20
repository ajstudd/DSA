here is what I am thinking, instead of incrementing, character by character, I will do this approach,
I will maintain a last set, which will initially be 0,
then for each iteration , I will do , lastset+ (lastset + number of 1 of size of last set)
so if last set was 0112,
next iteration will give me :
0112 (concat) (0112+1111)
and if the size of the string goes above k, I will pull the kth-1 element from the string, and suppose my initial letter was a.
and kth-1 char of the final string gives me 1,
So I will return a++;
that is b;

will this be optimised approach?

Great! Here's the **optimized solution** that runs in **`O(log k)`** time and **`O(1)`** space — no actual string is built.

---

### ✅ Core Idea:

You're building a pattern like:

```
Iteration 0: a                      → [0]
Iteration 1: a b                   → [0 1]
Iteration 2: a b b c               → [0 1 1 2]
Iteration 3: a b b c b c c d       → [0 1 1 2 1 2 2 3]
```

This is equivalent to:

```
S[0] = 0
S[i] = S[i // 2] + (i % 2)
```

This recurrence gives exactly the value at position `i`, which is how many times the character has been incremented from `'a'`.

---

### 🚀 Final Code (C++):

```cpp
#include <iostream>
using namespace std;

char kthCharacter(int k) {
    k--; // 0-based index
    int count = 0;
    while (k > 0) {
        count += (k % 2);
        k /= 2;
    }
    return 'a' + count;
}

int main() {
    int k;
    cin >> k;
    cout << kthCharacter(k) << endl;
    return 0;
}
```

---

### 🔎 How It Works:

- The number of `1`s in the binary representation of `k - 1` tells how many times to increment `'a'`.
- So, if `k = 5`, `k-1 = 4 → 100 (binary) → 1 one → return 'a' + 1 → 'b'`.

---

### ⏱ Time Complexity:

- **O(log k)** — due to binary decomposition.
- **O(1)** space — no string is created.

---
