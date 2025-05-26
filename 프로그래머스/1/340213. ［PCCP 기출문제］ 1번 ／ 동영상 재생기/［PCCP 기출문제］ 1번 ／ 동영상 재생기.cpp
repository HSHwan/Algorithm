#include <string>
#include <vector>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int video = stoi(video_len.substr(0, 2)) * 60 + stoi(video_len.substr(3, 2));
    int cur = stoi(pos.substr(0, 2)) * 60 + stoi(pos.substr(3, 2));
    int op_s = stoi(op_start.substr(0, 2)) * 60 + stoi(op_start.substr(3, 2));
    int op_e = stoi(op_end.substr(0, 2)) * 60 + stoi(op_end.substr(3, 2));
    if (cur >= op_s && cur < op_e)  cur = op_e;
    
    for (string cmd : commands) {
        if (cmd == "next")  cur = min(cur + 10, video);
        else    cur = max(cur - 10, 0);
        if (cur >= op_s && cur < op_e)  cur = op_e;
    }
    answer = (cur / 60 < 10 ? "0" : "") + to_string(cur / 60) + ":" + (cur % 60 < 10 ? "0" : "") + to_string(cur % 60);
    
    
    return answer;
}