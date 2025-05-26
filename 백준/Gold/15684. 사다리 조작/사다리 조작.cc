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

void backtrack(int max_cnt, int cnt) {
    if (horizon_num != 1e7) return;
    if (max_cnt == cnt) {
        if (match())    horizon_num = min(cnt, horizon_num);
        return;
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= h; j++) {
            if (horizon_line[i - 1][j] || horizon_line[i][j] || horizon_line[i + 1][j]) continue;
            horizon_line[i][j] = true;
            backtrack(max_cnt, cnt + 1);
            horizon_line[i][j] = false;
            while(!horizon_line[i - 1][j] && !horizon_line[i + 1][j])   j++;
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

    for (int i = 0; i < 4 && horizon_num == 1e7; i++)   backtrack(i, 0);

    if (horizon_num == 1e7) horizon_num = -1;
    cout << horizon_num;
}