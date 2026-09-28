#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> scores) {
    int answer = 1;
    vector<int> target = scores[0];
    sort(scores.begin(), scores.end(), [](vector<int> a, vector<int> b) { 
        if (a[0] == b[0])   return a[1] < b[1];
        return a[0] > b[0];
    });
    int max_peer_score = scores[0][1];
    for (int i = 0; i < scores.size(); i++) {
        if (max_peer_score > scores[i][1]) {
            if (target[0] == scores[i][0] && target[1] == scores[i][1]) return -1;
            continue;
        } 
        max_peer_score = max(scores[i][1], max_peer_score);
        if (scores[i][0] + scores[i][1] > target[0] + target[1])
            answer++;
    }

    return answer;
}