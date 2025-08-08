#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> score_map;
    for (int i = 0; i < name.size(); i++) {
        score_map[name[i]] = yearning[i];
    }
    for (vector<string> p : photo) {
        int score = 0;
        for (int i = 0; i < p.size(); i++) {
            if (!score_map.count(p[i])) continue;
            score += score_map[p[i]];
        }
        answer.push_back(score);
    }
    return answer;
}