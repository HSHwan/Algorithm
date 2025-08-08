#include <string>
#include <vector>
#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int solution(vector<string> storage, vector<string> requests) {
    int row = storage.size(), col = storage.front().size();
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (string req : requests) {
        char target = req[0];
        if (req.size() == 2) {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (storage[i][j] == target)    storage[i][j] = ' ';
                }
            }
        }
        else {
            vector<pair<int, int>> deleted;
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (i != 0 && i != row - 1 && j != 0 && j != col - 1)   continue;
                    if (storage[i][j] == target)    deleted.push_back({i, j});
                    else if (storage[i][j] == ' ') {
                        queue<pair<int, int>> q;
                        vector<vector<bool>> visited(row, vector<bool>(col, false));
                        q.push({i, j});
                        visited[i][j] = true;
                        while (!q.empty()) {
                            pair<int, int> cur_pos = q.front();
                            q.pop();
                            
                            for (pair<int, int> dir : dirs) {
                                int nx = cur_pos.X + dir.X, ny = cur_pos.Y + dir.Y;
                                if (nx >= row || nx < 0 || ny >= col || ny < 0) continue;
                                if (storage[nx][ny] == target && !visited[nx][ny]) {
                                    deleted.push_back({nx, ny});
                                    visited[nx][ny] = true;
                                }
                                else if (storage[nx][ny] == ' ' && !visited[nx][ny]) {
                                    q.push({nx, ny});
                                    visited[nx][ny] = true;
                                }
                            }
                        }
                    }
                }
            }
            
            for (pair<int, int> d : deleted) {
                storage[d.X][d.Y] = ' ';
            }
        }
    }
    
    int answer = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (storage[i][j] != ' ')   answer++;
        }
    }
    
    return answer;
}