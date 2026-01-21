#include <iostream>
#include <vector>
#include <queue>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define D first
#define V second
#define INF 1e9

using namespace std;

typedef pair<int, int> pii;

int n, m, r;
vector<vector<pii>> graph;
vector<vector<int>> dist;
vector<int> item;

void find_shortest(int i) {
    dist[i][i] = 0;
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, i});
    while (!pq.empty()) {
        int cur_dist = pq.top().D, cur_v = pq.top().V;
        pq.pop();
        for (pii edge : graph[cur_v]) {
            int nxt_dist = cur_dist + edge.D, nxt_v = edge.V;
            if (nxt_dist < dist[i][nxt_v]) {
                dist[i][nxt_v] = nxt_dist;
                pq.push({nxt_dist, nxt_v});
            }
        }
    }
}

int main() {
    FAST_IO
    cin >> n >> m >> r;
    item.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> item[i];
    }

    graph.resize(n + 1);
    for (int i = 0; i < r; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        graph[a].push_back({l, b});
        graph[b].push_back({l, a});
    }

    dist.assign(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        find_shortest(i);
    }

    int max_item = 0, item_num;
    for (int i = 1; i <= n; i++) {
        item_num = 0;
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] > m) continue;
            item_num += item[j];
        }
        max_item = max(item_num, max_item);
    }

    cout << max_item;
}