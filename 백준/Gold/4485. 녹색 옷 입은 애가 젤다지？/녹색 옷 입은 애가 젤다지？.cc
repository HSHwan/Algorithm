#include <iostream>
#include <vector>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define X first.first
#define Y first.second
#define R second
#define MAX_R 1e7

using namespace std;

typedef pair<int, int> pii;
typedef pair<pair<int, int>, int> ppi;

void print_black_rupee(int n, int rupee) {
    cout << "Problem " << n << ": " << rupee << '\n';
}

int main() {
    FAST_IO

    vector<pii> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int n, cnt = 0;
    cin >> n;
    while (n) {
        vector<vector<int>> cave(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> cave[i][j];
            }
        }
        
        vector<vector<int>> rupee_sum(n, vector<int>(n, MAX_R));
        queue<ppi> q;
        rupee_sum[0][0] = cave[0][0];
        q.push({{0, 0}, rupee_sum[0][0]});

        while (!q.empty()) {
            ppi cur = q.front();
            q.pop();
            for (pii dir : dirs) {
                int nxt_x = cur.X + dir.first, nxt_y = cur.Y + dir.second;
                if (nxt_x < 0 || nxt_x >= n || nxt_y < 0 || nxt_y >= n) continue;
                int nxt_sum = cur.R + cave[nxt_x][nxt_y];
                if (nxt_sum >= rupee_sum[nxt_x][nxt_y]) continue;
                rupee_sum[nxt_x][nxt_y] = nxt_sum;
                q.push({{nxt_x, nxt_y}, nxt_sum});
            }
        }

        cnt++;
        print_black_rupee(cnt, rupee_sum[n - 1][n - 1]);
        cin >> n;
    }
}