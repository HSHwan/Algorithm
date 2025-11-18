#include <iostream>
#include <vector>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_COUNT 1e7
#define V first
#define C second

using namespace std;

typedef pair<int, int> pii;

int main() {
    FAST_IO
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int min_v = 1, min_count = MAX_COUNT;
    for (int i = 1; i <= n; i++) {
        vector<bool> visited(n + 1);
        queue<pii> q;
        visited[i] = true;
        q.push({i, 0});
        int count = 0;

        while (!q.empty()) {
            pii cur = q.front();
            q.pop();

            for (int nxt : graph[cur.V]) {
                if (visited[nxt])   continue;
                visited[nxt] = true;
                count += cur.C + 1;
                q.push({nxt, cur.C + 1});
            }
        }
        if (min_count > count) {
            min_v = i;
            min_count = count;
        }
    }

    cout << min_v;
}