#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define X first
#define Y second
#define INF 1e7

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

int row, col;
vector<string> map;
vector<vector<int>> fire;
vector<vector<bool>> visited;
int escape = INF;
pii dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool isOut(pii pos) {
    return pos.X < 0 || pos.X >= row || pos.Y < 0 || pos.Y >= col;
}

void setFire(queue<pii> q) {
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        for (pii dir : dirs) {
            pii nxt = {cur.X + dir.X, cur.Y + dir.Y};
            if (isOut(nxt) || map[nxt.X][nxt.Y] == '#' || fire[nxt.X][nxt.Y] != INF)    continue;
            fire[nxt.X][nxt.Y] = fire[cur.X][cur.Y] + 1;
            q.push(nxt);
        }
    }

}

void bfs(pii pos) {
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    queue<ppi> q;
    q.push({pos, 0});
    visited[pos.X][pos.Y] = true;

    while (!q.empty()) {
        ppi cur = q.front();
        pii curPos = cur.first;
        int curDist = cur.second;
        q.pop();

        if (curPos.X == 0 || curPos.Y == 0 || curPos.X == row - 1 || curPos.Y == col - 1) {
            escape = curDist + 1;
            break;
        }

        for (pii dir : dirs) {
            pii nxtPos = {curPos.X + dir.X, curPos.Y + dir.Y};
            if (isOut(nxtPos) || \
                visited[nxtPos.X][nxtPos.Y] || \
                map[nxtPos.X][nxtPos.Y] != '.' || \
                curDist + 1 >= fire[nxtPos.X][nxtPos.Y]) continue;
            visited[nxtPos.X][nxtPos.Y] = true;
            q.push({nxtPos, curDist + 1});
        }
    }
}


int main() {
    FAST_IO
    cin >> row >> col;
    map.resize(row);
    fire.assign(row, vector<int>(col, INF));
    pii curPos;
    queue<pii> fireQ;
    for (int i = 0; i < row; i++) {
        cin >> map[i];

        for (int j = 0; j < col; j++) {
            if (map[i][j] == 'J')   curPos = {i, j};
            else if (map[i][j] == 'F') {
                fire[i][j] = 0;
                fireQ.push({i, j});
            } 
        }
    }

    setFire(fireQ);

    visited.assign(row, vector<bool>(col, false));

    bfs(curPos);

    if (escape != INF)  cout << escape;
    else    cout << "IMPOSSIBLE";
}