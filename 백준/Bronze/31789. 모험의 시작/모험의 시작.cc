#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    FAST_IO

    int n, money, attack;
    cin >> n >> money >> attack;

    string adventure = "NO";
    for (int i = 0; i < n; i++) {
        int s, c;
        cin >> c >> s;
        if (c > money || s <= attack)   continue;
        adventure = "YES";
    }
    cout << adventure;
}