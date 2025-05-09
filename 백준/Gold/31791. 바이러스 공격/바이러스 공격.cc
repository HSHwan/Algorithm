#include <iostream>
#include <vector>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;

int row, col, infect, delay;
vector<string> map;

struct Virus {
    pii pos;
    int time;
};

bool isOutOfRange(pii pos) {
    return pos.X < 0 || pos.X >= row || pos.Y < 0 || pos.Y >= col;
}

void solve(vector<pii> virus) {
    queue<Virus> q;
    vector<vector<int>> visited(row, vector<int>(col, -1));
    for (pii v : virus) {
        visited[v.X][v.Y] = 0;
        q.push({v, 0});
    }
    pii dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!q.empty()) {
        Virus now = q.front();
        pii nowPos = now.pos;
        q.pop();

        if (now.time == infect) continue;

        for (pii dir : dirs) {
            pii nextPos = {nowPos.X + dir.X, nowPos.Y + dir.Y};
            Virus next = {nextPos, now.time + 1};
            if (isOutOfRange(nextPos))  continue;
            if (map[nextPos.X][nextPos.Y] == '#') {
                next.time += delay;
                if (next.time > infect) {
                    if (visited[nextPos.X][nextPos.Y] == -1)  visited[nextPos.X][nextPos.Y] = -2;
                    continue;
                }
            }   
            if (visited[nextPos.X][nextPos.Y] > 0 && next.time >= visited[nextPos.X][nextPos.Y]) continue;
            visited[nextPos.X][nextPos.Y] = next.time;
            q.push(next);
        }
    }

    bool isSafe = false;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (visited[i][j] < 0) {
                cout << i + 1 << ' ' << j + 1 << '\n';   
                isSafe = true;
            }  
        }
    }

    if (!isSafe)    cout << -1;
}

int main() {
    FAST_IO
    cin >> row >> col;

    int virusNum, buildNum;
    cin >> infect >> delay >> virusNum >> buildNum;

    vector<pii> firstVirus;
    map.resize(row);
    for (int i = 0; i < row; i++) {
        cin >> map[i];
        for (int j = 0; j < col; j++) {
            if (map[i][j] == '*')   firstVirus.push_back({i, j});
        }
    }  

    solve(firstVirus);
}