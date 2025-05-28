#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long low = 1, high = 1e15;
    
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