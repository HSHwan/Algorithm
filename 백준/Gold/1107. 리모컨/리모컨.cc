#include <iostream>
#include <cstdlib>
#define NOW 100

using namespace std;

int channel, clickCount;
bool isBroken[10];

void checkAllChannels(int nextChannel, int count) {
    clickCount = min(abs(channel - nextChannel) + count, clickCount);
    if (nextChannel >= 1e5)
        return;
    for (int i = 0; i < 10; i++) {
        if (isBroken[i])
            continue;
        checkAllChannels(10 * nextChannel + i, count + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> channel;

    int brokenButtonNum, brokenButton;
    cin >> brokenButtonNum;
    for (int i = 0; i < brokenButtonNum; i++) {
        cin >> brokenButton;
        isBroken[brokenButton] = true;
    }

    clickCount = abs(channel - NOW);
    if (!isBroken[0] && clickCount > channel + 1)
        clickCount = channel + 1;
    for (int i = 1; i < 10; i++) {
        if (isBroken[i])
            continue;
        checkAllChannels(i, 1);
    }

    cout << clickCount;
}