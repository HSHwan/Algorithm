#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_LEN 1000

using namespace std;

int target;
int aLen, bLen;
int a[MAX_LEN], b[MAX_LEN];
int aSum[MAX_LEN], bSum[MAX_LEN];
vector<int> aPartSum, bPartSum;

void setArrPartSum(vector<int>& partSum, int* sum, int len) {
    partSum.assign(sum, sum + len);
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            sum[j] -= sum[i];
            partSum.push_back(sum[j]);
        }
    }
    sort(partSum.begin(), partSum.end());
}

long long countTwoArrSumMatch() {
    long long count = 0;
    int aPartSumLen = aPartSum.size(), bPartSumLen = bPartSum.size();
    int aIdx = 0, bIdx = bPartSumLen - 1;
    while (aIdx < aPartSumLen && bIdx >= 0) {
        int twoArrSum = aPartSum[aIdx] + bPartSum[bIdx];
        if (twoArrSum == target) {
            long long aCount = 0, bCount = 0;
            for (int i = aIdx; i < aPartSumLen; i++) {
                if (aPartSum[i] != aPartSum[aIdx])
                    break;
                aCount++;
            }
            for (int i = bIdx; i >= 0; i--) {
                if (bPartSum[i] != bPartSum[bIdx])
                    break;
                bCount++;
            }
            count += aCount * bCount;
            aIdx += aCount;
            bIdx -= bCount;
        }
        else if (twoArrSum > target)
            bIdx--;
        else
            aIdx++;
    }
    return count;
}

int main() {
    FAST_IO
    
    cin >> target;
    cin >> aLen;
    for (int i = 0; i < aLen; i++) {
        cin >> a[i];
        aSum[i] = a[i] + ((i > 0) ? aSum[i - 1] : 0);
    }
    cin >> bLen;
    for (int i = 0; i < bLen; i++) {
        cin >> b[i];
        bSum[i] = b[i] + ((i > 0) ? bSum[i - 1] : 0);
    }
    setArrPartSum(aPartSum, aSum, aLen);
    setArrPartSum(bPartSum, bSum, bLen);
    long long count = countTwoArrSumMatch();
    cout << count;
}