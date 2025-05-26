#include <iostream>
#include <vector>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;

struct Fish {
    int cnt;
    pii pos;
};

int n;
vector<vector<int>> map;
int cur_size = 2, cur_eat = 0, cur_time = 0;
pii cur_pos;
pii dirs[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

bool is_out(pii pos) {
    return pos.X < 0 || pos.X >= n || pos.Y < 0 || pos.Y >= n;
}

bool bfs() {
    queue<Fish> fq;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    fq.push({0, cur_pos});
    visited[cur_pos.X][cur_pos.Y] = true;
    Fish best = {n * n, cur_pos};

    while (!fq.empty()) {
        Fish cur = fq.front();
        pii curp = cur.pos;
        fq.pop();
        if (map[curp.X][curp.Y] > 0 && map[curp.X][curp.Y] < cur_size && best.cnt >= cur.cnt) {
            if (best.cnt > cur.cnt || \
                best.pos.X > curp.X || \
                (best.pos.X == curp.X && best.pos.Y > curp.Y))  best = cur;
        }
        if (best.cnt < cur.cnt) break;

        for (pii dir : dirs) {
            pii nxtp = {curp.X + dir.X, curp.Y + dir.Y};
            if (is_out(nxtp) || visited[nxtp.X][nxtp.Y] || map[nxtp.X][nxtp.Y] > cur_size)  continue;
            visited[nxtp.X][nxtp.Y] = true;
            fq.push({cur.cnt + 1, nxtp});
        }
    }

    if (best.cnt != n * n) {
        pii pos = best.pos;
        map[pos.X][pos.Y] = 0;
        cur_time += best.cnt;
        cur_pos = pos;
        cur_eat++;
        if (cur_eat == cur_size) {
            cur_eat = 0;
            cur_size++;
        }
        return true;
    }

    return false;
}

int main() {
    FAST_IO
    cin >> n;
    map.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                cur_pos = {i, j};
                map[i][j] = -1;
            } 
        }
    }

    while (bfs());

    cout << cur_time;
}