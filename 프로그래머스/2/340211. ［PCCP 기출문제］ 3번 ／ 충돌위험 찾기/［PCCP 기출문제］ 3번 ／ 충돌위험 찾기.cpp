#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    vector<vector<int>> robots(routes.size());
    int cur_num = robots.size();
    for (int i = 0; i < cur_num; i++) {
        robots[i] = points[routes[i][0] - 1];
        robots[i].push_back(1);
    }
    
    vector<vector<int>> map(101, vector<int>(101, 0));
    for (vector<int> robot : robots) {
        map[robot[0]][robot[1]]++;
        if (map[robot[0]][robot[1]] == 2)   answer++;   
    }
    
    while (cur_num) {
        for (int i = 0; i < robots.size(); i++) {
            int next_r = robots[i][2];
            if (next_r == -1)   continue;
            if (next_r == routes[i].size()) {
                robots[i][2] = -1;
                continue;
            }
            vector<int> next_p = points[routes[i][next_r] - 1];
            if (robots[i][0] != next_p[0]) {
                robots[i][0] += (next_p[0] - robots[i][0]) / abs(next_p[0] - robots[i][0]);
            }
            else {
                robots[i][1] += (next_p[1] - robots[i][1]) / abs(next_p[1] - robots[i][1]);
            }
            if (robots[i][0] == next_p[0] && robots[i][1] == next_p[1]) {
                robots[i][2]++;
                if (robots[i][2] == routes[i].size())   cur_num--;
            }
        }
        
        vector<vector<int>> map(101, vector<int>(101, 0));
        for (vector<int> robot : robots) {
            if (robot[2] == -1) continue;
            map[robot[0]][robot[1]]++;
            if (map[robot[0]][robot[1]] == 2)   answer++;   
        }
    }
    
    return answer;
}