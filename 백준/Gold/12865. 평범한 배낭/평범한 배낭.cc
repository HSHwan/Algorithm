#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int w[101], v[101];
int DP[101][100001];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> w[i] >> v[i];

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= K; j++){
			if (j >= w[i])
				DP[i][j] = max(DP[i - 1][j], v[i] + DP[i - 1][j - w[i]]);
			else 
				DP[i][j] = DP[i - 1][j];
		}
	}

	cout << DP[N][K] << '\n';

	return 0;
}