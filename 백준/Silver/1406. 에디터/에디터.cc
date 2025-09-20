#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL);

    string leftStr, nextStr;
    cin >> leftStr;

    int cmdNum;
    cin >> cmdNum;

    for (int i = 0; i < cmdNum; i++) {
        char cmd;
        cin >> cmd;

        switch (cmd) {
            case 'L': {
                if (!leftStr.empty()) {
                    nextStr.push_back(leftStr.back());
                    leftStr.pop_back();
                }
                break;
            }
            
            case 'D': {
                if (!nextStr.empty()) {
                    leftStr.push_back(nextStr.back());
                    nextStr.pop_back();
                }
                break;
            }

            case 'B': {
                if (!leftStr.empty()) {
                    leftStr.pop_back();
                }
                break;
            }

            case 'P': {
                char nextChar;
                cin >> nextChar;
                leftStr.push_back(nextChar);
                break;
            }
        }
    }

    reverse(nextStr.begin(), nextStr.end());
    cout << leftStr + nextStr;
}