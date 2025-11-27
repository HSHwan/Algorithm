#include <vector>
#include <queue>
#include <set>
#include <algorithm>

#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;

int solution(vector<vector<int>> land) {
    int row = land.size(), col = land.front().size();
    
    vector<pii> dirs = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
    vector<int> oils(col, 0);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (land[i][j] == 1) {
                set<int> row_idx;
                queue<pii> q;
                q.push({i, j});
                row_idx.insert(j);
                land[i][j] = -1;
                int count = 1;
                
                while (!q.empty()) {
                    pii cur = q.front();
                    q.pop();
                    for (pii dir : dirs) {
                        pii nxt = {cur.X + dir.X, cur.Y + dir.Y};
                        if (nxt.X >= row || nxt.X < 0 || nxt.Y >= col || nxt.Y < 0) continue;
                        if (land[nxt.X][nxt.Y] != 1)    continue;
                        row_idx.insert(nxt.Y);
                        count++;
                        q.push(nxt);
                        land[nxt.X][nxt.Y] = -1;
                    }
                }
                
                for (int i : row_idx) {
                    oils[i] += count;
                }
            }
        }
    }
    
    return *max_element(oils.begin(), oils.end());
}