#include <iostream>
#include <sstream>
#include <deque>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

void splitString(string str, deque<int>& arr) {
    char delim = ',';
    str = str.substr(1, str.size() - 2);
    istringstream iss(str);
    string buf;
    if (!str.empty() && str.find(delim) == string::npos) {
        arr.push_back(stoi(str));
        return;
    }
    while (getline(iss, buf, delim))    arr.push_back(stoi(buf));
}

void printArr(deque<int> arr, bool isRev) {
    if (arr.empty()) {
        cout << "[]";
        return;
    }

    cout << '[';
    if (!isRev) {
        int arrEnd = arr.size() - 1;
        for (int i = 0; i < arrEnd; i++)
            cout << arr[i] << ',';
        cout << arr.back();
    }
    else {
        int arrEnd = min((int) arr.size() - 1, 0);
        for (int i = arr.size() - 1; i > arrEnd; i--)
            cout << arr[i] << ',';
        cout << arr.front();
    }
    cout << ']';
}

int main() {
    FAST_IO
    int testcase;
    cin >> testcase;

    while (testcase--) {
        string acCmd, arrStr;
        int arrEnd;
        cin >> acCmd >> arrEnd >> arrStr;

        deque<int> arr;
        splitString(arrStr, arr);
        bool isRev = false, isError = false;

        for (char cmd : acCmd) {
            if (cmd == 'R') isRev = !isRev;
            else if (cmd == 'D') {
                if (arr.empty()) {
                    isError = true;
                    break;
                }
                if (isRev)  arr.pop_back();
                else        arr.pop_front();
            }   
        }

        if (isError)    cout << "error";
        else            printArr(arr, isRev);
        cout << '\n';
    }
}