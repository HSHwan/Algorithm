#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// first 1 2 3 4 5
// second 2 1 2 3 2 4 2 5
// third 3 3 1 1 2 2 4 4 5 5

vector<int> solution(vector<int> answers) {
    vector<int> answer, give_up_student[3] = {{1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
    int score[3] = {0, 0, 0}, give_up_student_len[3] = {5, 8, 10};
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < answers.size(); j++){
            if (give_up_student[i][j % give_up_student_len[i]]  == answers[j])  score[i]++;
        }
    }
    
    int max_score = *max_element(score, score + 3);
    for (int i = 0; i < 3; i++)
        if (score[i] == max_score)  answer.push_back(i + 1);
    return answer;
}