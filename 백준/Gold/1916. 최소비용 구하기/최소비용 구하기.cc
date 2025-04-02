#include <iostream>
#include <vector>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define W first
#define V second
#define INF 10e8

using namespace std;

typedef pair<int, int> pii;

int cityNum, busNum;
vector<vector<pii>> edges;

int findTravelMinCost(int start, int end) {
    vector<int> cost(cityNum + 1, INF);
    priority_queue<pii> pq;
    cost[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int nowVertex = pq.top().V;
        int nowCost = -pq.top().W;
        pq.pop();
        if (nowCost > cost[end])    continue;

        for (pii edge : edges[nowVertex]) {
            int nextVertex = edge.V;
            int nextCost = nowCost + edge.W;
            if (cost[nextVertex] > nextCost) {
                cost[nextVertex] = nextCost;
                pq.push({-nextCost, nextVertex});
            }
        }
    }

    return cost[end];
}

int main() {
    FAST_IO
    cin >> cityNum >> busNum;
    edges.resize(cityNum + 1, vector<pii>());
    for (int i = 0; i < busNum; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({w, v});
    }
    int start, end;
    cin >> start >> end;

    int cost = findTravelMinCost(start, end);
    cout << cost;
}