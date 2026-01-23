#include <iostream>

using namespace std;

void moveHanoiTop(int n, int start, int dest) {
    if (n == 1) {
        cout << start << ' ' << dest << '\n';
        return;
    }

    int anotherTop = 6 - (start + dest);
    moveHanoiTop(n - 1, start, anotherTop);
    cout << start << ' ' << dest << '\n';
    moveHanoiTop(n - 1, anotherTop, dest);
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL);

    int plateNum;
    cin >> plateNum;

    cout << (1 << plateNum) - 1 << '\n';

    moveHanoiTop(plateNum, 1, 3);
}