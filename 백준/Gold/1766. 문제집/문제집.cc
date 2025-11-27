#include <iostream>
#include <vector>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    FAST_IO
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> deg(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        deg[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        if (!deg[i])    pq.push(i);
    }

    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        cout << cur << ' ';
        for (int i : graph[cur]) {
            deg[i]--;
            if (!deg[i])    pq.push(i);
        }
    }
}