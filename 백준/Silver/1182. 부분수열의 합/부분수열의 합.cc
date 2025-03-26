#include <iostream>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_LEN 20

using namespace std;

int arr[MAX_LEN];

int main() {
    FAST_IO

    int arrLen, target;
    cin >> arrLen >> target;

    for (int i = 0; i < arrLen; i++)
        cin >> arr[i];

    int count = 0, seqSize = 1 << arrLen;
    for (int i = 1; i < seqSize; i++) {
        int sum = 0;
        for (int j = 0; j < arrLen; j++) {
            sum += arr[j] * ((i >> j) & 1);
        }
        count += (sum == target);
    }

    cout << count;
}