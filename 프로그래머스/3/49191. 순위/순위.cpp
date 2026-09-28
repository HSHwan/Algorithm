#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> graph(n + 1);
    for (vector<int> result : results) {
        graph[result[0]].push_back(result[1]);
    }
    
    vector<int> count(n + 1);
    for (int i = 1; i <= n; i++) {
        vector<bool> visited (n + 1);
        queue<int> q;
        q.push(i);
        visited[i] = true;
        
        while (!q.empty()) {
            int cur_v = q.front();
            q.pop();
            
            for (int nxt_v : graph[cur_v]) {
                if (visited[nxt_v]) continue;
                visited[nxt_v] = true;
                q.push(nxt_v);
                count[i]++;
                count[nxt_v]++;
            }
        }
    }
    
    for (int i : count) {
        if (i == n - 1) answer++;
    }
    
    return answer;
}