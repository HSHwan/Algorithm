#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    FAST_IO

    string pstr;
    cin >> pstr;

    vector<char> open;
    vector<int> value(pstr.size());

    for (char ch : pstr) {
        if (open.empty() && (ch == ')' || ch == ']')) {
            cout << 0;
            return 0;
        }
        int idx = open.size();
        if (ch == '(' || ch == '[') open.push_back(ch);
        else if (open.back() == '(' && ch == ')') {
            value[idx - 1] += 2 * ((value[idx] == 0) ? 1 : value[idx]);
            value[idx] = 0;
            open.pop_back();
        }
        else if (open.back() == '[' && ch == ']') {
            value[idx - 1] += 3 * ((value[idx] == 0) ? 1 : value[idx]);
            value[idx] = 0;
            open.pop_back();
        }
        else    break;
    }

    if (!open.empty()) {
        cout << 0;
        return 0;
    }
    cout << value[0];
}