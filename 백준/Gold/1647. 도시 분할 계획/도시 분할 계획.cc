#include <iostream>
#include <vector>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ROOT -1
#define C first
#define U second.first
#define V second.second

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pip;

vector<int> root, root_rank;

int find_root(int n) {
    if (root[n] == ROOT)    return n;
    return root[n] = find_root(root[n]);
}

bool union_vertex(int a, int b) {
    int root_a = find_root(a), root_b = find_root(b);
    if (root_a == root_b)   return false;
    if (root_rank[root_a] > root_rank[root_b])  root[root_b] = root_a;
    else if (root_rank[root_a] < root_rank[root_b]) root[root_a] = root_b;
    else {
        root[root_b] = root_a;
        root_rank[root_a]++;
    }
    return true;
}

int main() {
    FAST_IO
    int n, m;
    cin >> n >> m;

    priority_queue<pip, vector<pip>, greater<>> pq;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({c, {a, b}});
    }

    root.assign(n + 1, ROOT);
    root_rank.assign(n + 1, 0);
    int best_sum = 0, last_connected = 0;
    while (!pq.empty()) {
        pip edge = pq.top();
        if (union_vertex(edge.U, edge.V)) {
            best_sum += edge.C;
            last_connected = edge.C;
        }   
        pq.pop();
    }

    cout << best_sum - last_connected;
}