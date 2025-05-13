#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

vector<vector<int>> tree;
int root = 0, except, leaf = 0;

void dfs(int v) {
    if (v == except)    return;
    if (tree[v].empty() || (tree[v].size() == 1 && tree[v][0] == except))   leaf++;

    for (int nxt : tree[v]) {
        if (nxt != except)  dfs(nxt);
    }
}

int main() {
    FAST_IO
    int n;
    cin >> n;
    
    tree.resize(n);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        if (v == -1)    root = i;
        else    tree[v].push_back(i);
    }

    cin >> except;

    dfs(root);

    cout << leaf;
}