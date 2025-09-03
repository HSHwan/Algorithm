#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

typedef pair<int, int> pii;

pii target;
vector<vector<int>> graph;
vector<bool> visited;
bool is_found = false;

void dfs(int v, int count) {
    if (v == target.second) {
        is_found = true;
        cout << count;
        return;
    }

    for (int nxt_v : graph[v]) {
        if (visited[nxt_v]) continue;
        visited[nxt_v] = true;
        dfs(nxt_v, count + 1);
        if (is_found)   return;
    }
}

int main() {
    FAST_IO

    int n;

    cin >> n >> target.first >> target.second;
    graph.resize(n + 1);
    visited.assign(n + 1, false);

    int edge_num;
    cin >> edge_num;
    for (int i = 0; i < edge_num; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(target.first, 0);

    if (!is_found)  cout << -1;
}