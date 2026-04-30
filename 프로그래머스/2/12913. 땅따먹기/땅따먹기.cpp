#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land) {
    for (int i = 1; i < land.size(); i++) {
        for (int j = 0; j < 4; j++) {
            int prev_max = -1;
            for (int k = 0; k < 4; k++) {
                if (j == k) continue;
                prev_max = max(prev_max, land[i - 1][k]);
            }
            land[i][j] += prev_max;
        }
    }
    
    vector<int> last_land = land.back();
    return *max_element(last_land.begin(), last_land.end());
}