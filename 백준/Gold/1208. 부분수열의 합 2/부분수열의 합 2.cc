#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define MAX_LEN 40

using namespace std;

int len, target;
int arr[MAX_LEN];
vector<int> seq[2], sub[2];

void findSubArr(vector<int> arr, vector<int>& sub) {
    int arrLen = arr.size();
    int subArrLen = 1 << arrLen;
    for (int i = 0; i < subArrLen; i++) {
        int sum = 0;
        for (int j = 0; j < arrLen; j++) {
            sum += arr[j] * ((i >> j) & 1);
        }
        sub.push_back(sum);
    }
}

int main() {
    FAST_IO
    cin >> len >> target;

    for (int i = 0; i < len; i++) {
        cin >> arr[i];
        seq[i % 2].push_back(arr[i]);
    }
    for (int i = 0; i < 2; i++) {
        findSubArr(seq[i], sub[i]);
        sort(sub[i].begin(), sub[i].end());
    }

    long long count = 0;
    int oddIdx = 0, evenIdx = sub[1].size() - 1;
    while (oddIdx < sub[0].size() && evenIdx >= 0) {
        int sum = sub[0][oddIdx] + sub[1][evenIdx];
        if (sum > target)   evenIdx--;
        else if (sum < target)  oddIdx++;
        else {
            long long oddCount = 1, evenCount = 1;
            while (oddIdx + oddCount < sub[0].size() && sub[0][oddIdx + oddCount] == sub[0][oddIdx])
                oddCount++;
            while (evenIdx - evenCount >= 0 && sub[1][evenIdx - evenCount] == sub[1][evenIdx])
                evenCount++;
            count += oddCount * evenCount;
            oddIdx += oddCount;
            evenIdx -= evenCount;
        }
    }
    if (!target)    count--;
    cout << count;
}