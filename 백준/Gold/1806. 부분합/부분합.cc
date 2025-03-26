#include <iostream>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_LEN 100000

using namespace std;

int arr[MAX_LEN];

int main() {
    FAST_IO

    int arrLen, target;
    cin >> arrLen >> target;

    for (int i = 0; i < arrLen; i++)
        cin >> arr[i];

	int low = 0;
	int high = 0;
	int sum = arr[0];
	int len = arrLen + 1;

	while (low <= high && high < arrLen) {
		if (sum < target) {
			sum += arr[++high];
		}
		else {
			len = min(len, high - low + 1);
			sum -= arr[low++];
		}
	}

	if (len == arrLen + 1) len = 0;
    cout << len;
}