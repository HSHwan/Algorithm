#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<int> server(24, 0);
    for (int i = 0; i < 24; i++) {
        int need = players[i] / m - server[i];
        if (need > 0) {
            for (int j = i; j < min(i + k, 24); j++) {
                server[j] += need;
            }
            answer += need;
        }
    }
    
    return answer;
}