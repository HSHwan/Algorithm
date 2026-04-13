#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {    
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)    arr[i] = i + 1;

    do {
        for (int elem : arr)    cout << elem << ' ';
        cout << '\n';
    } while (next_permutation(arr.begin(), arr.end()));
}