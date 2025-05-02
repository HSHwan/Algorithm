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
    int dirNum, tiltCount;
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
    vector<pii> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int idx = 0, now = 0;
    Ball ballArr[1 << 11];
    ballArr[idx++] = {red, blue, -1, 1};

    while (now < idx) {
        Ball nowBall = ballArr[now++];
        if (nowBall.tiltCount > MAX_TILT)   break;

        for (int i = 0; i < 4; i++) {
            if (nowBall.dirNum == i || nowBall.dirNum == (i ^ 1)) continue;
            pii dir = dirs[i];
            Ball nextBall = nowBall;
            tiltBall(nextBall.r, dir);
            tiltBall(nextBall.b, dir);

            if (nextBall.b == ESCAPE)   continue;
            if (nextBall.r == ESCAPE)   return nextBall.tiltCount;
            if (nextBall.r == nextBall.b) {
                if (dir.X * (nowBall.r.X - nowBall.b.X) > 0 || dir.Y * (nowBall.r.Y - nowBall.b.Y) > 0) {
                    nextBall.b.X -= dir.X;
                    nextBall.b.Y -= dir.Y;
                }
                else {
                    nextBall.r.X -= dir.X;
                    nextBall.r.Y -= dir.Y;
                }
            }
            if (nowBall.b == nextBall.b && nowBall.r == nextBall.r) continue;

            nextBall.dirNum = i;
            nextBall.tiltCount++;
            ballArr[idx++] = nextBall;
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