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
        int k;
        cin >> k;
        vector<int> ord(k);
        for (int j = 0; j < k; j++) cin >> ord[j];
        for (int j = 1; j < k; j++) {
            graph[ord[j - 1]].push_back(ord[j]);
            deg[ord[j]]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!deg[i])    q.push(i);
    }
    
    vector<int> result;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        result.push_back(cur);
        for (int nxt : graph[cur]) {
            deg[nxt]--;
            if (!deg[nxt])  q.push(nxt);
        }
    }

    if (result.size() == n) {
        for (int i : result)    cout << i << '\n';
    }
    else    cout << 0;
}