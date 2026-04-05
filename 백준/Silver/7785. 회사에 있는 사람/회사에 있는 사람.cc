#include <iostream>
#include <set>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    FAST_IO
    set<string, greater<string>> logs;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string name, action;
        cin >> name >> action;
        if (action == "enter")  logs.insert(name);
        else logs.erase(name);
    }

    for (auto log : logs) {
        cout << log << '\n';
    }
}