#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cassert>

using namespace std;

const long long MOD = 1000000007LL;
const int MAXLOG = 20;
inline long long madd(long long a, long long b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}
inline long long msub(long long a, long long b)
{
    a -= b;
    if (a < 0)
        a += MOD;
    return a;
}
inline long long mmul(long long a, long long b) { return (a % MOD) * (b % MOD) % MOD; }

int main()
{
    int n, q;
    if (!(cin >> n >> q))
        return 0;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> depth(n + 1, 0), parent0(n + 1, 0), tin(n + 1, 0), tout(n + 1, 0);
    int timer = 0;
    {
        stack<pair<int, int>> st;
        st.push({1, 0});
        while (!st.empty())
        {
            auto pr = st.top();
            st.pop();
            int u = pr.first, p = pr.second;
            if (u > 0)
            {
                parent0[u] = p;
                depth[u] = (p == 0 ? 0 : depth[p] + 1);
                tin[u] = ++timer;
                st.push({-u, p});
                for (int v : g[u])
                    if (v != p)
                    {
                        st.push({v, u});
                    }
            }
            else
            {
                u = -u;
                tout[u] = timer;
            }
        }
    }

    vector<vector<int>> up(MAXLOG, vector<int>(n + 1, 0));
    for (int v = 1; v <= n; ++v)
        up[0][v] = parent0[v];
    for (int j = 1; j < MAXLOG; ++j)
    {
        for (int v = 1; v <= n; ++v)
        {
            int mid = up[j - 1][v];
            up[j][v] = (mid == 0 ? 0 : up[j - 1][mid]);
        }
    }

    auto isAncestor = [&](int a, int b) -> bool
    {
        return tin[a] <= tin[b] && tout[a] >= tout[b];
    };

    auto lca = [&](int a, int b) -> int
    {
        if (a == 0)
            return b;
        if (b == 0)
            return a;
        if (isAncestor(a, b))
            return a;
        if (isAncestor(b, a))
            return b;
        int x = a;
        for (int j = MAXLOG - 1; j >= 0; --j)
        {
            int anc = up[j][x];
            if (anc != 0 && !isAncestor(anc, b))
                x = anc;
        }
        return parent0[x];
    };

    const long long INV2 = (MOD + 1) / 2;

    for (int qi = 0; qi < q; ++qi)
    {
        int k;
        cin >> k;
        vector<int> nodes(k);
        long long totalLabelSum = 0;
        for (int i = 0; i < k; ++i)
        {
            cin >> nodes[i];
            totalLabelSum = madd(totalLabelSum, nodes[i] % MOD);
        }
        if (k == 1)
        {
            cout << 0 << endl;
            continue;
        }
        sort(nodes.begin(), nodes.end(), [&](int a, int b)
             { return tin[a] < tin[b]; });
        vector<int> vs;
        vs.push_back(nodes[0]);
        for (int i = 1; i < (int)nodes.size(); ++i)
        {
            int v = nodes[i];
            int w = lca(v, vs.back());
            if (w == vs.back())
            {
                vs.push_back(v);
                continue;
            }
            while ((int)vs.size() >= 2 && tin[vs[vs.size() - 2]] > tin[w])
            {
                vs.pop_back();
            }
            if (vs.back() != w)
            {
                vs.push_back(w);
            }
            vs.push_back(v);
        }
        sort(vs.begin(), vs.end(), [&](int a, int b)
             { return tin[a] < tin[b]; });
        vs.erase(unique(vs.begin(), vs.end()), vs.end());
        sort(vs.begin(), vs.end(), [&](int a, int b)
             { return tin[a] < tin[b]; });
        vector<int> stv;
        stv.push_back(vs[0]);
        vector<vector<int>> vt(n + 1);
        vector<int> usedNodes;
        usedNodes.push_back(vs[0]);
        for (size_t i = 1; i < vs.size(); ++i)
        {
            int v = vs[i];
            int w = lca(v, stv.back());
            while ((int)stv.size() >= 2 && tin[stv[stv.size() - 2]] > tin[w])
            {
                int child = stv.back();
                stv.pop_back();
                int parent = stv.back();
                vt[parent].push_back(child);
                usedNodes.push_back(child);
            }
            if (stv.back() != w)
            {
                int child = stv.back();
                stv.pop_back();
                vt[w].push_back(child);
                usedNodes.push_back(child);
                if (stv.empty() || stv.back() != w)
                {
                    stv.push_back(w);
                    usedNodes.push_back(w);
                }
            }
            stv.push_back(v);
            usedNodes.push_back(v);
        }
        while (stv.size() >= 2)
        {
            int child = stv.back();
            stv.pop_back();
            int parent = stv.back();
            vt[parent].push_back(child);
            usedNodes.push_back(child);
        }
        int root = stv[0];
        vector<int> isInSet;
        isInSet.assign(n + 1, 0);
        for (int x : nodes)
            isInSet[x] = 1;

        vector<long long> subSum(n + 1, 0);
        vector<pair<int, int>> stack2;
        stack2.push_back({root, 0});
        while (!stack2.empty())
        {
            auto pr = stack2.back();
            stack2.pop_back();
            int u = pr.first, state = pr.second;
            if (state == 0)
            {
                stack2.push_back({u, 1});
                for (int v : vt[u])
                    stack2.push_back({v, 0});
            }
            else
            {
                long long s = 0;
                if (isInSet[u])
                    s = madd(s, u % MOD);
                for (int v : vt[u])
                    s = madd(s, subSum[v]);
                subSum[u] = s;
            }
        }
        long long firstTerm = 0;
        for (int x : nodes)
        {
            long long dx = depth[x];
            long long xmod = x % MOD;
            long long others = msub(totalLabelSum, xmod);
            long long t = mmul(mmul(dx % MOD, xmod), others);
            firstTerm = madd(firstTerm, t);
        }
        long long lcaContrib = 0;
        stack2.clear();
        stack2.push_back({root, 0});
        while (!stack2.empty())
        {
            auto pr = stack2.back();
            stack2.pop_back();
            int u = pr.first, state = pr.second;
            if (state == 0)
            {
                stack2.push_back({u, 1});
                for (int v : vt[u])
                    stack2.push_back({v, 0});
            }
            else
            {
                long long total = 0;
                long long sumsq = 0;
                for (int v : vt[u])
                {
                    long long c = subSum[v];
                    total = madd(total, c);
                    sumsq = madd(sumsq, mmul(c, c));
                }
                if (isInSet[u])
                {
                    long long cu = u % MOD;
                    total = madd(total, cu);
                    sumsq = madd(sumsq, mmul(cu, cu));
                }
                if (total != 0)
                {
                    long long pairs = mmul(msub(mmul(total, total), sumsq), INV2);
                    long long add = mmul((depth[u] % MOD), pairs);
                    lcaContrib = madd(lcaContrib, add);
                }
            }
        }

        long long ans = msub(firstTerm, mmul(2 % MOD, lcaContrib));
        cout << ans << endl;
        for (int u : usedNodes)
            vt[u].clear();
    }
    return 0;
}
