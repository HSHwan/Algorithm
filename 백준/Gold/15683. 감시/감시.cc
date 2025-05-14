#include <iostream>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define X first
#define Y second
#define CHECK -1

using namespace std;

typedef pair<int, int> pii;

int row, col;

vector<vector<int>> room;
vector<pii> cctv;
pii dirs[4] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
int min_empty = 0;

bool isOutOfRange(pii pos) {
    return pos.X < 0 || pos.X >= row || pos.Y < 0 || pos.Y >= col;
}

int check(vector<vector<int>>& map, pii pos, pii dir, int empty) {
    int remaining = empty;
    while (!isOutOfRange(pos) && map[pos.X][pos.Y] != 6) {
        if (!map[pos.X][pos.Y]) {
            map[pos.X][pos.Y] = CHECK;
            remaining--;
        }   
        pos.X += dir.X;
        pos.Y += dir.Y;
    }
    return remaining;
}

void backtrack(int idx, vector<vector<int>> prev, int empty) {
    if (idx == cctv.size()) {
        min_empty = min(empty, min_empty);
        return;
    }

    pii current = cctv[idx];
    int nxt_empty = empty;
    vector<vector<int>> nxt(prev);

    int type = room[current.X][current.Y];
    switch (type) {
        case 1: {
            for (pii dir : dirs) {
                nxt = prev;
                nxt_empty = check(nxt, {current.X + dir.X, current.Y + dir.Y}, dir, empty);
                backtrack(idx + 1, nxt, nxt_empty);
            }
            break;
        }
        case 2: {
            for (int i = 0; i < 2; i++) {
                pii dir = dirs[i], rev_dir = dirs[i + 2];
                nxt = prev;
                nxt_empty = check(nxt, {current.X + dir.X, current.Y + dir.Y}, dir, empty);
                nxt_empty = check(nxt, {current.X + rev_dir.X, current.Y + rev_dir.Y}, rev_dir, nxt_empty);
                backtrack(idx + 1, nxt, nxt_empty);
            }
            break;
        }
        case 3: {
            for (int i = 0; i < 4; i++) {
                pii dir = dirs[i], rdir = dirs[(i + 1) % 4];
                nxt = prev;
                nxt_empty = check(nxt, {current.X + dir.X, current.Y + dir.Y}, dir, empty);
                nxt_empty = check(nxt, {current.X + rdir.X, current.Y + rdir.Y}, rdir, nxt_empty);
                backtrack(idx + 1, nxt, nxt_empty);
            }
            break;
        }
        case 4: {
            for (int i = 0; i < 4; i++) {
                nxt_empty = empty;
                nxt = prev;
                for (int j = 0; j < 4; j++) {
                    if (i == j) continue;
                    pii dir = dirs[j];
                    nxt_empty = check(nxt, {current.X + dir.X, current.Y + dir.Y}, dir, nxt_empty);
                }
                backtrack(idx + 1, nxt, nxt_empty);
            }
            break;
        }
        case 5: {
            for (pii dir : dirs)
                nxt_empty = check(nxt, {current.X + dir.X, current.Y + dir.Y}, dir, nxt_empty);
            backtrack(idx + 1, nxt, nxt_empty);
            break;
        }
    }
}

int main() {
    FAST_IO
    cin >> row >> col;

    room.resize(row, vector<int>(col));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> room[i][j];
            if (room[i][j] && room[i][j] != 6)  cctv.push_back({i, j});
            else if (!room[i][j])   min_empty++;
        }   
    }

    backtrack(0, room, min_empty);
    
    cout << min_empty;
}