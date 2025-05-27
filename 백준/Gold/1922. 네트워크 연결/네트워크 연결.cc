#include <iostream>
#include <vector>
#include <queue>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define C first
#define U second.first
#define V second.second
#define ROOT -1

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> ppi;

vector<int> root, rank_;

int find_root(int v) {
    if (root[v] == ROOT)    return v;
    return root[v] = find_root(root[v]);
}

bool union_vertex(int a, int b) {
    int root_a = find_root(a);
    int root_b = find_root(b);

    if (root_a == root_b)   return false;

    if (rank_[root_a] > rank_[root_b]) {
        root[root_b] = root_a;
    }
    else if (rank_[root_a] < rank_[root_b]) {
        root[root_a] = root_b;
    }
    else {
        root[root_b] = root_a;
        rank_[root_a]++;
    }

    return true;
}

int main() {
    FAST_IO

    int n, m;
    cin >> n >> m;
    
    priority_queue<ppi, vector<ppi>, greater<>> pq;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b) continue;
        pq.push({c, {a, b}});
    }

    root.assign(n + 1, ROOT);
    rank_.assign(n + 1, 0);
    int best = 0;
    while (!pq.empty()) {
        ppi edge = pq.top();
        if (union_vertex(edge.U, edge.V))   best += edge.C;
        pq.pop();
    }

    cout << best;
}