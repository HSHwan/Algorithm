#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> park_log, park_real;
    for (string record : records) {
        string car_time_str = record.substr(0, 5);
        int car_time = stoi(car_time_str.substr(0, 2)) * 60 + stoi(car_time_str.substr(3, 2));
        string car_num = record.substr(6, 4);
        string stat = record.substr(11);
        if (stat == "IN") {
            park_real[car_num] = car_time;
        }
        else if (stat == "OUT") {
            int interval = car_time - park_real[car_num];
            if (!park_log.count(car_num))    park_log[car_num] = interval;
            else    park_log[car_num] += interval;
            park_real[car_num] = -1;
        }
    }
    
    int max_time = 23 * 60 + 59;
    for (auto p : park_real) {
        string car_num = p.first;
        int interval = p.second;
        if (interval == -1)  continue;
        interval = max_time - interval;
        if (!park_log.count(car_num))   park_log[car_num] = interval;
        else    park_log[car_num] += interval;
    }    
    
    for (auto log : park_log) {
        int interval = log.second;
        int park_cost = fees[1];
        if (interval > fees[0]) {
            park_cost += ceil((double)(interval - fees[0]) / fees[2]) * fees[3];
        }
        answer.push_back(park_cost);
    }
    
    return answer;
}