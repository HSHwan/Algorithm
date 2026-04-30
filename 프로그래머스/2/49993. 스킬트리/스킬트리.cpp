#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<int> skill_idx(26, -1);
    for (int i = 0; i < skill.size(); i++) {
        skill_idx[skill[i] - 'A'] = i;
    }
    for (string tree : skill_trees) {
        int prev_skill = -1;
        bool possible = true;
        for (char ch : tree) {
            if (skill_idx[ch - 'A'] == -1)    continue;
            if (skill_idx[ch - 'A'] > prev_skill + 1) {
                possible = false;
                break;
            }
            else if (skill_idx[ch - 'A'] == prev_skill + 1) {
                prev_skill++;
            }
        }
        answer += possible;
    }
    return answer;
}