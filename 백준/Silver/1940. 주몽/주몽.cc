#include <iostream>
#include <vector>
#include <algorithm>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    FAST_IO

    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (num >= m)    continue;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    int count = 0;
    for (int i = 0, j = nums.size() - 1; i < nums.size() && j > i;) {
        int sum = nums[i] + nums[j];
        if (sum > m)    j--;
        else if (sum < m)   i++;
        else {
            i++;
            j--;
            count++;
        }
    }

    cout << count;
}