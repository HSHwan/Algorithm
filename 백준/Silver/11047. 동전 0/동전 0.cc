#include <iostream>
#include <vector>

using namespace std;

int N,K,A, coin_min = 0;
vector<int> coin;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for (int i = 0; i < N; i++){
        cin >> A;
        coin.push_back(A);
    }

    for (int i = N-1; i >= 0; i--){
        coin_min += K / coin[i];
        K %= coin[i];
        if (!K)
            break;
    }
    cout << coin_min;
}