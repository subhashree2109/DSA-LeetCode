#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1e9 + 7;

vector<vector<int>> tree;
vector<long long> fact, invFact;

// Fast exponentiation
long long power(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

// DFS returns {ways, subtree_size}
pair<long long,int> dfs(int node) {
    long long ways = 1;
    int size = 0;

    for (int child : tree[node]) {
        auto [childWays, childSize] = dfs(child);
        ways = ways * childWays % MOD;
        ways = ways * nCr(size + childSize, childSize) % MOD;
        size += childSize;
    }

    return {ways, size + 1};
}

int waysToBuildRooms(vector<int>& prevRoom) {
    int n = prevRoom.size();
    tree.resize(n);

    for (int i = 1; i < n; i++)
        tree[prevRoom[i]].push_back(i);

    // Precompute factorials
    fact.resize(n + 1);
    invFact.resize(n + 1);
    fact[0] = 1;

    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invFact[n] = power(fact[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;

    return dfs(0).first;
}

int main() {
    vector<int> prevRoom = {-1,0,0,1,2};
    cout << waysToBuildRooms(prevRoom);
    return 0;
}
