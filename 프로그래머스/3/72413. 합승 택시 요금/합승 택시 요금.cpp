#include <vector>
#include <queue>

#define MAX 201
#define INF 1e9
#define C first
#define V second

using namespace std;

typedef pair<int, int> pii;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<pii> edges[MAX];
    
    for (vector<int> fare : fares) {
        int start = fare[0], end = fare[1], d = fare[2];
        edges[start].push_back({d, end});
        edges[end].push_back({d, start});
    }
    
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
        priority_queue<pii, vector<pii>, greater<>> pq;
        pq.push({0, i});
        while (!pq.empty()) {
            int cur_v = pq.top().V, cur_cost = pq.top().C;
            pq.pop();
            
            for (pii edge : edges[cur_v]) {
                int nxt_v = edge.V, nxt_cost = cur_cost + edge.C;
                if (nxt_cost < dist[i][nxt_v]) {
                    dist[i][nxt_v] = nxt_cost;
                    pq.push({nxt_cost, nxt_v});
                }
            }
        }
    }
    
    int taxi_cost = INF;
    for (int i = 1; i <= n; i++) {
        int total = dist[s][i] + dist[i][a] + dist[i][b];
        if (total < 0)  continue;
        taxi_cost = min(total, taxi_cost);
    }
    
    return taxi_cost;
}