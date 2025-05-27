#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int low = 1, high = *max_element(diffs.begin(), diffs.end());
    while (low <= high) {
        int mid = (low + high) / 2;
        int n = diffs.size(), time_prev = 0;
        unsigned long long t = 0;
        for (int i = 0; i < n; i++) {
            int diff = diffs[i], time_cur = times[i];
            if (diff > mid) t += (time_cur + time_prev) * (diff - mid) + time_cur;
            else            t += time_cur;
            time_prev = time_cur;
        }
        if (t > limit)  low = mid + 1;
        else            high = mid - 1;
    }
    
    return low;
}