#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    FAST_IO

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<bool> nation(N + 1, false);
        int edge_num = 0;
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            if (!nation[a] || !nation[b]) {
                if (!nation[a]) nation[a] = true;
                if (!nation[b]) nation[b] = true;
                edge_num++;
            }
        }
        
        cout << N - 1 << '\n';
    }
}