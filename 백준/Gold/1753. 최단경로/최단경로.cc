#include <iostream>
#include <vector>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 10e7
#define W first
#define V second

using namespace std;

typedef pair<int, int> pii;

int vertexNum, edgeNum;
int start;
vector<vector<pii>> edges;
vector<int> dist;

void findShortestPath(int v) {
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, v});
    dist[v] = 0;

    while (!pq.empty()) {
        int nowDist = pq.top().W;
        int nowVertex = pq.top().V;
        pq.pop();

        for (pii edge : edges[nowVertex]) {
            int nextVertex = edge.V;
            int nextDist = nowDist + edge.W;
            if (nextDist < dist[nextVertex]) {
                pq.push({nextDist, nextVertex});
                dist[nextVertex] = nextDist;
            }
        }
    }
}

int main() {
    FAST_IO
    cin >> vertexNum >> edgeNum >> start;
    edges.resize(vertexNum + 1);
    for (int i = 0; i < edgeNum; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({w, v});
    }
    dist.assign(vertexNum + 1, INF);
    findShortestPath(start);

    for (int i = 1; i <= vertexNum; i++) {
        if (dist[i] == INF)    cout << "INF";
        else                        cout << dist[i];
        cout << '\n';
    }
}