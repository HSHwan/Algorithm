#include <string>
#include <vector>

using namespace std;

int solution(int x, int y, int n) {
    vector<int> calc_count(y + 1, -1);
    calc_count[x] = 0;
    for (int i = x; i < y; i++) {
        if (calc_count[i] == -1)    continue;
        int op_result[3] = {i + n, i * 2, i * 3};
        for (int result : op_result) {
            if (result > y) continue;
            if (calc_count[result] == -1)   calc_count[result] = calc_count[i] + 1;
            else    calc_count[result] = min(calc_count[result], calc_count[i] + 1);
        }
    }
    return calc_count[y];
}