#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    FAST_IO

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int num[10] = {0, };

    int max_len = 0;
    int start = 0, end = 0, count = 0;
    while (end < n) {
        if (!num[arr[end]]) count++;
        num[arr[end]]++;        
        while (count > 2) {
            num[arr[start]]--;
            if (!num[arr[start]])   count--;
            start++;
        }
        end++;
        max_len = max(end - start, max_len);
    }

    cout << max_len;
}