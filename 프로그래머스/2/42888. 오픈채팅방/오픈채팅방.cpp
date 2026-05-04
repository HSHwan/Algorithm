#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

typedef pair<string, string> pss;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> nickname_map;
    vector<pss> log_list;
    for (string line : record) {
        istringstream iss(line);
        string buf[3];
        iss >> buf[0] >> buf[1] >> buf[2];
        if (buf[0] == "Enter") {
            log_list.push_back({buf[1], "님이 들어왔습니다."});
            nickname_map[buf[1]] = buf[2];
        }
        else if (buf[0] == "Leave") {
            log_list.push_back({buf[1], "님이 나갔습니다."});
        }
        else {
            nickname_map[buf[1]] = buf[2];
        }
    }
    
    answer.resize(log_list.size());
    for (int i = 0; i < log_list.size(); i++) {
        answer[i] = nickname_map[log_list[i].first] + log_list[i].second;
    }
    return answer;
}