#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;

int N;
vector<vector<int>> map;
pii cur_pos;
int total_out = 0;

bool is_out(pii pos) {
    return (pos.X < 0 || pos.X >= N || pos.Y < 0 || pos.Y >= N);
}

void move_sand(pii pos, int moved) {
    if (is_out(pos))  total_out += moved;
    else {
        map[pos.X][pos.Y] += moved;
    }
}

void move_left(int cnt) {
    for (int i = 0; i < cnt; i++) {
        cur_pos.Y--;
        int alpha = map[cur_pos.X][cur_pos.Y];
        vector<pii> two_pos = {{cur_pos.X - 2, cur_pos.Y}, {cur_pos.X + 2, cur_pos.Y}};
        for (pii p : two_pos) {
            int moved = map[cur_pos.X][cur_pos.Y] / 50;
            move_sand(p, moved);
            alpha -= moved;
        }
        vector<pii> one_pos = {{cur_pos.X - 1, cur_pos.Y + 1}, {cur_pos.X + 1, cur_pos.Y + 1}};
        for (pii p : one_pos) {
            int moved = map[cur_pos.X][cur_pos.Y] / 100;
            move_sand(p, moved);
            alpha -= moved;
        }
        vector<pii> seven_pos = {{cur_pos.X - 1, cur_pos.Y}, {cur_pos.X + 1, cur_pos.Y}};
        for (pii p : seven_pos) {
            int moved = map[cur_pos.X][cur_pos.Y] * 7 / 100;
            move_sand(p, moved);
            alpha -= moved;
        }
        vector<pii> ten_pos = {{cur_pos.X - 1, cur_pos.Y - 1}, {cur_pos.X + 1, cur_pos.Y - 1}};
        for (pii p : ten_pos) {
            int moved = map[cur_pos.X][cur_pos.Y] / 10;
            move_sand(p, moved);
            alpha -= moved;
        }
        pii five_pos = {cur_pos.X, cur_pos.Y - 2};
        int moved = map[cur_pos.X][cur_pos.Y] / 20;
        move_sand(five_pos, moved);
        alpha -= moved;

        pii alpha_pos = {cur_pos.X, cur_pos.Y - 1};
        move_sand(alpha_pos, alpha);
        map[cur_pos.X][cur_pos.Y] = 0;
    }
    
}

void move_right(int cnt) {
    for (int i = 0; i < cnt; i++) {
        cur_pos.Y++;
        int alpha = map[cur_pos.X][cur_pos.Y];
        vector<pii> two_pos = {{cur_pos.X - 2, cur_pos.Y}, {cur_pos.X + 2, cur_pos.Y}};
        for (pii p : two_pos) {
            int moved = map[cur_pos.X][cur_pos.Y] / 50;
            move_sand(p, moved);
            alpha -= moved;
        }
        vector<pii> one_pos = {{cur_pos.X - 1, cur_pos.Y - 1}, {cur_pos.X + 1, cur_pos.Y - 1}};
        for (pii p : one_pos) {
            int moved = map[cur_pos.X][cur_pos.Y] / 100;
            move_sand(p, moved);
            alpha -= moved;
        }
        vector<pii> seven_pos = {{cur_pos.X - 1, cur_pos.Y}, {cur_pos.X + 1, cur_pos.Y}};
        for (pii p : seven_pos) {
            int moved = map[cur_pos.X][cur_pos.Y] * 7 / 100;
            move_sand(p, moved);
            alpha -= moved;
        }
        vector<pii> ten_pos = {{cur_pos.X - 1, cur_pos.Y + 1}, {cur_pos.X + 1, cur_pos.Y + 1}};
        for (pii p : ten_pos) {
            int moved = map[cur_pos.X][cur_pos.Y] / 10;
            move_sand(p, moved);
            alpha -= moved;
        }
        pii five_pos = {cur_pos.X, cur_pos.Y + 2};
        int moved = map[cur_pos.X][cur_pos.Y] / 20;
        move_sand(five_pos, moved);
        alpha -= moved;

        pii alpha_pos = {cur_pos.X, cur_pos.Y + 1};
        move_sand(alpha_pos, alpha);
        map[cur_pos.X][cur_pos.Y] = 0;
    }
    
}

void move_up(int cnt) {
    for (int i = 0; i < cnt; i++) {
        cur_pos.X--;
        int alpha = map[cur_pos.X][cur_pos.Y];
        vector<pii> two_pos = {{cur_pos.X, cur_pos.Y - 2}, {cur_pos.X, cur_pos.Y + 2}};
        for (pii p : two_pos) {
            int moved = map[cur_pos.X][cur_pos.Y] / 50;
            move_sand(p, moved);
            alpha -= moved;
        }
        vector<pii> one_pos = {{cur_pos.X + 1, cur_pos.Y - 1}, {cur_pos.X + 1, cur_pos.Y + 1}};
        for (pii p : one_pos) {
            int moved = map[cur_pos.X][cur_pos.Y] / 100;
            move_sand(p, moved);
            alpha -= moved;
        }
        vector<pii> seven_pos = {{cur_pos.X, cur_pos.Y - 1}, {cur_pos.X, cur_pos.Y + 1}};
        for (pii p : seven_pos) {
            int moved = map[cur_pos.X][cur_pos.Y] * 7 / 100;
            move_sand(p, moved);
            alpha -= moved;
        }
        vector<pii> ten_pos = {{cur_pos.X - 1, cur_pos.Y - 1}, {cur_pos.X - 1, cur_pos.Y + 1}};
        for (pii p : ten_pos) {
            int moved = map[cur_pos.X][cur_pos.Y] / 10;
            move_sand(p, moved);
            alpha -= moved;
        }
        pii five_pos = {cur_pos.X - 2, cur_pos.Y};
        int moved = map[cur_pos.X][cur_pos.Y] / 20;
        move_sand(five_pos, moved);
        alpha -= moved;

        pii alpha_pos = {cur_pos.X - 1, cur_pos.Y};
        move_sand(alpha_pos, alpha);
        map[cur_pos.X][cur_pos.Y] = 0;
    }
}

void move_down(int cnt) {
    for (int i = 0; i < cnt; i++) {
        cur_pos.X++;
        int alpha = map[cur_pos.X][cur_pos.Y];
        vector<pii> two_pos = {{cur_pos.X, cur_pos.Y - 2}, {cur_pos.X, cur_pos.Y + 2}};
        for (pii p : two_pos) {
            int moved = map[cur_pos.X][cur_pos.Y] / 50;
            move_sand(p, moved);
            alpha -= moved;
        }
        vector<pii> one_pos = {{cur_pos.X - 1, cur_pos.Y - 1}, {cur_pos.X - 1, cur_pos.Y + 1}};
        for (pii p : one_pos) {
            int moved = map[cur_pos.X][cur_pos.Y] / 100;
            move_sand(p, moved);
            alpha -= moved;
        }
        vector<pii> seven_pos = {{cur_pos.X, cur_pos.Y - 1}, {cur_pos.X, cur_pos.Y + 1}};
        for (pii p : seven_pos) {
            int moved = map[cur_pos.X][cur_pos.Y] * 7 / 100;
            move_sand(p, moved);
            alpha -= moved;
        }
        vector<pii> ten_pos = {{cur_pos.X + 1, cur_pos.Y - 1}, {cur_pos.X + 1, cur_pos.Y + 1}};
        for (pii p : ten_pos) {
            int moved = map[cur_pos.X][cur_pos.Y] / 10;
            move_sand(p, moved);
            alpha -= moved;
        }
        pii five_pos = {cur_pos.X + 2, cur_pos.Y};
        int moved = map[cur_pos.X][cur_pos.Y] / 20;
        move_sand(five_pos, moved);
        alpha -= moved;

        pii alpha_pos = {cur_pos.X + 1, cur_pos.Y};
        move_sand(alpha_pos, alpha);
        map[cur_pos.X][cur_pos.Y] = 0;
    }
}

int main() {
    FAST_IO
    
    cin >> N;
    map.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    cur_pos = {N / 2, N / 2};
    for (int i = 3; i <= N; i += 2) {
        move_left(1);
        move_down(i - 2);
        move_right(i - 1);
        move_up(i - 1);
        move_left(i - 1);
    }

    cout << total_out;
}