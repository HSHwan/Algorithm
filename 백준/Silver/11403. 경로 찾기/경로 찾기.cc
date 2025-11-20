#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int n;
vector<vector<int>> graph;
vector<vector<bool>> visited;
int start = 0;

void dfs(int v) {
    for (int nxt : graph[v]) {
        if (visited[start][nxt]) continue;
        visited[start][nxt] = true;
        dfs(nxt);
    }   
}

int main() {
    FAST_IO
    
    cin >> n;
    graph.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int is_connected;
            cin >> is_connected;
            if (is_connected)   graph[i].push_back(j);
        }
    }

    visited.assign(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        start = i;
        dfs(i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
}