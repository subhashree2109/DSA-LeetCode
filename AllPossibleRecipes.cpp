#include <bits/stdc++.h>
using namespace std;

vector<string> findAllRecipes(
    vector<string>& recipes,
    vector<vector<string>>& ingredients,
    vector<string>& supplies
) {
    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> indegree;

    // Initialize indegree
    for (auto& r : recipes)
        indegree[r] = 0;

    // Build graph
    for (int i = 0; i < recipes.size(); i++) {
        for (auto& ing : ingredients[i]) {
            graph[ing].push_back(recipes[i]);
            indegree[recipes[i]]++;
        }
    }

    queue<string> q;
    for (auto& s : supplies)
        q.push(s);

    vector<string> result;

    while (!q.empty()) {
        string cur = q.front();
        q.pop();

        for (auto& next : graph[cur]) {
            if (--indegree[next] == 0) {
                result.push_back(next);
                q.push(next);
            }
        }
    }

    return result;
}

int main() {
    vector<string> recipes = {"bread","sandwich","burger"};
    vector<vector<string>> ingredients = {
        {"yeast","flour"},
        {"bread","meat"},
        {"sandwich","meat","bread"}
    };
    vector<string> supplies = {"yeast","flour","meat"};

    vector<string> ans = findAllRecipes(recipes, ingredients, supplies);

    for (auto& r : ans)
        cout << r << " ";

    return 0;
}
