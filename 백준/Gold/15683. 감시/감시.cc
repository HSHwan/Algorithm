#include <iostream>
#include <vector>
#include <cstring>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define X first
#define Y second
#define MAX 8
#define CHECK -1

using namespace std;

typedef pair<int, int> pii;

int row, col;
int room[MAX][MAX];
vector<pii> cctv;
pii dirs[4] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
int min_empty = 0;

bool isOutOfRange(pii pos) {
    return pos.X < 0 || pos.X >= row || pos.Y < 0 || pos.Y >= col;
}

int check(pii pos, int d) {
    int cnt = 0;
    pii dir = dirs[d % 4];
    while (!isOutOfRange(pos) && room[pos.X][pos.Y] != 6) {
        if (!room[pos.X][pos.Y]) {
            room[pos.X][pos.Y] = CHECK;
            cnt++;
        }   
        pos.X += dir.X;
        pos.Y += dir.Y;
    }
    return cnt;
}

void backtrack(int idx, int empty) {
    if (idx == cctv.size()) {
        min_empty = min(empty, min_empty);
        return;
    }

    pii current = cctv[idx];
    int nxt_empty = empty;

    int type = room[current.X][current.Y];
    for (int i = 0; i < 4; i++) {
        int temp[MAX][MAX], nxt_empty = empty;
        memcpy(temp, room ,sizeof(room));
        if ((type == 2 && i > 1) || (type == 5 && i > 0))   break;
        nxt_empty -= check(current, i);
        if (type == 5)  nxt_empty -= check(current, i + 1);
        if (type != 1 && type != 3) nxt_empty -= check(current, i + 2);
        if (type != 1 && type != 2) nxt_empty -= check(current, i + 3);
        backtrack(idx + 1, nxt_empty);
        memcpy(room, temp,sizeof(room));
    }
}

int main() {
    FAST_IO
    cin >> row >> col;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> room[i][j];
            if (room[i][j] && room[i][j] != 6)  cctv.push_back({i, j});
            else if (!room[i][j])   min_empty++;
        }   
    }

    backtrack(0, min_empty);
    
    cout << min_empty;
}