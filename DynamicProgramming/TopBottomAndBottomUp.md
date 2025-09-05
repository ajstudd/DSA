# Top-Down (memoization) vs Bottom-Up (tabulation)

## Quick conceptual summary (one-sentence each)

- **Top-Down (memoization):** Write the recursive solution that directly matches the recurrence; remember computed results in a table so repeated subproblems are answered in O(1). The recursion drives which states get computed.
- **Bottom-Up (tabulation):** Iteratively compute small subproblems first and use them to build larger ones in a loop — fill the `dp` table from base up to target.

---

## Example problem we’ll use everywhere

Compute Fibonacci numbers (standard definition):

- `fib(0) = 0`
- `fib(1) = 1`
- `fib(n) = fib(n-1) + fib(n-2)` for `n >= 2`.

We will compute `fib(5)` (answer = 5) and also show the internal `dp` table evolution.

---

# 1) Top-Down (Memoization)

### Code (complete, ready to compile)

```cpp
#include <iostream>
#include <vector>
using namespace std;

int fibMemo(int n, vector<int>& dp) {
    if (dp[n] != -1)           // 1. if value already computed, return it
        return dp[n];         //    (memoization lookup)

    if (n == 0)               // 2. base-case: fib(0) = 0
        return dp[n] = 0;     //    store and return

    if (n == 1)               // 3. base-case: fib(1) = 1
        return dp[n] = 1;     //    store and return

    // 4. compute recursively and store result in dp before returning
    dp[n] = fibMemo(n - 1, dp) + fibMemo(n - 2, dp);
    return dp[n];
}

int main() {
    int n = 5;                      // compute fib(5)
    vector<int> dp(n + 1, -1);      // -1 means "not computed yet"
    int result = fibMemo(n, dp);    // call top-down memoized function
    cout << "fib(" << n << ") = " << result << "\n";

    cout << "dp table after computation:\n";
    for (int i = 0; i <= n; ++i)
        cout << "dp[" << i << "] = " << dp[i] << "\n";
    return 0;
}
```

### Line-by-line explanation (each important token)

- `#include <iostream>` / `#include <vector>` — bring in I/O and vector.
- `using namespace std;` — avoid `std::` on every name.
- `int fibMemo(int n, vector<int>& dp)` — function that returns `fib(n)`. The `dp` array is passed by reference so we share the memo table across recursive calls.
- `if (dp[n] != -1)` — **lookup**: if dp\[n] already holds a computed value, no need to recompute.
- `return dp[n];` — return the cached value immediately.
- `if (n == 0) return dp[n] = 0;` — base case; assign and return `dp[0] = 0`.
- `if (n == 1) return dp[n] = 1;` — base case; assign and return `dp[1] = 1`.
- `dp[n] = fibMemo(n - 1, dp) + fibMemo(n - 2, dp);` — compute recursively; **store** result in the memo table.
- `return dp[n];` — return computed value.
- `vector<int> dp(n + 1, -1);` — create memo table sized `n+1`, initialize all entries to `-1` (meaning "unknown").
- `int result = fibMemo(n, dp);` — start recursion.
- Print `dp` to inspect what was filled.

### Execution trace for `n = 5` (call order + dp updates)

I’ll show the call sequence and the dp after each assignment.

1. Call `fibMemo(5, dp)`. `dp[5] == -1` → need to compute `fib(4) + fib(3)`.
2. Compute `fibMemo(4)`: `dp[4] == -1` → compute `fib(3) + fib(2)`.
3. Compute `fibMemo(3)`: `dp[3] == -1` → compute `fib(2) + fib(1)`.
4. Compute `fibMemo(2)`: `dp[2] == -1` → compute `fib(1) + fib(0)`.
5. `fibMemo(1)` hits base → set `dp[1] = 1`, return `1`.

   - `dp` now: `[-1, 1, -1, -1, -1, -1]` (we’ll set dp\[0] next).

6. `fibMemo(0)` hits base → set `dp[0] = 0`, return `0`.

   - `dp` now: `[0, 1, -1, -1, -1, -1]`

7. Back to `fibMemo(2)`: compute `dp[2] = 1 + 0 = 1`, store and return.

   - `dp` now: `[0, 1, 1, -1, -1, -1]`

8. Back to `fibMemo(3)`: second term `fibMemo(1)` → dp\[1] exists (1), so `dp[3] = dp[2] + dp[1] = 1 + 1 = 2`.

   - `dp` now: `[0, 1, 1, 2, -1, -1]`

9. Back to `fibMemo(4)`: `fibMemo(2)` already computed (1), so `dp[4] = dp[3] + dp[2] = 2 + 1 = 3`.

   - `dp` now: `[0, 1, 1, 2, 3, -1]`

10. Back to `fibMemo(5)`: `fibMemo(3)` already computed (2), so `dp[5] = dp[4] + dp[3] = 3 + 2 = 5`.

    - Final `dp`: `[0, 1, 1, 2, 3, 5]`

11. Return `5`. Done.

**Key observation:** nodes in the recursion tree that repeat are computed only once, because `dp[...] != -1` short-circuits repeated calls.

### Complexity (top-down)

- **Time:** O(n) _amortized_, because each `dp[i]` is computed once; each compute does O(1) work beyond recursive calls. (If recurrence has `k` children per state and total distinct states = `S`, time = O(S \* k) roughly.)
- **Space:** O(n) for `dp` plus O(n) recursion stack in worst case (so O(n) extra).

### Pros & cons of Top-Down

- Pros:

  - Natural to write when you already have recursive recurrence.
  - If you only need a small subset of states, it computes only what’s needed.
  - Easier to debug for many problems.

- Cons:

  - Recursion overhead / stack depth may be large (stack overflow risk).
  - Slight constant factor overhead vs iterative loops.

---

# 2) Bottom-Up (Tabulation)

### Code (complete)

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 5;                      // we want fib(5)
    vector<int> dp(n + 1, 0);       // dp[i] will hold fib(i)
    dp[0] = 0;                      // base case
    if (n >= 1) dp[1] = 1;          // base case

    for (int i = 2; i <= n; ++i) {  // fill table from small to large
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    for (int i = 0; i <= n; ++i)    // print results
        cout << "fib(" << i << ") = " << dp[i] << "\n";
    return 0;
}
```

### Line-by-line explanation

- `vector<int> dp(n + 1, 0);` — allocate `dp` array with indices `0..n`, initialize with zeros.
- `dp[0] = 0;` — base value for `fib(0)`.
- `if (n >= 1) dp[1] = 1;` — base value for `fib(1)`. (Check to avoid out-of-range if `n==0`.)
- `for (int i = 2; i <= n; ++i)` — iterate from smallest subproblems upward.
- `dp[i] = dp[i - 1] + dp[i - 2];` — apply recurrence using already computed smaller values.
- Final loop prints all values.

### Table of dp evolution for `n = 5`

- Start: `dp = [0, 0, 0, 0, 0, 0]`
- set `dp[0] = 0` → `[0,0,0,0,0,0]`
- set `dp[1] = 1` → `[0,1,0,0,0,0]`
- i = 2 → `dp[2] = 1` → `[0,1,1,0,0,0]`
- i = 3 → `dp[3] = 2` → `[0,1,1,2,0,0]`
- i = 4 → `dp[4] = 3` → `[0,1,1,2,3,0]`
- i = 5 → `dp[5] = 5` → `[0,1,1,2,3,5]`

### Complexity (bottom-up)

- **Time:** O(n) — each `i` computed once in a tight loop.
- **Space:** O(n) for `dp` (but often optimizable to O(1) for Fibonacci / linear recurrences).

### Pros & cons of Bottom-Up

- Pros:

  - No recursion overhead.
  - Predictable memory and CPU behavior; often fastest in practice.
  - Easier to optimize memory (rolling arrays) because you control iteration order.

- Cons:

  - You must know an order of computation that respects dependencies (small → large).
  - If you only need a few scattered states, you might do more work than top-down (computes all states up to `n`).

---

# 3) When to pick which (short checklist)

- If recurrence is **natural** and you want quick implementation → **Top-down**.
- If `n` is large and recursion depth could cause stack overflow → **Bottom-up**.
- If you need all states (e.g., printing whole table, reconstructing solution) → **Bottom-up** is usually simpler.
- If you only need some states reachable from target and the state graph is sparse → **Top-down** can avoid unnecessary work.

---

# 4) Small second example — **Climbing Stairs** (ways to reach n steps, 1 or 2 steps at time)

### Recurrence

`ways(n) = ways(n-1) + ways(n-2)`, `ways(0)=1` (one way — do nothing), `ways(1)=1`.

### Top-down (memo)

```cpp
int waysTop(int n, vector<int>& dp) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (dp[n] != -1) return dp[n];
    return dp[n] = waysTop(n-1, dp) + waysTop(n-2, dp);
}
```

### Bottom-up (tabulation)

```cpp
vector<int> dp(n+1, 0);
dp[0] = 1;
if (n >= 1) dp[1] = 1;
for (int i = 2; i <= n; ++i) dp[i] = dp[i-1] + dp[i-2];
```

**Same math, same complexities.** This shows the pattern generalizes beyond Fibonacci.

---

# 5) Important practical tips, pitfalls & optimizations

1. **Initialize memo table properly**

   - Use `-1` (or a sentinel) to mean "not computed". Don’t use `0` unless `0` is not a valid result for uncomputed state.

2. **Careful with base cases**

   - Off-by-one in base cases shifts every result. Decide whether you want `fib(0)=0` or `fib(1)=1` and be consistent.

3. **Watch recursion depth**

   - For large `n` (e.g., `n=10^5`) top-down recursion will overflow the call stack. Use bottom-up or iterative.

4. **Use correct integer type**

   - Fibonacci grows fast. For `n >= 47`, `int` overflows on standard 32-bit. Prefer `long long` (or big integers) when `n` grows.

5. **Space optimization (rolling arrays)**

   - If recurrence only depends on the last `k` states (e.g., Fibonacci depends on last 2), you can keep only those `k` values → O(1) space.
   - Example (Fibonacci O(1) space):

     ```cpp
     long long a = 0, b = 1;
     for (int i = 2; i <= n; ++i) {
         long long c = a + b;
         a = b;
         b = c;
     }
     ```

6. **Reconstruct solution (path)**

   - For problems like LCS or knapsack, compute extra arrays (e.g., `parent[i][j]`) in bottom-up to reconstruct choices.
   - Top-down reconstruction is possible but often trickier.

7. **Multi-dimensional DP**

   - Same principles; just ensure iteration order respects dependencies. Example: if `dp[i][j]` depends on `dp[i-1][j]` and `dp[i][j-1]`, iterate `i` then `j`.

8. **Debugging strategy**

   - Print the `dp` table after computing a small input to check values.
   - For top-down, print when you compute and when you hit memo hits to see saved work.

---

# 6) Quick reference — pros/cons summary (compact)

- **Top-Down**

  - Pros: natural, only compute needed states, simpler to derive from recurrence.
  - Cons: recursion overhead, stack risk, sometimes harder to reason about iteration order.

- **Bottom-Up**

  - Pros: fast, no recursion, easy memory optimizations, deterministic.
  - Cons: may compute unnecessary states, must find correct order.

---

## Final — short checklist for your code

1. Initialize `dp` of size `n+1` properly.
2. Pick `-1` (or `LLONG_MIN`) as uncomputed sentinel in memo.
3. For top-down: set base cases and memoize before returning.
4. For bottom-up: fill base cases then iterate from small to large.
5. Use appropriate integer types and consider O(1) space when possible.

---
