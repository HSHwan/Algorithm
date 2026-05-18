#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

typedef pair<int, int> pii;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<vector<pii>> adj(N + 1);
    vector<int> dist(N + 1, INF);
    dist[1] = 0;
    int start_node = 1;
    for (vector<int> edge : road) {
        int a = edge[0], b = edge[1], d = edge[2];
        adj[a].push_back({d, b});
        adj[b].push_back({d, a});
    }
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    pq.push({0, 1});
    
    while (!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        
        if (cur_dist > dist[cur_node])  continue;
        
        for (pii edge : adj[cur_node]) {
            int nxt_dist = cur_dist + edge.first;
            int nxt_node = edge.second;
            
            if (nxt_dist < dist[nxt_node]) {
                dist[nxt_node] = nxt_dist;
                pq.push({nxt_dist, nxt_node});
            }
        }
    }
    
    for (int d : dist) {
        if (d <= K)
            answer++;
    }

    return answer;
}