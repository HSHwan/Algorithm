#include <string>
#include <vector>
#include <algorithm>
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;

int row, col;
vector<vector<bool>> visited;
vector<pii> dirs = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

int dfs(vector<string> maps, pii pos) {
    int sum = maps[pos.X][pos.Y] - '0';
    for (pii dir : dirs) {
        pii nxt_pos = {pos.X + dir.X, pos.Y + dir.Y};
        if (nxt_pos.X >= row || nxt_pos.X < 0 || nxt_pos.Y >= col || nxt_pos.Y < 0)
            continue;
        if (visited[nxt_pos.X][nxt_pos.Y] || maps[nxt_pos.X][nxt_pos.Y] == 'X')  continue;
        visited[nxt_pos.X][nxt_pos.Y] = true;
        sum += dfs(maps, nxt_pos);
    }
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    row = maps.size();
    col = maps.front().size();
    visited.assign(row, vector<bool>(col, false));
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (visited[i][j] || maps[i][j] == 'X') continue;
            visited[i][j] = true;
            answer.push_back(dfs(maps, {i, j}));
        }
    }
    if (answer.empty()) answer.push_back(-1);
    else    sort(answer.begin(), answer.end());
    
    return answer;
}