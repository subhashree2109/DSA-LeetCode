#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
double answer = 0.0;

void dfs(int node, int t, int target, double prob) {
    visited[node] = true;

    // Count unvisited neighbors
    int children = 0;
    for (int nei : graph[node]) {
        if (!visited[nei])
            children++;
    }

    // If time is up
    if (t == 0) {
        if (node == target)
            answer = prob;
        return;
    }

    // If no place to go, frog stays
    if (children == 0) {
        if (node == target)
            answer = prob;
        return;
    }

    // Move to unvisited neighbors
    for (int nei : graph[node]) {
        if (!visited[nei]) {
            dfs(nei, t - 1, target, prob / children);
        }
    }
}

int main() {
    int n = 7, t = 2, target = 4;
    vector<vector<int>> edges = {
        {1,2},{1,3},{1,7},{2,4},{2,6},{3,5}
    };

    graph.resize(n + 1);
    visited.resize(n + 1, false);

    for (auto &e : edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    dfs(1, t, target, 1.0);

    cout << fixed << setprecision(10) << answer << endl;
    return 0;
}
