#include <iostream>
using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    int A[N];
    for (int i=0;i<N;i++) {
        cin >> A[i];
    }
    int j=0;
    int sum=0;
    int num=0;
    for (int i=0;i<N;i++) {
        while(j!=N && sum<M) {
            sum+=A[j];
            j++;
        }
        if (sum==M) {
            num++;
        }
        sum-=A[i];
    }
    cout << num;
} 