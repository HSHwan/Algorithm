#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

vector<int> getFail(string str) {
    vector<int> fail(str.size());
    int j = 0;
    for (int i = 1; i < str.size(); i++) {
        while (j > 0 && str[i] != str[j])   j = fail[j - 1];
        if (str[i] == str[j])   fail[i] = ++j;
    }
    
    return fail;
}

string getPStr(int n) {
    string p = "I";
    for (int i = 0; i < n; i++) p.append("OI");
    return p;
}

int main() {
    FAST_IO

    int pNum, strLen;
    string str;

    cin >> pNum >> strLen >> str;
    
    string p = getPStr(pNum);
    vector<int> fail = getFail(p);
    int j = 0, pCount = 0;
    for (int i = 0; i < str.size(); i++) {
        while (j > 0 && str[i] != p[j]) j = fail[j - 1];
        if (str[i] == p[j]) j++;
        if (j == p.size()) {
            pCount++;
            j -= 2;
        }
    }

    cout << pCount;
}