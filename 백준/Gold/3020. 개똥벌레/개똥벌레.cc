#include <iostream>
#include <vector>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

typedef pair<int, int> pii;

int main() {
    FAST_IO
    int n, h;
    cin >> n >> h;

    vector<int> bot(h + 1, 0), top(h + 1, 0);
    for (int i = 0; i < n; i += 2) {
        int a, b;
        cin >> a >> b;
        bot[a]++;
        top[h + 1 - b]++;
    }

    for (int i = h - 1; i >= 1; i--) {
        bot[i] += bot[i + 1];
    }

    vector<int> result(h + 1, 0);
    int min_cnt = 1e9, section = 0;
    for (int i = 1; i <= h; i++) {
        top[i] += top[i - 1];
        result[i] += top[i] + bot[i];
        if (min_cnt > result[i]) {
            section = 1;
            min_cnt = result[i];
        }
        else if (result[i] == min_cnt)  section++;
    }

    cout << min_cnt << ' ' << section;
}