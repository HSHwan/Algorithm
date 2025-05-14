#include <iostream>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int word_cnt = 0;
vector<int> words;

void backtrack(int idx, int k, int used) {
    if (k == 0) {
        int cnt = 0;
        for (int word : words)  if ((word | used) == used)  cnt++;
        word_cnt = max(cnt, word_cnt);
        return;
    }

    for (int i = idx; i < 26; i++) {
        if (used & (1 << i))    continue;
        backtrack(i, k - 1, used | (1 << i));
    }
}

int main() {
    FAST_IO
    int n, k;
    cin >> n >> k;
    words.resize(n);
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (char ch : str) words[i] |= (1 << (ch - 'a'));
    }

    int used = 0;
    for (char ch : string("acint")) used |= (1 << (ch - 'a'));

    if (k >= 5) backtrack(0, k - 5, used);

    cout << word_cnt;
}