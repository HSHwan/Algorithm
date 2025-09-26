#include <iostream>
#include <vector>
#define ROOT -1
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

vector<int> root, root_rank;

int find_root(int n) {
    if (root[n] == ROOT)    return n;
    return root[n] = find_root(root[n]);
}

void union_graph(int a, int b) {
    int root_a = find_root(a);
    int root_b = find_root(b);

    if (root_a == root_b)   return;
    if (root_rank[root_a] > root_rank[root_b]) {
        root[root_b] = root_a;
    }
    else if (root_rank[root_b] > root_rank[root_a]) {
        root[root_a] = root_b;
    }
    else {
        root[root_b] = root_a;
        root_rank[root_a]++;
    }
}

int main() {
    FAST_IO

    int n, m;
    cin >> n >> m;

    root.assign(n + 1, ROOT);
    root_rank.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int connected;
            cin >> connected;
            if (connected)  union_graph(i, j);
        }
    }

    vector<int> plan(m);
    for (int i = 0; i < m; i++) cin >> plan[i];

    int target_root = find_root(plan.front());
    for (int city : plan) {
        if (find_root(city) != target_root) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}