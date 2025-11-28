#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

vector<vector<int>> tree;
vector<int> dep, ans;

void dfs(int v, int d) {
    dep[v] = d;
    for (int nxt : tree[v]) {
        if (dep[nxt] != -1)   continue;
        ans[nxt] = v;
        dfs(nxt, d + 1);
    }
}

int main() {
    FAST_IO
    int n;
    cin >> n;
    tree.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dep.assign(n + 1, -1);
    ans.assign(n + 1, 0);

    dfs(1, 0);
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