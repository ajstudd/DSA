#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct Fenwick
{
    int n;
    vector<long long> bit;
    Fenwick(int n = 0) { init(n); }
    void init(int n_)
    {
        n = n_;
        bit.assign(n + 2, 0);
    }
    void add(int i, long long val)
    {
        for (; i <= n + 1; i += i & -i)
            bit[i] += val;
    }
    long long sum(int i)
    {
        long long s = 0;
        for (; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }
    void rangeAdd(int l, int r, long long val)
    {
        add(l, val);
        add(r + 1, -val);
    }
    long long pointQuery(int i) { return sum(i); }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, P;
    while (cin >> N >> M >> P)
    {
        vector<long long> A(N + 1);
        for (int i = 1; i <= N; i++)
            cin >> A[i];

        vector<vector<int>> g(N + 1);
        for (int i = 0; i < M; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> parent(N + 1), depth(N + 1);
        vector<int> order;
        order.reserve(N);
        stack<int> st;
        st.push(1);
        parent[1] = 0;
        depth[1] = 0;

        while (!st.empty())
        {
            int u = st.top();
            st.pop();
            order.push_back(u);
            for (int v : g[u])
            {
                if (v != parent[u])
                {
                    parent[v] = u;
                    depth[v] = depth[u] + 1;
                    st.push(v);
                }
            }
        }

        vector<int> sz(N + 1, 1), heavy(N + 1, -1);
        for (int i = (int)order.size() - 1; i >= 0; i--)
        {
            int u = order[i], best = 0;
            for (int v : g[u])
            {
                if (v != parent[u])
                {
                    sz[u] += sz[v];
                    if (sz[v] > best)
                        best = sz[v], heavy[u] = v;
                }
            }
        }

        vector<int> head(N + 1), pos(N + 1);
        vector<long long> base(N + 1);
        int curPos = 1;
        stack<pair<int, int>> stk;
        stk.push({1, 1});

        while (!stk.empty())
        {
            auto [u, h] = stk.top();
            stk.pop();
            for (int v = u; v != -1; v = heavy[v])
            {
                head[v] = h;
                pos[v] = curPos;
                base[curPos++] = A[v];
                for (int w : g[v])
                {
                    if (w != parent[v] && w != heavy[v])
                        stk.push({w, w});
                }
            }
        }

        Fenwick bit(N);
        for (int i = 1; i <= N; i++)
            bit.rangeAdd(i, i, base[i]);

        auto updatePath = [&](int u, int v, long long val)
        {
            while (head[u] != head[v])
            {
                if (depth[head[u]] < depth[head[v]])
                    swap(u, v);
                bit.rangeAdd(pos[head[u]], pos[u], val);
                u = parent[head[u]];
            }
            if (depth[u] > depth[v])
                swap(u, v);
            bit.rangeAdd(pos[u], pos[v], val);
        };

        while (P--)
        {
            char c;
            cin >> c;
            if (c == 'I' || c == 'D')
            {
                int u, v;
                long long k;
                cin >> u >> v >> k;
                updatePath(u, v, (c == 'I' ? k : -k));
            }
            else if (c == 'Q')
            {
                int x;
                cin >> x;
                cout << bit.pointQuery(pos[x]) << '\n';
            }
        }
    }
    return 0;
}
