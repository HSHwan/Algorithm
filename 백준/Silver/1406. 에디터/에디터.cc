#include <iostream>
#include <list>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    FAST_IO

    list<char> str;
    string in_str;
    cin >> in_str;

    for (char ch : in_str)  str.push_back(ch);
    auto cursor = str.end();

    int cmd_num;
    cin >> cmd_num;
    while (cmd_num--) {
        char op;
        cin >> op;
        switch (op) {
            case 'P': {
                char added;
                cin >> added;
                str.insert(cursor, added);
                break;
            }
            case 'L': {
                if (cursor != str.begin())  cursor--;
                break;
            }
            case 'D': {
                if (cursor != str.end())    cursor++;
                break;
            }
            case 'B': {
                if (cursor != str.begin()) {
                    cursor--;
                    cursor = str.erase(cursor);
                }
                break;
            }
        }
    }

    for (char ch : str) cout << ch;
}