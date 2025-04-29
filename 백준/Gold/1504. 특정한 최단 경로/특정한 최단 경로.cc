#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 800
#define INF 1e9
#define W first
#define V second

using namespace std;

typedef pair<int, int> pii;

int v, e;
vector<pii> edge[MAX + 1];
unsigned long long dist[MAX + 1][MAX + 1];

void findShortestPathDist(int start) {
    dist[start][start] = 0;
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int now = pq.top().V;
        int nowDist = pq.top().W;
        pq.pop();

        for (pii e : edge[now]) {
            int next = e.V;
            int nextDist = nowDist + e.W;
            if (nextDist < dist[start][next]) {
                dist[start][next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main() {
    FAST_IO
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({c, b});
        edge[b].push_back({c, a});
    }
    int v1, v2;
    cin >> v1 >> v2;
    fill(dist[0], dist[MAX], INF);
    findShortestPathDist(1);
    findShortestPathDist(v1);
    findShortestPathDist(v2);
    if (dist[1][v1] == INF || dist[v1][v2] == INF || dist[v2][v] == INF)    cout << -1;
    else if (dist[1][v2] == INF || dist[v2][v1] == INF || dist[v1][v] == INF)    cout << -1;
    else    cout << min(dist[1][v1] + dist[v1][v2] + dist[v2][v], dist[1][v2] + dist[v2][v1] + dist[v1][v]);
}