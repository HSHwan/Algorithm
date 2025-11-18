#include <iostream>
#include <vector>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define NO -1
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;

int main() {
    FAST_IO
    int n, m;
    cin >> n >> m;

    pii target;
    vector<vector<int>> map(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) target = {i, j};
            else if (map[i][j] == 1)    map[i][j] = NO;         
        }
    }

    vector<pii> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    queue<pii> q;
    map[target.X][target.Y] = 0;
    q.push(target);

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        for (pii dir : dirs) {
            pii nxt = {cur.X + dir.X, cur.Y + dir.Y};
            if (nxt.X < 0 || nxt.X >= n || nxt.Y < 0 || nxt.Y >= m) continue;
            if (map[nxt.X][nxt.Y] != NO)    continue;
            map[nxt.X][nxt.Y] = map[cur.X][cur.Y] + 1;
            q.push(nxt);
        }
    }

    for (vector<int> row : map) {
        for (int i : row) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}