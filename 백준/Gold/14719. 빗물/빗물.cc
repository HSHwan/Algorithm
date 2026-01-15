#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    FAST_IO
    int h, w;
    cin >> h >> w;

    vector<int> block(w);
    for (int i = 0; i < w; i++) {
        cin >> block[i];
    }
    
    int total_water = 0;
    for (int i = 1; i < w - 1; i++) {
        int left = block[i], right = block[i];
        for (int j = 0; j < i; j++) {
            left = max(left, block[j]);
        }
        for (int j = i + 1; j < w; j++) {
            right = max(right, block[j]);
        }
        total_water += min(left, right) - block[i];
    }

    cout << total_water;
}