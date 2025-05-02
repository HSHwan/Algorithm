#include <iostream>
#include <vector>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 11
#define MAX_TILT 10
#define X first
#define Y second
#define ESCAPE make_pair(-1, -1)

using namespace std;

typedef pair<int, int> pii;

struct Ball {
    pii r, b;
    int tiltCount;
};

int row, col;
char board[MAX][MAX];

void tiltBall(pii& ball, pii dir) {
    while (board[ball.X][ball.Y] != '#') {
        if (board[ball.X][ball.Y] == 'O') {
            ball = {-1, -1};
            return;
        }
        ball.X += dir.X;
        ball.Y += dir.Y;
    }
    ball.X -= dir.X;
    ball.Y -= dir.Y;
}

int findBallEscapeCount(pii red, pii blue) {
    Ball nowBall = {red, blue, 0};
    queue<Ball> ballQ;
    ballQ.push(nowBall);

    vector<pii> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    while (!ballQ.empty()) {
        nowBall = ballQ.front();
        ballQ.pop();

        if (nowBall.b == ESCAPE)    continue;
        if (nowBall.tiltCount > MAX_TILT)   break;
        if (nowBall.r == ESCAPE)    return nowBall.tiltCount;

        for (pii dir : dirs) {
            Ball nextBall = nowBall;
            nextBall.tiltCount++;
            tiltBall(nextBall.r, dir);
            tiltBall(nextBall.b, dir);
            if (nextBall.r != ESCAPE && nextBall.r == nextBall.b) {
                if (dir.X * (nowBall.r.X - nowBall.b.X) > 0 || dir.Y * (nowBall.r.Y - nowBall.b.Y) > 0) {
                    nextBall.b.X -= dir.X;
                    nextBall.b.Y -= dir.Y;
                }
                else {
                    nextBall.r.X -= dir.X;
                    nextBall.r.Y -= dir.Y;
                }
            }
            ballQ.push(nextBall);
        }
    }

    return -1;
}

int main() {
    FAST_IO
    cin >> row >> col;
    for (int i = 0; i < row; i++) {
        cin >> board[i];
    }

    pii redPos, bluePos;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == 'R') {
                redPos = {i, j};
                board[i][j] = '.';
            }  
            else if (board[i][j] == 'B') {
                bluePos = {i, j};
                board[i][j] = '.';
            }
        }
    }

    cout << findBallEscapeCount(redPos, bluePos);
}