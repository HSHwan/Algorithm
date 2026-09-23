#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dict;
    for (char i = 'A'; i <= 'Z'; i++) {
        dict[string(1, i)] = dict.size() + 1;
    }
    int msg_len = msg.size();
    string cur_word = "";
    for (int i = 0; i < msg_len; i++) {
        string next_word = cur_word + msg[i];
        if (dict.count(next_word) == 0) {
            dict[next_word] = dict.size() + 1;
            answer.push_back(dict[cur_word]);
            cur_word = "";
        }
        cur_word += msg[i];
        if (i == msg_len - 1) {
            answer.push_back(dict[cur_word]);
        }
    }
    return answer;
}