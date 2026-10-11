#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

vector<vector<vector<int>>> pipes;

int backtrack(int n, int k, unordered_set<int> infected) {
    if (n == k || infected.size() == pipes[0].size() - 1)
        return infected.size();
    int max_count = infected.size();
    for (int i = 1; i <= 3; i++) {
        unordered_set<int> nxt_infected(infected);
        vector<bool> visited(pipes[0].size());
        queue<int> q;
        for (int j : infected) {
            visited[j] = true;
            q.push(j);
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            for (int nxt : pipes[i][cur]) {
                if (visited[nxt])   continue;
                visited[nxt] = true;
                q.push(nxt);
                nxt_infected.insert(nxt);
            }
        }
        
        if (nxt_infected.size() == infected.size()) continue;
        max_count = max(max_count, backtrack(n + 1, k, nxt_infected));
    }
    return max_count;
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    pipes.assign(4, vector<vector<int>>(n + 1));
    for (vector<int> edge : edges) {
        int x = edge[0], y = edge[1], type = edge[2];
        pipes[type][x].push_back(y);
        pipes[type][y].push_back(x);
    }
    
    unordered_set<int> infected{infection};
    return backtrack(0, k, infected);
}