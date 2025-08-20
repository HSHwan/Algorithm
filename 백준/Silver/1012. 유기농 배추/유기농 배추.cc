#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 50
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;

int map[MAX][MAX];
int row, col, k;
vector<pii> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void dfs(pii pos) {
    for (pii dir : dirs) {
        pii nxt_pos = {pos.X + dir.X, pos.Y + dir.Y};
        if (nxt_pos.X >= row || nxt_pos.X < 0 || nxt_pos.Y >= col || nxt_pos.Y < 0) continue;
        if (map[nxt_pos.X][nxt_pos.Y] != 1) continue;
        map[nxt_pos.X][nxt_pos.Y] = 0;
        dfs(nxt_pos);
    }
}

void solve() {
    cin >> row >> col >> k;

    vector<pii> selected;
    for (int i = 0; i < k; i++) {
        pii pos;
        cin >> pos.X >> pos.Y;
        selected.push_back(pos);
        map[pos.X][pos.Y] = 1;
    }

    int total = 0;
    for (pii s : selected) {
        if (map[s.X][s.Y] != 1) continue;
        map[s.X][s.Y] = 0;
        dfs(s);
        total++;
    }

    cout << total << '\n';
}

int main() {
    FAST_IO
    
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}