#include <iostream>
#include <vector>
#include <cstring>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 4000000

using namespace std;

bool isPrimeNum[MAX];
vector<int> primeNums;

void setPrimeNum() {
    memset(isPrimeNum, true, MAX);
    for (int i = 2; i < MAX; i++) {
        if (!isPrimeNum[i])   continue;
        primeNums.push_back(i);
        for (int j = 2 * i; j < MAX; j += i) {
            isPrimeNum[j] = false;
        }
    }
}

int main() {
    FAST_IO
    int n;
    cin >> n;

    setPrimeNum();
    int low = 0, high = 0;
    int sum = primeNums[0];

    int count = 0;
    int primeNumLen = primeNums.size();
    while (low <= high && high < primeNumLen) {
        if (sum < n)   sum += primeNums[++high];
        else {
            count += (sum == n);
            sum -= primeNums[low++];
        }
    }

    cout << count;
}