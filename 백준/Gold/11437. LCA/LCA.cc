#include <iostream>
#include <vector>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define A first
#define D second

using namespace std;

typedef pair<int, int> pii;

int main() {
    FAST_IO
    int n;
    cin >> n;
    vector<vector<int>> tree(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<int> dep(n + 1, -1), ans(n + 1);

    queue<pii> q;
    q.push({1, 0});
    dep[1] = 0;
    ans[1] = 1;

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        for (int v : tree[cur.A]) {
            if (dep[v] != -1)   continue;
            dep[v] = cur.D + 1;
            q.push({v, dep[v]});
            ans[v] = cur.A;
        }
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (dep[u] < dep[v])    swap(u, v);
        while(dep[u] > dep[v]) {
            u = ans[u];
        }
        while (u != v) {
            u = ans[u];
            v = ans[v];
        }
        cout << u << '\n';
    }
}