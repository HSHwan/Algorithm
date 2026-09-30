#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
#define N first
#define T second

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer (sources.size(), -1);
    vector<vector<int>> graph (n + 1);
    
    for (vector<int> road : roads) {
        graph[road[0]].push_back(road[1]);
        graph[road[1]].push_back(road[0]);
    }
    
    for (int i = 0; i < sources.size(); i++) {
        vector<bool> visited (n + 1);
        visited[sources[i]] = true;
        queue<pii> q;
        q.push({sources[i], 0});
        while (!q.empty()) {
            int cur_pos = q.front().N;
            int cur_time = q.front().T;
            q.pop();
            
            if (cur_pos == destination) {
                answer[i] = cur_time;
                break;
            }
            
            for (int nxt_pos : graph[cur_pos]) {
                if (visited[nxt_pos])   continue;
                visited[nxt_pos] = true;
                q.push({nxt_pos, cur_time + 1});
            }
        }
    }
    
    return answer;
}