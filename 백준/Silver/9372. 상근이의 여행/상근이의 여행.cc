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
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
        }
        
        cout << N - 1 << '\n';
    }
}