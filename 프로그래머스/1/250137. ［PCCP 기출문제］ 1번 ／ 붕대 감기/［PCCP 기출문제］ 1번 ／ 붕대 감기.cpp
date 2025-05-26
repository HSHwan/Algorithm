#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health, successStreak = 0, maxTime = attacks.back()[0], attackIdx = 0;
    for (int i = 1; i <= maxTime; i++){
        if (i == attacks[attackIdx][0]){
            answer -= attacks[attackIdx][1];
            successStreak = 0;
            attackIdx++;
        }
        else {
            successStreak++;
            answer += bandage[1] + ((successStreak == bandage[0]) ? bandage[2] : 0);
            answer = answer > health ? health : answer;
            successStreak %= bandage[0];
        }
        if (answer <= 0){
            answer = -1;
            break;
        }
    }
    return answer;
}