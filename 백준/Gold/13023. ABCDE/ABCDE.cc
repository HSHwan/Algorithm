#include <iostream>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 2000
using namespace std;

int v, e;
vector<vector<int>> graph;
bool visited[MAX];
bool exists = false;

void dfs(int v, int cnt) {
    if (exists) return;

    visited[v] = true;
    if (cnt == 4) {
        exists = true;
        return;
    }
    for (int nxt : graph[v]) {
        if (visited[nxt])   continue;
        dfs(nxt, cnt + 1);
    }
    visited[v] = false;
}

int main() {
    FAST_IO
    cin >> v >> e;
    graph.resize(v);
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < v; i++) {
        if (!graph[i].empty()) {
            visited[i] = true;
            dfs(i, 0);
        }  
        if (exists) break;
    }

    if (exists) cout << 1;
    else        cout << 0;
}