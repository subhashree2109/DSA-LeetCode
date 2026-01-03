#include <bits/stdc++.h>
using namespace std;

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    const int INF = 1e9;
    vector<vector<int>> dist(n, vector<int>(n, INF));

    // Distance to itself
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    // Fill edges
    for (auto &e : edges) {
        dist[e[0]][e[1]] = e[2];
        dist[e[1]][e[0]] = e[2];
    }

    // Floyd–Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    int minCount = INT_MAX;
    int resultCity = -1;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= distanceThreshold)
                count++;
        }

        // Choose smallest count, break tie by larger index
        if (count < minCount || (count == minCount && i > resultCity)) {
            minCount = count;
            resultCity = i;
        }
    }

    return resultCity;
}

int main() {
    int n = 4;
    vector<vector<int>> edges = {
        {0,1,3},{1,2,1},{1,3,4},{2,3,1}
    };
    int threshold = 4;

    cout << findTheCity(n, edges, threshold);
    return 0;
}
