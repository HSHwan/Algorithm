#include <iostream>
#include <vector>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> ppi;

int main() {
    FAST_IO
    int r, c;
    cin >> r >> c;

    vector<string> map(r);
    queue<pii> water;
    pii pos, target;
    for (int i = 0; i < r; i++) {
        cin >> map[i];
        for (int j = 0; j < c; j++) {
            switch (map[i][j]) {
                case 'D': {
                    target = {i, j};
                    break;
                }
                case 'S': {
                    pos = {i, j};
                    break;
                }
                case '*': {
                    water.push({i, j});
                    break;
                }
            }
        }
    }

    vector<vector<bool>> visited(r, vector<bool>(c, false));
    int best_t = r * c, map_t = 0;
    queue<ppi> q;
    q.push({0, pos});
    visited[pos.X][pos.Y] = true;
    vector<pii> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!q.empty()) {
        pii cur_pos = q.front().second;
        int cur_t = q.front().first;
        q.pop();
        if (cur_t >= best_t)    break;
        if (map_t == cur_t) {
            map_t++;
            int water_cnt = water.size();
            for (int i = 0; i < water_cnt; i++) {
                pii cur_w = water.front();
                water.pop();
                for (pii dir : dirs) {
                    pii nxt_w = {cur_w.X + dir.X, cur_w.Y + dir.Y};
                    if (nxt_w.X >= r || nxt_w.X < 0 || nxt_w.Y >= c || nxt_w.Y < 0) continue;
                    if (map[nxt_w.X][nxt_w.Y] != '.')   continue;
                    map[nxt_w.X][nxt_w.Y] = '*';
                    water.push(nxt_w);
                }
            }
        }
        for (pii dir : dirs) {
            pii nxt_pos = {cur_pos.X + dir.X, cur_pos.Y + dir.Y};
            if (nxt_pos.X == target.X && nxt_pos.Y == target.Y) {
                best_t = cur_t + 1;
                break;
            }
            if (nxt_pos.X >= r || nxt_pos.X < 0 || nxt_pos.Y >= c || nxt_pos.Y < 0) continue;
            if (visited[nxt_pos.X][nxt_pos.Y] || map[nxt_pos.X][nxt_pos.Y] != '.')  continue;
            visited[nxt_pos.X][nxt_pos.Y] = true;
            q.push({cur_t + 1, nxt_pos});
        }

        
    }

    if (best_t != r * c)    cout << best_t;
    else    cout << "KAKTUS";
}