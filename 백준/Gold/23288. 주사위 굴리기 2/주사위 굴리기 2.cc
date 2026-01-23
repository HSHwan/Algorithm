#include <iostream>
#include <vector>
#include <queue>
#define X first
#define Y second
#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

int mapWidth, mapLength;
int moveNum;
int diceDir;
int scoreSum = 0;
vector<int> dicePosNum = {0, 1, 2, 3, 4, 5, 6};
pair<int, int> dicePos;
vector<vector<int>> map;
vector<pair<int, int>> diceDirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<vector<int>> diceRollPos = {{2, 1, 5, 6}, {3, 1, 4, 6}, {5, 1, 2, 6}, {4, 1, 3, 6}};

void input(){
    cin >> mapWidth >> mapLength >> moveNum;
    vector<vector<int>>(mapWidth, vector<int>(mapLength)).swap(map);

    FOR(i, mapWidth){
        FOR(j, mapLength)
            cin >> map[i][j];
    }
}

bool isRollable(const pair<int, int>& pos, const int& nowDir){
    pair<int, int> nextPos = {pos.X + diceDirs[nowDir].X, pos.Y + diceDirs[nowDir].Y};
    return !(nextPos.X >= mapWidth || nextPos.Y >= mapLength || nextPos.X < 0 || nextPos.Y < 0);
}

void rollDice(){
    if (!isRollable(dicePos, diceDir))
        diceDir = (diceDir + 2) % 4;
    dicePos.X += diceDirs[diceDir].X;
    dicePos.Y += diceDirs[diceDir].Y;
    FOR(i, 3){
        swap(dicePosNum[diceRollPos[diceDir][i]], dicePosNum[diceRollPos[diceDir][i + 1]]);
    }
}

void getScore(){
    int score = map[dicePos.X][dicePos.Y];
    pair<int, int> nowPos = dicePos;
    vector<vector<bool>> mapVisit(mapWidth, vector<bool>(mapLength, false));
    queue<pair<int, int>> nextPosContainer;
    nextPosContainer.push(nowPos);
    mapVisit[nowPos.X][nowPos.Y] = true;

    while (!nextPosContainer.empty()){
        nowPos = nextPosContainer.front();
        nextPosContainer.pop();
        scoreSum += score;

        FOR(i, 4){
            if (!isRollable(nowPos, i))
                continue;
            pair<int, int> nextPos = {nowPos.X + diceDirs[i].X, nowPos.Y + diceDirs[i].Y};
            if (!mapVisit[nextPos.X][nextPos.Y] && map[nextPos.X][nextPos.Y] == score){
                nextPosContainer.push(nextPos);
                mapVisit[nextPos.X][nextPos.Y] = true;
            }
        }        
    }
}

void decideDirection(){
    if (dicePosNum[6] > map[dicePos.X][dicePos.Y]){
        diceDir = (diceDir + 1) % 4;
    }
    else if (dicePosNum[6] < map[dicePos.X][dicePos.Y]){
        diceDir = (diceDir + 3) % 4;
    }
}

void solve(){
    dicePos = {0, 0};
    diceDir = 1;
    FOR(i, moveNum){
        rollDice();
        getScore();
        decideDirection();
    }
}

void output(){
    cout << scoreSum;
}

int main(){
    input ();
    solve ();
    output();
}