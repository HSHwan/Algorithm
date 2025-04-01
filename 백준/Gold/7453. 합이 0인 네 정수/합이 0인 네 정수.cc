#include <iostream>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 4000

using namespace std;

int arr[4][MAX];
int arrSum[2][MAX * MAX];

int main() {
    FAST_IO
    int arrLen;
    cin >> arrLen;

    for (int i = 0; i < arrLen; i++)
        cin >> arr[0][i] >> arr[1][i] >> arr[2][i] >> arr[3][i];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < arrLen; j++) {
            for (int k = 0; k < arrLen; k++)
                arrSum[i][j * arrLen + k] = arr[2 * i][j] + arr[2 * i + 1][k];
        }
        sort(arrSum[i], arrSum[i] + arrLen * arrLen);
    }

    long long count = 0;
    int arrSumLen = arrLen * arrLen;
    int left = 0, right = arrSumLen - 1;
    while (left < arrSumLen && right >= 0) {
        int sum = arrSum[0][left] + arrSum[1][right];
        if (sum > 0)        right--;
        else if (sum < 0)   left++;
        else {
            long long leftCount = 0, rightCount = 0;
            while (left + leftCount < arrSumLen && arrSum[0][left + leftCount] == arrSum[0][left])
                leftCount++;
            while (right - rightCount >= 0 && arrSum[1][right - rightCount] == arrSum[1][right])
                rightCount++;
            count += leftCount * rightCount;
            left += leftCount;
            right -= rightCount;
        }
    }

    cout << count;
}