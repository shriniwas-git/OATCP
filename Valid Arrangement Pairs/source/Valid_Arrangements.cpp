#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, vector<int>> adj;
vector<vector<int>> ans;

void dfs(int node) {
    while (adj[node].size()) {
        int next = adj[node].back();
        adj[node].pop_back();
        dfs(next);
        ans.push_back({node, next});
    }
}

vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
    map<int, int> indegree;
    for (auto& p : pairs) {
        adj[p[0]].push_back(p[1]);
        ++indegree[p[0]];
        --indegree[p[1]];
    }
    int start = -1;
    for (auto& it : indegree) {
        if (it.second > 0) start = it.first;
    }
    if (start == -1) {
        start = pairs[0][0];
    }
    dfs(start);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream inputFile("input1.txt");
    ofstream outputFile("../output/output1.txt");
    
    int n;
    inputFile >> n;
    vector<vector<int>> pairs(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        inputFile >> pairs[i][0] >> pairs[i][1];
    }

    vector<vector<int>> result = validArrangement(pairs);

    if (result.size()!=n) {
        outputFile << "No valid arrangement possible\n";
    } else {
        for (const auto& pair : result) {
            outputFile << pair[0] << " " << pair[1] << "\n";
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
