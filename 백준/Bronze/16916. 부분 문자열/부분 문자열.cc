#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

vector<int> getFailFunc(string str) {
    vector<int> fail(str.size());
    int j = 0;
    for (int i = 1; i < str.size(); i++) {
        while (j > 0 && str[i] != str[j])   j = fail[j - 1];
        if (str[i] == str[j])   fail[i] = ++j;
    }

    return fail;
}

int main() {
    FAST_IO

    string s, p;
    cin >> s >> p;

    vector<int> fail = getFailFunc(p);
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        while (j > 0 && s[i] != p[j])   j = fail[j - 1];
        if (s[i] == p[j])   j++;
        if (j == p.size()) {
            cout << 1;
            return 0;
        }
    }

    cout << 0;
}