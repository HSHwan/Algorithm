#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ROOT -1

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> vertexRoot;

void unionGraph(int rootV, int leafV) {
    vertexRoot[leafV] = rootV;
}

void dfs(int v) {
    visited[v] = true;

    for (int nextV : graph[v]) {
        if (!visited[nextV]) {
            dfs(nextV);
        }
    }
    cout << v << ' ';
}

int main() {
    FAST_IO
    int vertexNum, edgeNum;
    cin >> vertexNum >> edgeNum;
    graph.resize(vertexNum + 1);
    visited.assign(vertexNum + 1, false);
    vertexRoot.assign(vertexNum + 1, ROOT);

    for (int i = 0; i < edgeNum; i++) {
        int u, v;
        cin >> u >> v;
        graph[v].push_back(u);
        unionGraph(v, u);
    }

    for (int i = 1; i <= vertexNum; i++) {
        if (vertexRoot[i] == ROOT)   dfs(i);
    }
}