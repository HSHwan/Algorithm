#include <iostream>
#include <vector>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int word_cnt = 0;
vector<string> words;
bool alpha[26], used[26];

int check_words() {
    int cnt = 0;
    for (string word : words) {
        bool read = true;
        for (int i = 4; i < word.size() - 4; i++) {
            if (!alpha[word[i] - 'a']) {
                read = false;
                break;
            }
        }
        if (read)   cnt++;
    }
    return cnt;
}

void backtrack(int idx, int k) {
    word_cnt = max(check_words(), word_cnt);

    if (k == 0 || idx == 25) {
        return;
    }

    for (int i = idx + 1; i < 26; i++) {
        if (!alpha[i] && used[i]) {
            alpha[i] = true;
            backtrack(i, k - 1);
            alpha[i] = false;
        }
    }
}

int main() {
    FAST_IO
    int n, k;
    cin >> n >> k;
    words.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        for (char ch : words[i])    used[ch - 'a'] = true;
    }

    if (k < 5) {
        cout << 0;
        return 0;
    }

    k -= 5;
    for (char ch : string("acint")) alpha[ch - 'a'] = true;

    backtrack(0, k);

    cout << word_cnt;
}