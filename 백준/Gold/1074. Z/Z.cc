#include <iostream>
#include <vector>
#include <cmath>
#define X first
#define Y second
#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

int arrPow;
int arrLen;
pair<int, int> pos;
int count = 0;

void input(){
    cin >> arrPow;
    arrLen = (int)pow(2, arrPow);

    cin >> pos.X >> pos.Y;
}

void solve(){
    pair<int, int> nowPos = {0, 0};
    int nowLen = arrLen / 2;
    while (nowPos.X != pos.X || nowPos.Y != pos.Y) {
        if (nowPos.X + nowLen <= pos.X) {
            count += 2 * nowLen * nowLen;
            nowPos.X += nowLen;
        }
            
        if (nowPos.Y + nowLen <= pos.Y) {
            count += nowLen * nowLen;
            nowPos.Y += nowLen;
        }

        nowLen /= 2;
    }
}

void output(){
    cout << count;
}

int main(){
    input ();
    solve ();
    output();
}