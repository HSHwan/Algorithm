#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int n, m, h;
vector<vector<bool>> horizon_line;
int horizon_num = 1e7;

bool match() {
    for (int i = 1; i <= n; i++) {
        int cur_v = i;
        for (int j = 1; j <= h; j++) {
            if (horizon_line[cur_v][j]) cur_v++;
            else if (horizon_line[cur_v - 1][j])    cur_v--;
        }

        if (cur_v != i) return false;
    }
    return true;
}

void backtrack(int idx, int cnt) {
    if (cnt > 3)    return;

    if (match()) {
        horizon_num = min(cnt, horizon_num);
        return;
    }

    for (int i = idx; i <= h; i++) {
        for (int j = 1; j < n; j++) {
            if (horizon_line[j - 1][i] || horizon_line[j][i] || horizon_line[j + 1][i]) continue;
            horizon_line[j][i] = true;
            backtrack(i, cnt + 1);
            horizon_line[j][i] = false;
        }
    }
}

int main() {
    FAST_IO
    cin >> n >> m >> h;

    horizon_line.resize(n + 1, vector<bool>(h + 1, false));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        horizon_line[b][a] = true;
    }

    backtrack(1, 0);

    if (horizon_num == 1e7) horizon_num = -1;
    cout << horizon_num;
}