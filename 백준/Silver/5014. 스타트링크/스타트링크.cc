#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 1'000'000
using namespace std;

int maxFloor, nowFloor, targetFloor, up, down;
vector<int> buttonCount(MAX + 1);

void bfs(int pos) {
    fill_n(buttonCount.begin(), MAX + 1, -1);
    int nowPos = pos;
    queue<int> posQ;
    posQ.push(nowPos);
    buttonCount[nowPos] = 0;
    
    while (!posQ.empty()) {
        nowPos = posQ.front();
        posQ.pop();
        for (int step : {up, -down}) {
            int nextPos = nowPos + step;
            if (nextPos < 1 || nextPos > maxFloor)
                continue;
            if (buttonCount[nextPos] != -1)
                continue;
            posQ.push(nextPos);
            buttonCount[nextPos] = buttonCount[nowPos] + 1;
        }
    }
}

int main() {
    cin >> maxFloor >> nowFloor >> targetFloor >> up >> down;

    if (targetFloor == nowFloor)
        buttonCount[targetFloor] = 0;
    
    bfs(nowFloor);

    if (buttonCount[targetFloor] != -1)
        cout << buttonCount[targetFloor];
    else
        cout << "use the stairs";
}