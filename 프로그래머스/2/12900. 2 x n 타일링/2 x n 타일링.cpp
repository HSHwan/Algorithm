#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> tiles(n + 1, 0);
    tiles[1] = 1;
    tiles[2] = 2;
    for (int i = 3; i <= n; i++) {
        tiles[i] = (tiles[i - 1] + tiles[i - 2]) % 1'000'000'007;
    }
    return tiles[n];
}