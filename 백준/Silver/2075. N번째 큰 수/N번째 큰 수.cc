#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    FAST_IO

    int N;
    cin >> N;

    int N_squared = N * N;
    vector<int> arr(N_squared);
    for (int i = 0; i < N_squared; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), greater<int>());
    cout << arr[N - 1];
}