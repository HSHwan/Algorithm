#include <string>
#include <vector>
#include <queue>
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;

int solution(vector<string> maps) {
    int row = maps.size(), col = maps.front().size();
    vector<vector<int>> map_s (row, vector<int>(col, -1)), map_e(row, vector<int>(col, -1));
    vector<pii> dirs = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
    
    pii start_pos, lever_pos, end_pos;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (maps[i][j] == 'S')  start_pos = {i, j};
            else if (maps[i][j] == 'L') lever_pos = {i, j};
            else if (maps[i][j] == 'E') end_pos = {i, j};
        }
    }
    
    map_s[start_pos.X][start_pos.Y] = 0;
    
    queue<pii> q;
    q.push(start_pos);
    while(!q.empty()) {
        pii cur = q.front();
        q.pop();
        for (pii dir : dirs) {
            pii nxt = {cur.X + dir.X, cur.Y + dir.Y};
            if (nxt.X >= row || nxt.X < 0 || nxt.Y >= col || nxt.Y < 0) continue;
            if (map_s[nxt.X][nxt.Y] != -1 || maps[nxt.X][nxt.Y] == 'X') continue;
            map_s[nxt.X][nxt.Y] = map_s[cur.X][cur.Y] + 1;
            q.push(nxt);
            if (maps[nxt.X][nxt.Y] == 'L') {
                while (!q.empty())
                    q.pop();
                break;
            }
        }
    }
    
    if (map_s[lever_pos.X][lever_pos.Y] == -1)  return -1;
    
    map_e[lever_pos.X][lever_pos.Y] = map_s[lever_pos.X][lever_pos.Y];
    q.push(lever_pos);
    while(!q.empty()) {
        pii cur = q.front();
        q.pop();
        for (pii dir : dirs) {
            pii nxt = {cur.X + dir.X, cur.Y + dir.Y};
            if (nxt.X >= row || nxt.X < 0 || nxt.Y >= col || nxt.Y < 0) continue;
            if (map_e[nxt.X][nxt.Y] != -1 || maps[nxt.X][nxt.Y] == 'X') continue;
            map_e[nxt.X][nxt.Y] = map_e[cur.X][cur.Y] + 1;
            q.push(nxt);
            if (maps[nxt.X][nxt.Y] == 'E') {
                while (!q.empty())
                    q.pop();
                break;
            }
        }
    }
    
    return map_e[end_pos.X][end_pos.Y];
}