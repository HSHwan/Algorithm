#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_B 257

using namespace std;

int main() {
    FAST_IO
    int N, M, B;
    cin >> N >> M >> B;

    vector<int> map(MAX_B, 0);
    int max_h = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int h;
            cin >> h;
            map[h]++;
            max_h = max(h, max_h);
        }
    }

    int min_t = 987654321, h = max_h;
    for (int i = max_h; i >= 0; i--) {
        int t = 0, b = B;
        for (int j = max_h; j >= 0; j--) {
            int unit_t = abs(j - i) * map[j];

            if (!map[j]) continue;
            if (j > i) {
                b += unit_t;
                t += unit_t * 2;
            }
            else {
                b -= unit_t;
                t += unit_t;
            }
            if (b < 0) {
                t = min_t;
                break;
            }
        }

        if (t < min_t) {
            min_t = t;
            h = i;
        }
    }

    cout << min_t << ' ' << h;
}