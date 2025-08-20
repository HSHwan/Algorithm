#include <iostream>
#include <vector>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 1e9
#define T first
#define V second
#define MAX 1001

using namespace std;

typedef pair<int, int> pii;

int v, e, target;
vector<pii> edges[MAX];
vector<vector<int>> time;

void find_shortest(int start) {
    time[start][start] = 0;
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int now_v = pq.top().V, now_t = pq.top().T;
        pq.pop();

        for (pii edge : edges[now_v]) {
            int nxt_v = edge.V, nxt_t = edge.T + now_t;
            if (nxt_t < time[start][nxt_v]) {
                time[start][nxt_v] = nxt_t;
                pq.push({nxt_t, nxt_v});
            }
        }

    }
}

void find_all_shortest() {
    for (int i = 1; i <= v; i++)
        find_shortest(i);
}

void find_longest() {
    int longest = 0;
    for (int i = 1; i <= v; i++)
        longest = max(time[i][target] + time[target][i], longest);
    cout << longest;
}

int main() {
    FAST_IO
    cin >> v >> e >> target;
    time.assign(v + 1, vector<int>(v + 1, INF));
    for (int i = 0; i < e; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        edges[u].push_back({t, v});
    }

    find_all_shortest();

    find_longest();
}