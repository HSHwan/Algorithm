#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long low = 1;
    long long high = (long long)*max_element(times.begin(), times.end()) * n;
    
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long pass = 0;
        for (int time : times) {
            pass += mid / time;
            if (pass >= n)  break;
        }
        if (pass >= n)  high = mid - 1;
        else            low = mid + 1;
    }

    return low;
}