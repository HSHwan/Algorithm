#include <iostream>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_LEN 10000

using namespace std;

int arr[MAX_LEN], arrSum[MAX_LEN + 1] = {0, };

int main() {
    FAST_IO

    int arrLen, target;
    cin >> arrLen >> target;

    for (int i = 0; i < arrLen; i++) {
        cin >> arr[i];
        arrSum[i + 1] = arr[i] + arrSum[i];
    }

    int count = 0;
    for (int i = 0; i < arrLen; i++) {
        for (int j = i + 1; j <= arrLen; j++) {
            arrSum[j] -= arrSum[i];
            count += (target == arrSum[j]);
        }
    }

    cout << count;
}